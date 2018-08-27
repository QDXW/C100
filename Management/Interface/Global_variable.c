/*
 * Global_variable.c
 *
 *  Created on: 2018Äê7ÔÂ13ÈÕ
 *      Author: Administrator
 */

/******************************************************************************/
#include "Global_variable.h"

/******************************************************************************/
float temp = 0.0;
volatile uint16 QRCode_count = 0;
uint8 QRCode_Buffer[500] = {0},SignalBuffer[1024] = {0};
uint16 UI_WindowBlocks = 0,adcx = 0,xPos = 0, yPos = 0;
uint8 Check_Lock = 0,Stop_Mode = 0;
uint8 USART1_TX = 0,Existed_Data = 0,Check_motor = 0;
uint8 Touch_State_Update = 0,Bluetooth_Update = 1,InvCode_Second = 0;
uint8 Display_Time = 1,Open_time = 0,Power_Open = 0,InvCode_Down_time = 0;
uint8 Record_Display = 1,Stored_Record = 1,QRCode_received = 0,Exti_lock = 0;
uint8 key_fall_flag = 0,short_key_flag = 0,doubleClick = 0,long_key_flag = 0;
uint8 Touch_Flag = 0,Touch_Pre = 0,Read_first = 1,Cup_Count = 0,Pic_Count = 0;
uint8 NowCup_Count = 0,Power_Switch = 0,Bluetooth_switch = 0,Quick_Second = 0;
uint8 Enter_Sleep = 0,Bluetooth_Connect = 0,Quick_Down_time = 0,BLE_Remind = 0;
uint8 Action_time = 0,Interface_Reord = 0,Touch_Success = 0,MotorDriver_Ctr = 0;
uint8 QRCode_existed = 0,ScanMotorDriver_InBasePosition = 0,Display_Battery = 1;


