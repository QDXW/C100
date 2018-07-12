/*
 * Interface_Record.c
 *
 *  Created on: 2018年2月24日
 *      Author: Administrator
 ******************************************************************************/
#include "Interface_Record.h"
#include "left.pic"
#include "Right.pic"

/******************************************************************************/
uint8 cBuffer[20] = {0};
uint8 kBuffer[10] = {0};

/******************************************************************************/
block_attr_Record block_Record_UI_Return = {
	UI_STATE_MAIN_WINDOW,

	ENABLE,							/* Display HZ16X8 */
	{
		UI_Return,
		0,   22,
		50,  45
	},

	ENABLE,								/* Display HZ16X8 */
	{
		"No Record!",
		80, 173,
		RED,WHITE,
	},

	DISABLE,								/* Display HZ16X8 */
	{0},
};

/******************************************************************************/
block_attr_Record block_Record_Name = {
	UI_STATE_MAIN_WINDOW,

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
		108,   44,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.Product_name,
		132,   42,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_SN = {
	UI_STATE_RECORD_DEMAND_PROCESS,
	ENABLE,							/* Interface Record rect */
	{
		left,
		10,  269,
		60,  51,
		1
	},

	ENABLE,								/* Display HZ16X8 */
	{
		"Time:",
		12,   64,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		cBuffer,
		60,   64,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_Time = {
	UI_STATE_RECORD_DEMAND_PROCESS,

	ENABLE,							/* Interface Record rect */
	{
		Right,
		170, 269,
		60,  51,
		2
	},

	ENABLE,								/* Display HZ16X8 */
	{
		"SN:",
		12,   84,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.Product_SN,
		38 ,   84,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH1 = {
	UI_STATE_RECORD_DEMAND_PROCESS,

	ENABLE,									/* Display Picture */
	{
		Print,
		98, 272,
		45, 51,
		3
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[0].TName,
		12,   123,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[0].Result,
		72,   123,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH2 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[1].TName,
		122,   123,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[1].Result,
		182,   123,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH3 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[2].TName,
		12,   139,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[2].Result,
		72,  139,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH4 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[3].TName,
		122,   139,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[3].Result,
		182,  139,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH5 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[4].TName,
		12,   155,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[4].Result,
		72,  155,
		BLACK,WHITE
	},
};
/******************************************************************************/
block_attr_Record block_Record_CH6 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[5].TName,
		122,   155,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[5].Result,
		182,  155,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH7 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[6].TName,
		12,   171,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[6].Result,
		72,  171,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH8 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[7].TName,
		122,   171,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[7].Result,
		182,  171,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH9 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[8].TName,
		12,   187,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[8].Result,
		72,  187,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH10 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[9].TName,
		122,   187,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[9].Result,
		182,  187,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH11 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[10].TName,
		12,   203,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[10].Result,
		72,  203,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH12 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[11].TName,
		122,   203,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[11].Result,
		182,  203,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH13 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"AXG",
		12,   219,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		"Neg--",
		72,  219,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH14 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"AXG",
		122,   219,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		"Neg--",
		182,  219,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH15 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"AXG",
		12,   235,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		"Neg--",
		72,  235,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH16 = {
	DISABLE,

	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"AXG",
		122,   235,
		BLACK,WHITE
	},

	ENABLE,								/* Display HZ16X8 */
	{
		"Neg--",
		182,  235,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Record* UI_WindowBlocksAttrArray_Record_UI_Return[] = {/* Window: Standard entry */
		&block_Record_UI_Return,
};

/******************************************************************************/
block_attr_Record* UI_WindowBlocksAttrArray_Record[][19] = {/* Window: Standard entry */
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2,&block_Record_CH3},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2,&block_Record_CH3,&block_Record_CH4},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2,&block_Record_CH3,&block_Record_CH4,&block_Record_CH5},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2,&block_Record_CH3,&block_Record_CH4,&block_Record_CH5,
		&block_Record_CH6},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2,&block_Record_CH3,&block_Record_CH4,&block_Record_CH5,
		&block_Record_CH6,&block_Record_CH7},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2,&block_Record_CH3,&block_Record_CH4,&block_Record_CH5,
		&block_Record_CH6,&block_Record_CH7,&block_Record_CH8},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2,&block_Record_CH3,&block_Record_CH4,&block_Record_CH5,
		&block_Record_CH6,&block_Record_CH7,&block_Record_CH8,&block_Record_CH9},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2,&block_Record_CH3,&block_Record_CH4,&block_Record_CH5,
		&block_Record_CH6,&block_Record_CH7,&block_Record_CH8,&block_Record_CH9,
		&block_Record_CH10},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2,&block_Record_CH3,&block_Record_CH4,&block_Record_CH5,
		&block_Record_CH6,&block_Record_CH7,&block_Record_CH8,&block_Record_CH9,
		&block_Record_CH10,&block_Record_CH11},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2,&block_Record_CH3,&block_Record_CH4,&block_Record_CH5,
		&block_Record_CH6,&block_Record_CH7,&block_Record_CH8,&block_Record_CH9,
		&block_Record_CH10,&block_Record_CH11,&block_Record_CH12},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2,&block_Record_CH3,&block_Record_CH4,&block_Record_CH5,
		&block_Record_CH6,&block_Record_CH7,&block_Record_CH8,&block_Record_CH9,
		&block_Record_CH10,&block_Record_CH11,&block_Record_CH12,&block_Record_CH13},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2,&block_Record_CH3,&block_Record_CH4,&block_Record_CH5,
		&block_Record_CH6,&block_Record_CH7,&block_Record_CH8,&block_Record_CH9,
		&block_Record_CH10,&block_Record_CH11,&block_Record_CH12,&block_Record_CH13,
		&block_Record_CH14},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2,&block_Record_CH3,&block_Record_CH4,&block_Record_CH5,
		&block_Record_CH6,&block_Record_CH7,&block_Record_CH8,&block_Record_CH9,
		&block_Record_CH10,&block_Record_CH11,&block_Record_CH12,&block_Record_CH13,
		&block_Record_CH14,&block_Record_CH15},
{&block_Record_Name,&block_Record_SN,&block_Record_Time,&block_Record_CH1,
		&block_Record_CH2,&block_Record_CH3,&block_Record_CH4,&block_Record_CH5,
		&block_Record_CH6,&block_Record_CH7,&block_Record_CH8,&block_Record_CH9,
		&block_Record_CH10,&block_Record_CH11,&block_Record_CH12,&block_Record_CH13,
		&block_Record_CH14,&block_Record_CH15,&block_Record_CH16},
};

