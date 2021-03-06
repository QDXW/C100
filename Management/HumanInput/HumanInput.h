/*
 * HumanInput.h
 *
 *  Created on: 2018��1��25��
 *      Author: Administrator
 */

#ifndef MANAGEMENT_HUMANINPUT_HUMANINPUT_H_
#define MANAGEMENT_HUMANINPUT_HUMANINPUT_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
uint8 key_open = 1;
uint8 Key_control = 1;
uint8 Interface_Key = 0;
uint8 key_state_confirm = 0;

/******************************************************************************/
extern void Key_Left(void);
extern void Key_Right(void);
extern void EXTIX_Init(void);
extern void Key_Confirm(void);
extern void HumanInput_Init(void);
extern void SYSCLKConfig_STOP(void);
extern void EXTI_Key_Confirm_Enable(void);
extern void EXTI_Key_Confirm_Disable(void);
extern void SystemManage_CheckPowerOff(void);
extern void SystemManage_Sleep_Process(void);
extern void SystemManage_EnterExitStop(void);

#endif /* MANAGEMENT_HUMANINPUT_HUMANINPUT_H_ */
