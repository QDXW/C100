/*
 * Interface_System_Time.h
 *
 *  Created on: 2018Äê6ÔÂ19ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_SYSTEM_TIME_H_
#define MANAGEMENT_INTERFACE_INTERFACE_SYSTEM_TIME_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
uint8 Year[2]={0};
uint8 Month[1]={0};
uint8 Day[1]={0};
uint8 Hour[1]={0};
uint8 Minute[1]={0};
uint8 Sec[1]={0};

/******************************************************************************/
typedef struct {
	uint8 Interface_Status;
	uint8 pic_enabled;     				/* Support picture or not */
	pic_attr pic_attr;					/* picture attribute */
	uint8 pic1_enabled;     				/* Support picture or not */
	pic_attr pic1_attr;					/* picture attribute */
} block_attr_SetTime;

/******************************************************************************/
typedef struct
{
	uint8 invalue;
	uint16 year;
	uint8 month;
	uint8 day;
	uint8 hour;
	uint8 min;
	uint8 sec;
} SET_DATA;

/******************************************************************************/
void UI_Draw_Window_System_Time(uint16 blockNum);
void UI_Background_Plate_SetTime(void);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_SYSTEM_TIME_H_ */
