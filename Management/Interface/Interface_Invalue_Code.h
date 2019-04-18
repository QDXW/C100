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
	uint8 pic1_enabled;     				/* Support picture or not */
	pic_attr pic1_attr;					/* picture attribute */
} block_attr_InvCode;

/******************************************************************************/
void UI_Background_Plate_InvCode (void);
void UI_Draw_Window_InvCode(uint16 blockNum);
void Invalid_Touch_Check(block_attr_InvCode* block,uint16* xpos,uint16* ypos);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_INVALUE_CODE_H_ */
