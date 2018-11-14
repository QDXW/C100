/*
 * Interface_System_Time.c
 *
 *  Created on: 2018Äê6ÔÂ19ÈÕ
 *      Author: Administrator
 */

/******************************************************************************/
#include "Interface_System_Time.h"
#include "Add.pic"
#include "minus.pic"

/******************************************************************************/
SET_DATA start_data = {0,2018,7,9,16,47,30};

/******************************************************************************/
block_attr_SetTime block_SetTime_return = {
	UI_STATE_SETTING,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		UI_Return,
		0,   22,
		50,  45,
		0
	},

	ENABLE,							/* Display HZ16X8 */
	{
		UI_Return,
		0,   22,
		50,  45,
		0
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_SetTime block_SetTime_Y1 = {
	UI_STATE_SET_TIME_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Add,
		45,   62,
		40,  40,
		1
	},

	ENABLE,							/* Display HZ16X8 */
	{
		Add,
		45,   62,
		40,  40,
		1
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_SetTime block_SetTime_Y2 = {
	UI_STATE_SET_TIME_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		minus,
		45,   123,
		40,  40,
		2
	},

	ENABLE,							/* Display HZ16X8 */
	{
		minus,
		45,   123,
		40,  40,
		2
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_SetTime block_SetTime_M1 = {
	UI_STATE_SET_TIME_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Add,
		107,   62,
		40,  40,
		3
	},

	ENABLE,							/* Display HZ16X8 */
	{
		Add,
		107,   62,
		40,  40,
		3
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_SetTime block_SetTime_M2 = {
	UI_STATE_SET_TIME_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		minus,
		107,   123,
		40,  40,
		4
	},

	ENABLE,							/* Display HZ16X8 */
	{
		minus,
		107,   123,
		40,  40,
		4
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_SetTime block_SetTime_D1 = {
	UI_STATE_SET_TIME_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Add,
		163,   62,
		40,  40,
		5
	},

	ENABLE,							/* Display HZ16X8 */
	{
		Add,
		163,   62,
		40,  40,
		5
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_SetTime block_SetTime_D2 = {
	UI_STATE_SET_TIME_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		minus,
		163,   123,
		40,  40,
		6
	},

	ENABLE,							/* Display HZ16X8 */
	{
		minus,
		163,   123,
		40,  40,
		6
	},

	DISABLE,
	{0},
};
/******************************************************************************/
block_attr_SetTime block_SetTime_H1 = {
	UI_STATE_SET_TIME_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Add,
		45,   164,
		40,  40,
		7
	},

	ENABLE,							/* Display HZ16X8 */
	{
		Add,
		45,   164,
		40,  40,
		7
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_SetTime block_SetTime_H2 = {
	UI_STATE_SET_TIME_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		minus,
		45,   225,
		40,  40,
		8
	},

	ENABLE,							/* Display HZ16X8 */
	{
		minus,
		45,   225,
		40,  40,
		8
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_SetTime block_SetTime_F1 = {
	UI_STATE_SET_TIME_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Add,
		107,   164,
		40,  40,
		9
	},

	ENABLE,							/* Display HZ16X8 */
	{
		Add,
		107,   164,
		40,  40,
		9
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_SetTime block_SetTime_F2 = {
	UI_STATE_SET_TIME_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		minus,
		107,   225,
		40,  40,
		10
	},

	ENABLE,							/* Display HZ16X8 */
	{
		minus,
		107,   225,
		40,  40,
		10
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_SetTime block_SetTime_S1 = {
	UI_STATE_SET_TIME_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Add,
		163,   164,
		40,  40,
		11
	},

	ENABLE,							/* Display HZ16X8 */
	{
		Add,
		163,   164,
		40,  40,
		11
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_SetTime block_SetTime_S2 = {
	UI_STATE_SET_TIME_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		minus,
		163,   225,
		40,  40,
		12
	},

	ENABLE,							/* Display HZ16X8 */
	{
		minus,
		163,   225,
		40,  40,
		12
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_SetTime block_SetTime_Confirm = {
	UI_STATE_SET_TIME_PROCESS,								/* Interface Quick rect */

	ENABLE,									/* Display Picture */
	{
		Confirmation,
		84,   272,
		72,   30,
		13
	},

	ENABLE,									/* Display Picture */
	{
		Confirm_China,
		84,   272,
		72,   30,
		13
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_SetTime* UI_WindowBlocksAttrArray_SetTime[] = {/* Window: Standard entry */
		&block_SetTime_return,
		&block_SetTime_Y1,
		&block_SetTime_Y2,
		&block_SetTime_M1,
		&block_SetTime_M2,
		&block_SetTime_D1,
		&block_SetTime_D2,
		&block_SetTime_H1,
		&block_SetTime_H2,
		&block_SetTime_F1,
		&block_SetTime_F2,
		&block_SetTime_S1,
		&block_SetTime_S2,
		&block_SetTime_Confirm,
};

/******************************************************************************/
void UI_Draw_Block_SetTime(block_attr_SetTime* block);

/******************************************************************************/
uint8 Interface_System_Time(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Interface_Reord = 3;
	UI_Background_Plate_SetTime();
	memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_SetTime) >> 2;
	memcpy(UI_WindowBlocksAttrArray, UI_WindowBlocksAttrArray_SetTime,sizeof(UI_WindowBlocksAttrArray_SetTime));
	UI_Draw_Window_System_Time(UI_WindowBlocks);
	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	return state;
}

/******************************************************************************/
void UI_Draw_Window_System_Time(uint16 blockNum)
{
	uint8 blockIndex = 0;					/* Draw blocks one by one */
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		UI_Draw_Block_SetTime(UI_WindowBlocksAttrArray_SetTime[blockIndex]);
	}
}

/******************************************************************************/
void UI_Draw_Block_SetTime(block_attr_SetTime* block)
{
	Display_Time = 0;
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		if (block->pic_enabled)						/* 2. Draw picture */
		{
			DisplayDriver_DrawPic_Touch(block->pic_attr.src,Interface_Back,
					block->pic_attr.offsetX,block->pic_attr.offsetY);
		}
		break;

	case DISPLAY_FONT_CHINESE:
		if (block->pic1_enabled)						/* 2. Draw picture */
		{
			DisplayDriver_DrawPic_Touch(block->pic1_attr.src,Interface_Back,
					block->pic1_attr.offsetX,block->pic1_attr.offsetY);
		}
		break;

	default:
		break;
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
void UI_Background_Plate_SetTime(void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(39,102,201,122,WHITE);
	DisplayDriver_Fill(39,204,201,224,WHITE);

	sprintf(Year,"%02d",start_data.year);
	DisplayDriver_Text16_Back(49,104,BLACK,WHITE,Year);
	DisplayDriver_DrawStraight_Line(92,112,108,112,BLACK);

	sprintf(Month,"%02d",start_data.month);
	DisplayDriver_Text16_Back(120,104,BLACK,WHITE,Month);
	DisplayDriver_DrawStraight_Line(149,112,165,112,BLACK);

	sprintf(Day,"%02d",start_data.day);
	DisplayDriver_Text16_Back(175,104,BLACK,WHITE,Day);

	sprintf(Hour,"%02d",start_data.hour);
	DisplayDriver_Text16_Back(58,206,BLACK,WHITE,Hour);
	DisplayDriver_Text16_Back(96,206,BLACK,WHITE,":");

	sprintf(Minute,"%02d",start_data.min);
	DisplayDriver_Text16_Back(120,206,BLACK,WHITE,Minute);
	DisplayDriver_Text16_Back(153,206,BLACK,WHITE,":");

	sprintf(Sec,"%02d",start_data.sec);
	DisplayDriver_Text16_Back(175,206,BLACK,WHITE,Sec);

	Display_Time = 1;
}

/******************************************************************************/
uint8 Interface_Set_Time_Process (uint16* xpos,uint16* ypos)
{
	switch(Pic_Count)
	{
	case 1:
		start_data.year += 1;
		if(start_data.year > 2118)
		{
			start_data.year = 2118;
		}
		sprintf(Year,"%d",start_data.year);
		DisplayDriver_Text16_Back(49,104,BLACK,WHITE,Year);
		break;
	case 2:
		start_data.year -= 1;
		if(start_data.year < 1918)
		{
			start_data.year = 1918;
		}
		sprintf(Year,"%02d",start_data.year);
		DisplayDriver_Text16_Back(49,104,BLACK,WHITE,Year);
		break;
	case 3:
		start_data.month += 1;
		if(start_data.month > 12)
		{
			start_data.month = 1;
		}
		sprintf(Month,"%02d",start_data.month);
		DisplayDriver_Text16_Back(120,104,BLACK,WHITE,Month);
		break;
	case 4:
		start_data.month -= 1;
		if(start_data.month < 1)
		{
			start_data.month = 1;
		}
		sprintf(Month,"%02d",start_data.month);
		DisplayDriver_Text16_Back(120,104,BLACK,WHITE,Month);
		break;
	case 5:
		start_data.day += 1;
		if(start_data.day > 31)
		{
			start_data.day = 1;
		}
		sprintf(Day,"%02d",start_data.day);
		DisplayDriver_Text16_Back(175,104,BLACK,WHITE,Day);
		break;
	case 6:
		start_data.day -= 1;
		if(start_data.day < 1)
		{
			start_data.day = 31;
		}
		sprintf(Day,"%02d",start_data.day);
		DisplayDriver_Text16_Back(175,104,BLACK,WHITE,Day);
		break;
	case 7:
		start_data.hour += 1;
		if(start_data.hour > 23)
		{
			start_data.hour = 0;
		}
		sprintf(Hour,"%02d",start_data.hour);
		DisplayDriver_Text16_Back(58,206,BLACK,WHITE,Hour);
		break;
	case 8:
		start_data.hour -= 1;
		if(start_data.hour > 23)
		{
			start_data.hour = 23;
		}
		sprintf(Hour,"%02d",start_data.hour);
		DisplayDriver_Text16_Back(58,206,BLACK,WHITE,Hour);
		break;
	case 9:
		start_data.min += 1;
		if(start_data.min > 59)
		{
			start_data.min = 0;
		}
		sprintf(Minute,"%02d",start_data.min);
		DisplayDriver_Text16_Back(120,206,BLACK,WHITE,Minute);
		break;
	case 10:
		start_data.min -= 1;
		if(start_data.min > 59)
		{
			start_data.min = 59;
		}
		sprintf(Minute,"%02d",start_data.min);
		DisplayDriver_Text16_Back(120,206,BLACK,WHITE,Minute);
		break;
	case 11:
		start_data.sec += 1;
		if(start_data.sec > 59)
		{
			start_data.sec = 0;
		}
		sprintf(Sec,"%02d",start_data.sec);
		DisplayDriver_Text16_Back(175,206,BLACK,WHITE,Sec);
		break;
	case 12:
		start_data.sec -= 1;
		if(start_data.sec > 59)
		{
			start_data.sec = 59;
		}
		sprintf(Sec,"%02d",start_data.sec);
		DisplayDriver_Text16_Back(175,206,BLACK,WHITE,Sec);
		break;
	case 13:
		SystemManage_RTC_Set(start_data.year, start_data.month,start_data.day,start_data.hour,
						start_data.min,start_data.sec);
		UI_Draw_Status_Bar();
		break;
	default:
		break;
	}
	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
}
