
#include "../../HAL/LEDMTRX/LEDMTRX_config.h"
#include "../../HAL/LEDMTRX/LEDMTRX_interface.h"
#include "../../HAL/LEDMTRX/LEDMTRX_private.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/STK/STK_interface.h"


/*Global array to iterate over led matrix rows*/
u8 Local_u8RowsArray[ROW_NUM][2] = {{ROW0},{ROW1},{ROW2},{ROW3},{ROW4},{ROW5},{ROW6},{ROW7}} ;

/*Global array to iterate over led matrix columns*/
u8 Local_u8ColsArray[COL_NUM][2] = {{COL0},{COL1},{COL2},{COL3},{COL4},{COL5},{COL6},{COL7}} ;


void LEDMTRX_voidInit(void)
{
	/*Local iterator to loop over rows and columns*/
	u8 Local_u8Iterator = 0 ;

	/*(1)Set all rows' pins to be -> output , push pull , low speed*/
	for(Local_u8Iterator=0 ; Local_u8Iterator<ROW_NUM ; Local_u8Iterator++)
	{
		GPIO_voidInitOutputPin(Local_u8RowsArray[Local_u8Iterator][0],Local_u8RowsArray[Local_u8Iterator][1] ,GPIO_PUSH_PULL , GPIO_LOW_SPEED);
	}

	/*(2)Set all columns' pins to be -> output , push pull , low speed*/
	for(Local_u8Iterator=0 ; Local_u8Iterator<COL_NUM ; Local_u8Iterator++)
	{
		GPIO_voidInitOutputPin(Local_u8ColsArray[Local_u8Iterator][0] ,Local_u8ColsArray[Local_u8Iterator][1] ,GPIO_PUSH_PULL , GPIO_LOW_SPEED);
	}

	/*(3)Deactivate all Columns */
	for(Local_u8Iterator=0 ; Local_u8Iterator<COL_NUM ; Local_u8Iterator++)
	{
		GPIO_voidSetOutPinValue(Local_u8ColsArray[Local_u8Iterator][0],Local_u8ColsArray[Local_u8Iterator][1],GPIO_OUTPUT_HIGH);
	}

	/*(4)set all leds OFF*/
	for(Local_u8Iterator=0 ; Local_u8Iterator<ROW_NUM ; Local_u8Iterator++)
	{
		GPIO_voidSetOutPinValue(Local_u8RowsArray[Local_u8Iterator][0],Local_u8RowsArray[Local_u8Iterator][1] ,GPIO_OUTPUT_LOW);
	}

}

void LEDMTRX_voidTurnOff(void)
{
	/*Local iterator to loop over rows and columns*/
	u8 Local_u8Iterator = 0 ;

	/*(1)Deactivate all Columns */
	for(Local_u8Iterator=0 ; Local_u8Iterator<COL_NUM ; Local_u8Iterator++)
	{
		GPIO_voidSetOutPinValue(Local_u8ColsArray[Local_u8Iterator][0],Local_u8ColsArray[Local_u8Iterator][1],GPIO_OUTPUT_HIGH);
	}

	/*(2)set all leds OFF*/
	for(Local_u8Iterator=0 ; Local_u8Iterator<ROW_NUM ; Local_u8Iterator++)
	{
		GPIO_voidSetOutPinValue(Local_u8RowsArray[Local_u8Iterator][0],Local_u8RowsArray[Local_u8Iterator][0] ,GPIO_OUTPUT_LOW);
	}
}


void LEDMTRX_voidDisplayPattern(u8 Copy_au8PaterrnArray[] , u16 time)
{	
	u8 Iterator_25time = 0;
	for(Iterator_25time=0 ; Iterator_25time<(time/25) ; Iterator_25time++)
	{

	/*Local iterator to loop over columns*/
	u8 Local_u8ColsIterator = 0 ;

	/*Local iterator to loop over rows*/
	u8 Local_u8RowsIterator = 0 ;

	/*Loop over columns to activate one by one*/
	for(Local_u8ColsIterator=0 ; Local_u8ColsIterator<COL_NUM ; Local_u8ColsIterator++)
	{
		/*Activate the current Column -> Set it's pin to be low output*/
		GPIO_voidSetOutPinValue(Local_u8ColsArray[Local_u8ColsIterator][0],Local_u8ColsArray[Local_u8ColsIterator][1] , GPIO_OUTPUT_LOW);

		/*Loop over all rows to set the corresponding value -> either 0 or 1 from the pattern array index*/
		for(Local_u8RowsIterator=0 ; Local_u8RowsIterator<ROW_NUM ; Local_u8RowsIterator++)
		{
			/*Set the value of the row to be the value of the corresponding bit for the row
			 * the corresponding pattern index for the activated column*/
			GPIO_voidSetOutPinValue(Local_u8RowsArray[Local_u8RowsIterator][0] ,Local_u8RowsArray[Local_u8RowsIterator][1]
				,GET_BIT(Copy_au8PaterrnArray[Local_u8ColsIterator] , Local_u8RowsIterator));
		}

		/*Set delay = 2.5 millisecond between every activation*/
		STK_voidDelaySync(2500);

		/*Led matrix reset before the new activation*/
		LEDMTRX_voidTurnOff();
	}
	}
}
