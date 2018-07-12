/*
 * Interface_About_Machine.c
 *
 *  Created on: 2018Äê6ÔÂ19ÈÕ
 *      Author: Administrator
 *Deep_Blue/

/******************************************************************************/
#include "Interface_About_Machine.h"

/******************************************************************************/
block_attr_about block_about_Return = {
	UI_STATE_SETTING,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		UI_Return,
		0,   22,
		50,  45
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_about* UI_WindowBlocksAttrArray_Main_About[] = {		/* Window: Main entry */
		&block_about_Return,
};

/******************************************************************************/
void UI_Draw_Block_About(block_attr_about* block);

/******************************************************************************/
uint8 Interface_About_Machine(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	UI_Background_Plate_About_Machine();
	memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Main_About) >> 2;
	memcpy(UI_WindowBlocksAttrArray, UI_WindowBlocksAttrArray_Main_About,
			sizeof(UI_WindowBlocksAttrArray_Main_About));
	UI_Draw_Window_About_Machine(UI_WindowBlocks);
	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	return state;
}

/******************************************************************************/
void UI_Draw_Window_About_Machine(uint16 blockNum)
{
	uint8 blockIndex = 0;						/* Draw blocks one by one */
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		UI_Draw_Block_About(UI_WindowBlocksAttrArray_Main_About[blockIndex]);
	}
}

/******************************************************************************/
void UI_Draw_Block_About(block_attr_about* block)
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
void UI_Background_Plate_About_Machine(void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(20,72,220,250,LIGHTBLUE);
	DisplayDriver_Text16_Touch(40,99,WHITE,WHITE,"Type: RL-C100");
	DisplayDriver_Text16_Touch(40,135,WHITE,WHITE,"SN  : 201807101809");
	DisplayDriver_Text16_Touch(40,171,WHITE,WHITE,"HW Version: 1.1.1");
	DisplayDriver_Text16_Touch(40,207,WHITE,WHITE,"FW Version: 1.8.0710");
	Display_Time = 1;
}
