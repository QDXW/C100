/*
 * Interface_Quick.c
 *
 *  Created on: 2018年2月24日
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
};

/******************************************************************************/
block_attr_Quick block_Quick_Scan_China = {
	UI_STATE_MAIN_WINDOW,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		UI_Return,
		0,   22,
		50,  45,
		5
	},
};

/******************************************************************************/
block_attr_Quick* UI_WindowBlocksAttrArray_Quick[] = {/* Window: Standard entry */
		&block_Quick_Scan,
};

/******************************************************************************/
block_attr_Quick* UI_WindowBlocksAttrArray_Quick_China[] = {/* Window: Standard entry */
		&block_Quick_Scan_China,
};

/******************************************************************************/
void UI_Draw_Block_Quick(block_attr_Quick* block);

/******************************************************************************/
uint8 Interface_Quick(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Enter_Sleep = 0;
	Display_Battery = 0;
	if(Cup_Count != 0)
	{
		UI_state = UI_STATE_START;
		return state;
	}
	UI_Background_Plate_Quick();
	QRCode_Trigger_Disabled();
	memset(UI_WindowBlocksAttrArray,0,sizeof(UI_WindowBlocksAttrArray));
	UI_WindowBlocks = sizeof(UI_WindowBlocksAttrArray_Quick) >> 2;
	memcpy(UI_WindowBlocksAttrArray, UI_WindowBlocksAttrArray_Quick,
			sizeof(UI_WindowBlocksAttrArray_Quick));
	UI_Draw_Window_Quick(UI_WindowBlocks);
	UI_Language_Plate_Quick();
	UI_WindowBlocks = 2;
	QRCode_Trigger_Enabled();
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
void UI_Language_Plate_Quick (void)
{
	Display_Time = 0;
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		DisplayDriver_Text_Flex(16,56,169,BLACK,WHITE,"Scan the QR code");
		break;

	case DISPLAY_FONT_CHINESE:
		DisplayDriver_Text_Flex(24,60,160,Interface_Back,WHITE,"扫描二维码");
		break;

	default:
		break;
	}
	Display_Time = 1;
}

/******************************************************************************/
uint8 Interface_Quick_Touch_Process(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Quick_Down_time = 1;

	if(1 == QRCode_received)
	{
		QRCode_received = 0;
		if ((QRCode_Identify()) && (4 == QR_Date.head.Model))						/* Decode */
		{
			Send_QRCode();
			UI_state = UI_STATE_INSERT_CUP;
			Quick_Down_time = 0;
			state = UI_STATE_RERUN;
		}
		else
		{
			UI_state = UI_STATE_INVALUE_CODE_PROCESS;
			Quick_Down_time = 0;
			state = UI_STATE_RERUN;

			/* 清空结构体    1、QR接收结构体   2、处理后QR结构体    3、存储结构体 */
			Cup_Count = 0;
			memset(&QR_Date, 0, sizeof(QRCODE_STRUCT));
			memset(&QR_Date_Analyze, 0, sizeof(QRCODE_STRUCT));
			memset(&Storage_Data, 0, sizeof(STORAGE_SINGLE_DATA_STRUCT));
		}

		/* Clear size */
		QRCode_count = 0;
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
		if((0 < *xpos) && (*xpos < 60) && (22 < *ypos) && (*ypos < 65))
		{
			UI_state = block->Interface_Status;
			Pic_Count = block->pic_attr.count;
			Quick_Down_time = 0;
			return UI_STATE_RERUN;
		}
	}
}
