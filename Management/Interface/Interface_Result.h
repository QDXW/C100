/*
 * Interface_Result.h
 *
 *  Created on: 2018Äê2ÔÂ26ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_RESULT_H_
#define MANAGEMENT_INTERFACE_INTERFACE_RESULT_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
typedef struct {
	uint8 Interface_Status;
	uint8 pic_enabled;     				/* Support picture or not */
	pic_attr pic_attr;					/* picture attribute */
	uint8 pic1_enabled;     				/* Support picture or not */
	pic_attr pic1_attr;					/* picture attribute */
	uint8 char_enabled;					/* Support char or not */
	char_attr char_attr;				/* char attribute */
	uint8 char2_enabled;					/* Support char or not */
	char_attr char2_attr;				/* char attribute */
} block_attr_Result;

/******************************************************************************/
void UI_Draw_Window_Result(uint16 blockNum);
void UI_Background_Plate_Result (void);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_RESULT_H_ */
