/*
 * Language_Display.c
 *
 *  Created on: 2019年3月29日
 *      Author: Administrator
 */
/******************************************************************************/
#include "Language_Display.h"

/******************************************************************************/
void UI_Language_Plate_Main (void)
{
	Display_Time = 0;
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		DisplayDriver_Text_Flex(16,28,138,WHITE,Interface_Back,"Standard");
		DisplayDriver_Text_Flex(16,160,138,WHITE,Interface_Back,"Quick");
		DisplayDriver_Text_Flex(16,36,297,WHITE,Interface_Back,"Record");
		DisplayDriver_Text_Flex(16,148,297,WHITE,Interface_Back,"Settings");
		break;

	case DISPLAY_FONT_CHINESE:
		DisplayDriver_Text_Flex(16,28,138,WHITE,Interface_Back,"标准检测");
		DisplayDriver_Text_Flex(16,148,138,WHITE,Interface_Back,"快速检测");
		DisplayDriver_Text_Flex(16,44,297,WHITE,Interface_Back,"记录");
		DisplayDriver_Text_Flex(16,164,297,WHITE,Interface_Back,"设置");
		break;

	case DISPLAY_FONT_GERMAN:
		DisplayDriver_Text_Flex(16,28,138,WHITE,Interface_Back,"Standard");
		DisplayDriver_Text_Flex(16,152,138,WHITE,Interface_Back,"Schnell");
		DisplayDriver_Text_Flex(16,28,297,WHITE,Interface_Back,"Speicher");
		DisplayDriver_Text_Flex(16,168,297,WHITE,Interface_Back,"Set");
		break;

	default:
		break;
	}
	Display_Time = 1;
}

/******************************************************************************/
void UI_Language_Plate_Quick (void)
{
	Display_Time = 0;
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		DisplayDriver_Text_Flex(16,56,169,BLACK,WHITE,"Scan the QR code");
		break;

	case DISPLAY_FONT_CHINESE:
		DisplayDriver_Text_Flex(24,60,160,Interface_Back,WHITE,"扫描二维码");
		break;

	case DISPLAY_FONT_GERMAN:
		DisplayDriver_Text_Flex(16,28,169,BLACK,WHITE,"Scannen Sie den QR Code");
		break;

	default:
		break;
	}
	Display_Time = 1;
}

/******************************************************************************/
void UI_Language_Plate_Start (void)
{
	Display_Time = 0;
	DisplayDriver_Text_Flex(16,60,64,BLACK,Interface_Back,QR_Date.head.name);
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		DisplayDriver_Text_Flex(16,14,64,BLACK,Interface_Back,"Name:");
		DisplayDriver_Text_Flex(16,14,84,BLACK,Interface_Back,"  SN:");
		break;

	case DISPLAY_FONT_CHINESE:
		DisplayDriver_Text_Flex(16,14,64,BLACK,Interface_Back,"名称:");
		DisplayDriver_Text_Flex(16,14,84,BLACK,Interface_Back,"批号:");
		break;

	case DISPLAY_FONT_GERMAN:
		DisplayDriver_Text_Flex(16,14,64,BLACK,Interface_Back,"Name:");
		DisplayDriver_Text_Flex(16,14,84,BLACK,Interface_Back," LOT:");
		break;

	default:
		break;
	}
	Display_Time = 1;
}

/******************************************************************************/
void UI_Language_Plate_Cup(void)
{
	Display_Time = 0;
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		DisplayDriver_Text_Flex(16,80,164,BLACK,WHITE,"Insert Cup");
		break;

	case DISPLAY_FONT_CHINESE:
		DisplayDriver_Text_Flex(24,72,155,Interface_Back,WHITE,"插入杯子");
		break;

	case DISPLAY_FONT_GERMAN:
		DisplayDriver_Text_Flex(16,72,164,BLACK,WHITE,"Einf$gen cup");
		break;

	default:
		break;
	}
	Display_Time = 1;
}

