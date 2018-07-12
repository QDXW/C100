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

	ENABLE,								/* Display HZ16X8 */
	{
		"Name:",
		12,   64,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date.head.name,
		54,   64,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_SN = {
	UI_STATE_INSERT_CUP,

	ENABLE,							/* Interface Start rect */
	{
		Confirmation,
		144,  258,
		72,   62
	},

	ENABLE,								/* Display HZ16X8 */
	{
		"SN:",
		12,   84,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date.head.SN,
		38 ,   84,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH1 = {
	UI_STATE_DELETE,

	ENABLE,							/* Interface Start rect */
	{
		Delete,
		24,   258,
		72,   62
	},

	ENABLE,								/* Display HZ16X8 */
	{
		"1:",
		12,   103,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[0].TName,
		32,   103,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH2 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"2:",
		122,   103,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[1].TName,
		142,   103,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH3 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"3:",
		12,   120,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[2].TName,
		32,  120,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH4 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"4:",
		122,   120,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[3].TName,
		142,  120,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH5 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"5:",
		12,   137,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[4].TName,
		32,  137,
		BLACK,Interface_Back
	},
};
/******************************************************************************/
block_attr_Start block_Start_CH6 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"6:",
		122,   137,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[5].TName,
		142,  137,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH7 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"7:",
		12,   154,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[6].TName,
		32,  154,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH8 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"8:",
		122,   154,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[7].TName,
		142,  154,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH9 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"9:",
		12,   171,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[8].TName,
		32,  171,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH10 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"10:",
		122,   171,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[9].TName,
		150,  171,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH11 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"11:",
		12,   188,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[10].TName,
		40,  188,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH12 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"12:",
		122,   188,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[11].TName,
		150,  188,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH13 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"13:",
		12,   205,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[12].TName,
		40,  205,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH14 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"14:",
		122,   205,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[13].TName,
		150,  205,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH15 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"15:",
		12,   222,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[14].TName,
		40,  222,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start block_Start_CH16 = {
	DISABLE,

	DISABLE,							/* Interface Start rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"16:",
		122,   222,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		QR_Date_Analyze.ch_data[15].TName,
		150,  222,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Start* UI_WindowBlocksAttrArray_Start[][18] = {/* Window: Standard entry */
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

	if (block->char1_enabled)					/* 4. Draw character */
	{
		DisplayDriver_Text16_Touch(
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
