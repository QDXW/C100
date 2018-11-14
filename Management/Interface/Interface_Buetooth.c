/*
 * Interface_Buetooth.c
 *
 *  Created on: 2018年7月6日
 *      Author: Administrator
 */

/******************************************************************************/
#include "Interface_Buetooth.h"

/******************************************************************************/
uint8 Interface_Buetooth_Process (uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	if(Pic_Count == 3)
	{
		if(!Bluetooth_switch)
		{
			DisplayDriver_Fill(44,288,100,310,Interface_Back);

			switch(Font_Switch)
			{
			case DISPLAY_FONT_ENGLISH:
					DisplayDriver_Text_Flex(16,52,288,WHITE,WHITE,"ON");
				break;

			case DISPLAY_FONT_CHINESE:
					DisplayDriver_Text_Flex(16,44,288,WHITE,WHITE,"打开");
				break;

			default:
				break;
			}
			GPIO_SetBits(GPIOE, GPIO_Pin_4);
			Bluetooth_switch = 1;
		}
		else
		{
			DisplayDriver_Fill(44,288,100,310,Interface_Back);

			switch(Font_Switch)
			{
			case DISPLAY_FONT_ENGLISH:
					DisplayDriver_Text_Flex(16,48,288,WHITE,WHITE,"OFF");
				break;

			case DISPLAY_FONT_CHINESE:
					DisplayDriver_Text_Flex(16,44,288,WHITE,WHITE,"关闭");
				break;

			default:
				break;
			}

			GPIO_ResetBits(GPIOE, GPIO_Pin_4);
			GPIO_ResetBits(GPIOC, GPIO_Pin_9);
			Bluetooth_Connect = 0;
			Bluetooth_switch = 0;
		}
	}
	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	return state;
}
