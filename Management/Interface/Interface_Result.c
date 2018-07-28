/*
 * Interface_Result.c
 *
 *  Created on: 2018Äê2ÔÂ26ÈÕ
 *      Author: Administrator
 */

/******************************************************************************/
#include "Interface_Result.h"
#include "Save.pic"

/******************************************************************************/
block_attr_Result block_Result_Return = {
	UI_STATE_MAIN_WINDOW,

	ENABLE,									/* Display Picture */
	{
		UI_Return,
		0,   22,
		50,  45,
		0
	},
	ENABLE,								/*Display HZ16X8*/
	{
		"Item",
		14,   82,
		BLACK,WHITE,
	},

	ENABLE,									/*Display HZ16X8*/
	{
		"Result",
		65,   82,
		BLACK,WHITE,
	},
};

/******************************************************************************/
block_attr_Result block_Result_Result = {
	UI_STATE_RESULT_TOUCH_PROCESS,

	ENABLE,									/* Display Picture */
	{
		Print,
		98, 22,
		45, 40,
		1
	},

	ENABLE,								/*Display HZ16X8*/
	{
		"Item",
		124,   82,
		BLACK,WHITE,
	},

	ENABLE,									/*Display HZ16X8*/
	{
		"Result",
		178,   82,
		BLACK,WHITE,
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH1 = {
	UI_STATE_RESULT_TOUCH_PROCESS,

	ENABLE,							/* Interface Result rect */
	{
		Save,
		195, 22,
		45,  45,
		2
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[0].TName,
		14,   103,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[0].Result,
		74,   103,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH2 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[1].TName,
		124,   103,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[1].Result,
		184,   103,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH3 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[2].TName,
		14,   121,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[2].Result,
		74,  121,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH4 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[3].TName,
		124,   121,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[3].Result,
		184,  121,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH5 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[4].TName,
		14,   139,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[4].Result,
		74,  139,
		BLACK,Interface_Back
	},
};
/******************************************************************************/
block_attr_Result block_Result_CH6 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[5].TName,
		124,   139,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[5].Result,
		184,  139,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH7 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[6].TName,
		14,   157,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[6].Result,
		74,  157,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH8 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[7].TName,
		124,   157,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[7].Result,
		184,  157,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH9 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[8].TName,
		14,   174,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[8].Result,
		74,  174,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH10 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[9].TName,
		124,   174,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[9].Result,
		184,  174,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH11 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[10].TName,
		14,   193,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[10].Result,
		74,  193,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH12 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[11].TName,
		124,   193,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[11].Result,
		184,  193,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH13 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[12].TName,
		14,   211,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[12].Result,
		74,  211,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH14 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[13].TName,
		124,   211,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[13].Result,
		184,  211,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH15 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[14].TName,
		14,   229,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[14].Result,
		74,  229,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH16 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[15].TName,
		124,   229,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[15].Result,
		184,  229,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result block_Result_CH17 = {
	DISABLE,

	DISABLE,							/* Interface Result rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[16].TName,
		14,   247,
		BLACK,Interface_Back
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[16].Result,
		74,  247,
		BLACK,Interface_Back
	},
};

/******************************************************************************/
block_attr_Result* UI_WindowBlocksAttrArray_Result[][20] = {/* Window: Result entry */
{&block_Result_Return,&block_Result_Result,&block_Result_CH1},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3,&block_Result_CH4},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3,&block_Result_CH4,&block_Result_CH5},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3,&block_Result_CH4,&block_Result_CH5,&block_Result_CH6},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3,&block_Result_CH4,&block_Result_CH5,&block_Result_CH6,
		&block_Result_CH7},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3,&block_Result_CH4,&block_Result_CH5,&block_Result_CH6,
		&block_Result_CH7,&block_Result_CH8},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3,&block_Result_CH4,&block_Result_CH5,&block_Result_CH6,
		&block_Result_CH7,&block_Result_CH8,&block_Result_CH9},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3,&block_Result_CH4,&block_Result_CH5,&block_Result_CH6,
		&block_Result_CH7,&block_Result_CH8,&block_Result_CH9,&block_Result_CH10},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3,&block_Result_CH4,&block_Result_CH5,&block_Result_CH6,
		&block_Result_CH7,&block_Result_CH8,&block_Result_CH9,&block_Result_CH10,
		&block_Result_CH11},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3,&block_Result_CH4,&block_Result_CH5,&block_Result_CH6,
		&block_Result_CH7,&block_Result_CH8,&block_Result_CH9,&block_Result_CH10,
		&block_Result_CH11,&block_Result_CH12},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3,&block_Result_CH4,&block_Result_CH5,&block_Result_CH6,
		&block_Result_CH7,&block_Result_CH8,&block_Result_CH9,&block_Result_CH10,
		&block_Result_CH11,&block_Result_CH12,&block_Result_CH13},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3,&block_Result_CH4,&block_Result_CH5,&block_Result_CH6,
		&block_Result_CH7,&block_Result_CH8,&block_Result_CH9,&block_Result_CH10,
		&block_Result_CH11,&block_Result_CH12,&block_Result_CH13,&block_Result_CH14},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3,&block_Result_CH4,&block_Result_CH5,&block_Result_CH6,
		&block_Result_CH7,&block_Result_CH8,&block_Result_CH9,&block_Result_CH10,
		&block_Result_CH11,&block_Result_CH12,&block_Result_CH13,&block_Result_CH14
		,&block_Result_CH15},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3,&block_Result_CH4,&block_Result_CH5,&block_Result_CH6,
		&block_Result_CH7,&block_Result_CH8,&block_Result_CH9,&block_Result_CH10,
		&block_Result_CH11,&block_Result_CH12,&block_Result_CH13,&block_Result_CH14
		,&block_Result_CH15,&block_Result_CH16},
{&block_Result_Return,&block_Result_Result,&block_Result_CH1,&block_Result_CH2,
		&block_Result_CH3,&block_Result_CH4,&block_Result_CH5,&block_Result_CH6,
		&block_Result_CH7,&block_Result_CH8,&block_Result_CH9,&block_Result_CH10,
		&block_Result_CH11,&block_Result_CH12,&block_Result_CH13,&block_Result_CH14
		,&block_Result_CH15,&block_Result_CH16,&block_Result_CH17},
};

