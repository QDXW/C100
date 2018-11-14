/*
 * Interface_Quick.h
 *
 *  Created on: 2018Äê2ÔÂ24ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_QUICK_H_
#define MANAGEMENT_INTERFACE_INTERFACE_QUICK_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
typedef struct {
	uint8 Interface_Status;
	uint8 pic_enabled;     				/* Support picture or not */
	pic_attr pic_attr;					/* picture attribute */
} block_attr_Quick;

/******************************************************************************/
extern void UI_Draw_Window_Quick(uint16 blockNum);
void UI_Draw_Window_Quick_font(uint16 blockNum);
void UI_Background_Plate_Quick (void);
void UI_Language_Plate_Quick (void);
uint8 Quick_Touch_Check(block_attr_Quick* block,uint16* xpos,uint16* ypos);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_QUICK_H_ */
