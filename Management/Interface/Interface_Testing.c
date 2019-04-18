/*
 * Interface_Testing.c
 *
 *  Created on: 2018年2月26日
 *      Author: Administrator
 */	 		 
/******************************************************************************/
#include "Interface_Testing.h"

/******************************************************************************/
uint16 max = 0;
uint8 Storage_Data_Conut = 0;
uint16 BOUNDARY_VALUE = 2500;
uint8 SignalProcess[1024] = {0};

/******************************************************************************/
Down_Time block_Testing = {
	UI_STATE_MAIN_WINDOW,

	ENABLE,							/* Display HZ16X8 */
	{
		UI_Return,
		0,   22,
		50,  45
	},
};

/******************************************************************************/
Down_Time* UI_WindowBlocksAttrArray_Down_Time[] = {/* Window: Testing entry */
		&block_Testing,
};

/******************************************************************************/
uint8 Interface_Testing(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	uint16 Start_Postion=0;
	if(Interface_Reord)
	{
		UI_state = UI_STATE_DOWN_TIME_PROCESS;
		return state;
	}

	max = 0;
	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_12))
	{
		if(temp <= 3.0)
		{
			Display_Time = 0;
			DisplayDriver_Fill(0,22,240,320,Interface_Back);
			UI_Background_Battery_Low_Display();
			Display_Time = 1;
			UI_state = UI_STATE_MAIN_WINDOW;
			Delay_ms_SW(1500);
			return state;
		}
	}
	Exti_lock = DISABLE;
	QRCode_Trigger_Disabled();
	UI_Background_Plate_Testing();
	SystemManage_5V_Enabled();
	Start_Postion = Get_Start_Postion();
	RotationMotor_Input_StepDrive(Foreward_Rotation,Start_Postion);
	if(Confirm_CUP)
	{
		Acquisition_Signal();
		UI_state = UI_STATE_RESULT;
	}
	else
	{
		UI_state = UI_STATE_INSERT_CUP;
	}
	SystemManage_5V_Disabled();
	Delay_ms_SW(100);
	return state;
}
/******************************************************************************/
void Acquisition_Signal(void)
{
	uint8 j = 0,Step_Count = 46,Step_Start = 36,i = 0;
	NowCup_Count = 0;
	Storage_Data_Conut = 0;
	Storage_Time();
	for(i = 0;i < 12;i++)
	{
		memset(&Storage_Data.CH_data[i].Result[0],0,6);
	}
	/* 第二步:旋转360度，环绕杯子采集信号 */

	/* 二维码 */
	QR_Date_SignalProcess_Alg_data();

	ScanMotorDriver_Goto_BasePosition();
	/* 采样与结果存储*/
	for(NowCup_Count = 0;NowCup_Count< 17;NowCup_Count++)
	{
		if(QR_Date.ch_data[NowCup_Count].Switch_Bool)
		{
			/* 采样 */
			SignalSample_SampleStrip();

			/* 运行算法 */
			memcpy(&SignalProcess_Alg_data.sampleBuffer[0], SignalProcess_sampleBuffer, SignalSample_count << 1);
			SignalProcess_Alg_data.sampleNumber = SignalSample_count;
			SignalProcess_Run();


			/* 判定结果 */
			Result_Display();
			Storage_Data_Conut += 1;

			/* 调试输出 */
			if(UI_runMode)
			{
				memset(SignalProcess,0,sizeof(SignalProcess));
				memcpy(SignalProcess,SignalProcess_sampleBuffer,1024);
				HostComm_Cmd_Send_RawData((SignalSample_count - 20) << 1, &SignalProcess[2]);
				Delay_ms_SW(30);
				memset(SignalProcess,0,sizeof(SignalProcess));
				HostComm_Cmd_Send_C_T(SignalProcess_Alg_data.calcInfo.areaC, SignalProcess_Alg_data.calcInfo.areaT);
				Delay_ms_SW(40);
			}
		}

		/* 转动电机转动30° */
		if((NowCup_Count/4) == 1)
		{
			RotationMotor_Input_StepDrive(Foreward_Rotation,19);
		}
		else
		{
			RotationMotor_Input_StepDrive(Foreward_Rotation,18);
		}

		/* 进度条刷新 */
		for(j = Step_Start;j < Step_Count;j++)		/* 每次进度条走十格 */
		{
			Delay_ms(30);
			Display_Time = 0;
			DisplayDriver_Fill(j,130,j+1,150,Thint_GREEN);
			Display_Time = 1;
		}
		Step_Start = Step_Count;					/* 重置进度条开始位置 */
		Step_Count += 10;
	}
}

