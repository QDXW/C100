/*
 * Interface_Setting.h
 *
 *  Created on: 2018��2��24��
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_SETTING_H_
#define MANAGEMENT_INTERFACE_INTERFACE_SETTING_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
typedef struct {
	uint8 Interface_Status;
	uint8 pic_enabled;     				/* Support picture or not */
	pic_attr pic_attr;					/* picture attribute */
} block_attr_Setting;

/******************************************************************************/
void UI_Draw_Window_Setting(uint16 blockNum);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_SETTING_H_ */
