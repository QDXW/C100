/*
 * Interface_Calibration.h
 *
 *  Created on: 2018Äê8ÔÂ31ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_CALIBRATION_H_
#define MANAGEMENT_INTERFACE_INTERFACE_CALIBRATION_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
typedef struct {
	uint8 Interface_Status;
	uint8 pic_enabled;     				/* Support picture or not */
	pic_attr pic_attr;					/* picture attribute */
	uint8 pic1_enabled;     				/* Support picture or not */
	pic_attr pic1_attr;					/* picture attribute */
} block_attr_Calibration;

/******************************************************************************/
void UI_Background_Plate_Calibration(void);
void UI_Draw_Window_Calibration(uint16 blockNum);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_CALIBRATION_H_ */
