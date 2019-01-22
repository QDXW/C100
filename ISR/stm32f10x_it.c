 /*******************************************************************************
 * File name: stm32f10x_it.c
 * Author: Hanson Liu
 * Mail: han_liu_zju@sina.com
 * Date: 2014.12 ~ Now
 ******************************************************************************/
#include "stm32f10x_it.h"
#include "HumanInput_CapTS.h"

/******************************************************************************/
uint8 time_second = 60,Battery_Second = 0,Check_flag = 0,Bar_second = 0;

/******************************************************************************/
void Delay_ms_SW(__IO uint32 nCount)
{
#define SW_72MHZ_1MS_COUNT (0x27FF)
	uint32 subCount;
	for(; nCount != 0; nCount--)
	{
		subCount = SW_72MHZ_1MS_COUNT;
		for(; subCount != 0; subCount--);
	}
}

/******************************************************************************/
void NMI_Handler(void)
{
}

/******************************************************************************/
void HardFault_Handler(void)
{
	/* Go to infinite loop when Hard Fault exception occurs */
	while (1)
	{
	}
}

/******************************************************************************/
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/******************************************************************************/
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/******************************************************************************/
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/******************************************************************************/
void SVC_Handler(void)
{
}

/******************************************************************************/
void DebugMon_Handler(void)
{
}

/******************************************************************************/
void PendSV_Handler(void)
{
}

/******************************************************************************/
void SysTick_Handler(void)
{
	TimingDelay_Decrement();								/* Decrease TimingDelay */

	if(Enter_Sleep)
	{
		if(!Touch_State_Update)
		{
			Power_Second++;
			if(Power_Second > 999)
			{
				Power_Second = 0;
				Power_Minute++;
				if(Power_Minute > 29)
				{
					Power_Minute = 0;
					SystemManage_Sleep_Process();
				}
			}
		}
		else
		{
			Touch_State_Update = 0;
			Power_Second = 0;
			Power_Minute = 0;
		}
	}
	else
	{
		Power_Second = 0;
		Power_Minute = 0;
	}


	 if(key_fall_flag == 1)									//�������������¼�
	 {
		 if(!GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4))		//������������
		 {
			 if(key_holdon_ms < 1100)
			 {
				 key_holdon_ms++;
			 }
			 else 											//�������µ�2000ms���жϳ���ʱ����������ɳ�����־
			 {
				 key_holdon_ms = 0;
				 short_key_flag=0;							//��̰�����־
				 long_key_flag = 1;							//��������־��λ
				 key_fall_flag = 0;							//�尴�����±�־
				 short_key_down = 0;
			 }
		 }
		 else 												//����̧��
		 {
			 if(key_holdon_ms>50)							//����ʱ�����50ms�����ɵ�����־
			 {
				 key_holdon_ms=0;
				 short_key_flag=0;
				 long_key_flag =0;
				 key_fall_flag=0;

				 //�����ϴε���ʱ����100~500ms֮�䣬����Ϊ���������¼�
				 if(keyupCnt > 50 && keyupCnt < 300)
				 {
					 doubleClick = TRUE;
					 short_key_flag=0;
				 }
				 keyUpFlag = TRUE;							//����̧�𰴼������ɰ���̧���־
			 }
			 else  											//��������ʱ��С��50ms������
			 {
				 key_holdon_ms = 0;
				 short_key_flag = 0;
				 long_key_flag = 0;
				 key_fall_flag = 0;
			 }
		 }
	 }

	if(keyUpFlag)											//����̧�������������������500ms
		keyupCnt++;
	if(keyupCnt > 300)
	{
		short_key_flag = 1;
		keyupCnt = 0;
		keyUpFlag = FALSE;
	}
	Key_Confirm();											//�˺�������������ʱ

	EXTI_Key_Confirm_Enable();
}

/******************************************************************************/
void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		SignalSample_moveThenSample = 1;
	}

	TIM_ClearITPendingBit(TIM3, ENABLE ); 			//��� TIM3 �����жϱ�־
}

