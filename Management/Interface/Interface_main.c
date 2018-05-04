/*
 * Interface_main.c
 *
 *  Created on: 2018Äê2ÔÂ9ÈÕ
 *      Author: Administrator
 */

/******************************************************************************/
#include "PIC_Interface.h"
#include "Storage_Flash.h"
#include "Interface_main.h"
#include "SystemManage_RTC.h"

/******************************************************************************/
uint8 Cup_Count = 0;
uint8 Read_first = 1;

#if Drug_S100
extern uint8 page_Num;
extern uint8 Page_Flag;
extern uint8 page_tatol;
#endif

uint16 UI_WindowBlocks = 0;
uint8 UI_state = UI_STATE_MAIN_WINDOW;

#if Drug_S100
/******************************************************************************/
block_attr block_standard = {
		ENABLE,									/* Interface Main rect */
		{
			0,   20,
			128, 160,
			BACKCOLOR_CONTENT_BACK
		},

		ENABLE,									/* Display Picture */
		{
			gImage_PIC_Standard,
			12, 24,
			45, 45
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Standard",
			0,  71,
			White,Magenta,
			Baby_Blue
		},

		ENABLE,									/* Parting line */
		{
			63,  20,
			63,  160,
			Light_Gray
		},
};

/******************************************************************************/
block_attr block_quick = {
		DISABLE,
		{0},

		ENABLE,									/* Display Picture */
		{
			gImage_PIC_Quick,
			71,  24,
			45,  45
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Quick",
			74,  71,
			White,Magenta,
			Baby_Blue
		},

		ENABLE,									/* Parting line */
		{
			64,  20,
			64,  160,
			Thint_Blue
		},
};

/******************************************************************************/
block_attr block_record = {
		DISABLE,
		{0},

		ENABLE,									/* Display Picture */
		{
			gImage_PIC_Record,
			12,  94,
			45, 45
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Record",
			12,  141,
			White,Magenta,
			Baby_Blue
		},

		ENABLE,									/* Parting line */
		{
			0,    90,
			128,  90,
			Light_Gray
		},
};

/******************************************************************************/
block_attr block_settings = {
		DISABLE,
		{0},

		ENABLE,									/* Display Picture */
		{
			gImage_PIC_Setting,
			71, 94,
			45, 45
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Setting",
			68,  141,
			White,Magenta,
			Baby_Blue
		},

		ENABLE,									/* Parting line */
		{
			0,    91,
			128,  91,
			Thint_Blue
		},
};

/******************************************************************************/
block_font_attr block_font = {
		ENABLE,									/* Display HZ16X8 */
		{
			"Standard",
			0,  71,
			White,Magenta,
			Baby_Blue
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Quick",
			74,  71,
			White,Magenta,
			Baby_Blue
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Record",
			12,  141,
			White,Magenta,
			Baby_Blue
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Setting",
			68,  141,
			White,Magenta,
			Baby_Blue
		},
};

/******************************************************************************/
block_attr* UI_WindowBlocksAttrArray_Main[] = {		/* Window: Main entry */
		&block_standard,
		&block_quick,
		&block_record,
		&block_settings,
};
block_font_attr* UI_WindowBlocksAttrArray_Main_font[] = {
		&block_font,
};
#endif

#if Drug_C100
/******************************************************************************/
block_attr block_standard = {
		ENABLE,									/* Interface Main rect */
		{
			0,   20,
			128, 160,
			BACKCOLOR_CONTENT_BACK
		},

		ENABLE,									/* Display Picture */
		{
			gImage_PIC_Standard,
			12, 24,
			45, 45
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Standard",
			0,  71,
			White,Magenta,
			Baby_Blue
		},

		ENABLE,									/* Parting line */
		{
			63,  20,
			63,  160,
			Light_Gray
		},
};

/******************************************************************************/
block_attr block_quick = {
		DISABLE,
		{0},

		ENABLE,									/* Display Picture */
		{
			gImage_PIC_Quick,
			71,  24,
			45,  45
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Quick",
			74,  71,
			White,Magenta,
			Baby_Blue
		},

		ENABLE,									/* Parting line */
		{
			64,  20,
			64,  160,
			Thint_Blue
		},
};

