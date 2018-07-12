/*
 * Interface_Setting.h
 *
 *  Created on: 2018Äê2ÔÂ24ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_SETTING_H_
#define MANAGEMENT_INTERFACE_INTERFACE_SETTING_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/


/******************************************************************************/
typedef struct {
	uint8 Interface_Status;
	uint8 pic_enabled;     				/* Support picture or not */
	pic_attr pic_attr;					/* picture attribute */
	uint8 char_enabled;					/* Support char or not */
	char_attr char_attr;				/* char attribute */
} block_attr_Setting;

/******************************************************************************/
void UI_Draw_Window_Setting(uint16 blockNum);
void UI_Background_Plate_Setting(void);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_SETTING_H_ */
