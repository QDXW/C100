/*
 * ScanMotorDriver_PositionSensor.h
 *
 *  Created on: 2018��3��6��
 *      Author: Administrator
 */

#ifndef MANAGEMENT_SCANMOTOR_SCANMOTORDRIVER_POSITIONSENSOR_H_
#define MANAGEMENT_SCANMOTOR_SCANMOTORDRIVER_POSITIONSENSOR_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/
#if LCD_OLD
#define POSSEN_INT_PORT      (GPIOA)
#define POSSEN_INT_PIN       (GPIO_Pin_2)
#else
#define POSSEN_INT_PORT      (GPIOA)
#define POSSEN_INT_PIN       (GPIO_Pin_12)
#endif
#define POSSEN_INT_EXTI      (EXTI_Line2)
#define POSSEN_EXTI_PORT     (GPIO_PortSourceGPIOF)
#define POSSEN_EXTI_PIN      (GPIO_PinSource2)
#define POSSEN_EXTI_CH       (EXTI2_IRQn)

#define CAN_POSSEN_INT_STATE()\
	(GPIO_ReadInputDataBit(POSSEN_INT_PORT, POSSEN_INT_PIN))

/******************************************************************************/
void ScanMotorDriver_PositionSensor_Int_Enable(void);
void ScanMotorDriver_PositionSensor_Int_Disable(void);
void ScanMotorDriver_PositionSensor_Init(void);

#endif /* MANAGEMENT_SCANMOTOR_SCANMOTORDRIVER_POSITIONSENSOR_H_ */
