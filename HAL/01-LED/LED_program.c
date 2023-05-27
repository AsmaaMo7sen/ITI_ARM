/************************************/
/* Author:    Mena Ghobrial         */
/* Date:      18 OCT 2022           */
/* Version:   V01                   */
/************************************/

/* Include LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include MCAL */
#include "GPIO_interface.h"

/* Include HAL */
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


void HLED_voidInit(void)
{
	MGPIO_voidSetPinMode(HLED_PIN, GPIO_OUTPUT);
}



void HLED_voidOn(void)
{
	MGPIO_voidWritePinValue(HLED_PIN, GPIO_HIGH);
}


void HLED_voidOff(void)
{
	MGPIO_voidWritePinValue(HLED_PIN, GPIO_LOW);
}



void HLED_voidToggle(void)
{
	MGPIO_voidTogglePinValue(HLED_PIN);
}