/******************************************************************************/
void UI_Draw_Block_Record(block_attr_Record* block);

/******************************************************************************/
uint8 Interface_Record(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Enter_Sleep = 1;
	Interface_Reord = 2;

	/* 读取flash信息  */
	Read_Record();

	/* 判断是否为空  */
	Data_Changer();

	if((reagent_Strip[0]) == 0)
	{
		UI_Background_Plate_Record_NO ();
		memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
		UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Record_UI_Return) >> 2;
		memcpy(UI_WindowBlocksAttrArray,UI_WindowBlocksAttrArray_Record_UI_Return,
				sizeof(UI_WindowBlocksAttrArray_Record_UI_Return));
		UI_Draw_Window_Record(UI_WindowBlocks);
	}
	else
	{
		/* 不为空显示内容  */
		if(Record_Display)
		{
			UI_Background_Plate_Record();
			Record_Display = 0;
		}

		Display_Time = 0;
		DisplayDriver_Fill(11,123,119,249,WHITE);
		DisplayDriver_Fill(121,123,228,249,WHITE);
		sprintf(kBuffer,"%02d",reagent_Strip[0]);
		DisplayDriver_Text16_Back(113, 255, BLACK,Interface_Back,kBuffer);
		Display_Time = 1;

		memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
		UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Record[Storage_Data.StripNum-1]) >> 2;
		memcpy(UI_WindowBlocksAttrArray,UI_WindowBlocksAttrArray_Record[0],
				sizeof(UI_WindowBlocksAttrArray_Record[0]));
		UI_Draw_Window_Record(UI_WindowBlocks);
	}

	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	return state;
}