/******************************************************************************/
void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)  	//���TIM4�����жϷ������
	{
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);  		//���TIMx�����жϱ�־

		/* Quick����ɨ�赹��ʱ  */
		if(Quick_Down_time)
		{
			Quick_Second++;
			if(Quick_Second > 240)
			{
				Quick_Second = 0;
			}
		}
		else
		{
			Quick_Second = 0;
		}

		if(InvCode_Down_time)
		{
			InvCode_Second++;
			if(InvCode_Second > 240)
			{
				InvCode_Second = 0;
			}
		}
		else
		{
			InvCode_Second = 0;
		}

		/* ����������ʾ  */
		if((!MotorDriver_Ctr) && Display_Time && Power_Open)
		{
			Display_Time = 0;
			Bluetooth_Connection();
			Display_Time = 1;
		}

		if((BLE_Remind) && Display_Time && Power_Open)
		{
			Display_Time = 0;
			/* ��������  */
			if(Printer_isConnected())
			{
				DisplayDriver_Fill(28,290,220,310,Interface_Back);
			}
			else
			{
				switch(Font_Switch)
				{
				case DISPLAY_FONT_ENGLISH:
					DisplayDriver_Text_Flex(16,24,294,WHITE,WHITE,"Bluetooth not connected!");
					break;

				case DISPLAY_FONT_CHINESE:
					DisplayDriver_Text_Flex(16,80,294,WHITE,WHITE,"����δ����!");
					break;

				default:
					break;
				}
			}
			Display_Time = 1;
		}

		/* ��ص���ͼ����ʾ  */
		if((!MotorDriver_Ctr) && Display_Time && Power_Open)
		{
			if((UI_state == UI_STATE_TESTING) || (UI_state == UI_STATE_RESULT) || (UI_state == UI_STATE_IN_CALIBRATION_PROCESS))
			{

			}
			else
			{
				Display_Time = 0;
				Battery_Display();
				Display_Time = 1;
			}

			Bar_second++;
			if(Bar_second > 10)
				UI_Draw_Status_Bar();
			else
				Bar_second = 0;
		}

		/* ��׼���Խ��浹��ʱ  */
		if((Open_time) && Display_Time)
		{
			time_second--;
			Display_Down_Time_second();
			if(time_second < 1)
			{
				time_second = 60;
				Action_time--;
				Display_Down_Time_Msec();
				if(Action_time < 1)
				{
					Action_time = 0;
					Open_time = 0;
					time_second = 60;
				}
			}
		}
		else
		{
			time_second = 60;
		}

		if(Check_motor)
		{
			Display_Time = 0;
			if(1 == Check_Lock)
			{
				DisplayDriver_Fill(0,0,240,320,Interface_Back);
				switch(Font_Switch)
				{
				case DISPLAY_FONT_ENGLISH:
					DisplayDriver_Text_Flex (16,28,160,RED,RED,"Error: 001 Screw motor!");
					break;

				case DISPLAY_FONT_CHINESE:
					DisplayDriver_Text_Flex(16,28,160,BLACK,Interface_Bar,"����:001   ˿�˵������");
					break;

				default:
					break;
				}

				Check_flag = 1;
			}

			if(2 == Check_Lock)
			{
				if(!Check_flag)
				{
					DisplayDriver_Fill(0,0,240,320,Interface_Back);
				}
				switch(Font_Switch)
				{
				case DISPLAY_FONT_ENGLISH:
					DisplayDriver_Text_Flex (16,28,180,RED,RED,"Error: 002 Rotating motor!");
					break;

				case DISPLAY_FONT_CHINESE:
					DisplayDriver_Text_Flex(16,28,180,BLACK,Interface_Bar,"����:002  ת���������");
					break;

				default:
					break;
				}

			}

			Display_Time = 1;
			Check_motor = 0;
		}
		else
		{
			Check_motor = 0;
			if(0 == Check_Lock)
			{
				Check_flag = 0;
			}
		}

		if(Stop_Mode)
		{
			Stop_Mode_Second++;
			if(Stop_Mode_Second > 599)
			{
				GPIO_ResetBits(GPIOB, GPIO_Pin_3);
			}
		}
		else
		{
			Stop_Mode_Second = 0;
		}
	}
}

/******************************************************************************/
void TIM7_IRQHandler(void)
{

}

/******************************************************************************/
void EXTI0_IRQHandler(void)
{

}

/******************************************************************************/
void EXTI1_IRQHandler(void)
{
	ScanMotorDriver_InBasePosition = 1;
	ScanMotorDriver_PositionSensor_Int_Disable();
	EXTI_ClearITPendingBit(EXTI_Line1);		 		//���LINE1�ϵ��жϱ�־λ
}

/******************************************************************************/
void EXTI2_IRQHandler(void)
{
	RotaMotorDriver_PositionSensor_Int_Disable();
	EXTI_ClearITPendingBit(EXTI_Line2);			 	//���LINE2�ϵ��жϱ�־λ
}

/******************************************************************************/
void EXTI3_IRQHandler(void)
{
}

/******************************************************************************/
void EXTI4_IRQHandler(void)
{
	if(Exti_lock)
	{
		if(EXTI_GetITStatus(EXTI_Line4))	 		//ȷ�ϰ���
		{
			key_fall_flag = 1;						//ȷ�ϰ���
			EXTI_ClearITPendingBit(EXTI_Line4);		//���LINE4�ϵ��жϱ�־λ
			EXTI_Key_Confirm_Disable();
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line4);		 	 	//���LINE4�ϵ��жϱ�־λ
}

/******************************************************************************/
void EXTI9_5_IRQHandler(void)
{
	EXTI_ClearITPendingBit(EXTI_Line8);  			//���LINE8�ϵ��жϱ�־λ
	EXTI_ClearITPendingBit(EXTI_Line9);  			//���LINE9�ϵ��жϱ�־λ
}

/******************************************************************************/
void EXTI15_10_IRQHandler(void)
{
	/* CapTS interrupt service routine */
	if(EXTI_GetITStatus(CAPTS_INT_EXTI) != RESET)
	{
		Delay_SW(0XFF);
		if(CapTS_INT_STATE() == 0)
		{
			TPR_Structure.TouchSta |= TP_COORD_UD;
			Touch_State_Update = 1;
		}
		/* Charger insert interrupt
		 * Do nothing because STOP mode automatically exits by interrupt */

		EXTI_ClearITPendingBit(CAPTS_INT_EXTI);
	}
}

/******************************************************************************/
void PVD_IRQHandler(void)
{
}

/******************************************************************************/
void Display_Down_Time_second (void)
{
	char tbuf[4] = {0};
	sprintf((char*)tbuf,"%02d",time_second);
	Display_Time = 0;
	DisplayDriver_Text16_Back(118,132,WHITE,LIGHTBLUE,tbuf);
	Display_Time = 1;
}

/******************************************************************************/
void Display_Down_Time_Msec (void)
{
	char tbuf[4] = {0};
	sprintf((char*)tbuf,"%02d:",Action_time);
	Display_Time = 0;
	DisplayDriver_Text16_Back(94,132,WHITE,LIGHTBLUE,tbuf);
	Display_Time = 1;
}
