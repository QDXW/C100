                                                                                                   /*
 * Interface_Start.c
 *
 *  Created on: 2018年2月26日
 *      Author: Administrator
 */

/******************************************************************************/
#include "Interface_Start.h"

/*******************************************************************************
 * Interface_Start
 * 开始界面屏幕显示内容
 * ****************************************************************************/
block_attr_Start block_Start_Name = {
	UI_STATE_MAIN_WINDOW,

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

	DISABLE,								/* Display HZ16X8 */
	{
		"Name:",
		14,   64,
		BLACK,Interface_Back
	},

	DISABLE,								/* Display HZ16X8 */
	{
		QR_Date.head.name,
		60,   64,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_SN = {
	UI_STATE_INSERT_CUP,

	ENABLE,							/* Interface Start rect */
	{
		Confirmation,
		144,  266,
		72,   54
	},

	ENABLE,							/* Interface Start rect */
	{
//		Confirm_China,
		Notarize,
		144,  270,
		72,   54
	},

	DISABLE,								/* Display HZ16X8 */
	{
		"  SN:",
		14,   84,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date.head.SN,
		60 ,   84,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH1 = {
	UI_STATE_DELETE,

	ENABLE,							/* Interface Start rect */
	{
		Delete,
		24,   266,
		72,   54
	},

	ENABLE,							/* Interface Start rect */
	{
//		Delete_China,
		Delete,
		24,   270,
		72,   54
	},

	ENABLE,								/* Display HZ16X8 */
	{
		" 1:",
		14,   103,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[0].TName,
		44,   103,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH2 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		" 2:",
		124,   103,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[1].TName,
		152,   103,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH3 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		" 3:",
		14,   120,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[2].TName,
		44,  120,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH4 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		" 4:",
		124,   120,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[3].TName,
		152,  120,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH5 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		" 5:",
		14,   137,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[4].TName,
		44,  137,
		BLACK,Interface_Back
	},
};
/******************************************************************************/
block_attr_Start block_Start_CH6 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		" 6:",
		124,   137,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[5].TName,
		152,  137,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH7 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		" 7:",
		14,   154,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[6].TName,
		44,  154,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH8 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		" 8:",
		124,   154,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[7].TName,
		152,  154,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH9 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		" 9:",
		14,   171,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[8].TName,
		44,  171,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH10 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"10:",
		124,   171,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[9].TName,
		152,  171,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH11 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"11:",
		14,   188,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[10].TName,
		44,  188,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH12 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"12:",
		124,   188,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[11].TName,
		152,  188,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH13 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"13:",
		14,   205,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[12].TName,
		44,  205,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH14 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"14:",
		124,   205,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[13].TName,
		152,  205,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH15 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"15:",
		14,   222,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[14].TName,
		44,  222,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH16 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"16:",
		124,   222,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[15].TName,
		152,  222,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH17 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"17:",
		14,   238,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[16].TName,
		44,  238,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start* UI_WindowBlocksAttrArray_Start[][19] = {/* Window: Standard entry */
{&block_Start_Name,&block_Start_SN,&block_Start_CH1},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3,
		&block_Start_CH4},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3,
		&block_Start_CH4,&block_Start_CH5},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3,
		&block_Start_CH4,&block_Start_CH5,&block_Start_CH6},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3,
		&block_Start_CH4,&block_Start_CH5,&block_Start_CH6,&block_Start_CH7},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3,
		&block_Start_CH4,&block_Start_CH5,&block_Start_CH6,&block_Start_CH7,
		&block_Start_CH8},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3,
		&block_Start_CH4,&block_Start_CH5,&block_Start_CH6,&block_Start_CH7,
		&block_Start_CH8,&block_Start_CH9},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3,
		&block_Start_CH4,&block_Start_CH5,&block_Start_CH6,&block_Start_CH7,
		&block_Start_CH8,&block_Start_CH9,&block_Start_CH10},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3,
		&block_Start_CH4,&block_Start_CH5,&block_Start_CH6,&block_Start_CH7,
		&block_Start_CH8,&block_Start_CH9,&block_Start_CH10,&block_Start_CH11},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3,
		&block_Start_CH4,&block_Start_CH5,&block_Start_CH6,&block_Start_CH7,
		&block_Start_CH8,&block_Start_CH9,&block_Start_CH10,&block_Start_CH11,&block_Start_CH12},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3,
		&block_Start_CH4,&block_Start_CH5,&block_Start_CH6,&block_Start_CH7,
		&block_Start_CH8,&block_Start_CH9,&block_Start_CH10,&block_Start_CH11,
		&block_Start_CH12,&block_Start_CH13},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3,
		&block_Start_CH4,&block_Start_CH5,&block_Start_CH6,&block_Start_CH7,
		&block_Start_CH8,&block_Start_CH9,&block_Start_CH10,&block_Start_CH11,
		&block_Start_CH12,&block_Start_CH13,&block_Start_CH14},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3,
		&block_Start_CH4,&block_Start_CH5,&block_Start_CH6,&block_Start_CH7,
		&block_Start_CH8,&block_Start_CH9,&block_Start_CH10,&block_Start_CH11,
		&block_Start_CH12,&block_Start_CH13,&block_Start_CH14,&block_Start_CH15},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3,
		&block_Start_CH4,&block_Start_CH5,&block_Start_CH6,&block_Start_CH7,
		&block_Start_CH8,&block_Start_CH9,&block_Start_CH10,&block_Start_CH11,
		&block_Start_CH12,&block_Start_CH13,&block_Start_CH14,&block_Start_CH15,
		&block_Start_CH16},
{&block_Start_Name,&block_Start_SN,&block_Start_CH1,&block_Start_CH2,&block_Start_CH3,
		&block_Start_CH4,&block_Start_CH5,&block_Start_CH6,&block_Start_CH7,
		&block_Start_CH8,&block_Start_CH9,&block_Start_CH10,&block_Start_CH11,
		&block_Start_CH12,&block_Start_CH13,&block_Start_CH14,&block_Start_CH15,
		&block_Start_CH16,&block_Start_CH17},
};

