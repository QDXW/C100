/*
 * Global_variable.h
 *
 *  Created on: 2018Äê7ÔÂ13ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_GLOBAL_VARIABLE_H_
#define MANAGEMENT_INTERFACE_GLOBAL_VARIABLE_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
extern float temp;
extern uint8 QRCode_Buffer[600],SignalBuffer[1024],data_SN[12];
extern volatile uint16 QRCode_count;
extern uint8 Stop_Mode,UI_runMode,Result_Judge,Calibration_channel;
extern uint8 USART1_TX,Existed_Data,Check_motor,Check_Lock,Font_Switch;
extern uint8 Action_time,MotorDriver_Ctr,ScanMotorDriver_InBasePosition;
extern uint8 Display_Time,Bluetooth_Update,QRCode_received,QRCode_existed;
extern uint8 Enter_Sleep,Interface_Reord,Quick_Down_time,InvCode_Down_time;
extern uint8 doubleClick,Read_first,UI_state,key_state_confirm,NowCup_Count;
extern uint8 Cup_Count,Pic_Count,Touch_Success,Record_Display,Stored_Record;
extern uint8 Bluetooth_Connect,Touch_State_Update,Open_time,Display_Battery;
extern uint8 key_fall_flag,short_key_flag,long_key_flag,Exti_lock,BLE_Remind;
extern uint8 Power_Open,Power_Switch,Bluetooth_switch,Quick_Second,InvCode_Second;

extern uint16 Power_Second,Power_Minute;
extern uint16 adcx,xPos, yPos,UI_WindowBlocks,Data_Boundary,Stop_Mode_Second;

extern uint32 Data_SN;


#endif /* MANAGEMENT_INTERFACE_GLOBAL_VARIABLE_H_ */