/******************************************************************************/
block_attr block_record = {
		DISABLE,
		{0},

		ENABLE,									/* Display Picture */
		{
			gImage_PIC_Record,
			12,  94,
			45, 45
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Record",
			12,  141,
			White,Magenta,
			Baby_Blue
		},

		ENABLE,									/* Parting line */
		{
			0,    90,
			128,  90,
			Light_Gray
		},
};

/******************************************************************************/
block_attr block_settings = {
		DISABLE,
		{0},

		ENABLE,									/* Display Picture */
		{
			gImage_PIC_Setting,
			71, 94,
			45, 45
		},

		ENABLE,									/* Display HZ16X8 */
		{
			"Setting",
			68,  141,
			White,Magenta,
			Baby_Blue
		},

		ENABLE,									/* Parting line */
		{
			0,    91,
			128,  91,
			Thint_Blue
		},
};

/******************************************************************************/
block_attr* UI_WindowBlocksAttrArray_Main[] = {		/* Window: Main entry */
		&block_standard,
		&block_quick,
		&block_record,
		&block_settings,
};

#endif

/******************************************************************************/
void UI_Draw_Block(block_attr* block);
void UI_Draw_Block_font(block_font_attr* block);

/******************************************************************************/
uint8 Interface_Process(uint16* KeyCode)
{
	/* Define each state */
	static uint8 (* const UI_stateMachine[UI_STATE_MAX_STATE_NUM])(uint16) =
	{
			Interface_Main,					/* Interface Main Display */
			Interface_Key_Event,			/* Interface Key Event */
			Interface_Main_font,			/* Interface Main font Display */
			Interface_Start,				/* Interface Start Display */
			Interface_Quick,				/* Interface Quick Display */
			Interface_Record,				/* Interface Record Display */
			Interface_Setting,				/* Interface Setting Display */
			Interface_Testing,				/* Interface Test Display */
			Interface_Quick_font,			/* Interface Quick font Display */
			Interface_Result,				/* Interface Result Display */
			Interface_Result_2,				/* Interface Start Display */
			Interface_Insert_Cup,			/* Interface insert cup Display */
			Interface_Start_font,			/* Interface Start font Display */
			Interface_Record_2				/* Interface Record2 Display */
	};
	uint8 state;
	do										/* Polling each state */
	{
		if (UI_state < UI_STATE_MAX_STATE_NUM)
		{
			state = UI_stateMachine[UI_state](*KeyCode);
		}
		*KeyCode = 0;	/* Clear touch information to avoid repeated respond */
	} while(state & UI_STATE_RERUN);

	return UI_STATE_RERUN;
}

/******************************************************************************/
uint8 Interface_Main(uint16 KeyCode)
{
#if Drug_S100
	Exti_lock = DISABLE;
	Interface_Key = DISABLE;
	key_state_confirm = 0;
	QRCode_Trigger_Disabled();
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Main) >> 2;
	UI_Draw_Window(UI_WindowBlocks);
	UI_state = UI_STATE_MAIN_FONT;
#endif

#if Drug_C100
	QRCode_Trigger_Disabled();
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Main) >> 2;
	UI_Draw_Window(UI_WindowBlocks);
#endif

	return UI_STATE_RERUN;
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
	if (block->rect_enabled)					/* 1. Draw Rect */
	{
		Lcd_ColorBox(block->rect_attr.startX, block->rect_attr.startY,
				block->rect_attr.width, block->rect_attr.height,
				block->rect_attr.color);
	}

	if (block->pic_enabled)						/* 2. Draw picture */
	{
		DisplayDriver_DrawPic(block->pic_attr.offsetX,
				block->pic_attr.offsetY, block->pic_attr.width,
				block->pic_attr.height,block->pic_attr.src);
	}

	if (block->line_enabled)					/* 3.Parting line */
	{
		DisplayDriver_DrawLine(block->Parting_line_attr.startX,
				block->Parting_line_attr.startY,
				block->Parting_line_attr.endX,
				block->Parting_line_attr.endY,
				block->Parting_line_attr.color);
	}

	if (block->char_enabled)					/* 4. Draw character */
	{
			DisplayDriver_Text16_B(
					block->char_attr.offsetX,block->char_attr.offsetY,
					block->char_attr.color,block->char_attr.faceColor,
					block->char_attr.str);
	}
	Display_Time = 1;
}

