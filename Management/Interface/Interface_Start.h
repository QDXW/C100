/*
 * Interface_Start.h
 *
 *  Created on: 2018Äê2ÔÂ26ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_START_H_
#define MANAGEMENT_INTERFACE_INTERFACE_START_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
typedef struct {
	uint8 Interface_Status;
	uint8 pic_enabled;     				/* Support picture or not */
	pic_attr pic_attr;     				/* Picture attribute */
	uint8 pic1_enabled;     				/* Support picture or not */
	pic_attr pic1_attr;     				/* Picture attribute */
	uint8 char_enabled;					/* Support char or not */
	char_attr char_attr;				/* char attribute */
	uint8 char1_enabled;					/* Support char or not */
	char_attr char1_attr;				/* char attribute */
} block_attr_Start;

/******************************************************************************/
void UI_Draw_Window_Start(uint16 blockNum);
void UI_Draw_Window_Delete(uint16 blockNum);
void UI_Background_Plate_Start (void);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_START_H_ */