/******************************************************************************/
void UI_Language_Plate_Result (void)
{
	Display_Time = 0;
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		DisplayDriver_Text_Flex(16,14,82,BLACK,WHITE,"Item");
		DisplayDriver_Text_Flex(16,65,82,BLACK,WHITE,"Result");
		DisplayDriver_Text_Flex(16,124,82,BLACK,WHITE,"Item");
		DisplayDriver_Text_Flex(16,178,82,BLACK,WHITE,"Result");
		break;

	case DISPLAY_FONT_CHINESE:
		DisplayDriver_Text_Flex(16,14,82,BLACK,WHITE,"名称");
		DisplayDriver_Text_Flex(16,65,82,BLACK,WHITE,"结果");
		DisplayDriver_Text_Flex(16,124,82,BLACK,WHITE,"名称");
		DisplayDriver_Text_Flex(16,178,82,BLACK,WHITE,"结果");
		break;

	case DISPLAY_FONT_GERMAN:
		DisplayDriver_Text_Flex(16,14,82,BLACK,WHITE,"Anal");
		DisplayDriver_Text_Flex(16,65,82,BLACK,WHITE,"Ergebn");
		DisplayDriver_Text_Flex(16,124,82,BLACK,WHITE,"Anal");
		DisplayDriver_Text_Flex(16,178,82,BLACK,WHITE,"Ergebn");
		break;

	default:
		break;
	}
	Display_Time = 1;
}

/******************************************************************************/
void UI_Language_Plate_InvCode (void)
{
	Display_Time = 0;
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		DisplayDriver_Text_Flex(16,60,159,RED,WHITE,"Invalid QR Code");
		break;

	case DISPLAY_FONT_CHINESE:
		DisplayDriver_Text_Flex(24,60,159,RED,WHITE,"无效二维码");
		break;

	case DISPLAY_FONT_GERMAN:
		DisplayDriver_Text_Flex(16,48,159,RED,WHITE,"Ung$ltiger QR Code");
		break;

	default:
		break;
	}
	Display_Time = 1;
}

/******************************************************************************/
void UI_Background_Plate_Testing (void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(36,130,205,150,WHITE);

	switch(Font_Switch)
		{
		case DISPLAY_FONT_ENGLISH:
			DisplayDriver_Text_Flex(16,80,160,WHITE,WHITE,"testing...");
		break;

	case DISPLAY_FONT_CHINESE:
			DisplayDriver_Text_Flex(16,76,160,WHITE,WHITE,"正在测试...");
			break;

	case DISPLAY_FONT_GERMAN:
		DisplayDriver_Text_Flex(16,68,160,WHITE,WHITE,"Test l]uft...");
		break;

		default:
			break;
		}
	Display_Time = 1;
}

/******************************************************************************/
void UI_Background_Battery_Low_Display (void)
{
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		DisplayDriver_Text16_Touch(24, 80, RED,WHITE,"Battery Low!");
		break;

	case DISPLAY_FONT_CHINESE:
		DisplayDriver_Text_Flex(24,72, 155, RED,WHITE,"电量过低");
		break;

	case DISPLAY_FONT_GERMAN:
		DisplayDriver_Text_Flex(16,56,160,WHITE,WHITE,"Batterie schwach");
		break;

	default:
		break;
	}
}

/******************************************************************************/
void UI_Language_Plate_Setting(void)
{
	Display_Time = 0;
	DisplayDriver_DrawStraight_Line(0,121,240,121,CYAN_Line);
	DisplayDriver_DrawStraight_Line(0,122,240,122,Thint_Line);
	DisplayDriver_DrawStraight_Line(0,221,240,221,CYAN_Line);
	DisplayDriver_DrawStraight_Line(0,222,240,222,Thint_Line);

	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		if(Bluetooth_switch)
		{
			DisplayDriver_Text_Flex(16,120,104,WHITE,WHITE,"About Machine");
			DisplayDriver_Text_Flex(16,21,204,WHITE,WHITE,"System Time");
			DisplayDriver_Text_Flex(16,167,204,WHITE,WHITE,"ON");
			DisplayDriver_Text_Flex(16,28,300,WHITE,WHITE,"Language");
		}
		else
		{
			DisplayDriver_Text_Flex(16,120,104,WHITE,WHITE,"About Machine");
			DisplayDriver_Text_Flex(16,21,204,WHITE,WHITE,"System Time");
			DisplayDriver_Text_Flex(16,163,204,WHITE,WHITE,"OFF");
			DisplayDriver_Text_Flex(16,28,300,WHITE,WHITE,"Language");
		}
		break;

	case DISPLAY_FONT_CHINESE:
		if(Bluetooth_switch)
		{
			DisplayDriver_Text_Flex(16,143,104,WHITE,WHITE,"关于本机");
			DisplayDriver_Text_Flex(16,33,204,WHITE,WHITE,"系统时间");
			DisplayDriver_Text_Flex(16,159,204,WHITE,WHITE,"打开");
			DisplayDriver_Text_Flex(16,49,300,WHITE,WHITE,"语言");
		}
		else
		{
			DisplayDriver_Text_Flex(16,143,104,WHITE,WHITE,"关于本机");
			DisplayDriver_Text_Flex(16,33,204,WHITE,WHITE,"系统时间");
			DisplayDriver_Text_Flex(16,159,204,WHITE,WHITE,"关闭");
			DisplayDriver_Text_Flex(16,49,300,WHITE,WHITE,"语言");
		}
		break;

	case DISPLAY_FONT_GERMAN:
		if(Bluetooth_switch)
		{
			DisplayDriver_Text_Flex(16,156,104,WHITE,WHITE,"$ber");
			DisplayDriver_Text_Flex(16,49,204,WHITE,WHITE,"Zeit");
			DisplayDriver_Text_Flex(16,167,204,WHITE,WHITE,"An");
			DisplayDriver_Text_Flex(16,32,300,WHITE,WHITE,"Sprache");
		}
		else
		{
			DisplayDriver_Text_Flex(16,156,104,WHITE,WHITE,"$ber");
			DisplayDriver_Text_Flex(16,49,204,WHITE,WHITE,"Zeit");
			DisplayDriver_Text_Flex(16,163,204,WHITE,WHITE,"Aus");
			DisplayDriver_Text_Flex(16,32,300,WHITE,WHITE,"Sprache");
		}
		break;

	default:
		break;
	}
	Display_Time = 1;
}