/******************************************************************************/
uint8 Interface_Key_Event(uint16 KeyCode)
{
#if  Drug_S100
	switch(Interface_Key)
	{
		case 0:
			switch(key_state_confirm)
			{
				case 0:
					UI_state = UI_STATE_MAIN_FONT;
				break;

				case 1:
					UI_state = Key_control + 2;
					key_state_confirm = DISABLE;
					key_state = 1;
					Key_control = 1;
				break;

				default:
				break;
			}
		break;

		case 1:
			switch(key_state_confirm)
			{
				case 1:
					UI_state = UI_STATE_TESTING;
					key_state_confirm = DISABLE;
					Key_control = 1;
				break;
				case 2:
					UI_state = UI_STATE_START_FONT;
					key_state_confirm = DISABLE;
					Key_control = 1;
				break;

				default:
				break;
			}
		break;

		case 2:
			switch(key_state_confirm)
			{
				case 0:
					if(Key_control == 1 && Page_Flag)
					{
						UI_state = UI_STATE_RESULT;
					}
					if(Key_control == 2 && (!Page_Flag))
					{
						UI_state = UI_STATE_RESULT_2;
					}
				break;

				case 1:
					UI_state = UI_STATE_MAIN_WINDOW;
					Interface_Key = DISABLE;
					Key_control = 1;
					key_state = 1;
					key_state_confirm = DISABLE;
				break;

				default:
				break;
			}
		break;

		case 3:
			switch(key_state_confirm)
			{
				case 0:
					if(Key_control == 1)
					{
						UI_state = UI_STATE_MAIN_WINDOW;
						Interface_Key = DISABLE;
						Key_control = 1;
						key_state = 1;
						key_state_confirm = DISABLE;
					}
				break;

				default:
				break;
			}
		break;

		case 4:
			switch(key_state_confirm)
			{
				case 0:
					switch(Key_control)
					{
						case 1:
							if (page_Num == 1 && reagent_Strip[0] == 1)
							{
								reagent_Strip[0] = 1;
							}
							else if (page_Num == 1)
							{
								reagent_Strip[0]--;
								if (reagent_Strip[0] < 1)
									reagent_Strip[0]  = reagent_Strip[1];
							}
							UI_state = UI_STATE_RECORD;

						break;

						case 2:
							if (page_Num == 1 && reagent_Strip[0] >= 100 && page_tatol == 1)
							{
								reagent_Strip[0] = 100;
								UI_state = UI_STATE_RECORD;
							}
							else
							{
								if (page_Num == 1 && page_tatol == 1)
								{
									reagent_Strip[0]++;
									if (reagent_Strip[0] > reagent_Strip[1])
										reagent_Strip[0] = 1;
									UI_state = UI_STATE_RECORD;
								}

								if (page_Num == 1 && page_tatol == 2)
								{
									UI_state = UI_STATE_RECORD2;
								}

								if (page_Num == 2 && page_tatol == 2)
								{
									reagent_Strip[0]++;
									if (reagent_Strip[0] > reagent_Strip[1])
										reagent_Strip[0] = reagent_Strip[1];
									UI_state = UI_STATE_RECORD;
								}
							}
						break;

						default:
						break;
					}

				break;

				case 1:
					UI_state = UI_STATE_MAIN_WINDOW;
					Interface_Key = DISABLE;
					Key_control = 1;
					key_state = 1;
					key_state_confirm = DISABLE;
				break;

				default:
				break;
			}
		break;

		default:
		break;
	}
#endif

#if Drug_C100


#endif
}

#if Drug_S100
/******************************************************************************/
uint8 Interface_Main_font(uint16 KeyCode)
{
	Exti_lock = DISABLE;
	UI_WindowBlocks = 0;
	Read_first = 1;
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Main_font) >> 2;
	UI_Draw_Window_font(UI_WindowBlocks);
	Exti_lock = ENABLE;
	while(!key_state);
	UI_state = UI_STATE_KEY_STATE;
	return UI_STATE_RERUN;
}

/******************************************************************************/
void UI_Draw_Window_font(uint16 blockNum)
{
	uint8 blockIndex = 0;
	if(key_state)								/* Draw blocks one by one */
	{
		for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
		{
			UI_Draw_Block_font(UI_WindowBlocksAttrArray_Main_font[blockIndex]);
		}
	}
}

