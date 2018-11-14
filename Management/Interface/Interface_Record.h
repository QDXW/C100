/*
 * Interface_Record.h
 *
 *  Created on: 2018Äê2ÔÂ24ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_RECORD_H_
#define MANAGEMENT_INTERFACE_INTERFACE_RECORD_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
extern uint8 Exti_lock;
extern uint8 Interface_Key;

/******************************************************************************/
typedef struct {
	uint8 Interface_Status;
	uint8 pic_enabled;     				/* Support picture or not */
	pic_attr pic_attr;					/* picture attribute */
	uint8 char_enabled;					/* Support char or not */
	char_attr char_attr;				/* char attribute */
	uint8 char1_enabled;					/* Support char or not */
	char_attr char1_attr;				/* char attribute */
} block_attr_Record;

/******************************************************************************/
void Data_Changer(void);
void Page_Display(void);
void UI_Language_Plate_Record (void);
void UI_Background_Plate_Record (void);
void UI_Background_Plate_Record_NO (void);
void UI_Draw_Window_Record(uint16 blockNum);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_RECORD_H_ */
