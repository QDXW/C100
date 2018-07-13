/*
 * Interface_Quick.c
 *
 *  Created on: 2018Äê2ÔÂ24ÈÕ
 *      Author: Administrator
 ******************************************************************************/
#include "Interface_Quick.h"

/******************************************************************************/
block_attr_Quick block_Quick_Scan = {
	UI_STATE_MAIN_WINDOW,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		UI_Return,
		0,   22,
		50,  45,
		5
	},

	ENABLE,
	{
		"Scan the QR code",
		56,   169,
		BLACK,WHITE
	},
};

/******************************************************************************/
block_attr_Quick* UI_WindowBlocksAttrArray_Quick[] = {/* Window: Standard entry */
		&block_Quick_Scan,
};

/******************************************************************************/
void UI_Draw_Block_Quick(block_attr_Quick* block);

/******************************************************************************/
uint8 Interface_Quick(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Enter_Sleep = 0;
	if(Cup_Count != 0)
	{
		UI_state = UI_STATE_START;
		return state;
	}
	UI_Background_Plate_Quick();
	QRCode_Trigger_Disabled();
	memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Quick) >> 2;
	memcpy(UI_WindowBlocksAttrArray, UI_WindowBlocksAttrArray_Quick,sizeof(UI_WindowBlocksAttrArray_Quick));
	UI_Draw_Window_Quick(UI_WindowBlocks);
	QRCode_Trigger_Enabled();
	UI_WindowBlocks = 2;
	UI_state = UI_STATE_QUICK_TOUCH_PROCESS;
	return state;
}

/******************************************************************************/
void UI_Draw_Window_Quick(uint16 blockNum)
{
	uint8 blockIndex = 0;					/* Draw blocks one by one */
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		UI_Draw_Block_Quick(UI_WindowBlocksAttrArray_Quick[blockIndex]);
	}
}

/******************************************************************************/
void UI_Draw_Block_Quick(block_attr_Quick* block)
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
void UI_Background_Plate_Quick (void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(10,62,229,270,WHITE);
	Display_Time = 1;
}

/******************************************************************************/
uint8 Interface_Quick_Touch_Process(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Quick_Down_time = 1;
	if(QRCode_received)
	{
		if (QRCode_existed)
		{
			UI_state = UI_STATE_INSERT_CUP;
			QRCode_received = 0;
			QRCode_existed = 0;
			Quick_Down_time = 0;
		}
		else
		{
			UI_state = UI_STATE_INVALUE_CODE_PROCESS;
			QRCode_received = 0;
			Quick_Down_time = 0;
		}
	}
	else
	{
		if (Quick_Second > 20)
		{
			UI_state = UI_STATE_MAIN_WINDOW;
			Quick_Down_time = 0;
			Quick_Second = 0;
		}
		Quick_Touch_Check(UI_WindowBlocksAttrArray_Quick[0],xpos,ypos);
	}
	return state;
}

/******************************************************************************/
uint8 Quick_Touch_Check(block_attr_Quick* block,uint16* xpos,uint16* ypos)
{
	if((xpos != 0) || (ypos != 0))
	{
		if((0 < *xpos) && (*xpos < 45) && (22 < *ypos) && (*ypos < 65))
		{
			UI_state = block->Interface_Status;
			Pic_Count = block->pic_attr.count;
			Quick_Down_time = 0;
			return UI_STATE_RERUN;
		}
	}
}