/******************************************************************************/
uint8 Interface_Result(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Exti_lock = ENABLE;
	BLE_Remind = 1;
	UI_Background_Plate_Result();
	memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Result[Storage_Data.StripNum-1]) >> 2;
	memcpy(UI_WindowBlocksAttrArray, UI_WindowBlocksAttrArray_Result[Storage_Data.StripNum-1],
			sizeof(UI_WindowBlocksAttrArray_Result[Storage_Data.StripNum-1]));
	UI_Draw_Window_Result(UI_WindowBlocks);
	UI_WindowBlocks = 4;
	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	return state;
}

/******************************************************************************/
void UI_Draw_block_Result(block_attr_Result* block);

/******************************************************************************/
void UI_Draw_Window_Result(uint16 blockNum)
{
	uint8 blockIndex = 0;					/* Draw blocks one by one */
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		if(UI_WindowBlocksAttrArray_Result[Storage_Data.StripNum-1][blockIndex])
		{
			UI_Draw_block_Result(UI_WindowBlocksAttrArray_Result[Storage_Data.StripNum-1][blockIndex]);
		}
	}
}

/******************************************************************************/
void UI_Draw_block_Result(block_attr_Result* block)
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

	if (block->char2_enabled)					/* 4. Draw character */
	{
		DisplayDriver_Text16_Touch(
				block->char2_attr.offsetX,block->char2_attr.offsetY,
				block->char2_attr.color,block->char2_attr.backColor,
				block->char2_attr.str);
	}
	Display_Time = 1;
}

/******************************************************************************/
void UI_Background_Plate_Result (void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(10,70,229,270,WHITE);
	DisplayDriver_DrawStraight_Line(119,70,119,290,Interface_Back);
	DisplayDriver_DrawStraight_Line(10,100,229,100,Interface_Back);
	Display_Time = 1;
}

/******************************************************************************/
uint8 Interface_Result_Touch_Process(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	if(1 == Pic_Count )
	{
		if (Printer_isConnected())
		{
			UI_Process_BLE_Print();
		}
	}

	if(2 == Pic_Count)
	{
		if(Stored_Record)
		{
			Storage_Record();
			Display_Time = 0;
			DisplayDriver_Text16_Touch(56, 275, WHITE,WHITE,"Has been stored!");
			Display_Time = 0;
			Stored_Record = 0;
		}
	}

	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	return state;
}

