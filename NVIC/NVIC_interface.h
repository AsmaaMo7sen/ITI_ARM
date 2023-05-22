/*
 * NVIC_interface.h
 *
 *  Created on: May 22, 2023
 *      Author: Hardware
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_


/*this function is to initialize NVIC , sets priority configurations*/
void NVIC_voidInit(void);

void NVIC_voidEnableInterrupt(u8 Copy_u8IntId);

void NVIC_voidDisableInterrupt(u8 Copy_u8IntId);

void NVIC_voidSetPendingFlag(u8 Copy_u8IntId);

void NVIC_voidClearPendingFlag(u8 Copy_u8IntId);

u8 NVIC_u8ReadActiveFlag(u8 Copy_u8IntId);

void NVIC_voidSetSWPriority(u8 Copy_u8SWPriority , u8 Copy_u8IntId );



#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
