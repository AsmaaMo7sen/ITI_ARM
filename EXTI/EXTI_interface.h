/*
 * EXTI_interface.h
 *
 *  Created on: May 22, 2023
 *      Author: Hardware
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

/*16 macro for exti lines*/
#define EXTI_LINE0           0
#define EXTI_LINE1           1
#define EXTI_LINE2           2
#define EXTI_LINE3           3
#define EXTI_LINE4           4
#define EXTI_LINE5           5
#define EXTI_LINE6           6
#define EXTI_LINE7           7


/*3 macros for sense signals*/
#define FALLING_EDGE        1
#define RISING_EDGE         2
#define ON_CHANGE           3

void EXTI_voidEnableInt(u8 Copy_u8IntId , void(*Copy_ptrToFunc)(void));
void EXTI_voidDisableInt(u8 Copy_u8IntId);
void EXTI_voidSetSenseSignal(u8 Copy_u8SenseSignal , u8 Copy_u8IntId);
void EXTI_voidSetLinePort(u8 Copy_u8IntId , u8 Copy_u8PortId) ;
static void EXTI_voidClearPendingFlag(u8 Copy_u8IntId);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
