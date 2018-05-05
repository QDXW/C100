/*******************************************************************************
 * File name: main.c
 * Author: Hanson Liu
 * Mail: han_liu_zju@sina.com
 * Date: 2014.12 ~ Now
 ******************************************************************************/
#include "main.h"
#include "QRCode.h"
#include "Storage_Flash.h"
#include "SystemManage_RTC.h"
#include "Version_selection.h"

/******************************************************************************/
#define SYSTICK_FREQ_72MHz  72000000
#define SYSTICK_FREQ_1MS    SYSTICK_FREQ_72MHz/1000

/******************************************************************************/
static u32 TimingDelay;					/* Timer Delay Count */
uint8 Power_Open = 0;
uint8 Display_Time = 1;
//uint16 insk[3] = {1,1,0};

/******************************************************************************/
void main(void)
{
//	uint8 cBuffer[20] = {0};
//	uint8 asd = 1;

	RCC_Configuration();				/* RCC Initialize */

	HumanInput_Init();					/* KEY HumanInput Initialize */

#if Drug_S100
	DisplayDriver_Init();				/* LCD DisplayDriver Initialize */
#endif

#if Drug_C100
	DisplayDriver_Init_Touch();			/* Touch LCD DisplayDriver Initialize */
	HumanInput_CapTS_Init();			/* HumanInput CapTS Initialize */
#endif

	SysTick_Init(SYSTICK_FREQ_1MS);		/* Initialize system tick timer */
//
//	PCF8563_Init();						/* PCF8563 Initialize */
//
//	TIM4_Int_Init();					/* TIM4 Initialize */
//
//	EXTIX_Init();						/* EXTIX Initialize */
//
//	QRCode_Init();						/* QRCode Initialize */
//
//	RotationMotor_Init();				/* RotationMotorDriver Initialize */
//
//	ScanMotorDriver_Init();				/* ScanMotorDriver Initialize */
//
	SignalSample_Sample_Init();			/* SignalSample Sample Initialize */
//
//	USB_VirtualCOM_Init();				/* USB VirtualCOM Initialize */
//
//	HostComm_Init();					/* HostComm Initialize */
//
//	Status_Init();						/* Status Initialize */
//
//	Storage_Flash_Init();				/* Storage Flash Initialize */
	GPIO_SetBits(GPIOD, GPIO_Pin_2);
	while(1)
	{

//		Exti_lock = ENABLE;
//
//		ScanMotorDriver_StartDetection();
//		Delay_ms_SW(3000);
		SystemManage_5V_Enabled();
		Delay_ms_SW(1000);
		SystemManage_5V_Disabled();
		Delay_ms(1000);
//
//		RotationMotor_SelfCheck_StepDrive();
//		ScanMotorDriver_StartDetection();
//		if(asd)
//		{
//			asdhg = Get_Start_Postion();
//			RotationMotor_Input_StepDrive(1,asdhg + 42);
//			ScanMotorDriver_Goto_CentrePosition();
//		asd = 0;
//		}
//
//		Read_Record();
//		memcpy(cBuffer,&insk[0],3);
//
//		Storage_Read(cBuffer,0x00,3);
//		memcpy(cBuffer,&insk,2);
//		Storage_Write(cBuffer, 0x00, 3);
//		Storage_Read(cBuffer,0x00,3);
//		Read_Record();
//		memcpy(&insk[1],cBuffer,1);
//		insk += 1;
//		if(insk == 101)
//			insk = 100;
//		memcpy(cBuffer,&insk,2);
//		Storage_Write(cBuffer, 0x00, 2);
//		sprintf(cBuffer,"%d",insk[1]);
//		Display_Time = 0;
//		DisplayDriver_Text16_B(4, 90, Black,White,cBuffer);
//		Display_Time = 1;
//		Delay_ms(1000);
//		SignalSample_SampleStrip();

//		Interface_Process(0);			/* User Interface */
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
void Status_Init(void)
{
#if Drug_S100
   	GPIO_SetBits(GPIOD, GPIO_Pin_2);
   	Display_Time = 0;
   	Lcd_ColorBox(0,20,128,140,White);
	DisplayDriver_DrawPic(0,50,128,40,gImage_Power_on);
	DisplayDriver_DrawPic(0,117,128,18,gImage_Power_on2);
	Lcd_ColorBox(0,0,128,20,Dark_Blue);
	DisplayDriver_DrawPic(75,1,18,18,gImage_Blutooth);
	Battery_Empty_ICO();
#endif

#if	Drug_C100
	GPIO_SetBits(GPIOD, GPIO_Pin_2);
	Display_Time = 0;

	Display_Time = 1;
	Battery_Empty_ICO();
#endif

//	RotationMotor_SelfCheck_StepDrive();
//	ScanMotorDriver_SelfCheck_StepDrive();
	Power_Open = 1;
}
