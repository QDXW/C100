/*
 * Interface_Invalue_Code.c
 *
 *  Created on: 2018Äê7ÔÂ11ÈÕ
 *      Author: Administrator
 */
/******************************************************************************/
#include "Interface_Invalue_Code.h"

/******************************************************************************/
block_attr_InvCode block_InvCode_UI_Return = {
	UI_STATE_MAIN_WINDOW,			/* Interface status */

	ENABLE,							/* Display HZ16X8 */
	{
		UI_Return,
		0,   22,
		50,  45
	},

	ENABLE,
	{
		"Invalid QR Code",
		60,   159,
		RED,WHITE
	},
};

/******************************************************************************/
block_attr_InvCode block_InvCode_Delete = {
	UI_STATE_QUICK,			/* Interface status */

	ENABLE,							/* Interface Start rect */
	{
		Delete,
		84,   265,
		72,   55
	},

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_InvCode* UI_WindowBlocksAttrArray_InvCode[] = {/* Window: Standard entry */
		&block_InvCode_UI_Return,
		&block_InvCode_Delete,
};

/******************************************************************************/
void UI_Draw_Block_InvCode(block_attr_InvCode* block);

/******************************************************************************/
uint8 Interface_Invalue_Code_Process(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Display_Battery = 1;
	UI_Background_Plate_InvCode();
	QRCode_Trigger_Disabled();
	memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_InvCode) >> 2;
	memcpy(UI_WindowBlocksAttrArray, UI_WindowBlocksAttrArray_InvCode,sizeof(UI_WindowBlocksAttrArray_InvCode));
	UI_Draw_Window_InvCode(UI_WindowBlocks);
	UI_WindowBlocks = 1;
	UI_state = UI_STATE_INVALID_TOUCH_PROCESS;
	return state;
}

/******************************************************************************/
void UI_Draw_Window_InvCode(uint16 blockNum)
{
	uint8 blockIndex = 0;					/* Draw blocks one by one */
	for (blockIndex = 0; blockIndex < blockNum; blockIndex++)
	{
		UI_Draw_Block_InvCode(UI_WindowBlocksAttrArray_InvCode[blockIndex]);
	}
}

/******************************************************************************/
void UI_Draw_Block_InvCode(block_attr_InvCode* block)
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
void UI_Background_Plate_InvCode (void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(10,82,229,250,WHITE);
	Display_Time = 1;
}

/******************************************************************************/
uint8 Interface_Invalid_Touch_Process(uint16* xpos,uint16* ypos)
{
	uint8 state = 0,i = 0;
	InvCode_Down_time = 1;
	if(InvCode_Second > 15)
	{
		InvCode_Down_time = 0;
		InvCode_Second = 0;
		UI_state = UI_STATE_MAIN_WINDOW;
	}

	if((xpos != 0) || (ypos != 0))
	{
		for(i = 0;i < 2;i++)
		{
			Invalid_Touch_Check(UI_WindowBlocksAttrArray_InvCode[i],xpos,ypos);
			if(Touch_Success)
			{
				Touch_Success = 0;
				InvCode_Down_time = 0;
			}
		}
	}
	return state;
}

/******************************************************************************/
void Invalid_Touch_Check(block_attr_InvCode* block,uint16* xpos,uint16* ypos)
{
	uint16 startX = 0,endX = 0;
	uint16 startY = 0,endY = 0;
	startX = block->pic_attr.offsetX;
	endX = startX + block->pic_attr.width;
	startY = block->pic_attr.offsetY;
	endY = startY + block->pic_attr.height;
	if(block->Interface_Status)
	{
		if((startX < *xpos) && (*xpos < endX) && (startY < *ypos) && (*ypos < endY))
		{
			UI_state = block->Interface_Status;
			Pic_Count = block->pic_attr.count;
			Touch_Success = 1;
		}
	}
}
