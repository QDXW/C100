/*
 * Interface_main.h
 *
 *  Created on: 2018Äê2ÔÂ9ÈÕ
 *      Author: Administrator
 */

#ifndef MANAGEMENT_INTERFACE_INTERFACE_MAIN_H_
#define MANAGEMENT_INTERFACE_INTERFACE_MAIN_H_

/******************************************************************************/
#include "Project_File.h"

/******************************************************************************/


/******************************************************************************/
/* Touch screen position */
extern uint8 Cup_Count,Pic_Count,Touch_Success,Record_Display,Stored_Record;
extern uint8 doubleClick,Read_first,UI_state,key_state_confirm,Exti_lock;
extern float temp;
extern uint16 xPos, yPos,UI_WindowBlocks;

/******************************************************************************/
/* Rectangular attribute */
typedef struct {
	uint16 startX; 			/* Start X */
	uint16 startY; 			/* Start Y */
	uint16 width; 			/* Width */
	uint16 height; 			/* Height */
	uint16 color; 			/* Color */
} rect_attr;

/******************************************************************************/
/* Straight line */
typedef struct {
	uint16 startX; 			/* Start X */
	uint16 startY; 			/* Start Y */
	uint16 endX; 			/* EndX */
	uint16 endY; 			/* EndY */
	uint16 color; 			/* Color */
} line_attr;

/******************************************************************************/
/* Picture attribute */
typedef struct {
	const uint8* src; 		/* Picture data array */
	uint16 offsetX;			/* Offset X away from rect_attr.startX */
	uint16 offsetY; 		/* Offset Y away from rect_attr.startY */
	uint16 width; 			/* Picture width */
	uint16 height;			/* Picture height */
	uint8 count;			/* Picture count */
} pic_attr;

/******************************************************************************/
/* Character attribute */
typedef struct {
	uint8* str; 			/* String to be shown */
	uint16 offsetX;			/* Offset X away from rect_attr.startX */
	uint16 offsetY; 		/* Offset Y away from rect_attr.startY */
	uint16 color; 			/* Font color */
	uint16 backColor; 		/* Back color */
	uint16 faceColor; 		/* face color */
} char_attr;

/******************************************************************************/
typedef struct {
	uint8 Interface_Status;
	uint8 pic_enabled;     				/* Support picture or not */
	pic_attr pic_attr;     				/* Picture attribute */
	uint8 char_enabled;					/* Support char or not */
	char_attr char_attr;				/* char attribute */
} block_attr;

/******************************************************************************/
typedef enum {
	UI_STATE_MAIN_WINDOW_PROCESS,	/* Interface touch process */
	UI_STATE_MAIN_WINDOW, 			/* Interface main display */
	UI_STATE_STANDARD,				/* Interface STANDARD display */
	UI_STATE_START,					/* Interface Start Display */
	UI_STATE_QUICK, 				/* Interface Quick Display */
	UI_STATE_RECORD, 				/* Interface Record Display */
	UI_STATE_SETTING, 				/* Interface Setting Display */
	UI_STATE_TESTING,				/* Interface Testing Display */
	UI_STATE_RESULT,				/* Interface Result Display */
	UI_STATE_INSERT_CUP,			/* Interface insert cup Display */
	UI_STATE_DELETE, 				/* Interface Record2 Display */
	UI_STATE_DOWN_TIME_PROCESS,		/* Interface DOWN TIME Display */
	UI_STATE_BLUETOOTH_PROCESS,		/* Interface BLUETOOTH Display */
	UI_STATE_ABOUT_MACHINE,			/* Interface ABOUT MACHINE Display */
	UI_STATE_SYSTEM_TIME,			/* Interface SYSTEM TIME Display */
	UI_STATE_SET_TIME_PROCESS,		/* Interface SET TIME Display */
	UI_STATE_QUICK_TOUCH_PROCESS,	/* Interface QUICK TOUCH Display */
	UI_STATE_DOWN_TIME_TOUCH_PROCESS,	/* Interface DOWN TIME TOUCH Display */
	UI_STATE_RESULT_TOUCH_PROCESS,	/* Interface Result TOUCH Display */
	UI_STATE_INVALUE_CODE_PROCESS,	/* Interface INVALUE CODE TOUCH Display */
	UI_STATE_INVALID_TOUCH_PROCESS,	/* Interface INVALID TOUCH Display */
	UI_STATE_RECORD_DEMAND_PROCESS,	/* Interface RECORD DEMAND Display */

	UI_STATE_MAX_STATE_NUM,
} UI_STATE;

/******************************************************************************/
void Battery_Display (void);
extern void Status_Init(void);
extern void Battery_Empty_ICO(void);
extern void UI_Draw_Status_Bar (void);
extern void Bluetooth_Connection (void);
extern void UI_Draw_Window(uint16 blockNum);
extern uint8 Interface_Record_2(uint16 KeyCode);
extern uint8 Interface_Result_2(uint16 KeyCode);
extern uint8 Interface_Quick_font(uint16 blockNum);
extern uint8 Interface_Standard_font(uint16 KeyCode);
extern void UI_Draw_Window_Quick_font(uint16 blockNum);
extern void SignalSample_Moving_Average_Data(uint16 *Data,uint16 Length,uint16 Period);


void UI_Background_Plate_Main (void);
void Touch_process(uint16* xpos,uint16* ypos);
uint8 Touch_Check (uint16* xpos,uint16* ypos);
uint8 Interface_Main(uint16* xpos,uint16* ypos);
extern block_attr* UI_WindowBlocksAttrArray[20];
uint8 Interface_Key_Event(uint16* xpos,uint16* ypos);
extern uint8 Interface_Quick(uint16* xpos,uint16* ypos);
extern uint8 Interface_Start(uint16* xpos,uint16* ypos);
extern uint8 Interface_Record(uint16* xpos,uint16* ypos);
extern uint8 Interface_Result(uint16* xpos,uint16* ypos);
extern uint8 Interface_Delete(uint16* xpos,uint16* ypos);
extern uint8 Interface_Setting(uint16* xpos,uint16* ypos);
extern uint8 Interface_Testing(uint16* xpos,uint16* ypos);
extern uint8 Interface_Standard(uint16* xpos,uint16* ypos);
extern uint8 Interface_Insert_Cup(uint16* xpos,uint16* ypos);
extern uint8 Interface_System_Time(uint16* xpos,uint16* ypos);
uint8 Interface_Main_Window_Process(uint16* xpos,uint16* ypos);
extern uint8 Interface_About_Machine(uint16* xpos,uint16* ypos);
void UI_Touch_Check(block_attr* block,uint16* xpos,uint16* ypos);
extern uint8 Interface_Down_Time_Process(uint16* xpos,uint16* ypos);
extern uint8 Interface_Buetooth_Process (uint16* xpos,uint16* ypos);
extern uint8 Interface_Set_Time_Process (uint16* xpos,uint16* ypos);
extern uint8 Interface_Quick_Touch_Process(uint16* xpos,uint16* ypos);
extern uint8 Interface_Result_Touch_Process(uint16* xpos,uint16* ypos);
extern uint8 Interface_Invalue_Code_Process(uint16* xpos,uint16* ypos);
extern uint8 Interface_Record_Demand_Process(uint16* xpos,uint16* ypos);
extern uint8 Interface_Invalid_Touch_Process(uint16* xpos,uint16* ypos);
extern uint8 Interface_Down_Time_Touch_Process(uint16* xpos,uint16* ypos);

#endif /* MANAGEMENT_INTERFACE_INTERFACE_MAIN_H_ */
