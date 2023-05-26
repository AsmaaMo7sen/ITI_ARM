/*
 * STK_interface.h
 *
 *  Created on: May 26, 2023
 *      Author: Hardware
 */

#ifndef MCAL_STK_STK_INTERFACE_H_
#define MCAL_STK_STK_INTERFACE_H_


void STK_voidInit(void);

void STK_voidDelaySync(u32 Copy_u32Delay_us);

void STK_voidDelayAsync(u32 Copy_u32Delay_us , void(*Copy_ptrToFunc)(void));

u32 STK_u32GetRemainingTime(void);

u32 STK_u32GetElapsedTime(void);



#endif /* MCAL_STK_STK_INTERFACE_H_ */