/******************************************************************************/
uint16 Get_Start_Postion(void)
{
	uint8 Judge_Flag = 2,Trend_FLag = 0,Judge_Trend = 0;
	uint16 Start_Postion = 0,Postion_Down = 0,i = 0,Postion_Up = 0;
	while(Judge_Flag--)
	{
		if(0 == Judge_Flag)
		{
			RotationMotor_Input_StepDrive(Foreward_Rotation,30);
		}

		Acquisition_StartSignal();

		/* 3.找到上升沿的位置 */
		for(i = 0;i < 511;i++)
		{
			if((SignalProcess_sampleBuffer[i] <= Data_Boundary) && (SignalProcess_sampleBuffer[i+1] > Data_Boundary))
			{
				Trend_FLag = 1;
				if(Check_Trend(&SignalProcess_sampleBuffer[0],i,Trend_FLag))
				{
					Postion_Up = i;
					Judge_Trend = 1;
					Confirm_CUP = 1;
				}
				else
				{
					Confirm_CUP = NO_CUP;
					Judge_Trend = 0;
				}
			}
		}

		if (0 == Postion_Up)
		{
			Postion_Up = 1;
		}

		if(Judge_Trend)
		{
			Start_Postion = Calculate_Postion_Up(&SignalProcess_sampleBuffer[0],Postion_Up);
			if(Calculate_StartPostion_Down(&SignalProcess_sampleBuffer[0],Start_Postion))
			{
				Judge_Flag = 0;
				Confirm_CUP = 1;
			}
			else
			{
				Confirm_CUP = NO_CUP;
				Start_Postion = 0;
			}
		}
	}

	if(!Confirm_CUP)
	{
		Start_Postion = 0;
	}
	else
	{
		Calculate_Max_Postion(Start_Postion);
	}

	return Start_Postion;
}

/******************************************************************************/
uint16 Calculate_Postion_Up(uint16* Signal,uint16 Postion)
{
	uint16 Start_Postion = 0,i = 0,Confirm_Postion = 1,Reconfirm_Postion = 0;

	i = Postion;
	do
	{
		if(Signal[i] <= Signal[i+1])
		{
			i += 1;
			Start_Postion = i;
			Confirm_Postion = 1;
			if(i >511)
			{
				Confirm_Postion = 0;
				Reconfirm_Postion = 1;
			}
		}
		else
		{
			Confirm_Postion = 0;
		}

	}while(Confirm_Postion);

	if(Reconfirm_Postion)
	{
		i = 1;
		do
		{
			if(Signal[i] <= Signal[i+1])
			{
				i += 1;
				Start_Postion = i;
				Confirm_Postion = 1;
			}
			else
			{
				Confirm_Postion = 0;
			}

		}while(Confirm_Postion);
	}

	return Start_Postion;
}

/******************************************************************************/
uint8 Calculate_StartPostion_Down(uint16* Signal,uint16 Postion)
{
	uint16 Start_Postion = 0,i = 0,Confirm_Postion = 1,Reconfirm_Postion = 0;
	i = Postion;

	if((i+6) < 511)
	{
		while(Confirm_Postion)
		{
			if(Signal[i] < Signal[i+1])
			{
				return 0;
			}
			else
			{
				Start_Postion= 1;
			}

			i += 1;
			if(i >= (Postion+5))
			{
				Confirm_Postion = 0;
			}
			else
			{
				Confirm_Postion = 1;
			}
		}
	}
	else
	{
		while(Confirm_Postion)
		{
			if(Signal[i] < Signal[i+1])
			{
				return 0;
			}
			else
			{
				Start_Postion= 1;
			}

			i += 1;
			if(i >= (Postion+5))
			{
				Confirm_Postion = 0;
			}
			else
			{
				Confirm_Postion = 1;
			}
		}
	}
	return Start_Postion;
}

/******************************************************************************/
uint16 Check_Trend(uint16 *Signal,uint16 Postion,uint8 Flag)
{
	uint16 i = 0,state = 0,Start_Postion = 0;
	Start_Postion  = Postion;
	if (Flag)
	{
		if((Start_Postion + 6) < 511)
		{
			for(i = Start_Postion;i < (Start_Postion + 6);i++)
			{
				if(Signal[i] < Signal[i+1])
				{
					state = 1;
				}
				else
				{
					state = 0;
				}
			}
		}
		else
		{
			for(i = Start_Postion;i < 511;i++)
			{
				if(Signal[i] < Signal[i+1])
				{
					state = 1;
				}
				else
				{
					state = 0;
				}
			}
		}
	}
	else
	{
		if((Start_Postion + 2) < 511)
		{
			for(i = Start_Postion;i < (Start_Postion + 1);i++)
			{
				if(Signal[i] > Signal[i+1])
				{
					state = 1;
				}
				else
				{
					state = 0;
				}
			}
		}
		else
		{
			for(i = Start_Postion;i < (Start_Postion + 1);i++)
			{
				if(Signal[1] > Signal[2])
				{
					state = 1;
				}
				else
				{
					state = 0;
				}
			}
		}
	}
	return state;
}

