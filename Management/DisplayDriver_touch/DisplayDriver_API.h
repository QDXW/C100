/*******************************************************************************
 * File name: DisplayDriver_API.h
 * Author: Hanson Liu
 * Mail: han_liu_zju@sina.com
 * Date: 2014.12 ~ Now
 ******************************************************************************/
#ifndef __MANAGEMENT_DISPLAYDRIVER_DISPLAYDRIVER_API_H_
#define __MANAGEMENT_DISPLAYDRIVER_DISPLAYDRIVER_API_H_

/******************************************************************************/
#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/******************************************************************************/
#define TOUCHPANEL2_8ENABLE 1
#define AT1963_ENABLE       0

/******************************************************************************/
extern void DisplayDriver_Clear_Touch(uint16 color);
extern void DisplayDriver_Text16_Touch(unsigned short x, unsigned short y, unsigned short fc,
		unsigned short bc, uint8 *s);
extern void DisplayDriver_Text16_Back(unsigned short x, unsigned short y, unsigned short fc,
		unsigned short bc, uint8 *s);
extern void DisplayDriver_DrawBmp(const uint8* bmpbit,uint16 x,uint16 y);
extern void DisplayDriver_Text24(uint16 x, uint16 y, uint16 fc, uint16 bc, uint8 *s);
extern void DisplayDriver_Text32(uint16 x, uint16 y, uint16 fc, uint16 bc, uint8 *s);
extern void DisplayDriver_Text48(uint16 x, uint16 y, uint16 fc, uint16 bc, uint8 *s);
extern void DisplayDriver_TextAny(uint16 x, uint16 y, uint8 w, uint8 h, uint16 fc,
		uint16 bc, const uint8 *s, uint16 addr);
extern void DisplayDriver_SetCursor(u16 x, u16 y);
extern void DisplayDriver_DrawPoint(u16 x,u16 y, u16 color);
extern void DisplayDriver_Fill(u16 start_x,u16 start_y,u16 end_x,u16 end_y,u16 color);
extern void DisplayDriver_DrawStraight_Line(u16 startx,u16 starty, u16 endx,u16 endy,u16 color);
extern void DisplayDriver_DrawPic_Touch(const uint8* src, uint16 bc, uint16 x, uint16 y);
extern void DisplayDriver_DrawRectangle(u16 start_x,u16 start_y,u16 end_x,u16 end_y,
		u16 color);
extern void DisplayDriver_DrawCircle(u16 x_postion,u16 y_postion,u8 radius, u16 color);
extern u16 DisplayDriver_SwapBlueRed(u16 c);
extern void DisplayDriver_Text16_Any(unsigned short x, unsigned short y,
		uint8 oneLineNum, unsigned short fc, unsigned short bc, uint8 *s);
extern void DisplayDriver_DrawPoint_Big(u16 x,u16 y, u16 color);
extern void DisplayDriver_DrawCircle_Solid(u16 x_postion,u16 y_postion,u8 radius, u16 color);

void DisplayDriver_Text16_China(unsigned short x, unsigned short y, unsigned short fc,
		unsigned short bc, uint8 *s);

void DisplayDriver_Text24_China(unsigned short x, unsigned short y, unsigned short fc,
		unsigned short bc, uint8 *s);

void DisplayDriver_Text32_China(unsigned short x, unsigned short y, unsigned short fc,
		unsigned short bc, uint8 *s);

extern void DisplayDriver_Text_Flex(uint8 Size,unsigned short x, unsigned short y, unsigned short fc,
		unsigned short bc, uint8 *s);

#endif /* __MANAGEMENT_DISPLAYDRIVER_DISPLAYDRIVER_API_H_ */
