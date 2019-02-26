/*
 * Project_File.h
 *
 *  Created on: 2018年5月19日
 *      Author: Administrator
 */
/******************************************************************************/
#ifndef MANAGEMENT_INTERFACE_PROJECT_FILE_H_
#define MANAGEMENT_INTERFACE_PROJECT_FILE_H_

/******************************************************************************/
#define UI_STATE_RERUN 			(1u)
#define REALY_ICO_C100			1			/* 睿丽科技标识  */
#define PROTZEK_ICO_C100 		0			/* 德国标识  */
#define HENGRUI_ICO_C100		0			/* 中泰科技标识   */

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
#include "DisplayDriver_touch.h"
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
#include "SignalProcess_Sample.h"
#include "ScanMotorDriver_PositionSensor.h"
#include "RotationMotorDriver_PositionSensor.h"
#include "DisplayDriver_FontLib.h"

/******************************************************************************/
extern const unsigned char UI_Return[];
extern const unsigned char Confirmation[];
extern const unsigned char Confirm_China[];
extern const unsigned char Print[];
extern const unsigned char Delete[];
extern const unsigned char Delete_China[];

#if PROTZEK_ICO_C100
extern const unsigned char PROTZEK_ICO[];
#endif

#if HENGRUI_ICO_C100
extern const unsigned char HENGRUI_ICO[];
#endif

#endif /* MANAGEMENT_INTERFACE_PROJECT_FILE_H_ */
