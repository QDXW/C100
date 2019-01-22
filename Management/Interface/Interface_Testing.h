/*
 * Interface_Testing.h
 *
 *  Created on: 2018Äê2ÔÂ26ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_TESTING_H_
#define MANAGEMENT_INTERFACE_INTERFACE_TESTING_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
#define  NO_CUP        		   		(0)

/******************************************************************************/
uint8 Confirm_CUP = 0;

/******************************************************************************/
typedef struct {
	uint8 Interface_Status;
	uint8 pic_enabled;     				/* Support picture or not */
	pic_attr pic_attr;     				/* Picture attribute */
} Down_Time;

/******************************************************************************/
void Result_Display(void);
void Acquisition_StartSignal(void);
void Display_Down_Time_Plate (void);
extern uint16 Get_Start_Postion(void);
extern void Acquisition_Signal(void);
void UI_Background_Plate_Testing (void);
void Get_sampleBuffer_Start_Position(void);
void QR_Date_SignalProcess_Alg_data (void);
uint16 Get_sampleBuffer_Boundary_Value(void);
extern uint16 Get_sampleBuffer_Max_Value(void);
void Calculate_Max_Postion(uint16 First_Postion);
uint16 Judge_Max (uint16* Signal,uint16 New_Postion);
extern void UI_Draw_Window_Down_Time(uint16 blockNum);
uint16 Calculate_Postion_Up(uint16* Signal,uint16 Postion);
uint16 Check_Trend(uint16 *Signal,uint16 Postion,uint8 Flag);
uint16 Calculate_Start_Postion(uint16* Signal,uint16 Postion);
uint8 Calculate_StartPostion_Down(uint16* Signal,uint16 Postion);
uint8 Down_Time_Touch_Check(Down_Time* block,uint16* xpos,uint16* ypos);
void SignalSample_Moving_Average_Data(uint16 *Data,uint16 Length,uint16 Period);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_TESTING_H_ */
