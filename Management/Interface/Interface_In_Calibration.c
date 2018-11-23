/*
 * Interface_In_Calibration.c
 *
 *  Created on: 2018年9月3日
 *      Author: Administrator
 */

/******************************************************************************/
#include "Interface_In_Calibration.h"
#include "All_Step.pic"
#include "Empty_Step.pic"

/******************************************************************************/
uint8 Potential_Value = 255,Left_Value = 0,Right_Value = 255;
uint16 Mid_Value = 1;

/******************************************************************************/
block_attr_In_Calibration block_attr_In_Calibration_return = {
	UI_STATE_SETTING,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		UI_Return,
		0,   22,
		45,  40,
		0
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_In_Calibration* UI_WindowBlocksAttrArray_In_Calibration[] = {/* Window: Standard entry */
		&block_attr_In_Calibration_return,
};

/******************************************************************************/
void UI_Draw_Block_In_Calibration(block_attr_In_Calibration* block);

/******************************************************************************/
uint8 Interface_In_Calibration_Process(uint16* xpos,uint16* ypos)
{
	uint8 state = 0,Calibration_State = 0;
	Enter_Sleep = 0,Calibration_channel = 1;
	MotorDriver_Ctr = 1;
	Display_Battery = 0;

	/* 开始校准，无低功耗，触摸无效 */
	UI_Background_Plate_In_Calibration();
	HumanInput_CapTS_Int(DISABLE);
	Calibration_State = Dichotomy_Calculate();
	memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_In_Calibration) >> 2;
	memcpy(UI_WindowBlocksAttrArray, UI_WindowBlocksAttrArray_In_Calibration,sizeof(UI_WindowBlocksAttrArray_In_Calibration));
	UI_Draw_Window_In_Calibration(UI_WindowBlocks);

	/* 结果判定显示 */
	if(Calibration_State)
	{
		Display_Time = 0;
		DisplayDriver_Fill(15,80,225,273,WHITE);

		switch(Font_Switch)
		{
		case DISPLAY_FONT_ENGLISH:
			DisplayDriver_Text_Flex(16,28,162,BLACK,Interface_Bar,"calibration Successful!");
			break;

		case DISPLAY_FONT_CHINESE:
			DisplayDriver_Text_Flex(24,72,158,BLACK,Interface_Bar,"校准成功");
			break;

		default:
			break;
		}
		Display_Time = 1;
	}
	else
	{
		Display_Time = 0;
		DisplayDriver_Fill(15,80,225,273,WHITE);

		switch(Font_Switch)
		{
		case DISPLAY_FONT_ENGLISH:
			DisplayDriver_Text16_Touch(40,162,BLACK,Interface_Bar,"Calibration failure!");
			break;

		case DISPLAY_FONT_CHINESE:
			DisplayDriver_Text_Flex(24,72,158,BLACK,Interface_Bar,"校准失败");
			break;

		default:
			break;
		}
		Display_Time = 1;
	}

	HumanInput_CapTS_Int(ENABLE);
	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	MotorDriver_Ctr = 0;
	Delay_ms_SW(40);
	Display_Battery = 1;
	Enter_Sleep = 1;
	return state;
}

/******************************************************************************/
void UI_Draw_Window_In_Calibration(uint16 blockNum)
{
	uint8 blockIndex = 0;					/* Draw blocks one by one */
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		UI_Draw_Block_In_Calibration(UI_WindowBlocksAttrArray_In_Calibration[blockIndex]);
	}
}

/******************************************************************************/
void UI_Draw_Block_In_Calibration(block_attr_In_Calibration* block)
{
	Display_Time = 0;
	if (block->pic_enabled)						/* 2. Draw picture */
	{
		DisplayDriver_DrawPic_Touch(block->pic_attr.src,Interface_Back,
				block->pic_attr.offsetX,block->pic_attr.offsetY);
	}

	if (block->char_enabled)					/* 4. Draw character */
	{
		DisplayDriver_Text16_Touch(
				block->char_attr.offsetX,block->char_attr.offsetY,
				block->char_attr.color,block->char_attr.backColor,
				block->char_attr.str);
	}
	Display_Time = 1;
}

