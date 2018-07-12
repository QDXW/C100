/*
 * Interface_Input_Cup.h
 *
 *  Created on: 2018Äê3ÔÂ19ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_INSERT_CUP_H_
#define MANAGEMENT_INTERFACE_INTERFACE_INSERT_CUP_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
typedef struct {
	uint8 Interface_Status;
	uint8 pic_enabled;     				/* Support picture or not */
	pic_attr pic_attr;					/* picture attribute */
	uint8 char_enabled;					/* Support char or not */
	char_attr char_attr;				/* char attribute */
} block_attr_Insert_Cup;

/******************************************************************************/
void UI_Draw_Window_Insert_Cup(uint16 blockNum);
void UI_Background_Plate_Cup(void);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_INSERT_CUP_H_ */
