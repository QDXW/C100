/*
 * Interface_About_Machine.h
 *
 *  Created on: 2018Äê6ÔÂ19ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_ABOUT_MACHINE_H_
#define MANAGEMENT_INTERFACE_INTERFACE_ABOUT_MACHINE_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
typedef struct {
	uint8 Interface_Status;
	uint8 pic_enabled;     				/* Support picture or not */
	pic_attr pic_attr;     				/* Picture attribute */
	uint8 char_enabled;					/* Support char or not */
	char_attr char_attr;				/* char attribute */
} block_attr_about;

/******************************************************************************/
void UI_Draw_Window_About_Machine(uint16 blockNum);
void UI_Background_Plate_About_Machine(void);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_ABOUT_MACHINE_H_ */