/******************************************************************************/
void UI_Background_Plate_In_Calibration(void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_DrawPic_Touch(Empty_Step,Interface_Bar,10,138);
//	DisplayDriver_Text16_Touch(64,162,WHITE,Interface_Bar,"Calibrating...");
	Display_Time = 1;
}

/******************************************************************************/
void UI_Language_Plate_In_Calibration(void)
{
	Display_Time = 0;
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		DisplayDriver_Text_Flex(16,64,162,WHITE,Interface_Bar,"Calibrating...");
		break;

	case DISPLAY_FONT_CHINESE:
		DisplayDriver_Text_Flex(16,64,162,WHITE,Interface_Bar,"正在校准...");
		break;

	default:
		break;
	}
	Display_Time = 1;
}

/******************************************************************************/
uint8 Dichotomy_Calculate (void)
{
	uint16 i = 0,Max_Value = 0;
	uint8 num = 0,Poll_Count = 0;
	uint8 MBuffer[20] = {0};
	uint8 Result = 1,Step = 0,Num = 26,Start_Step =26;
	SignalSample_count = 0,Result_Judge = 0,Poll_Count = 0;
	Mid_Value = 255,Left_Value = 0,Right_Value = 255;

	SystemManage_5V_Enabled();
	ScanMotorDriver_Goto_BasePosition();
	SystemManage_5V_Disabled();

	/* 先判断0和255是否符合要求  */
	for(num = 0;num < 2;num++)
	{
		SignalSample_count = 0;
		Mid_Value = (num > 0)?255:0;
		SignalSample_resistorValue = (uint8)Mid_Value;
		SignalSample_resistorValueStored = (uint8)Mid_Value;
		SignalSample_Sample_SetResistor();

		SystemManage_5V_Enabled();
		ScanMotorDriver_Goto_BasePosition();
		SignalSample_SampleStrip();
		SystemManage_5V_Disabled();

		/* 调试模式下可输出数据  */
		if(UI_runMode)
		{
			memset(SignalBuffer,0,SignalSample_count << 1);
			memcpy(SignalBuffer, SignalProcess_sampleBuffer, SignalSample_count << 1);
			HostComm_Cmd_Send_RawData(SignalSample_count << 1, SignalBuffer);
		}

		if(Mid_Value)
		{
			for(i = 10;i < 135;i++)
			{
				if(SignalProcess_sampleBuffer[i] > 150)
				{
					Result_Judge = 0;
					return 0;
				}
			}
		}
		else
		{
			/* 求取最大值  */
			for(i = 10;i < 136;i++)
			{
				if(Max_Value < SignalProcess_sampleBuffer[i])
				{
					Max_Value = SignalProcess_sampleBuffer[i];
				}
			}
			if(Max_Value < 1900)
			{
				Result_Judge = 0;
				return 0;
			}
		}
	}

	Mid_Value = 20;
	do
	{
		if((Mid_Value < 1) && (Mid_Value > 254))
		{
			Result_Judge = 0;
			return 0;
		}

		/* 根据二分法设定的值重新采集数据 */
		SignalSample_count = 0,Max_Value = 0;
		Mid_Value = (Left_Value+Right_Value)/2;
		SignalSample_resistorValue = (uint8)Mid_Value;
		SignalSample_resistorValueStored = (uint8)Mid_Value;
		SignalSample_Sample_SetResistor();

		/* 丝杆电机上下信号采集  */
		memset(&SignalProcess_sampleBuffer[0],0,2*512);
		SystemManage_5V_Enabled();
		ScanMotorDriver_Goto_BasePosition();
		SignalSample_SampleStrip();
		SystemManage_5V_Disabled();

		/* 调试模式下可输出数据  */
		if(UI_runMode)
		{
			memset(SignalBuffer,0,SignalSample_count << 1);
			memcpy(SignalBuffer, SignalProcess_sampleBuffer, SignalSample_count << 1);
			HostComm_Cmd_Send_RawData(SignalSample_count << 1, SignalBuffer);
		}

		/* 求取最大值  */
		for(i = 1;i < 136;i++)
		{
			if(Max_Value < SignalProcess_sampleBuffer[i])
			{
				Max_Value = SignalProcess_sampleBuffer[i];
			}
		}

		/* 限定条件  */
		Result_Judge = (Max_Value > 1900)?1:0;
		Right_Value = (!Result_Judge)?Mid_Value:Right_Value;
		if(!Result_Judge)
			continue;

		for(i = 10;i < 135;i++)
		{
			Result_Judge = (SignalProcess_sampleBuffer[i] < 2100)?1:0;
			Left_Value = (!Result_Judge)?Mid_Value:Left_Value;
			if(!Result_Judge)
				break;

			Result_Judge = (SignalProcess_sampleBuffer[i] >= 200)?1:0;
			Right_Value = (!Result_Judge)?Mid_Value:Right_Value;
		}

		/* 进度刷新  */
		if(Calibration_channel)
		{
			if(Step < 9)
			{
				Step ++;
				for(Num = Start_Step;Num < (Start_Step + 20);Num++ )
				{
					Display_Time = 0;
					DisplayDriver_Fill(Num,142,Num,154,GREEN);
					if(Step >= 9)
					{
						DisplayDriver_DrawPic_Touch(All_Step,Interface_Bar,10,138);
					}
					Display_Time = 1;
					Delay_ms(30);
				}
				Start_Step += 20;
			}
		}

		/* 大于15次退出，校验失败 */
		Poll_Count++;
		if(Poll_Count > 12)
		{
			Result_Judge = 0;
			return Result_Judge;
		}

		Result = 1;
		/* 判定结果是否符合要求  */
		Result_Judge = Result_Judge?Dichotomy_Search(SignalProcess_sampleBuffer,Mid_Value):0;
		Result = Result_Judge;

		if(!Result)
			Storage_Write(&SignalSample_resistorValue, FLASH_CALI_ADDR,1);

	}while(!Result_Judge);

	if(Result)
	{
		Storage_Write(&SignalSample_resistorValue, FLASH_CALI_ADDR,1);
		/* Use it immediately */
		SignalSample_Sample_SetResistor();
	}

	return Result_Judge;
}