/******************************************************************************/
void Acquisition_StartSignal(void)
{
	uint16 i = 0;
	SignalSample_count = 0;

	/* 第一步:扫描电机转到中间位置 */
	memset(&SignalProcess_sampleBuffer[0],0,2*512);
	ScanMotorDriver_PositionSensor_Int_Enable();
	ScanMotorDriver_Goto_BasePosition();
	ScanMotorDriver_Goto_CentrePosition();
	SignalSample_Sample_EnterCriticalArea();
	for(i = 0;i < Whole_Circle;i++)
	{
		RotationMotor_Input_StepDrive(Foreward_Rotation,1);
		SignalProcess_sampleBuffer[SignalSample_count++]
									= SignalProcess_Collecting_Data();
	}

	if(UI_runMode)
	{
		memset(SignalBuffer,0,1024);
		memcpy(SignalBuffer, SignalProcess_sampleBuffer, 1024);
		HostComm_Cmd_Send_RawData(1024, SignalBuffer);
	}

	SignalSample_Sample_ExitCriticalArea();
	ScanMotorDriver_Goto_BasePosition();
	ScanMotorDriver_Goto_DetectionPosition();
	/* 第三步:数据处理得到杯子检测的起始位置*/
	/* 1.对数据进行移动平均 */

	Get_sampleBuffer_Boundary_Value();
	Get_sampleBuffer_Max_Value();
//	memcpy(SignalBuffer, &Data_Boundary, 2);
//	HostComm_Cmd_Send_RawData(2, SignalBuffer);
	/* 2.有无杯子判断 */
	if((max < 1200) || (BOUNDARY_VALUE > 900))
	{
		Confirm_CUP = NO_CUP;
		return;
	}
	else
	{
		Confirm_CUP = 1;
	}
}

/******************************************************************************/
void Calculate_Max_Postion(uint16 First_Postion)
{
	uint8 i = 0,reagent_Strip_Count = 17;
	uint16 Before_Postion = First_Postion,Last_Postion = First_Postion + 18;
	memset(Record_Max_Postion,0,sizeof(Record_Max_Postion));
	memcpy(&SignalProcess_sampleBuffer[512],SignalProcess_sampleBuffer,512);

	for(i= 0;i < reagent_Strip_Count;i++)
	{
		if(SignalProcess_sampleBuffer[Last_Postion] > Data_Boundary)
		{
			Last_Postion = Judge_Max(&SignalProcess_sampleBuffer[0],Last_Postion);
			Record_Max_Postion[i] = Last_Postion - Before_Postion;
			Before_Postion = Last_Postion;
			Last_Postion += 18;
		}
		else
		{
			reagent_Strip_Count = i;
			for(;i < 17;i++)
				Record_Max_Postion[i] = 1;
		}
	}
}

/******************************************************************************/
uint16 Judge_Max (uint16* Signal,uint16 New_Postion)
{
	uint16 Postion_Plus = New_Postion - 7,Postion_Add = New_Postion + 7;
	uint16 Max_Value = Signal[New_Postion],i = New_Postion;
	for(i = Postion_Plus;i <= Postion_Add;i++)
	{
		if(Signal[i] > Max_Value)
		{
			New_Postion = i;
		}
	}

	return New_Postion;
}

