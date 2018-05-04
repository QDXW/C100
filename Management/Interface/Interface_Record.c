/*
 * Interface_Record.c
 *
 *  Created on: 2018Äê2ÔÂ24ÈÕ
 *      Author: Administrator
 ******************************************************************************/
#include "Storage_Flash.h"
#include "Interface_Record.h"

/******************************************************************************/
uint8 cBuffer[20] = {0};
uint8 tBuffer[10] = {0};
uint8 page_tatol = 1;
uint8 page_Num = 1;
uint16 UI_WindowBlocks_Record = 0;

/******************************************************************************/
block_attr_Record block_Record_BACKCOLOR_BACK = {
	ENABLE,								/* Interface Record rect */
	{
		0,   20,
		128, 140,
		BACKCOLOR_CONTENT_BACK
	},

	DISABLE,							/* Display HZ16X8 */
	{0},

	DISABLE,							/* Display HZ16X8 */
	{0},
};

/******************************************************************************/
block_attr_Record block_Record_Pname = {
	DISABLE,								/* Interface Record rect */
	{0},

	DISABLE,								/* Display HZ16X8 */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.Product_name,
		4,   26,
		Black,BACKCOLOR_CONTENT_BACK
	},
};

/******************************************************************************/
block_attr_Record block_Record_SN = {
	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"SN:",
		21,   42,
		Black,BACKCOLOR_CONTENT_BACK
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.Product_SN,
		45,   42,
		Black,BACKCOLOR_CONTENT_BACK
	},
};

/******************************************************************************/
block_attr_Record block_Record_Time = {
	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		"Time:",
		5,   58,
		Black,BACKCOLOR_CONTENT_BACK
	},

	ENABLE,								/* Display HZ16X8 */
	{
		cBuffer,
		45,   58,
		Black,BACKCOLOR_CONTENT_BACK
	},
};

/******************************************************************************/
block_attr_Record block_Record_Time2 = {
	DISABLE,							/* Interface Record rect */
	{0},

	DISABLE,								/* Display HZ16X8 */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		tBuffer,
		45,   74,
		Black,BACKCOLOR_CONTENT_BACK
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH1 = {
	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[0].TName,
		4,   90,
		Black,BACKCOLOR_CONTENT_BACK
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[0].Result,
		60,   90,
		Black,BACKCOLOR_CONTENT_BACK
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH2 = {
	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[1].TName,
		5,   106,
		Black,BACKCOLOR_CONTENT_BACK
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[1].Result,
		60,   106,
		Black,BACKCOLOR_CONTENT_BACK
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH3 = {
	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[2].TName,
		5,   122,
		Black,BACKCOLOR_CONTENT_BACK
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[2].Result,
		60,   122,
		Black,BACKCOLOR_CONTENT_BACK
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH4 = {
	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[3].TName,
		5,   138,
		Black,BACKCOLOR_CONTENT_BACK
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[3].Result,
		60,   138,
		Black,BACKCOLOR_CONTENT_BACK
	}
};

/******************************************************************************/
block_attr_Record* UI_WindowBlocksAttrArray_Record[][9] = {/* Window: Standard entry */
{&block_Record_BACKCOLOR_BACK,&block_Record_Pname,&block_Record_Time,&block_Record_SN,
		&block_Record_Time2,&block_Record_CH1},
{&block_Record_BACKCOLOR_BACK,&block_Record_Pname,&block_Record_Time,&block_Record_SN,
		&block_Record_Time2,&block_Record_CH1,&block_Record_CH2},
{&block_Record_BACKCOLOR_BACK,&block_Record_Pname,&block_Record_Time,&block_Record_SN,
		&block_Record_Time2,&block_Record_CH1,&block_Record_CH2,&block_Record_CH3},
{&block_Record_BACKCOLOR_BACK,&block_Record_Pname,&block_Record_Time,&block_Record_SN,
		&block_Record_Time2,&block_Record_CH1,&block_Record_CH2,&block_Record_CH3,
		&block_Record_CH4},
};

/******************************************************************************/
void UI_Draw_Block_Record(block_attr_Record* block);

/******************************************************************************/
uint8 Interface_Record(uint16 KeyCode)
{
	Exti_lock = DISABLE;
	Interface_Key = 4;
	Read_Record();
	Data_Changer();
	if(Storage_Data.StripNum > 4)
	{
		page_tatol = 2;
		page_Num = 1;
		UI_WindowBlocks_Record = sizeof(UI_WindowBlocksAttrArray_Record[3]) >> 2;
	}
	else
	{
		page_tatol = 1;
		UI_WindowBlocks_Record = sizeof(UI_WindowBlocksAttrArray_Record[Storage_Data.StripNum-1]) >> 2;
	}
	UI_Draw_Window_Record(UI_WindowBlocks_Record);
	Exti_lock = ENABLE;
	while(!key_state);
	UI_state = UI_STATE_KEY_STATE;
	return UI_STATE_RERUN;
}

/******************************************************************************/
void UI_Draw_Window_Record(uint16 blockNum)
{
	uint8 blockIndex = 0;					/* Draw blocks one by one */
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		if(Storage_Data.StripNum > 4)
		{
			if(UI_WindowBlocksAttrArray_Record[3][blockIndex])
			{
				UI_Draw_Block_Record(UI_WindowBlocksAttrArray_Record[3][blockIndex]);
			}
		}
		else
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
	if (block->rect_enabled)				/* 1. Draw Rect */
	{
		Lcd_ColorBox(block->rect_attr.startX, block->rect_attr.startY,
				block->rect_attr.width, block->rect_attr.height,
				block->rect_attr.color);
	}

	if (block->char_enabled)				/* 2. Draw character */
	{

		DisplayDriver_Text16_B(
				block->char_attr.offsetX,block->char_attr.offsetY,
				block->char_attr.color,block->char_attr.faceColor,
				block->char_attr.str);
	}

	if (block->char2_enabled)				/* 2. Draw character */
	{

		DisplayDriver_Text16_B(
				block->char2_attr.offsetX,block->char2_attr.offsetY,
				block->char2_attr.color,block->char2_attr.faceColor,
				block->char2_attr.str);
	}
	Display_Time = 1;
	key_state = 0;
}

/******************************************************************************/
void Data_Changer(void)
{
	memset(cBuffer,0,sizeof(cBuffer));
	memset(tBuffer,0,sizeof(tBuffer));
	sprintf(cBuffer,"%d/%02d/%02d",Storage_Data.Product_Time.year,Storage_Data.Product_Time.month,Storage_Data.Product_Time.day);
	sprintf(tBuffer,"%02d:%02d",Storage_Data.Product_Time.hour,Storage_Data.Product_Time.min);
}
