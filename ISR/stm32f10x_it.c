 /*******************************************************************************
 * File name: stm32f10x_it.c
 * Author: Hanson Liu
 * Mail: han_liu_zju@sina.com
 * Date: 2014.12 ~ Now
 ******************************************************************************/
#include "stm32f10x_it.h"

/******************************************************************************/
extern uint8 SignalSample_moveThenSample;
extern uint8 Power_Open;
extern uint8 Display_Time;
uint8 time_second = 59,Battery_Second = 0;
extern uint8 Open_time;
uint16 Power_Second = 0;
uint16 Power_Minute = 0;

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
				if(Power_Minute > 30)
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


	 if(key_fall_flag == 1)									//发生按键按下事件
	 {
		 if(!GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4))		//按键持续按下
		 {
			 if(key_holdon_ms < 1100)
			 {
				 key_holdon_ms++;
			 }
			 else 											//按键按下到2000ms就判断长按时间成立，生成长按标志
			 {
				 key_holdon_ms = 0;
				 short_key_flag=0;							//清短按键标志
				 long_key_flag = 1;							//长按键标志置位
				 key_fall_flag = 0;							//清按键按下标志
				 short_key_down = 0;
			 }
		 }
		 else 												//按键抬起
		 {
			 if(key_holdon_ms>50)							//按下时间大于50ms，生成单击标志
			 {
				 key_holdon_ms=0;
				 short_key_flag=0;
				 long_key_flag =0;
				 key_fall_flag=0;

				 //距离上次单击时间在100~500ms之间，则认为发生连击事件
				 if(keyupCnt > 50 && keyupCnt < 300)
				 {
					 doubleClick = TRUE;
					 short_key_flag=0;
				 }
				 keyUpFlag = TRUE;							//单击抬起按键后，生成按键抬起标志
			 }
			 else  											//按键持续时间小于50ms，忽略
			 {
				 key_holdon_ms = 0;
				 short_key_flag = 0;
				 long_key_flag = 0;
				 key_fall_flag = 0;
			 }
		 }
	 }

	if(keyUpFlag)											//单击抬起后，启动计数，计数到500ms
		keyupCnt++;
	if(keyupCnt > 300)
	{
		short_key_flag = 1;
		keyupCnt = 0;
		keyUpFlag = FALSE;
	}
	Key_Confirm();											//此函数决不能有延时

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

	TIM_ClearITPendingBit(TIM3, ENABLE ); 			//清除 TIM3 更新中断标志
}

/******************************************************************************/
void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)  	//检查TIM4更新中断发生与否
	{
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);  		//清除TIMx更新中断标志

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

		if(Display_Time)
		{
			Display_Time = 0;
			Bluetooth_Connection();

			if(UI_state == UI_STATE_RESULT)
			{
				if (Bluetooth_Connect)
				{
//					DisplayDriver_Fill(28,290,220,310,Interface_Back);
				}
				else
				{
					DisplayDriver_Text16_Touch(28,290,WHITE,WHITE,"Bluetooth disconnected");
				}
			}
			Display_Time = 1;
		}

		if((!MotorDriver_Ctr) && Display_Time)
		{
			if((UI_state != UI_STATE_TESTING) && (UI_state != UI_STATE_RESULT))
			{
				Display_Time = 0;
				Battery_Display();
				Display_Time = 1;
			}
			UI_Draw_Status_Bar();
		}

		if(Open_time)
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
					Open_time = 0;
					time_second = 59;
				}
			}
		}
		else
		{
			time_second = 59;
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
	EXTI_ClearITPendingBit(EXTI_Line1);		 		//清除LINE1上的中断标志位
}

/******************************************************************************/
void EXTI2_IRQHandler(void)
{
	RotaMotorDriver_PositionSensor_Int_Disable();
	EXTI_ClearITPendingBit(EXTI_Line2);			 	//清除LINE2上的中断标志位
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
		if(EXTI_GetITStatus(EXTI_Line4))	 		//确认按键
		{
			key_fall_flag = 1;						//确认按键
			EXTI_ClearITPendingBit(EXTI_Line4);		//清除LINE4上的中断标志位
			EXTI_Key_Confirm_Disable();
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line4);		 	 	//清除LINE4上的中断标志位
}

/******************************************************************************/
void EXTI9_5_IRQHandler(void)
{
	EXTI_ClearITPendingBit(EXTI_Line8);  			//清除LINE8上的中断标志位
	EXTI_ClearITPendingBit(EXTI_Line9);  			//清除LINE9上的中断标志位
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
