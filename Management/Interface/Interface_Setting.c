/*
 * Interface_Setting.c
 *
 *  Created on: 2018年2月24日
 *      Author: Administrator
 */

/******************************************************************************/
#include "Interface_Setting.h"
#include "system.pic"
#include "time.pic"
#include "Blutooth.pic"
#include "Calibration.pic"

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

	DISABLE,
	{0},
};

/******************************************************************************/
block_attr_Setting block_Setting_system = {
	UI_STATE_ABOUT_MACHINE,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		system,
		17,  62,
		86, 86,
		1
	},

	DISABLE,
	{
		"About Machine",
		8,   154,
		WHITE,WHITE
	},
};

/******************************************************************************/
block_attr_Setting block_Setting_Time = {
	UI_STATE_SYSTEM_TIME,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		time,
		137,  62,
		86, 86,
		2
	},

	DISABLE,
	{
		"System Time",
		140,  154,
		WHITE,WHITE
	},
};

/******************************************************************************/
block_attr_Setting block_Setting_Blutooth_OFF = {
	UI_STATE_BLUETOOTH_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Blutooth,
		17,  196,
		86, 86,
		3
	},

	DISABLE,
	{
		"OFF",
		48,  288,
		WHITE,WHITE
	},
};

/******************************************************************************/
block_attr_Setting block_Setting_Blutooth_ON = {
	UI_STATE_BLUETOOTH_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Blutooth,
		17,  196,
		86, 86,
		3
	},

	DISABLE,
	{
		"ON",
		52,  288,
		WHITE,WHITE
	},
};

/******************************************************************************/
block_attr_Setting block_Calibration = {
	UI_STATE_CALIBRATION_PROCESS,								/* Interface Quick rect */

	ENABLE,							/* Display HZ16X8 */
	{
		Calibration,
		137,  196,
		86, 86,
		4
	},

	DISABLE,
	{
		"Calibration",
		136,  288,
		WHITE,WHITE
	},
};

/******************************************************************************/
block_attr_Setting* UI_WindowBlocksAttrArray_Setting[] = {/* Window: Standard entry */
		&block_Setting_return,
		&block_Setting_Time,
		&block_Setting_system,
		&block_Setting_Blutooth_OFF,
		&block_Calibration,
};

/******************************************************************************/
void UI_Draw_Block_Setting(block_attr_Setting* block);
void UI_Draw_Block_Setting_2(block_attr_Setting* block);

/******************************************************************************/
uint8 Interface_Setting(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Interface_Reord = 3;
	UI_Background_Plate_Setting();
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
void UI_Background_Plate_Setting(void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_DrawStraight_Line(119,22,119,320,CYAN_Line);
	DisplayDriver_DrawStraight_Line(120,22,120,320,Thint_Line);
	DisplayDriver_DrawStraight_Line(0,185,240,185,CYAN_Line);
	DisplayDriver_DrawStraight_Line(0,186,240,186,Thint_Line);
	Display_Time = 1;
}

/******************************************************************************/
void UI_Language_Plate_Setting(void)
{
	Display_Time = 0;
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		if(Bluetooth_switch)
		{
			DisplayDriver_Text_Flex(16,8,154,WHITE,WHITE,"About Machine");
			DisplayDriver_Text_Flex(16,140,154,WHITE,WHITE,"System Time");
//			DisplayDriver_Text_Flex(16,52,288,WHITE,WHITE,"ON");
			DisplayDriver_Text_Flex(16,136,288,WHITE,WHITE,"Calibration");
		}
		else
		{
			DisplayDriver_Text_Flex(16,8,154,WHITE,WHITE,"About Machine");
			DisplayDriver_Text_Flex(16,140,154,WHITE,WHITE,"System Time");
//			DisplayDriver_Text_Flex(16,48,  288,WHITE,WHITE,"OFF");
			DisplayDriver_Text_Flex(16,136,288,WHITE,WHITE,"Calibration");
		}
		break;

	case DISPLAY_FONT_CHINESE:
		if(Bluetooth_switch)
		{
			DisplayDriver_Text_Flex(16,28,154,WHITE,WHITE,"关于本机");
			DisplayDriver_Text_Flex(16,140,154,WHITE,WHITE,"系统时间");
			DisplayDriver_Text_Flex(16,52,288,WHITE,WHITE,"打开");
			DisplayDriver_Text_Flex(16,64,288,WHITE,WHITE,"校准");
		}
		else
		{
			DisplayDriver_Text_Flex(16,28,154,WHITE,WHITE,"关于本机");
			DisplayDriver_Text_Flex(16,140,154,WHITE,WHITE,"系统时间");
			DisplayDriver_Text_Flex(16,48,  288,WHITE,WHITE,"关闭");
			DisplayDriver_Text_Flex(16,164,288,WHITE,WHITE,"校准");
		}
		break;

	default:
		break;
	}
	Display_Time = 1;
}