/******************************************************************************/
uint8 Dichotomy_Search(uint16 *Signal,uint8 Dichotomy_Value)
{
	uint8  Result_Flag = 0;
	uint16 i = 0,j = 0,Max_Value = 0,Max_Position = 0,Low_Value = 0,Low_Position = 0;
	uint16 Up_Trend = 0,Down_Trend = 0,Boundary_Down = 0,Valley_Value = 0;
	Max_Value = 0,Low_Value = 0;

	SignalSample_count = 0;
	SystemManage_5V_Enabled();
	SignalSample_Sample_SetResistor();
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
	SignalSample_Sample_ExitCriticalArea();
	SystemManage_5V_Disabled();

	/* 调试模式下可输出数据  */
	if(UI_runMode)
	{
		memset(SignalBuffer,0,1024);
		memcpy(SignalBuffer, SignalProcess_sampleBuffer, 1024);
		HostComm_Cmd_Send_RawData(1024, SignalBuffer);
	}

	/* 得到上升沿、下降沿、边界值以下的数据个数  */
	for(i = 0;i < 511;i++)
	{
		if(SignalProcess_sampleBuffer[i] < 2200)
		{
			if((SignalProcess_sampleBuffer[i] < Data_Boundary) && (SignalProcess_sampleBuffer[i+1] >= Data_Boundary))
			{
				Up_Trend += 1;
			}

			if((SignalProcess_sampleBuffer[i] > Data_Boundary) && (SignalProcess_sampleBuffer[i+1] <= Data_Boundary))
			{
				Down_Trend += 1;
			}

			if(Data_Boundary > 200)
			{
				if(SignalProcess_sampleBuffer[i] < (Data_Boundary - 200))
				{
					Boundary_Down += 1;
				}
			}
		}
		else
		{
			Left_Value = Mid_Value;
			Result_Judge = 0;
			return 1;
		}
	}

	/* 判定上升沿下降沿都是一个、边界值以下的数据大于 160个，且谷值大于边界值250 */
	if((1 == Up_Trend) && (1 == Down_Trend) && (Boundary_Down > 160) )
	{
		Result_Judge = 1;
		Result_Flag = 1;
	}
	else
	{
		if(Boundary_Down > 160)
		{
			Right_Value = Mid_Value;
		}
		else
		{
			Left_Value = Mid_Value;
		}

		Result_Judge = 0;
		Result_Flag = 0;
	}

	return Result_Flag;
}