/******************************************************************************/
void UI_Background_Plate_About_Machine(void)
{
	Display_Time = 0;
	DisplayDriver_Fill(0,22,240,320,Interface_Back);
	DisplayDriver_Fill(20,72,220,250,LIGHTBLUE);

	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		DisplayDriver_Text_Flex(16,40,99,WHITE,WHITE,"Type: RL-C100");
		DisplayDriver_Text_Flex(16,40,135,WHITE,WHITE,"SN  :");
		DisplayDriver_Text_Flex(16,80,135,WHITE,WHITE,data_SN);
		DisplayDriver_Text_Flex(16,40,171,WHITE,WHITE,"HW Version: 1.1");
		DisplayDriver_Text_Flex(16,40,207,WHITE,WHITE,"FW Version: 1.9.0313");
		break;

	case DISPLAY_FONT_CHINESE:
		DisplayDriver_Text_Flex(16,40,99,WHITE,WHITE,"型号: RL-C100");
		DisplayDriver_Text_Flex(16,40,135,WHITE,WHITE,"批号:");
		DisplayDriver_Text_Flex(16,88,135,WHITE,WHITE,data_SN);
		DisplayDriver_Text_Flex(16,40,171,WHITE,WHITE,"固件版本: 1.1");
		DisplayDriver_Text_Flex(16,40,207,WHITE,WHITE,"软件版本: 1.9.0313");
		break;

	case DISPLAY_FONT_GERMAN:
		DisplayDriver_Text_Flex(16,40,99,WHITE,WHITE,"Typ: RL-C100");
		DisplayDriver_Text_Flex(16,40,135,WHITE,WHITE,"SN  :");
		DisplayDriver_Text_Flex(16,72,135,WHITE,WHITE,data_SN);
		DisplayDriver_Text_Flex(16,40,171,WHITE,WHITE,"HW Version: 1.1");
		DisplayDriver_Text_Flex(16,40,207,WHITE,WHITE,"FW Version: 1.9.0313");
		break;

	default:
		break;
	}
	Display_Time = 1;
}