/******************************************************************************/
void UI_Draw_Block_font(block_font_attr* block)
{
	Display_Time = 0;
	if (block->char1_enabled)				/* 2. Draw character */
	{
		if(Key_control == 1)
		{
			DisplayDriver_Text16_B(
					block->char1_attr.offsetX,block->char1_attr.offsetY,
					block->char1_attr.color,block->char1_attr.backColor,
					block->char1_attr.str);
		}
		else
		{
			DisplayDriver_Text16_B(
					block->char1_attr.offsetX,block->char1_attr.offsetY,
					block->char1_attr.color,block->char1_attr.faceColor,
					block->char1_attr.str);
		}
	}

	if (block->char2_enabled)				/* 2. Draw character */
	{
		if(Key_control == 2)
		{
			DisplayDriver_Text16_B(
					block->char2_attr.offsetX,block->char2_attr.offsetY,
					block->char2_attr.color,block->char2_attr.backColor,
					block->char2_attr.str);
		}
		else
		{
			DisplayDriver_Text16_B(
					block->char2_attr.offsetX,block->char2_attr.offsetY,
					block->char2_attr.color,block->char2_attr.faceColor,
					block->char2_attr.str);
		}
	}

	if (block->char3_enabled)				/* 2. Draw character */
	{
		if(Key_control == 3)
		{
			DisplayDriver_Text16_B(
					block->char3_attr.offsetX,block->char3_attr.offsetY,
					block->char3_attr.color,block->char3_attr.backColor,
					block->char3_attr.str);
		}
		else
		{
			DisplayDriver_Text16_B(
					block->char3_attr.offsetX,block->char3_attr.offsetY,
					block->char3_attr.color,block->char3_attr.faceColor,
					block->char3_attr.str);
		}
	}

	if (block->char4_enabled)				/* 2. Draw character */
	{
		if(Key_control == 4)
		{
			DisplayDriver_Text16_B(
					block->char4_attr.offsetX,block->char4_attr.offsetY,
					block->char4_attr.color,block->char4_attr.backColor,
					block->char4_attr.str);
		}
		else
		{
			DisplayDriver_Text16_B(
					block->char4_attr.offsetX,block->char4_attr.offsetY,
					block->char4_attr.color,block->char4_attr.faceColor,
					block->char4_attr.str);
		}
	}
	Display_Time = 1;
	key_state = DISABLE;
}
#endif

/******************************************************************************/
void UI_Draw_Status_Bar(void)					/* UI Draw Status Bar and Battery */
{
	char tbuf[10] = {0};
	PCF8563_Read(&SystemManage_CurrentTime);
	sprintf((char*)tbuf,"%02d:%02d",SystemManage_CurrentTime.hour,
			SystemManage_CurrentTime.min);
	Display_Time = 0;
	DisplayDriver_Text16_B(12,2,White,BACKCOLOR_CONTENT_BAR,tbuf);
	Display_Time = 1;
}

/******************************************************************************/
void Battery_Empty_ICO(void)
{
#if Drug_S100
	int i = 0;
	Display_Time = 0;
	DisplayDriver_DrawLine(101,5,120,5,White);
	DisplayDriver_DrawLine(101,6,120,6,White);

	DisplayDriver_DrawLine(101,5,101,16,White);
	DisplayDriver_DrawLine(102,5,102,16,White);

	DisplayDriver_DrawLine(101,16,120,16,White);
	DisplayDriver_DrawLine(101,15,120,15,White);

	DisplayDriver_DrawLine(120,16,120,12,White);
	DisplayDriver_DrawLine(121,15,121,12,White);
	DisplayDriver_DrawLine(120,6,120,9,White);
	DisplayDriver_DrawLine(121,6,121,9,White);

	DisplayDriver_DrawLine(122,8,123,8,White);
	DisplayDriver_DrawLine(122,9,123,9,White);
	DisplayDriver_DrawLine(122,10,123,10,White);
	DisplayDriver_DrawLine(122,11,123,11,White);
	DisplayDriver_DrawLine(122,12,123,12,White);
	DisplayDriver_DrawLine(122,13,123,13,White);
	for(i= 104;i<120;)
	{
		Lcd_ColorBox(i,8,3,6,White);
		i += 4;
	}
	Display_Time = 1;
#endif
}
