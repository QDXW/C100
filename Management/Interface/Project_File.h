/*
 * Project_File.h
 *
 *  Created on: 2018��5��19��
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_PROJECT_FILE_H_
#define MANAGEMENT_INTERFACE_PROJECT_FILE_H_

/******************************************************************************/
#define LCD_OLD   1
#define UI_STATE_RERUN (1u)

/******************************************************************************/
#include "stm32f10x.h"
#include "main.h"
#include "string.h"
#include "stdarg.h"
#include "comDef.h"
#include "QRCode.h"
#include "Common.h"
#include "Printer.h"
#include "HostComm.h"
#include "stmflash.h"
#include "hw_config.h"
#include "Comm_FIFO.h"
#include "RotationMotor.h"
#include "Storage_Flash.h"
#include "Signalprocess.h"
#include "stm32f10x_i2c.h"
#include "Interface_main.h"
#include "ScanMotorDriver.h"
#include "Global_variable.h"
#include "SystemManage_RTC.h"
#include "HumanInput_CapTS.h"
#include "DisplayDriver_API.h"
#include "DisplayDriver_touch.h"
#include "SignalProcess_Sample.h"
#include "ScanMotorDriver_PositionSensor.h"
#include "RotationMotorDriver_PositionSensor.h"

/******************************************************************************/
extern const unsigned char UI_Return[];
extern const unsigned char Confirmation[];
extern const unsigned char Print[];
extern const unsigned char Delete[];

#endif /* MANAGEMENT_INTERFACE_PROJECT_FILE_H_ */
