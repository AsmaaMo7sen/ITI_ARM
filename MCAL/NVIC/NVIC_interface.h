/*
 * NVIC_interface.h
 *
 *  Created on: May 22, 2023
 *      Author: shady
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

#include "NVIC_private.h"



/* 
 * Description: Initializes the Nested Vectored Interrupt Controller (NVIC) based on the configuration in the NVIC configuration header file.
 *              This function sets the interrupt priority grouping, and enables any interrupts that have been configured to be enabled.
 */
void NVIC_voidInit(void);

/* 
 * Description: Enables the interrupt with the given interrupt ID.
 * Parameters:
 *    - Copy_u8IntId: The ID of the interrupt to enable.
 */
void NVIC_voidEnableInterrupt(u8 Copy_u8IntId);

/* 
 * Description: Disables the interrupt with the given interrupt ID.
 * Parameters:
 *    - Copy_u8IntId: The ID of the interrupt to disable.
 */
void NVIC_voidDisableInterrupt(u8 Copy_u8IntId);

/* 
 * Description: Sets the pending flag for the interrupt with the given interrupt ID.
 * Parameters:
 *    - Copy_u8IntId: The ID of the interrupt to set the pending flag for.
 */
void NVIC_voidSetPendingFlag(u8 Copy_u8IntId);

/* 
 * Description: Clears the pending flag for the interrupt with the given interrupt ID.
 * Parameters:
 *    - Copy_u8IntId: The ID of the interrupt to clear the pending flag for.
 */
void NVIC_voidClearPendingFlag(u8 Copy_u8IntId);

/* 
 * Description: Reads the active flag for the interrupt with the given interrupt ID.
 * Parameters:
 *    - Copy_u8IntId: The ID of the interrupt to read the active flag for.
 * Returns:
 *    - An 8-bit value indicating the state of the active flag for the specified interrupt. 
 */
u8 NVIC_u8ReadActiveFlag(u8 Copy_u8IntId);


/* 
 * Description: Sets the software priority for the interrupt with the given interrupt ID.
 *              This function sets both the group and sub-priority into the high 4 bits of the interrupt priority register (IPR).
 * Parameters:
 *    - Copy_u8SWPriority: The software priority to set, ranging from 0 to 15.
 *    - Copy_u8IntId: The ID of the interrupt to set the software priority for.
 */
void NVIC_voidSetSWPriority(u8 Copy_u8SWPriority , u8 Copy_u8IntId);

#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
