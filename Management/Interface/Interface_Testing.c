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

uint8 SignalBuffer[1024] = {0};

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
		if(temp > 3.6)
		{

		}
		else
		{
			Display_Time = 0;
			DisplayDriver_Fill(0,22,240,320,Interface_Back);
			DisplayDriver_Text16_Touch(24, 80, RED,WHITE,"No Battery!");
			Display_Time = 1;
			UI_state = UI_STATE_MAIN_WINDOW;
			Delay_ms_SW(1500);
			return state;
		}
	}

	Exti_lock = DISABLE;
	Display_Battery = 0;
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
			Result_Judge();
			Storage_Data_Conut += 1;

			/* 调试输出 */
//			HostComm_Cmd_Send_C_T(SignalProcess_Alg_data.calcInfo.areaC, SignalProcess_Alg_data.calcInfo.areaT);
		}

		/* 转动电机转动30° */
		RotationMotor_Input_StepDrive(Foreward_Rotation,18);

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
	uint16 i = 0;
	uint16 Pre_Count = 0,Next_Count = 0;
	uint16 Start_Postion=0;
	uint16 Forever_Value = 0;
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

	memset(SignalBuffer,0,1024);
	memcpy(SignalBuffer, SignalProcess_sampleBuffer, 1024);
	HostComm_Cmd_Send_RawData(1024, SignalBuffer);

	SignalSample_Sample_ExitCriticalArea();
	ScanMotorDriver_Goto_BasePosition();
	ScanMotorDriver_Goto_DetectionPosition();
	/* 第三步:数据处理得到杯子检测的起始位置*/
	/* 1.对数据进行移动平均 */
	SignalSample_Moving_Average_Data(SignalProcess_sampleBuffer,SIGNALSAMPLE_MAX_COUNT,15);
	Get_sampleBuffer_Boundary_Value();
	Get_sampleBuffer_Max_Value();
	/* 2.有无杯子判断 */
	if((max < 1200) || (BOUNDARY_VALUE > 900))
	{
		Confirm_CUP = NO_CUP;
		return Confirm_CUP;
	}
	else
	{
		Confirm_CUP = 1;
	}

	/* 3.找到上升沿的位置 */
	for(i = 0;i < 511;i++)
	{
		if((SignalProcess_sampleBuffer[i] < 600) && (SignalProcess_sampleBuffer[i+1] >= 600))
		{
			Start_Postion = i;
		}
	}

	/* 判断上升沿是否在最后  */
		if((511-Start_Postion) < 9)
		{
			/* 求取上升沿在最后最大值  */
			for(i = Start_Postion;i < 511;i++)
			{
				if(SignalProcess_sampleBuffer[i] < SignalProcess_sampleBuffer[i+1])
				{
					Pre_Count = SignalProcess_sampleBuffer[i+1];
					Start_Postion = i+1;
				}
			}

			/* 上升沿在最后不为峰值的情况  */
			if(Pre_Count < SignalProcess_sampleBuffer[0])
			{
				Start_Postion = Calculate_Start_Postion(&SignalProcess_sampleBuffer[0],0);
			}
		}
		else
		{
			Start_Postion = Calculate_Start_Postion(&SignalProcess_sampleBuffer[0],Start_Postion);
		}
		return (Start_Postion + 9);
}

/******************************************************************************/
uint16 Get_sampleBuffer_Boundary_Value(void)
{
	uint16 i = 0;
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
	}
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
void Result_Judge(void)
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
void UI_Background_Plate_Testing (void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(36,130,205,150,WHITE);
	DisplayDriver_Text16_Touch(80,160,WHITE,WHITE,"testing...");
	Display_Time = 1;
}

/******************************************************************************/
uint8 Interface_Down_Time_Process(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Interface_Reord = 0;
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
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(74,112,154,168,LIGHTBLUE);
	sprintf((char*)tbuf,"%02d:%02d",(Action_time-1),59);
	DisplayDriver_Text16_Back(94,132,WHITE,LIGHTBLUE,tbuf);
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
			return UI_STATE_RERUN;
	}
	return state;
}

/******************************************************************************/
uint8 Down_Time_Touch_Check(Down_Time* block,uint16* xpos,uint16* ypos)
{
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
}
