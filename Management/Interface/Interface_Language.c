/*
 * Interface_Language.c
 *
 *  Created on: 2018年11月22日
 *      Author: Administrator
 */
/******************************************************************************/
#include "Interface_Language.h"
#include "Language_OFF.pic"
#include "Language_ON.pic"

/******************************************************************************/
block_attr_Language block_Language_return = {
	UI_STATE_SETTING,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		UI_Return,
		0,   22,
		50,  45,
		1,
	},

	DISABLE,							/* Display HZ16X8 */
	{0},

	200,
};

/******************************************************************************/
block_attr_Language block_Language_English_OFF = {
	UI_STATE_LANGUSGE_CONFIRM_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Language_OFF,
		25,   62,
		80,  22,
		1,
	},

	ENABLE,							/* Display HZ16X8 */
	{
		"English",
		37,   65,
		WHITE,  Interface_Back,
	},
	LANGUAGE_ENGLISH_OFF,
};

/******************************************************************************/
block_attr_Language block_Language_English_ON = {
	UI_STATE_LANGUSGE_CONFIRM_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Language_ON,
		25,   62,
		80,  22,
		0
	},

	ENABLE,							/* Display HZ16X8 */
	{
		"English",
		37,   65,
		WHITE,  Interface_Back,
	},
	LANGUAGE_ENGLISH_ON,
};

/******************************************************************************/
block_attr_Language block_Language_China_OFF = {
	UI_STATE_LANGUSGE_CONFIRM_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Language_OFF,
		135,   62,
		80,  22,
		1,
	},

	ENABLE,							/* Display HZ16X8 */
	{
		"简体中文",
		139,   65,
		WHITE,  Interface_Back,
	},
	LANGUAGE_CHAINESE_OFF,
};

/******************************************************************************/
block_attr_Language block_Language_China_ON = {
	UI_STATE_LANGUSGE_CONFIRM_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Language_ON,
		135,   62,
		80,  22,
		0
	},

	ENABLE,							/* Display HZ16X8 */
	{
		"简体中文",
		139,   65,
		WHITE,  Interface_Back,
	},

	LANGUAGE_CHAINESE_ON,
};

/******************************************************************************/
block_attr_Language* UI_WindowBlocksAttrArray_Language[] = {/* Window: Standard entry */
		&block_Language_return,
		&block_Language_English_OFF,
		&block_Language_English_ON,
		&block_Language_China_OFF,
		&block_Language_China_ON,
};

/******************************************************************************/
uint8 Interface_Language_Process(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	Display_Time = 1;
	memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Language) >> 2;
	memcpy(UI_WindowBlocksAttrArray, UI_WindowBlocksAttrArray_Language,
			sizeof(UI_WindowBlocksAttrArray_Language));
	UI_Draw_Window_Language(UI_WindowBlocks);
	UI_state = UI_STATE_LANGUSGE_CONFIRM_PROCESS;
	return state;
}

/******************************************************************************/
void UI_Draw_Window_Language(uint16 blockNum)
{
	uint8 blockIndex = 0;					/* Draw blocks one by one */
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		UI_Draw_Block_Language(UI_WindowBlocksAttrArray_Language[blockIndex]);
	}
}

/******************************************************************************/
void UI_Draw_Block_Language(block_attr_Language* block)
{
	Display_Time = 0;
	if ((block->pic_enabled) && block->pic_attr.count)						/* 2. Draw picture */
	{
		DisplayDriver_DrawPic_Touch(block->pic_attr.src,Interface_Back,
				block->pic_attr.offsetX,block->pic_attr.offsetY);
	}

	if (block->char_enabled)					/* 4. Draw character */
	{
		DisplayDriver_Text_Flex(
				16,
				block->char_attr.offsetX,block->char_attr.offsetY,
				block->char_attr.color,block->char_attr.backColor,
				block->char_attr.str);
	}
	Display_Time = 1;
}

/******************************************************************************/
uint8 Interface_Language_Window_Process(uint16* xpos,uint16* ypos)
{
	return Touch_Language (xpos,ypos);
}

/******************************************************************************/
uint8 Touch_Language (uint16* xpos,uint16* ypos)
{
	uint8 blockIndex = 0,state = 0;						/* Draw blocks one by one */
	if((xpos != 0) || (ypos != 0))
	{
		for (blockIndex = 0; blockIndex < UI_WindowBlocks; blockIndex++)
		{
			Touch_Language_Check(UI_WindowBlocksAttrArray_Language[blockIndex],xpos,ypos);
			if(Touch_Success)
			{
				Touch_Success = 0;
				return UI_STATE_RERUN;
			}
		}
	}
	return state;
}

/******************************************************************************/
void Touch_Language_Check(block_attr_Language* block,uint16* xpos,uint16* ypos)
{
	uint8 blockIndex = 0;
	uint16 startX = 0,endX = 0;
	uint16 startY = 0,endY = 0;
	startX = block->pic_attr.offsetX;
	endX = startX + block->pic_attr.width;
	startY = block->pic_attr.offsetY;
	endY = startY + block->pic_attr.height;
	if(block->Interface_Status)
	{
		if((startX < *xpos) && (*xpos < endX) && (startY < *ypos) && (*ypos < endY) && (!(block->Language_select %2)))
		{
			UI_state = block->Interface_Status;
			block->pic_attr.count = 1;
			Pic_Count = block->Language_select;
			Touch_Success = 1;
			if((block->Language_select > 0) && (block->Language_select < 100))
			{
				switch((block->Language_select/2 - 1))
				{
				case DISPLAY_FONT_CHINESE:
					Font_Switch = DISPLAY_FONT_CHINESE;
					Storage_Write(&Font_Switch, (FLASH_CALI_ADDR+FLASH_OFFSET_ADDR*3),1);
					break;

				case DISPLAY_FONT_ENGLISH:
					Font_Switch = DISPLAY_FONT_ENGLISH;
					Storage_Write(&Font_Switch, (FLASH_CALI_ADDR+FLASH_OFFSET_ADDR*3),1);
					break;

				default:
					break;
				}
			}

			for (blockIndex = 0; blockIndex < UI_WindowBlocks; blockIndex++)
			{
				Update_Language_Interface(UI_WindowBlocksAttrArray_Language[blockIndex],xpos,ypos);
			}
		}
	}
}

/******************************************************************************/
void Update_Language_Interface (block_attr_Language* block,uint16* xpos,uint16* ypos)
{

	Display_Time = 0;
	if (block->pic_enabled && block->pic_attr.count)						/* 2. Draw picture */
	{
		DisplayDriver_DrawPic_Touch(block->pic_attr.src,Interface_Back,
				block->pic_attr.offsetX,block->pic_attr.offsetY);
	}

	if (block->char_enabled)					/* 4. Draw character */
	{
		DisplayDriver_Text_Flex(
				16,
				block->char_attr.offsetX,block->char_attr.offsetY,
				block->char_attr.color,block->char_attr.backColor,
				block->char_attr.str);
	}
	Display_Time = 1;

	if((50 < *xpos) && (67 < *ypos) && (!(block->Language_select %2)))
	{
		block->pic_attr.count = 0;
	}
}
