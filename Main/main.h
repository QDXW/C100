/*******************************************************************************
 * File name: main.h
 * Author: Hanson Liu
 * Mail: han_liu_zju@sina.com
 * Date: 2014.12 ~ Now
 ******************************************************************************/
#ifndef MAIN_MAIN_H_
#define MAIN_MAIN_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
extern const unsigned char UI_Return[];
extern uint8 Power_Open,Power_Switch,Bluetooth_switch,Quick_Second,InvCode_Second;
extern uint8 Enter_Sleep,Interface_Reord,Quick_Down_time,InvCode_Down_time;
extern uint8 Bluetooth_Connect,Touch_State_Update,Open_time;
extern uint8 Display_Time,Bluetooth_Update;
extern uint16 adcx;
extern float temp;

/******************************************************************************/
extern void SysTick_Init(u32 ticks);
extern void Delay_ms(__IO uint32 nTime);
extern void TimingDelay_Decrement(void);
extern void Delay_SW(__IO uint32 nCount);
extern void Delay_ms_SW(__IO uint32 nCount);
extern uint8 Interface_Process(uint16* xpos,uint16* ypos);

#endif /* MAIN_MAIN_H_ */
