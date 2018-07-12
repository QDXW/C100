/*
 * Interface_Insert_Cup.c
 *
 *  Created on: 2018Äê3ÔÂ19ÈÕ
 *      Author: Administrator
 */
/******************************************************************************/
#include "Interface_Insert_Cup.h"

/******************************************************************************/
block_attr_Insert_Cup block_Insert_Cup_Notice = {
	UI_STATE_MAIN_WINDOW,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		UI_Return,
		0,   22,
		50,  45
	},

	DISABLE,									/*Display HZ16X8*/
	{
		"Notice",
		15,   64,
		RED,Interface_Bar,
	},
};

/******************************************************************************/
block_attr_Insert_Cup block_Insert_Cup_Please = {
	UI_STATE_TESTING,

	ENABLE,							/* Display HZ16X8 */
	{
		Confirmation,
		84, 263,
		72,  57
	},

	ENABLE,									/* Display HZ16X8 */
	{
		"Insert Cup",
		80,   164,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Insert_Cup* UI_WindowBlocksAttrArray_Insert_Cup[] = {/* Window: Insert_Cup entry */
		&block_Insert_Cup_Notice,
		&block_Insert_Cup_Please,
};

/******************************************************************************/
uint8 Interface_Insert_Cup(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	UI_Background_Plate_Cup();
	memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Insert_Cup) >> 2;
	memcpy(UI_WindowBlocksAttrArray, UI_WindowBlocksAttrArray_Insert_Cup,sizeof(UI_WindowBlocksAttrArray_Insert_Cup));
	UI_Draw_Window_Insert_Cup(UI_WindowBlocks);
	UI_WindowBlocks = 2;
	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	return state;
}

/******************************************************************************/
void UI_Draw_Block_Insert_Cup(block_attr_Insert_Cup* block);

/******************************************************************************/
void UI_Draw_Window_Insert_Cup(uint16 blockNum)
{
	uint8 blockIndex = 0;					/* Draw blocks one by one */
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		UI_Draw_Block_Insert_Cup(UI_WindowBlocksAttrArray_Insert_Cup[blockIndex]);
	}
}

/******************************************************************************/
void UI_Draw_Block_Insert_Cup(block_attr_Insert_Cup* block)
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
void UI_Background_Plate_Cup(void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(10,62,229,260,WHITE);
	Display_Time = 1;
}