/******************************************************************************/
uint16 Get_sampleBuffer_Boundary_Value(void)
{
	uint16 Old_Record = 1,New_Record = 0;
	uint16 i = 0,Old_Boundary = 0,New_Boundary = 0,Boundary_Count = 0;
	BOUNDARY_VALUE = 2500;
	for(i = 0;i < SIGNALSAMPLE_MAX_COUNT;i++)
	{
		if(BOUNDARY_VALUE >= SignalProcess_sampleBuffer[i])
		{
			BOUNDARY_VALUE = SignalProcess_sampleBuffer[i];
		}
	}

	if(BOUNDARY_VALUE > 1500)
	{
		BOUNDARY_VALUE = 2500;
		return BOUNDARY_VALUE;
	}

	Old_Boundary = BOUNDARY_VALUE;
	New_Boundary = BOUNDARY_VALUE;

	for(Data_Boundary = BOUNDARY_VALUE;Data_Boundary < 1000;Data_Boundary += 5)
	{
		Boundary_Count = 0;
		for(i = 0;i < 511;i++)
		{
			if((Data_Boundary > SignalProcess_sampleBuffer[i+1]) && (Data_Boundary <= SignalProcess_sampleBuffer[i]))
			{
				Boundary_Count += 1;
			}

			if((Data_Boundary < SignalProcess_sampleBuffer[i+1]) && (Data_Boundary >= SignalProcess_sampleBuffer[i]) )
			{
				Boundary_Count += 1;
			}
		}

		New_Record = ((Boundary_Count < 3) && (Boundary_Count > 0))?1:0;

		if(Old_Record && (!New_Record))
		{
			New_Boundary = Data_Boundary;
		}

		if((!Old_Record) && New_Record)
		{
			Old_Boundary = Data_Boundary;
		}

		if(Old_Record && New_Record)
		{
			New_Boundary = Data_Boundary;
		}

		Old_Record = New_Record;
	}

	if(New_Boundary == Old_Boundary)
	{
		BOUNDARY_VALUE = 2500;
		return BOUNDARY_VALUE;
	}

	Data_Boundary = (New_Boundary + Old_Boundary)/2;


	return BOUNDARY_VALUE;
}

/******************************************************************************/
uint16 Get_sampleBuffer_Max_Value(void)
{
	uint16 j=0;
	max = 0;
	for(j = 0;j < SIGNALSAMPLE_MAX_COUNT;j++)
	{
		if(max < SignalProcess_sampleBuffer[j])
		{
			max = SignalProcess_sampleBuffer[j];
		}
	}
	return max;
}

/******************************************************************************/
void SignalSample_Moving_Average_Data(uint16 *Data,uint16 Length,uint16 Period)
{
	uint16 i=0,j=0;
	uint32 Num = 0;
	/*对数据进行移动平均*/
	for(i = 0;i < Length-Period;i++)
	{
		for(j = 0;j < Period;j++)
		{
			Num += Data[i+j];
		}
		Data[i] = Num/Period;
		Num=0;
	}
}

/******************************************************************************/
uint16 Calculate_Start_Postion(uint16* Signal,uint16 Postion)
{
	uint16 Start_Postion = 0,i = 0;
	Start_Postion = Postion;
	for(i = Postion;i < (Postion+14);i++)
	{
		if(Signal[i] < Signal[i+1])
		{
			Start_Postion = i+1;
		}
	}
	return Start_Postion;
}

/******************************************************************************/
void QR_Date_SignalProcess_Alg_data (void)
{
	/* @TODO */
	SignalProcess_Alg_data.posInfo.C_center = QR_Date.head.midC;
	SignalProcess_Alg_data.posInfo.searchHalfRadius_C = QR_Date.head.searchHalfRadius_C;
	SignalProcess_Alg_data.posInfo.dist_C_T1 = QR_Date.head.distC_T;
	SignalProcess_Alg_data.posInfo.searchHalfRadius_T = QR_Date.head.searchHalfRadius_T;
	SignalProcess_Alg_data.posInfo.dist_peak1 = QR_Date.head.distC_Base1;
	SignalProcess_Alg_data.posInfo.dist_peak2 = QR_Date.head.distC_Base2;
	SignalProcess_Alg_data.posInfo.dist_peak3 = QR_Date.head.distC_Base3;
	SignalProcess_Alg_data.posInfo.dist_peak4 = QR_Date.head.distC_Base4;
	SignalProcess_Alg_data.posInfo.areaC_HalfRadius = QR_Date.head.areaC_HalfRadius;
	SignalProcess_Alg_data.posInfo.areaT_HalfRadius = QR_Date.head.areaT_HalfRadius;
	SignalProcess_Alg_data.posInfo.winSize = QR_Date.head.winSize;
	SignalProcess_Alg_data.limitEnabled = QR_Date.head.limitEnabled;
	SignalProcess_Alg_data.limitInfo.C_stepSize = QR_Date.head.C_stepSize;
	SignalProcess_Alg_data.limitInfo.C_magnitude = QR_Date.head.C_magnitude;
	SignalProcess_Alg_data.limitInfo.C_MIN = QR_Date.head.C_MIN;
}

