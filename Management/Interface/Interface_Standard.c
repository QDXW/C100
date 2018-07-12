/*
 * Interface_Standard.c
 *
 *  Created on: 2018Äê5ÔÂ10ÈÕ
 *      Author: Administrator
 */

/******************************************************************************/
#include "Interface_Standard.h"

/******************************************************************************/
uint8 Interface_Standard(uint16* xpos,uint16* ypos)
{
	uint8 state = 0;
	Interface_Reord = 1;
	Enter_Sleep = 0;
	if(Cup_Count != 0)
	{
		UI_state = UI_STATE_START;
		return state;
	}
	else
	{
		UI_state = UI_STATE_QUICK;
	}
}