/******************************************************************************/
uint8 Interface_Start(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	QRCode_Trigger_Disabled();
	UI_Background_Plate_Start();
	memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Start[Cup_Count-1]) >> 2;
	memcpy(UI_WindowBlocksAttrArray, UI_WindowBlocksAttrArray_Start[Cup_Count-1],12);
	UI_Draw_Window_Start(UI_WindowBlocks);
	UI_Language_Plate_Start();
	UI_WindowBlocks = 3;
	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	return state;
}

/******************************************************************************/
void UI_Draw_block_Start(block_attr_Start* block);

/******************************************************************************/
void UI_Draw_Window_Start(uint16 blockNum)
{
	uint8 blockIndex = 0;					/* Draw blocks one by one */
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		if(UI_WindowBlocksAttrArray_Start[Cup_Count-1][blockIndex])
		{
			UI_Draw_block_Start(UI_WindowBlocksAttrArray_Start[Cup_Count-1][blockIndex]);
		}
	}
}

/******************************************************************************/
void UI_Draw_block_Start(block_attr_Start* block)
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

	case DISPLAY_FONT_GERMAN:
		if (block->pic1_enabled)						/* 2. Draw picture */
		{
			DisplayDriver_DrawPic_Touch(block->pic1_attr.src,Interface_Back,
					block->pic1_attr.offsetX,block->pic1_attr.offsetY);
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
		DisplayDriver_Text_Flex(
				16,
				block->char_attr.offsetX,block->char_attr.offsetY,
				block->char_attr.color,block->char_attr.backColor,
				block->char_attr.str);
	}

	if (block->char1_enabled)					/* 4. Draw character */
	{
		DisplayDriver_Text_Flex(
				16,
				block->char1_attr.offsetX,block->char1_attr.offsetY,
				block->char1_attr.color,block->char1_attr.backColor,
				block->char1_attr.str);
	}
	Display_Time = 1;
}

uint8 Interface_Delete(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Clear_Data();
	UI_state = UI_STATE_QUICK;
	return state;
}

/******************************************************************************/
void UI_Background_Plate_Start (void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(10,62,229,256,WHITE);
	DisplayDriver_DrawStraight_Line(0,82,229,82,Interface_Back);
	DisplayDriver_DrawStraight_Line(0,102,229,102,Interface_Back);
	DisplayDriver_DrawStraight_Line(120,102,120,256,Interface_Back);
	Display_Time = 1;
}
