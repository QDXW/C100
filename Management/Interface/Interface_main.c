/*
 * Interface_main.c
 *
 *  Created on: 2018Äê2ÔÂ9ÈÕ
 *      Author: Administrator
 */

/******************************************************************************/
#include "Interface_main.h"
#include "Standard.pic"
#include "Quick.pic"
#include "Record.pic"
#include "Setting.pic"
#include "Open_face.pic"
#include "Open_HZ.pic"
#include "statusbar_bat.pic"
#include "statusbar_charging.pic"
#include "Blutooth_Ico.pic"

/******************************************************************************/
uint8 UI_state = UI_STATE_MAIN_WINDOW;

/******************************************************************************/
block_attr block_standard = {
		UI_STATE_STANDARD,
		ENABLE,									/* Display Picture */
		{
			Standard,
			7,  28,
			106, 106
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Standard",
			28,  138,
			WHITE,WHITE,
			Interface_Back
		},
};

/******************************************************************************/
block_attr block_quick = {
		UI_STATE_QUICK,
		ENABLE,									/* Display Picture */
		{
			Quick,
			127,  28,
			106, 106
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Quick",
			160,  138,
			WHITE,WHITE,
			Interface_Back
		},
};

/******************************************************************************/
block_attr block_record = {
		UI_STATE_RECORD,
		ENABLE,									/* Display Picture */
		{
			Record,
			7,  187,
			106, 106
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Record",
			36,  297,
			WHITE,WHITE,
			Interface_Back
		},
};

/******************************************************************************/
block_attr block_settings = {
		UI_STATE_SETTING,
		ENABLE,									/* Display Picture */
		{
			Setting,
			127, 187,
			106, 106
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Settings",
			148,  297,
			WHITE,WHITE,
			Interface_Back
		},
};

/******************************************************************************/
block_attr* UI_WindowBlocksAttrArray_Main[] = {		/* Window: Main entry */
		&block_standard,
		&block_quick,
		&block_record,
		&block_settings,
};
/******************************************************************************/
block_attr* UI_WindowBlocksAttrArray[20] = {0};

/******************************************************************************/
void UI_Draw_Block(block_attr* block);

/******************************************************************************/
uint8 Interface_Process(uint16* xpos,uint16* ypos)
{
	/* Define each state */
	static uint8 (* const UI_stateMachine[UI_STATE_MAX_STATE_NUM])(uint16* xpos,uint16* ypos) =
	{
			Interface_Main_Window_Process,
			Interface_Main,						/* Interface Main Display */
			Interface_Standard,					/* Interface Main Display */
			Interface_Start,					/* Interface Start Display */
			Interface_Quick,					/* Interface Quick Display */
			Interface_Record,					/* Interface Record Display */
			Interface_Setting,					/* Interface Setting Display */
			Interface_Testing,					/* Interface Test Display */
			Interface_Result,					/* Interface Result Display */
			Interface_Insert_Cup,				/* Interface insert cup Display */
			Interface_Delete,					/* Interface Delete Display */
			Interface_Down_Time_Process,		/* Interface Down Time Display */
			Interface_Buetooth_Process,			/* Interface Buetooth Display */
			Interface_About_Machine,			/* Interface About Machine Display */
			Interface_System_Time,				/* Interface About Machine Display */
			Interface_Set_Time_Process,			/* Interface About Machine Display */
			Interface_Quick_Touch_Process,		/* Interface About Machine Display */
			Interface_Down_Time_Touch_Process,	/* Interface About Machine Display */
			Interface_Result_Touch_Process,		/* Interface Result Touch Display */
			Interface_Invalue_Code_Process,		/* Interface Result Touch Display */
			Interface_Invalid_Touch_Process,	/* Interface Result Touch Display */
			Interface_Record_Demand_Process,	/* Interface Result Touch Display */

	};
	uint8 state;
	do										/* Polling each state */
	{
		if (UI_state < UI_STATE_MAX_STATE_NUM)
		{
			state = UI_stateMachine[UI_state](&xPos,&yPos);
		}
		xPos = 0;	/* Clear touch information to avoid repeated respond */
		yPos = 0;
	} while(state & UI_STATE_RERUN);

	return state;
}

/******************************************************************************/
uint8 Interface_Main(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Enter_Sleep = 1;
	Read_first = 1,Record_Display = 1;
	Interface_Reord = 0,Stored_Record = 1;
	QRCode_Trigger_Disabled();
	UI_Background_Plate_Main();
	memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Main) >> 2;
	memcpy(UI_WindowBlocksAttrArray, UI_WindowBlocksAttrArray_Main,
			sizeof(UI_WindowBlocksAttrArray_Main));
	UI_Draw_Window(UI_WindowBlocks);
	Exti_lock = ENABLE;
	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	return state;
}

/******************************************************************************/
void UI_Draw_Window(uint16 blockNum)
{
	uint8 blockIndex = 0;						/* Draw blocks one by one */
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		UI_Draw_Block(UI_WindowBlocksAttrArray_Main[blockIndex]);
	}
}

