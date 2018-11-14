/*
 * HumanInput.c
 *
 *  Created on: 2018��1��25��
 *      Author: Administrator
 ******************************************************************************/
#include "HumanInput.h"

/******************************************************************************/
uint8 LED = 0,HSEStartUpStatusPwr = 0;

/*******************************************************************************
	��������HumanInput_Init
	��  ��: ��
	��  ��: ��
	����˵����ʹ�ܰ�����ӦGPIO�ܽ�
	��ʼ������Ӳ���豸��δ�����жϡ�
*******************************************************************************/
void HumanInput_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	//��ʼ�� WK_UP-->GPIOA.0	  ��������
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		//PA0���ó����룬Ĭ������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);				//��ʼ��GPIOB.0
}

/*******************************************************************************
	��������EXTIX_Init
	��  ��: ��
	��  ��: ��
	����˵����ʹ�ܰ�����Ӧ�ⲿ�ж�    ����
	��ʼ������Ӳ���豸��δ�����жϡ�
*******************************************************************************/
void EXTIX_Init(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	//GPIOB.4	  �ж����Լ��жϳ�ʼ������ �����ش���
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource4);

	EXTI_InitStructure.EXTI_Line = EXTI_Line4;  				//�м�ȷ�ϰ�ť
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;			//�����ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//ʹ���ⲿ�ж�ͨ��
	NVIC_Init(&NVIC_InitStructure);
}

/******************************************************************************/
void EXTI_Key_Confirm_Disable(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;

	//GPIOB.4	  �ж����Լ��жϳ�ʼ������ �����ش���
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource4);

	EXTI_InitStructure.EXTI_Line = EXTI_Line4;  				//�м�ȷ�ϰ�ť
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = DISABLE;
	EXTI_Init(&EXTI_InitStructure);
}

/******************************************************************************/
void EXTI_Key_Confirm_Enable(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	//GPIOB.4	  �ж����Լ��жϳ�ʼ������ �����ش���
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource4);

	EXTI_InitStructure.EXTI_Line = EXTI_Line4;  				//�м�ȷ�ϰ�ť
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;			//�����ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//ʹ���ⲿ�ж�ͨ��
	NVIC_Init(&NVIC_InitStructure);
}

/*******************************************************************************
	��������KeyX_Work
	��  ��: ��
	��  ��: ��
	����˵������Ӧ��������
	��ʼ������Ӳ���豸��δ�����жϡ�
*******************************************************************************/
void Key_Confirm(void)
{
	if(Power_Open && long_key_flag )
	{
		SystemManage_CheckPowerOff();
	}

	if(!Power_Open && Exti_lock && long_key_flag)
	{
		SystemManage_CheckPowerOff();
	}

	if(short_key_flag)
	{
		if(Stop_Mode)
		{
			SYSCLKConfig_STOP();
			Stop_Mode = 0;
		}
		else
		{
			key_state_confirm = ENABLE;

		}
		short_key_flag = 0;
		Stop_Mode_Second = 0;
	}
}

/******************************************************************************/
void SystemManage_Sleep_Process(void)
{
	Stop_Mode = 1;

	/* �ر�5V��Դ  */
	SystemManage_5V_Disabled();

	/* �رձ���  */
	GPIO_ResetBits(GPIOD,GPIO_Pin_2);

	/* �رմ���Ч��  */
	HumanInput_CapTS_Int(DISABLE);

	Exti_lock = ENABLE;
}

/******************************************************************************/
void SystemManage_EnterExitStop(void)
{
    /* Request to enter STOP mode with regulator in low power mode*/
    PWR_EnterSTOPMode(PWR_Regulator_LowPower, PWR_STOPEntry_WFI);

    /* At this stage the system has resumed from STOP mode,
     * like external interrupt, internal timer interrupt, etc */

    /* Configures system clock after wake-up from STOP: enable HSE, PLL and
     * select PLL as system clock source
     *  (HSE and PLL are disabled in STOP mode) */
    SYSCLKConfig_STOP();
}

/******************************************************************************/
void SYSCLKConfig_STOP(void)
{
	Power_Second = 0,Power_Minute = 0;
	GPIO_SetBits(GPIOD,GPIO_Pin_2);
	Delay_ms_SW(150);
	HumanInput_CapTS_Int(ENABLE);
	TPR_Structure.TouchSta = 0;
	key_state_confirm = 0;
}

/******************************************************************************/
void SystemManage_CheckPowerOff(void)
{
	QRCode_Trigger_Disabled();
	SystemManage_5V_Disabled();
	RotaMotorDriver_Control(MOTOR_DISABLED);
	ScanMotorDriver_Control(MOTOR_DISABLED);
	GPIO_ResetBits(GPIOE, GPIO_Pin_5);
	GPIO_ResetBits(GPIOB, GPIO_Pin_3);
	GPIO_ResetBits(GPIOD, GPIO_Pin_2);
	while(1);
}
