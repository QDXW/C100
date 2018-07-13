/*
 * Interface_Buetooth.c
 *
 *  Created on: 2018Äê7ÔÂ6ÈÕ
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
			DisplayDriver_Fill(48,288,72,310,Interface_Back);
			DisplayDriver_Text16_Touch(52, 288,WHITE,WHITE,"ON");
			GPIO_SetBits(GPIOE, GPIO_Pin_4);
			Bluetooth_switch = 1;
		}
		else
		{
			DisplayDriver_Fill(48,288,72,310,Interface_Back);
			DisplayDriver_Text16_Touch(48,288,WHITE,WHITE,"OFF");
			GPIO_ResetBits(GPIOE, GPIO_Pin_4);
			GPIO_ResetBits(GPIOC, GPIO_Pin_9);
			Bluetooth_switch = 0;
		}
	}
	UI_state = UI_STATE_MAIN_WINDOW_PROCESS;
	return state;
}
