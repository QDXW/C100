/*
 * Interface_Calibration.c
 *
 *  Created on: 2018Äê8ÔÂ31ÈÕ
 *      Author: Administrator
 */
/******************************************************************************/
#include "Interface_Calibration.h"
#include "Start_Buton.pic"
#include "Start_Key.pic"
#include "Start_remind.pic"

/******************************************************************************/
block_attr_Calibration block_attr_Calibration_return = {
	UI_STATE_MAIN_WINDOW,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		UI_Return,
		0,   22,
		45,  40,
		0
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_Calibration block_attr_Start_Key = {
	UI_STATE_IN_CALIBRATION_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Start_Key,
		50,   63,
		140,  140,
		0
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_Calibration block_attr_Start_remind = {
	UI_STATE_MAIN_WINDOW_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Start_remind,
		10,  250,
		220,  40,
		0
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_Calibration* UI_WindowBlocksAttrArray_Calibration[] = {/* Window: Standard entry */
		&block_attr_Calibration_return,
		&block_attr_Start_Key,
		&block_attr_Start_remind,
};

/******************************************************************************/
void UI_Draw_Block_Calibration(block_attr_Calibration* block);

/******************************************************************************/
uint8 Interface_Calibration_Process (uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Display_Battery = 1;
	UI_Background_Plate_Calibration();
	memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Calibration) >> 2;
	memcpy(UI_WindowBlocksAttrArray, UI_WindowBlocksAttrArray_Calibration,sizeof(UI_WindowBlocksAttrArray_Calibration));
	UI_Draw_Window_Calibration(UI_WindowBlocks);
	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	return state;
}

/******************************************************************************/
void UI_Draw_Window_Calibration(uint16 blockNum)
{
	uint8 blockIndex = 0;					/* Draw blocks one by one */
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		UI_Draw_Block_Calibration(UI_WindowBlocksAttrArray_Calibration[blockIndex]);
	}
}

/******************************************************************************/
void UI_Draw_Block_Calibration(block_attr_Calibration* block)
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
void UI_Background_Plate_Calibration(void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(0,220,240,320,WHITE);
	Display_Time = 1;
}
