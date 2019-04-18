/*
 * Interface_Setting.c
 *
 *  Created on: 2018Äê2ÔÂ24ÈÕ
 *      Author: Administrator
 */

/******************************************************************************/
#include "Interface_Setting.h"
#include "system.pic"
#include "time.pic"
#include "Blutooth.pic"
#include "Calibration.pic"
#include "Language.pic"

/******************************************************************************/
block_attr_Setting block_Setting_return = {
	UI_STATE_MAIN_WINDOW,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		UI_Return,
		0,   22,
		45,  40,
		0
	},
};

/******************************************************************************/
block_attr_Setting block_Setting_system = {
	UI_STATE_ABOUT_MACHINE,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		system,
		135,  25,
		80, 80,
		1
	},
};

/******************************************************************************/
block_attr_Setting block_Setting_Time = {
	UI_STATE_SYSTEM_TIME,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		time,
		25,  125,
		80, 80,
		2
	},
};

/******************************************************************************/
block_attr_Setting block_Setting_Blutooth = {
	UI_STATE_BLUETOOTH_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Blutooth,
		135,  122,
		80, 80,
		3
	},
};

/******************************************************************************/
block_attr_Setting block_Calibration = {
	UI_STATE_CALIBRATION_PROCESS,								/* Interface Quick rect */

	DISABLE,							/* Display HZ16X8 */
	{
		Calibration,
		25,  222,
		80, 80,
		4
	},
};

/******************************************************************************/
block_attr_Setting block_Language = {
	UI_STATE_LANGUSGE_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Language,
		25,  222,
		80, 80,
		4
	},
};

/******************************************************************************/
block_attr_Setting* UI_WindowBlocksAttrArray_Setting[] = {/* Window: Standard entry */
		&block_Setting_return,
		&block_Setting_Time,
		&block_Setting_system,
		&block_Setting_Blutooth,
//		&block_Calibration,
		&block_Language,
};

/******************************************************************************/
void UI_Draw_Block_Setting(block_attr_Setting* block);

/******************************************************************************/
uint8 Interface_Setting(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Interface_Reord = 3;
	memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Setting) >> 2;
	memcpy(UI_WindowBlocksAttrArray, UI_WindowBlocksAttrArray_Setting,sizeof(UI_WindowBlocksAttrArray_Setting));
	UI_Draw_Window_Setting(UI_WindowBlocks);
	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	UI_Language_Plate_Setting();
	return state;
}

/******************************************************************************/
void UI_Draw_Window_Setting(uint16 blockNum)
{
	uint8 blockIndex = 0;					/* Draw blocks one by one */
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	Display_Time = 1;
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		UI_Draw_Block_Setting(UI_WindowBlocksAttrArray_Setting[blockIndex]);
	}
}

/******************************************************************************/
void UI_Draw_Block_Setting(block_attr_Setting* block)
{
	Display_Time = 0;
	if (block->pic_enabled)						/* 2. Draw picture */
	{
		DisplayDriver_DrawPic_Touch(block->pic_attr.src,Interface_Back,
				block->pic_attr.offsetX,block->pic_attr.offsetY);
	}
	Display_Time = 1;
}
