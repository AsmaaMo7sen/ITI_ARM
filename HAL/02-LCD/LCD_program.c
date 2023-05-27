/*************************************/
/* Author:  Mena Ghobrial            */
/* Date:    16 OCT 2022              */
/* Version: V01                      */
/*************************************/

/* Include LIB */
#include "STD_LIB.h"
#include "BIT_MATH.h"

/* Include MCAL */
#include "GPIO_interface.h"
#include "STK_interface.h"

/* Include HAL */
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"


void HLCD_voidInit(void)
{
	MSTK_voidSetBusyWait(35000);
	MGPIO_voidSetPinMode(HLCD_RS, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(HLCD_RW, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(HLCD_EN, GPIO_OUTPUT);
	
	#if HLCD_MODE  ==   HLCD_8_BIT_MODE
	MGPIO_voidSetPinMode(HLCD_D0, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(HLCD_D1, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(HLCD_D2, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(HLCD_D3, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(HLCD_D4, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(HLCD_D5, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(HLCD_D6, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(HLCD_D7, GPIO_OUTPUT);
	MSTK_voidSetBusyWait(35000);
	
	/* Commands */
	HLCD_voidWriteCommand(0x38);    // to select 8-bit mode
	MSTK_voidSetBusyWait(2000);
	HLCD_voidWriteCommand(0x0C);    // to turn display on , cursor off
	MSTK_voidSetBusyWait(100);
	HLCD_voidWriteCommand(0x02);    // to return home
	MSTK_voidSetBusyWait(2000);
	HLCD_voidWriteCommand(0x06);    // to display from left to right
	MSTK_voidSetBusyWait(2000);
	HLCD_voidWriteCommand(0x01);    // to clear LCD
	MSTK_voidSetBusyWait(2000);
	
	#elif HLCD_MODE  ==   HLCD_4_BIT_MODE
	MGPIO_voidSetPinMode(HLCD_D4, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(HLCD_D5, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(HLCD_D6, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(HLCD_D7, GPIO_OUTPUT);
	MSTK_voidSetBusyWait(35000);
	
	/* Commands */
	HLCD_voidWriteCommand(0x33);
	MSTK_voidSetBusyWait(2000);
	HLCD_voidWriteCommand(0x32);
	MSTK_voidSetBusyWait(2000);
	HLCD_voidWriteCommand(0x28);
	MSTK_voidSetBusyWait(2000);
	HLCD_voidWriteCommand(0x0C);    // to turn display on , cursor off
	MSTK_voidSetBusyWait(100);
	HLCD_voidWriteCommand(0x02);    // to return home
	MSTK_voidSetBusyWait(2000);
	HLCD_voidWriteCommand(0x06);    // to display from left to right
	MSTK_voidSetBusyWait(2000);
	HLCD_voidWriteCommand(0x01);    // to clear LCD
	MSTK_voidSetBusyWait(2000);
	#endif
}

void HLCD_voidWriteCommand(u8 Copy_u8Command)
{
	MGPIO_voidWritePinValue(HLCD_RS, GPIO_LOW);
	MGPIO_voidWritePinValue(HLCD_RW, GPIO_LOW);
	MGPIO_voidWritePinValue(HLCD_EN, GPIO_LOW);
	HLCD_voidLatch(Copy_u8Command);
}

void HLCD_voidWriteCharacter(u8 Copy_u8Character)
{
	MGPIO_voidWritePinValue(HLCD_RS, GPIO_HIGH);
	MGPIO_voidWritePinValue(HLCD_RW, GPIO_LOW);
	MGPIO_voidWritePinValue(HLCD_EN, GPIO_LOW);
	HLCD_voidLatch(Copy_u8Character);
}


void HLCD_voidWriteString(u8 * Copy_Pu8String)
{
	u8 Local_u8Index = 0;
	while(Copy_Pu8String[Local_u8Index] != '\0')
	{
		HLCD_voidWriteCharacter(Copy_Pu8String[Local_u8Index]);
		Local_u8Index++;
	}
}


void HLCD_voidWriteNumber(s32 Copy_s32Number)
{
	s32 Local_s32NumberCopy = Copy_s32Number;
	u8 Local_u8Arr[10] = {0};
	s8 Local_s8Counter = 0;
	if(Local_s32NumberCopy == 0)
	{
		HLCD_voidWriteCharacter('0');
	}
	else
	{
		if(Local_s32NumberCopy < 0)
		{
			HLCD_voidWriteCharacter('-');
			Local_s32NumberCopy = -Local_s32NumberCopy;
		}
		while(Local_s32NumberCopy != 0)
		{
			Local_u8Arr[Local_s8Counter] = Local_s32NumberCopy%10;
			Local_s32NumberCopy = Local_s32NumberCopy/10;
			Local_s8Counter++;
		}
		Local_s8Counter--;
		while(Local_s8Counter >= 0)
		{
			HLCD_voidWriteCharacter(Local_u8Arr[Local_s8Counter]+'0');
			Local_s8Counter--;
		}
	}
}

static void HLCD_voidLatch(u8 Copy_u8Latch)
{
	MGPIO_voidWritePinValue(HLCD_RW, GPIO_LOW);
	MGPIO_voidWritePinValue(HLCD_EN, GPIO_LOW);
	
	#if HLCD_MODE  ==   HLCD_8_BIT_MODE
	MGPIO_voidWritePinValue(HLCD_D0, ((Copy_u8Latch>>0)&1));
	MGPIO_voidWritePinValue(HLCD_D1, ((Copy_u8Latch>>1)&1));
	MGPIO_voidWritePinValue(HLCD_D2, ((Copy_u8Latch>>2)&1));
	MGPIO_voidWritePinValue(HLCD_D3, ((Copy_u8Latch>>3)&1));
	MGPIO_voidWritePinValue(HLCD_D4, ((Copy_u8Latch>>4)&1));
	MGPIO_voidWritePinValue(HLCD_D5, ((Copy_u8Latch>>5)&1));
	MGPIO_voidWritePinValue(HLCD_D6, ((Copy_u8Latch>>6)&1));
	MGPIO_voidWritePinValue(HLCD_D7, ((Copy_u8Latch>>7)&1));
	
	
	#elif HLCD_MODE  ==   HLCD_4_BIT_MODE
	MGPIO_voidWritePinValue(HLCD_D4, ((Copy_u8Latch>>4)&1));
	MGPIO_voidWritePinValue(HLCD_D5, ((Copy_u8Latch>>5)&1));
	MGPIO_voidWritePinValue(HLCD_D6, ((Copy_u8Latch>>6)&1));
	MGPIO_voidWritePinValue(HLCD_D7, ((Copy_u8Latch>>7)&1));
	
	MGPIO_voidWritePinValue(HLCD_EN, GPIO_HIGH);
	MSTK_voidSetBusyWait(5000);
	MGPIO_voidWritePinValue(HLCD_EN, GPIO_LOW);
	MSTK_voidSetBusyWait(5000);

	MGPIO_voidWritePinValue(HLCD_D4, ((Copy_u8Latch>>0)&1));
	MGPIO_voidWritePinValue(HLCD_D5, ((Copy_u8Latch>>1)&1));
	MGPIO_voidWritePinValue(HLCD_D6, ((Copy_u8Latch>>2)&1));
	MGPIO_voidWritePinValue(HLCD_D7, ((Copy_u8Latch>>3)&1));
	
	#endif
	MGPIO_voidWritePinValue(HLCD_EN, GPIO_HIGH);
	MSTK_voidSetBusyWait(5000);
	MGPIO_voidWritePinValue(HLCD_EN, GPIO_LOW);
	MSTK_voidSetBusyWait(5000);
}


void HLCD_voidClear(void)
{
	HLCD_voidWriteCommand(0x01);
}

void HLCD_voidGoToPosition(u8 Copy_u8Row, u8 Copy_u8Col)
{
	u8 arr[2] = {0x80,0xC0};
	HLCD_voidWriteCommand(arr[Copy_u8Row]+Copy_u8Col);
}