/******************************************************************************/
void UI_Draw_Window_Record(uint16 blockNum)
{
	uint8 blockIndex = 0;					/* Draw blocks one by one */

	if(!(reagent_Strip[0]))
	{
		for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
		{
			UI_Draw_Block_Record(UI_WindowBlocksAttrArray_Record_UI_Return[blockIndex]);
		}
	}
	else
	{
		for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
		{
			if(UI_WindowBlocksAttrArray_Record[Storage_Data.StripNum-1][blockIndex])
			{
				UI_Draw_Block_Record(UI_WindowBlocksAttrArray_Record[Storage_Data.StripNum-1][blockIndex]);
			}
		}
	}
}

/******************************************************************************/
void UI_Draw_Block_Record(block_attr_Record* block)
{
	Display_Time = 0;
	if (block->pic_enabled)						/* 2. Draw picture */
	{
		DisplayDriver_DrawPic_Touch(block->pic_attr.src,Interface_Back,
				block->pic_attr.offsetX,block->pic_attr.offsetY);
	}

	if (block->char_enabled)					/* 4. Draw character */
	{
		DisplayDriver_Text16_Back(
				block->char_attr.offsetX,block->char_attr.offsetY,
				block->char_attr.color,block->char_attr.backColor,
				block->char_attr.str);
	}

	if (block->char1_enabled)					/* 4. Draw character */
	{
		DisplayDriver_Text16_Back(
				block->char1_attr.offsetX,block->char1_attr.offsetY,
				block->char1_attr.color,block->char1_attr.backColor,
				block->char1_attr.str);
	}
	Display_Time = 1;
}

/******************************************************************************/
void Data_Changer(void)
{
	memset(cBuffer,0,sizeof(cBuffer));
	sprintf(cBuffer,"%d/%02d/%02d %02d:%02d",Storage_Data.Product_Time.year,
			Storage_Data.Product_Time.month,Storage_Data.Product_Time.day,
			Storage_Data.Product_Time.hour,Storage_Data.Product_Time.min);
}

/******************************************************************************/
void UI_Background_Plate_Record_NO (void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(11,82,230,265,WHITE);
	sprintf(kBuffer,"%02d",reagent_Strip[0]);
	DisplayDriver_Text16_Back(113, 255, BLACK,Interface_Back,kBuffer);
	Display_Time = 1;
}

/******************************************************************************/
void UI_Background_Plate_Record (void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(10,62,229,250,WHITE);
	DisplayDriver_DrawCircle_Solid(100,50,10,WHITE);
	DisplayDriver_Fill(100,40,229,60,WHITE);
	DisplayDriver_DrawStraight_Line(0,82,240,82,Interface_Back);
	DisplayDriver_DrawStraight_Line(0,102,240,102,Interface_Back);
	DisplayDriver_DrawStraight_Line(0,122,240,122,Interface_Back);
	DisplayDriver_DrawStraight_Line(120,102,120,250,Interface_Back);
	DisplayDriver_Text16_Touch(12, 104, BLACK,WHITE,"Item");
	DisplayDriver_Text16_Touch(62, 104, BLACK,WHITE,"Result");
	DisplayDriver_Text16_Touch(122, 104, BLACK,WHITE,"Item");
	DisplayDriver_Text16_Touch(172, 104, BLACK,WHITE,"Result");
	Display_Time = 1;
}

/******************************************************************************/
uint8 Interface_Record_Demand_Process(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	if(Pic_Count == 1)
	{
		reagent_Strip[0]--;
		if(reagent_Strip[0] <= 1)
		{
			reagent_Strip[0] = 1;
		}
		UI_state = UI_STATE_RECORD;
	}

	if(Pic_Count == 2)
	{
		if(reagent_Strip[2] == 1)
		{
			reagent_Strip[0]++;
			if(reagent_Strip[0] > 500)
			{
				reagent_Strip[0] = 500;
			}
		}
		else
		{
			reagent_Strip[0]++;
			if(reagent_Strip[0] >= reagent_Strip[1])
			{
				reagent_Strip[0] = reagent_Strip[1];
			}
		}
		UI_state = UI_STATE_RECORD;
	}

	if(Pic_Count == 3)
	{
		UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	}

	return state;
}
