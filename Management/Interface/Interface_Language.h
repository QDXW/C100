/*
 * Interface_Language.h
 *
 *  Created on: 2018Äê11ÔÂ22ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_LANGUAGE_H_
#define MANAGEMENT_INTERFACE_INTERFACE_LANGUAGE_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
typedef struct {
	uint8 Interface_Status;
	uint8 pic_enabled;     				/* Support picture or not */
	pic_attr pic_attr;     				/* Picture attribute */
	uint8 char_enabled;					/* Support char or not */
	char_attr char_attr;				/* char attribute */
	uint8 Language_select;
} block_attr_Language;

/******************************************************************************/
typedef enum {
	LANGUAGE_CHAINESE_OFF = 1,
	LANGUAGE_CHAINESE_ON,
	LANGUAGE_ENGLISH_OFF,
	LANGUAGE_ENGLISH_ON,
	LANGUAGE_GERMAN_OFF,
	LANGUAGE_GERMAN_ON,

	LANGUAGE_SELECT_MAX_NUM,
} LANGUAGE_SELECT;

/******************************************************************************/
void UI_Draw_Window_Language(uint16 blockNum);
uint8 Touch_Language (uint16* xpos,uint16* ypos);
void UI_Draw_Block_Language(block_attr_Language* block);
void Touch_Language_Check(block_attr_Language* block,uint16* xpos,uint16* ypos);
void Update_Language_Interface (block_attr_Language* block,uint16* xpos,uint16* ypos);


#endif /* MANAGEMENT_INTERFACE_INTERFACE_LANGUAGE_H_ */
