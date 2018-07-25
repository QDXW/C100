/*******************************************************************************
 * File name: STMFlash.c
 * Author: Hanson Liu
 * Mail: han_liu_zju@sina.com
 * Date: 2014.12 ~ Now
 ******************************************************************************/
#include "stmflash.h"

extern QRCODE_STRUCT QR_Date; 

/******************************************************************************/
#define STM32_FLASH_SIZE (512) 	 	  /* Flash size, unit is Kbytes */

#if (STM32_FLASH_SIZE < 256)
#define STM_SECTOR_SIZE (1024)
#else
#define STM_SECTOR_SIZE	(2048)
#endif

/******************************************************************************/
uint16 flashTmpBuffer[STM_SECTOR_SIZE/2];
uint16 Information_Num = 1;

/******************************************************************************/
uint16 STMFlash_ReadHalfWord(uint32 faddr);
void STMFlash_Write_NoCheck(uint32 WriteAddr, uint16 *pBuffer,
		uint16 NumToWrite);

/******************************************************************************/
uint16 STMFlash_ReadHalfWord(uint32 faddr)
{
	return *(volatile uint16*)faddr;
}

/******************************************************************************/
void STMFlash_Write_NoCheck(uint32 WriteAddr, uint16 *pBuffer,
		uint16 NumToWrite)
{ 			 		 
	uint16 i;
	for(i = 0; i < NumToWrite; i++)
	{
		FLASH_ProgramHalfWord(WriteAddr, pBuffer[i]);
	    WriteAddr += 2;
	}  
} 

/******************************************************************************/
void STMFlash_Write(uint32 WriteAddr, uint16 *pBuffer, uint16 NumToWrite)
{
	uint32 secpos;
	uint16 secoff;
	uint16 secremain;
 	uint16 i;
	uint32 offaddr;

	if(WriteAddr < FLASH_BASE ||
			(WriteAddr >= (FLASH_BASE + (STM32_FLASH_SIZE << 10))))
		return;

	FLASH_Unlock();
	offaddr = WriteAddr - FLASH_BASE;
	secpos = offaddr / STM_SECTOR_SIZE;
	secoff = (offaddr % STM_SECTOR_SIZE) >> 1;
	secremain = (STM_SECTOR_SIZE >> 1) - secoff;

	if(NumToWrite <= secremain)
		secremain = NumToWrite;

	while(1) 
	{
		STMFlash_Read(secpos * STM_SECTOR_SIZE + FLASH_BASE, flashTmpBuffer,
				STM_SECTOR_SIZE >> 1);
		for(i=0; i < secremain; i++)
		{
			if(flashTmpBuffer[secoff + i] != 0XFFFF)
				break;
		}

		if(i < secremain)
		{
			FLASH_ErasePage(secpos * STM_SECTOR_SIZE + FLASH_BASE);
			for(i = 0; i < secremain; i++)
			{
				flashTmpBuffer[i + secoff] = pBuffer[i];
			}

			STMFlash_Write_NoCheck(secpos * STM_SECTOR_SIZE + FLASH_BASE,
					flashTmpBuffer, STM_SECTOR_SIZE >> 1);
		}else
			STMFlash_Write_NoCheck(WriteAddr, pBuffer, secremain);

		if(NumToWrite == secremain)
			break;
		else
		{
			secpos++;
			secoff = 0;
		   	pBuffer += secremain;
			WriteAddr += secremain;
		   	NumToWrite -= secremain;
			if(NumToWrite > (STM_SECTOR_SIZE >> 1))
				secremain = STM_SECTOR_SIZE >> 1;
			else
				secremain = NumToWrite;
		}	 
	};

	FLASH_Lock();
}

/******************************************************************************/
void STMFlash_Read(uint32 ReadAddr, uint16 *pBuffer, uint16 NumToRead)
{
	uint16 i;

	for(i = 0; i < NumToRead; i++)
	{
		pBuffer[i] = STMFlash_ReadHalfWord(ReadAddr);
		ReadAddr += 2;
	}
}