/******************************************************************************/
void Result_Display(void)
{
	if (SignalProcess_Alg_data.calcInfo.validity == ALG_RESULT_ABNORMAL_C)
	{
		memcpy(Storage_Data.CH_data[Storage_Data_Conut].Result, "INV",5);
		return;
	}
	else if (SignalProcess_Alg_data.calcInfo.validity == ALG_RESULT_LOW_AREA_C)
	{
		memcpy(Storage_Data.CH_data[Storage_Data_Conut].Result, "INV",5);
		return;
	}
	else if (SignalProcess_Alg_data.calcInfo.validity == ALG_RESULT_NO_T)
	{
		memcpy(Storage_Data.CH_data[Storage_Data_Conut].Result, "Pos++",5);
		return;
	}
	else
	{
		if(SignalProcess_Alg_data.calcInfo.ratioC_T > Storage_Data.CH_data[Storage_Data_Conut].threshold1)
		{
			memcpy(Storage_Data.CH_data[Storage_Data_Conut].Result, "Pos++",5);
		}
		else if (SignalProcess_Alg_data.calcInfo.ratioC_T > Storage_Data.CH_data[Storage_Data_Conut].threshold2)
		{
			memcpy(Storage_Data.CH_data[Storage_Data_Conut].Result, "Pos+",5);
		}
		else if (SignalProcess_Alg_data.calcInfo.ratioC_T > Storage_Data.CH_data[Storage_Data_Conut].threshold3)
		{
			memcpy(Storage_Data.CH_data[Storage_Data_Conut].Result, "Neg-",5);
		}
		else
		{
			memcpy(Storage_Data.CH_data[Storage_Data_Conut].Result, "Neg--",5);
		}
	}
}

/******************************************************************************/
uint8 Interface_Down_Time_Process(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Interface_Reord = 0;
	Action_time = QR_Date.head.time*60;
	Display_Down_Time_Plate();
	memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Down_Time) >> 2;
	memcpy(UI_WindowBlocksAttrArray, UI_WindowBlocksAttrArray_Down_Time,sizeof(UI_WindowBlocksAttrArray_Down_Time));
	UI_Draw_Window_Down_Time(UI_WindowBlocks);
	UI_state = UI_STATE_DOWN_TIME_TOUCH_PROCESS;
	Delay_ms_SW(100);
	return state;
}

/******************************************************************************/
void Display_Down_Time_Plate (void)
{
	char tbuf[8] = {0};
	uint8 time_second = 0,time_Minute = 0;

	time_second = Action_time%60;
	time_Minute = Action_time/60;

	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(74,112,154,168,LIGHTBLUE);
	sprintf((char*)tbuf,"%02d:%02d",time_Minute,time_second);
	DisplayDriver_Text16_Back(95,132,WHITE,LIGHTBLUE,tbuf);
	Display_Time = 1;
}

/******************************************************************************/
void UI_Draw_block_Down_Time(Down_Time* block);

/******************************************************************************/
void UI_Draw_Window_Down_Time(uint16 blockNum)
{
	uint8 blockIndex = 0;					/* Draw blocks one by one */
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		UI_Draw_block_Down_Time(UI_WindowBlocksAttrArray_Down_Time[blockIndex]);
	}
}

/******************************************************************************/
void UI_Draw_block_Down_Time(Down_Time* block)
{
	Display_Time = 0;
	if (block->pic_enabled)					/* 4. Draw character */
	{
		DisplayDriver_DrawPic_Touch(block->pic_attr.src,Interface_Back,
			block->pic_attr.offsetX,block->pic_attr.offsetY);
	}
	Display_Time = 1;
}

/******************************************************************************/
uint8 Interface_Down_Time_Touch_Process(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Open_time = 1;
	Down_Time_Touch_Check(UI_WindowBlocksAttrArray_Down_Time[0],xpos,ypos);
	if(!Action_time)
	{
			UI_state = UI_STATE_TESTING;
			Open_time = 0;
			Action_time = QR_Date.head.time;
			return UI_STATE_RERUN;
	}
	return state;
}

/******************************************************************************/
uint8 Down_Time_Touch_Check(Down_Time* block,uint16* xpos,uint16* ypos)
{
	uint8 stat = 0;
	if((xpos != 0) || (ypos != 0))
	{
		if((0 < *xpos) && (*xpos < 45) && (22 < *ypos) && (*ypos < 65))
		{
			UI_state = block->Interface_Status;
			Pic_Count = block->pic_attr.count;
			Open_time = 0;
			return UI_STATE_RERUN;
		}
	}
	return stat;
}
