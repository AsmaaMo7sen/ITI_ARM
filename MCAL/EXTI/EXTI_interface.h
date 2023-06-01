/*
 * EXTI_interface.h
 *
 *  Created on: May 22, 2023
 *      Author: shady
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

/* 
 * Description: This file contains the function prototypes and definitions for the External Interrupt/Event Controller (EXTI) module.
 *              It provides functions to enable and disable interrupts, and to set the sensing signal for each interrupt.
 */

#define FALLING_EDGE         1    // Macro definition for falling edge trigger selection
#define RISING_EDGE          2    // Macro definition for rising edge trigger selection
#define ON_CHANGE            3    // Macro definition for both rising and falling edge trigger selection

/* 
 * Description: Enables the external interrupt for the given interrupt ID and sets the interrupt callback function.
 * Parameters:
 *    - Copy_u8IntId: The ID of the interrupt to enable.
 *    - Copy_ptrToFunc: A pointer to the function to be called when the interrupt occurs.
 */
void EXTI_voidEnableInt(u8 Copy_u8IntId , void(*Copy_ptrToFunc)(void));

/* 
 * Description: Disables the external interrupt for the given interrupt ID.
 * Parameters:
 *    - Copy_u8IntId: The ID of the interrupt to disable.
 */
void EXTI_voidDisableInt(u8 Copy_u8IntId);

/* 
 * Description: Sets the sensing signal for the given interrupt ID.
 * Parameters:
 *    - Copy_u8IntId: The ID of the interrupt to set the sensing signal for.
 */
void EXTI_voidSetSenceSignal(u8 Copy_u8SenceSignal,u8 Copy_u8IntId);

/* 
 * Description: Sets the line and port ID for the given interrupt ID.
 * Parameters:
 *    - Copy_u8IntId: The ID of the interrupt to set the line and port ID for.
 *    - Copy_u8PortId: The ID of the port to set for the interrupt.
 */
void EXTI_voidSteLinePort(u8 Copy_u8IntId,u8 Copy_u8PortId);

#endif/* MCAL_EXTI_EXTI_INTERFACE_H_ */