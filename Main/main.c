 /*******************************************************************************
 * File name: main.c
 * Author: Hanson Liu
 * Mail: han_liu_zju@sina.com
 * Date: 2014.12 ~ Now
 ******************************************************************************/
#include "main.h"

/******************************************************************************/
#define SYSTICK_FREQ_72MHz  72000000
#define SYSTICK_FREQ_1MS    SYSTICK_FREQ_72MHz/1000

/******************************************************************************/
static u32 TimingDelay;					/* Timer Delay Count */
//uint16 insk[4] = {0,0,0,65535};
//uint8 MBuffer[20] = {0};

/******************************************************************************/
void main(void)
{
	uint16 asd = 1;

	RCC_Configuration();				/* RCC Initialize */

	HumanInput_Init();					/* KEY HumanInput Initialize */

	DisplayDriver_Init_Touch();			/* Touch LCD DisplayDriver Initialize */

	HumanInput_CapTS_Init();			/* HumanInput CapTS Initialize */

	SysTick_Init(SYSTICK_FREQ_1MS);		/* Initialize system tick timer */

	Printer_BLE_Init();					/* Printer BLE Initialize */

	PCF8563_Init();						/* PCF8563 Initialize */

	EXTIX_Init();						/* EXTIX Initialize */

	Adc_Init();							/* ADC Initialize */

	QRCode_Init();						/* QRCode Initialize */

	ScanMotorDriver_Init();				/* ScanMotorDriver Initialize */

	RotationMotor_Init();				/* RotationMotorDriver Initialize */

	SignalSample_Sample_Init();			/* SignalSample Sample Initialize */

	HostComm_Init();					/* HostComm Initialize */

	TIM4_Int_Init(9999,7199);			/* 10Khz的计数频率，计数到10000为1s */

	Storage_Flash_Init();				/* Storage Flash Initialize */

	Status_Init();						/* Status Initialize */

	while(1)
	{
//		Debug_Function();

		HumanInput_TouchScreen_Process();

		HostComm_Process();

		Interface_Process(&xPos,&yPos);			/* User Interface */

	}
}

/******************************************************************************/
void SysTick_Init(u32 ticks)
{
	if(SysTick_Config(ticks))
	{
		while (1);						/* Capture error */
	}
}

/*******************************************************************************
* Timer Delay
*******************************************************************************/
void Delay_ms(u32 nTime)
{
	TimingDelay = nTime;

	while(TimingDelay != 0);
}

/******************************************************************************/
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{
		TimingDelay--;
	}
}

/******************************************************************************/
void Debug_Function(void)
{
//	memcpy(MBuffer,insk,8);
//
//	Storage_Write(MBuffer, 0x00, 8);
//
//	Storage_Read(MBuffer,0x00,8);
//	memcpy(insk,MBuffer,8);
//	sprintf(MBuffer,"%02d %02d %02d %02d",insk[0],insk[1],insk[2],insk[3]);
//	Display_Time = 0;
//	DisplayDriver_Text16_Touch(60, 43, BLACK,WHITE,MBuffer);
//	Display_Time = 1;
//
//	SystemManage_5V_Enabled();
//	SignalSample_Sample_EnterCriticalArea();
//	RotationMotor_Input_StepDrive(Foreward_Rotation,Get_Start_Postion());
//	Delay_ms_SW(2000);
//	SignalSample_SampleStrip();
//	memset(SignalBuffer,0,500);
//	memcpy(SignalBuffer, &SignalProcess_sampleBuffer[0], SignalSample_count<< 1);
//	HostComm_Cmd_Send_RawData(SignalSample_count << 1, SignalBuffer);
}
