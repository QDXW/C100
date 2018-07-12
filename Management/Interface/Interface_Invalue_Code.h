/*
 * Interface_Invalue_Code.h
 *
 *  Created on: 2018Äê7ÔÂ11ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_INVALUE_CODE_H_
#define MANAGEMENT_INTERFACE_INTERFACE_INVALUE_CODE_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
typedef struct {
	uint8 Interface_Status;
	uint8 pic_enabled;     				/* Support picture or not */
	pic_attr pic_attr;					/* picture attribute */
	uint8 char_enabled;					/* Support char or not */
	char_attr char_attr;				/* char attribute */
	uint8 char2_enabled;					/* Support char or not */
	char_attr char2_attr;				/* char attribute */
} block_attr_InvCode;

/******************************************************************************/
void UI_Background_Plate_InvCode (void);
void UI_Draw_Window_InvCode(uint16 blockNum);
void Invalid_Touch_Check(block_attr_InvCode* block,uint16* xpos,uint16* ypos);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_INVALUE_CODE_H_ */
