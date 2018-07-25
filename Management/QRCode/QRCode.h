/*
 * QRCode.h
 *
 *  Created on: 2018Äê3ÔÂ7ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_QRCODE_QRCODE_H_
#define MANAGEMENT_QRCODE_QRCODE_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
#define QRCODE_TEST_NAME_MAX         (8)
#define QRCODE_BUFFER_SIZE           (600)

#if LCD_OLD
/******************************************************************************/
#define QRCODE_TRIG_PORT                (GPIOA)
#define QRCODE_TRIG_PIN                 (GPIO_Pin_3)
#else
#define QRCODE_TRIG_PORT                (GPIOD)
#define QRCODE_TRIG_PIN                 (GPIO_Pin_3)
#endif

#define QRCODE_TX_PORT      		 (GPIOC)
#define QRCODE_TX_PIN         		 (GPIO_Pin_10)

#define QRCODE_RX_PORT     			 (GPIOC)
#define QRCODE_RX_PIN        		 (GPIO_Pin_11)

#define QRCODE_USART          		 (USART3)
#define QRCODE_USART_IRQN          	 (USART3_IRQn)

/******************************************************************************/
typedef struct {
    uint16 crc;
    uint8 name[20];
    uint8 SN[10];
    uint8 time;
    uint8 midC;
    uint8 distC_T;
    uint8 distC_Base1;
    uint8 distC_Base2;
    uint8 distC_Base3;
    uint8 distC_Base4;
    uint8 stripNum;
    uint16 searchHalfRadius_C;
    uint16 searchHalfRadius_T;
    uint16 areaC_HalfRadius;
    uint16 areaT_HalfRadius;
    uint16 winSize;
    uint8 limitEnabled;
    uint8 value;
    uint16 C_stepSize;
    uint16 C_magnitude;
    uint16 C_MIN;
    uint16 reserved;
} QRCODE_HEAD_STRUCT;

/******************************************************************************/
typedef struct {
    uint8 TName[QRCODE_TEST_NAME_MAX];
    uint8 Switch_Bool;
    float threshold1;
    float threshold2;
    float threshold3;
} QRCODE_SINGLE_LINE;

/******************************************************************************/
typedef struct {
    QRCODE_HEAD_STRUCT head;
    QRCODE_SINGLE_LINE ch_data[17];
} QRCODE_STRUCT;

/******************************************************************************/
extern QRCODE_STRUCT QR_Date;
extern QRCODE_STRUCT QR_Date_Analyze;

/******************************************************************************/
extern void Clear_Data(void);
extern void QRCode_Init(void);
extern void QRCode_Restart(void);
extern void QRCode_GPIO_Init(void);
extern void QRCode_Uart_Init(void);
extern uint8 QRCode_Identify(void);
extern void QRCode_Uart_Config(void);
extern void QRCode_Uart_GPIO_Init(void);
extern void QRCode_Trigger_Enabled(void);
extern void QRCode_Trigger_Disabled(void);
extern void QRCode_Uart_NVIC_Configuration(void);

#endif /* MANAGEMENT_QRCODE_QRCODE_H_ */