/******************************************************************************/
void UI_Draw_Block(block_attr* block)
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
void UI_Draw_Status_Bar(void)					/* UI Draw Status Bar and Battery */
{
	char tbuf[10] = {0};
	PCF8563_Read(&SystemManage_CurrentTime);
	sprintf((char*)tbuf,"%02d:%02d",SystemManage_CurrentTime.hour,
			SystemManage_CurrentTime.min);
	Display_Time = 0;
	DisplayDriver_Text16_Back(10,2,WHITE,Interface_Bar,tbuf);
	Display_Time = 1;
}

/******************************************************************************/
uint8 Interface_Main_Window_Process(uint16* xpos,uint16* ypos)
{
	Touch_Check (xpos,ypos);
}
/******************************************************************************/
uint8 Touch_Check (uint16* xpos,uint16* ypos)
{
	uint8 blockIndex = 0,state = 0;						/* Draw blocks one by one */
	if((xpos != 0) || (ypos != 0))
	{
		for (blockIndex = 0; blockIndex < UI_WindowBlocks; blockIndex++)
		{
			UI_Touch_Check(UI_WindowBlocksAttrArray[blockIndex],xpos,ypos);
			if(Touch_Success)
			{
				Touch_Success = 0;
				return UI_STATE_RERUN;
			}
		}
	}
	return state;
}

/******************************************************************************/
void UI_Touch_Check(block_attr* block,uint16* xpos,uint16* ypos)
{
	uint16 startX = 0,endX = 0;
	uint16 startY = 0,endY = 0;
	startX = block->pic_attr.offsetX;
	endX = startX + block->pic_attr.width;
	startY = block->pic_attr.offsetY;
	endY = startY + block->pic_attr.height;
	if(block->Interface_Status)
	{
		if((startX < *xpos) && (*xpos < endX) && (startY < *ypos) && (*ypos < endY))
		{
			UI_state = block->Interface_Status;
			Pic_Count = block->pic_attr.count;
			Touch_Success = 1;
		}
	}
}

/******************************************************************************/
void UI_Background_Plate_Main (void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_DrawStraight_Line(119,22,119,320,CYAN_Line);
	DisplayDriver_DrawStraight_Line(120,22,120,320,Thint_Line);
	DisplayDriver_DrawStraight_Line(0,170,240,170,CYAN_Line);
	DisplayDriver_DrawStraight_Line(0,171,240,171,Thint_Line);
	Display_Time = 1;
}

/******************************************************************************/
void Status_Init(void)
{
	GPIO_SetBits(GPIOD, GPIO_Pin_2);
	Display_Time = 0;
	DisplayDriver_Fill(0,20,240,320,Interface_Back);
	DisplayDriver_Fill(0,0,240,21,0X0AF8);
	DisplayDriver_DrawPic_Touch(Open_face,Interface_Bar,15,35);
	DisplayDriver_DrawPic_Touch(statusbar_bat,Interface_Bar,200,2);
	DisplayDriver_Text16_Touch(11,290,WHITE,Interface_Bar,"A good assistant for doctor!");
	Battery_Display();
	Bluetooth_Connection();
	UI_Draw_Status_Bar();
	Display_Time = 1;
	SystemManage_5V_Enabled();
	RotationMotor_SelfCheck_StepDrive();
	ScanMotorDriver_SelfCheck_StepDrive();
	SystemManage_5V_Disabled();
	Power_Open = 1;
	HumanInput_CapTS_Int(ENABLE);
}

/******************************************************************************/
void Battery_Display (void)
{
	int i = 0;

	adcx = Get_Adc_Average(ADC_Channel_11,10);
	temp = (float)adcx*(5.185/4096.0);

	DisplayDriver_Fill(103,7,118,8,Interface_Bar);
	if((!Power_Open) || (UI_state == UI_STATE_TESTING))
	{
		temp += 0.36;
	}

	if((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_12)) && (temp < 3.6))
	{
		DisplayDriver_Fill(203,7,104,15,RED);
	}
	else
	{
		if(temp > 4.1)
		{
			DisplayDriver_Fill(203,6,218,13,0x7EF);
		}
		else if(temp > 4.0)
		{
			DisplayDriver_Fill(203,6,215,13,0x7EF);
		}
		else if(temp > 3.9)
		{
			DisplayDriver_Fill(203,6,212,13,0x7EF);
		}
		else if(temp > 3.8)
		{
			DisplayDriver_Fill(203,6,209,13,0x7EF);
		}
		else if(temp > 3.7)
		{
			DisplayDriver_Fill(203,6,206,13,0x7EF);
		}
		else if(temp > 3.65)
		{
			DisplayDriver_Fill(202,5,202,14,RED);
		}
		else
		{
//			SystemManage_CheckPowerOff();
		}
	}


	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_12))
	{
		DisplayDriver_DrawPic_Touch(statusbar_charging,Interface_Bar,225,1);
	}
	else
	{
		DisplayDriver_Fill(225,0,240,20,Interface_Bar);
	}
}

/******************************************************************************/
void Bluetooth_Connection (void)
{
	if (Printer_isConnected())
	{
		if (!Bluetooth_Connect)
		{
			DisplayDriver_DrawPic_Touch(Blutooth_Ico,Interface_Bar,170,3);
			Bluetooth_Connect = 1;
		}
	}
	else
	{
		DisplayDriver_Fill(169,2,181,20,Interface_Bar);
		Bluetooth_Connect = 0;
	}
}