/******************************************************************************/
void UI_Language_Plate_Record (void)
{
	Display_Time = 0;
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		if((reagent_Strip[0]) == 0)
		{
			DisplayDriver_Text_Flex(16,80, 173,RED,WHITE,"No Record!");
		}
		else
		{
			DisplayDriver_Text_Flex(16,110,42,BLACK,WHITE,Storage_Data.Product_name);
			DisplayDriver_Text_Flex(16,12,64,BLACK,WHITE,"Time:");
			DisplayDriver_Text_Flex(16,12,84,BLACK,WHITE,"  SN:");
			DisplayDriver_Text_Flex(16,12, 104, BLACK,WHITE,"Item");
			DisplayDriver_Text_Flex(16,62, 104, BLACK,WHITE,"Result");
			DisplayDriver_Text_Flex(16,122, 104, BLACK,WHITE,"Item");
			DisplayDriver_Text_Flex(16,172, 104, BLACK,WHITE,"Result");
		}
		break;

	case DISPLAY_FONT_CHINESE:
		if((reagent_Strip[0]) == 0)
		{
			DisplayDriver_Text_Flex(24,80, 173,RED,WHITE,"无记录");
		}
		else
		{
			DisplayDriver_Text_Flex(16,110,42,BLACK,WHITE,Storage_Data.Product_name);
			DisplayDriver_Text_Flex(16,12,64,BLACK,WHITE,"时间:");
			DisplayDriver_Text_Flex(16,12,84,BLACK,WHITE,"批号:");
			DisplayDriver_Text_Flex(16,12, 104, BLACK,WHITE,"名称");
			DisplayDriver_Text_Flex(16,74, 104, BLACK,WHITE,"结果");
			DisplayDriver_Text_Flex(16,122, 104, BLACK,WHITE,"名称");
			DisplayDriver_Text_Flex(16,184, 104, BLACK,WHITE,"结果");
		}
		break;

	case DISPLAY_FONT_GERMAN:
		if((reagent_Strip[0]) == 0)
		{
			DisplayDriver_Text_Flex(16,76, 173,RED,WHITE,"Kein rekord!");
		}
		else
		{
			DisplayDriver_Text_Flex(16,110,42,BLACK,WHITE,Storage_Data.Product_name);
			DisplayDriver_Text_Flex(16,12,64,BLACK,WHITE,"Zeit:");
			DisplayDriver_Text_Flex(16,12,84,BLACK,WHITE," LOT:");
			DisplayDriver_Text_Flex(16,4, 104, BLACK,WHITE,"Analyt");
			DisplayDriver_Text_Flex(16,54, 104, BLACK,WHITE,"Ergebnis");
			DisplayDriver_Text_Flex(16,114, 104, BLACK,WHITE,"Analyt");
			DisplayDriver_Text_Flex(16,164, 104, BLACK,WHITE,"Ergebnis");
		}
		break;

	default:
		break;
	}
	Display_Time = 1;
}

/******************************************************************************/
void Interface_Result_Save_Process(void)
{
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		DisplayDriver_Text_Flex(16,56, 275, WHITE,WHITE,"Has been stored!");
		break;

	case DISPLAY_FONT_CHINESE:
		DisplayDriver_Text_Flex(16,92, 275, WHITE,WHITE,"已保存!");
		break;

	case DISPLAY_FONT_GERMAN:
		DisplayDriver_Text_Flex(16,48, 275, WHITE,WHITE,"Wurde gespeichert!");
		break;

	default:
		break;
	}
}

/******************************************************************************/
void Interface_Screw_motor_Process(void)
{
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		DisplayDriver_Text_Flex (16,28,160,RED,RED,"Error: 001 Screw motor!");
		break;

	case DISPLAY_FONT_CHINESE:
		DisplayDriver_Text_Flex(16,28,160,BLACK,Interface_Bar,"错误:001   丝杆电机故障");
		break;

	case DISPLAY_FONT_GERMAN:
		DisplayDriver_Text_Flex (16,0,160,RED,RED,"Error: 001 Motor der Schraube!");
		break;

	default:
		break;
	}
}

/******************************************************************************/
void Interface_Rotating_motor_Process(void)
{
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		DisplayDriver_Text_Flex (16,28,180,RED,RED,"Error: 002 Rotating motor!");
		break;

	case DISPLAY_FONT_CHINESE:
		DisplayDriver_Text_Flex(16,28,180,BLACK,Interface_Bar,"错误:002  转动电机故障");
		break;

	case DISPLAY_FONT_GERMAN:
		DisplayDriver_Text_Flex (16,28,180,RED,RED,"Error: 002 Motor drehbar!");
		break;

	default:
		break;
	}
}

/******************************************************************************/
void Interface_Bluetooth_not_connected_Process(void)
{
	switch(Font_Switch)
	{
	case DISPLAY_FONT_ENGLISH:
		DisplayDriver_Text_Flex(16,24,294,WHITE,WHITE,"Bluetooth not connected!");
		break;

	case DISPLAY_FONT_CHINESE:
		DisplayDriver_Text_Flex(16,80,294,WHITE,WHITE,"蓝牙未连接!");
		break;

	case DISPLAY_FONT_GERMAN:
		DisplayDriver_Text_Flex(16,0,294,WHITE,WHITE,"Bluetooth nicht angeschlossen!");
		break;

	default:
		break;
	}
}
