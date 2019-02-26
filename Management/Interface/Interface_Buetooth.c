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
			DisplayDriver_Fill(155,204,220,220,Interface_Back);

			switch(Font_Switch)
			{
			case DISPLAY_FONT_ENGLISH:
				DisplayDriver_Text_Flex(16,167,204,WHITE,WHITE,"ON");
				break;

			case DISPLAY_FONT_CHINESE:
				DisplayDriver_Text_Flex(16,159,204,WHITE,WHITE,"打开");
				break;

			default:
				break;
			}
			state = 0;
			GPIO_SetBits(GPIOE, GPIO_Pin_4);
			Bluetooth_switch = 1;
			Storage_Write(&state, (FLASH_CALI_ADDR+FLASH_OFFSET_ADDR*4),1);
		}
		else
		{
			DisplayDriver_Fill(155,204,220,220,Interface_Back);

			switch(Font_Switch)
			{
			case DISPLAY_FONT_ENGLISH:
				DisplayDriver_Text_Flex(16,163,204,WHITE,WHITE,"OFF");
				break;

			case DISPLAY_FONT_CHINESE:
				DisplayDriver_Text_Flex(16,159,204,WHITE,WHITE,"关闭");
				break;

			default:
				break;
			}
			state = 1;
			GPIO_ResetBits(GPIOE, GPIO_Pin_4);
			GPIO_ResetBits(GPIOC, GPIO_Pin_9);
			Bluetooth_Connect = 0;
			Bluetooth_switch = 0;
			Storage_Write(&state, (FLASH_CALI_ADDR+FLASH_OFFSET_ADDR*4),1);
		}
	}
	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	return state;
}
