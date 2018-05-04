/*
 * Interface_Start.h
 *
 *  Created on: 2018��2��26��
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_START_H_
#define MANAGEMENT_INTERFACE_INTERFACE_START_H_

/******************************************************************************/
#include "Interface_main.h"

/******************************************************************************/
extern uint8 key_state;
extern uint8 Exti_lock;
extern uint8 Key_control;
uint16 UI_WindowBlocks_Start = 0;
uint16 UI_WindowBlocks_Start_font = 0;

/******************************************************************************/
typedef struct {
	uint8 rect_enabled; 				/* Support rectangular or not */
	rect_attr rect_attr;				/* Rectangular attribute */
	uint8 char_enabled;					/* Support char or not */
	char_attr char_attr;				/* char attribute */
	uint8 char_enabled2;					/* Support char or not */
	char_attr char_attr2;				/* char attribute */
} block_attr_Start;

/******************************************************************************/
extern void UI_Draw_Window_Start(uint16 blockNum);
void UI_Draw_Start_font(uint16 blockNum);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_START_H_ */


