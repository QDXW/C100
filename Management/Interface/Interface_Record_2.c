/*
 * Interface_Record_2.c
 *
 *  Created on: 2018Äê4ÔÂ20ÈÕ
 *      Author: Administrator
 */

#include "Interface_Record_2.h"
#include "Storage_Flash.h"

/******************************************************************************/
extern uint8 cBuffer[20];
extern uint8 tBuffer[10];
extern uint8 page_tatol;
extern uint8 page_Num;

/******************************************************************************/
block_attr_Record block_Record_BACKCOLOR_CONTENT_BACK = {
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
block_attr_Record block_Record_CH5 = {
	DISABLE,								/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[4].TName,
		5,   26,
		Black,BACKCOLOR_CONTENT_BACK
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[4].Result,
		60,   26,
		Black,BACKCOLOR_CONTENT_BACK
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH6 = {
	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[5].TName,
		5,   42,
		Black,BACKCOLOR_CONTENT_BACK
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[5].Result,
		60,   42,
		Black,BACKCOLOR_CONTENT_BACK
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH7 = {
	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[6].TName,
		5,   58,
		Black,BACKCOLOR_CONTENT_BACK
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[6].Result,
		60,   58,
		Black,BACKCOLOR_CONTENT_BACK
	},

};

/******************************************************************************/
block_attr_Record block_Record_CH8 = {
	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[7].TName,
		5,   74,
		Black,BACKCOLOR_CONTENT_BACK
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[7].Result,
		60,   74,
		Black,BACKCOLOR_CONTENT_BACK
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH9 = {
	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[8].TName,
		5,   90,
		Black,BACKCOLOR_CONTENT_BACK
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[8].Result,
		60,   90,
		Black,BACKCOLOR_CONTENT_BACK
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH10 = {
	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[9].TName,
		5,   106,
		Black,BACKCOLOR_CONTENT_BACK
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[9].Result,
		60,   106,
		Black,BACKCOLOR_CONTENT_BACK
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH11 = {
	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[10].TName,
		5,   122,
		Black,BACKCOLOR_CONTENT_BACK
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[10].Result,
		60,   122,
		Black,BACKCOLOR_CONTENT_BACK
	},
};

/******************************************************************************/
block_attr_Record block_Record_CH12 = {
	DISABLE,							/* Interface Record rect */
	{0},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[11].TName,
		5,   138,
		Black,BACKCOLOR_CONTENT_BACK
	},

	ENABLE,								/* Display HZ16X8 */
	{
		Storage_Data.CH_data[11].Result,
		60,   138,
		Black,BACKCOLOR_CONTENT_BACK
	}
};

/******************************************************************************/
block_attr_Record* UI_WindowBlocksAttrArray_Record_2[][9] = {/* Window: Standard entry */
{&block_Record_BACKCOLOR_CONTENT_BACK,&block_Record_CH5},
{&block_Record_BACKCOLOR_CONTENT_BACK,&block_Record_CH5,&block_Record_CH6},
{&block_Record_BACKCOLOR_CONTENT_BACK,&block_Record_CH5,&block_Record_CH6,&block_Record_CH7},
{&block_Record_BACKCOLOR_CONTENT_BACK,&block_Record_CH5,&block_Record_CH6,&block_Record_CH7,&block_Record_CH8},
{&block_Record_BACKCOLOR_CONTENT_BACK,&block_Record_CH5,&block_Record_CH6,&block_Record_CH7,&block_Record_CH8,
		&block_Record_CH9},
{&block_Record_BACKCOLOR_CONTENT_BACK,&block_Record_CH5,&block_Record_CH6,&block_Record_CH7,&block_Record_CH8,
		&block_Record_CH9,&block_Record_CH10},
{&block_Record_BACKCOLOR_CONTENT_BACK,&block_Record_CH5,&block_Record_CH6,&block_Record_CH7,&block_Record_CH8,
		&block_Record_CH9,&block_Record_CH10,&block_Record_CH11},
{&block_Record_BACKCOLOR_CONTENT_BACK,&block_Record_CH5,&block_Record_CH6,&block_Record_CH7,&block_Record_CH8,
		&block_Record_CH9,&block_Record_CH10,&block_Record_CH11,&block_Record_CH12},
};

/******************************************************************************/
void UI_Draw_Block_Record_2(block_attr_Record* block);

/******************************************************************************/
uint8 Interface_Record_2(uint16 KeyCode)
{
	Exti_lock = DISABLE;
	Interface_Key = 4;
	Read_Record();
	Data_Changer();
	page_Num = 2;
	UI_WindowBlocks_Record_2 = sizeof(UI_WindowBlocksAttrArray_Record_2[Storage_Data.StripNum-5]) >> 2;
	UI_Draw_Window_Record_2(UI_WindowBlocks_Record_2);
	Exti_lock = ENABLE;
	while(!key_state);
	UI_state = UI_STATE_KEY_STATE;
	return UI_STATE_RERUN;
}

/******************************************************************************/
void UI_Draw_Window_Record_2(uint16 blockNum)
{
	uint8 blockIndex = 0;					/* Draw blocks one by one */
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		if(UI_WindowBlocksAttrArray_Record_2[Storage_Data.StripNum-5][blockIndex])
		{
			UI_Draw_Block_Record_2(UI_WindowBlocksAttrArray_Record_2[Storage_Data.StripNum-5][blockIndex]);
		}
	}
}

/******************************************************************************/
void UI_Draw_Block_Record_2(block_attr_Record* block)
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
