/*
 * NVIC_prog.c
 *
 *  Created on: May 22, 2023
 *      Author: shady
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "NVIC_Cfg.h"
#include "NVIC_private.h"
#include "NVIC_interface.h"




/* 
 * Description: Initializes the Nested Vectored Interrupt Controller (NVIC) based on the configuration in the NVIC configuration header file.
 *              This function sets the interrupt priority grouping, and enables any interrupts that have been configured to be enabled.
 */
void NVIC_voidInit(void)
{
    /*Local var for the val of AIRCR reg*/
    u32 Local_u32RegVal ;

    /*set cfg of system sw priorities*/
    Local_u32RegVal = VECT_KEY | (PRIORITY_CONFIG << 8);

    /*assign the value to AIRCR reg*/
    SCB_AIRCR=Local_u32RegVal;
}

/* 
 * Description: Enables the interrupt with the given interrupt ID.
 * Parameters:
 *    - Copy_u8IntId: The ID of the interrupt to enable.
 */
void NVIC_voidEnableInterrupt(u8 Copy_u8IntId)
{
    NVIC->ISER[Copy_u8IntId / 32 ] = (1 << (Copy_u8IntId % 32));
}

/* 
 * Description: Disables the interrupt with the given interrupt ID.
 * Parameters:
 *    - Copy_u8IntId: The ID of the interrupt to disable.
 */
void NVIC_voidDisableInterrupt(u8 Copy_u8IntId)
{
    NVIC->ICER[Copy_u8IntId / 32 ] = (1 << (Copy_u8IntId % 32));   
}

/* 
 * Description: Sets the pending flag for the interrupt with the given interrupt ID.
 * Parameters:
 *    - Copy_u8IntId: The ID of the interrupt to set the pending flag for.
 */
void NVIC_voidSetPendingFlag(u8 Copy_u8IntId)
{
    NVIC->ISPR[Copy_u8IntId / 32 ] = (1 << (Copy_u8IntId% 32));
}

/* 
 * Description: Clears the pending flag for the interrupt with the given interrupt ID.
 * Parameters:
 *    - Copy_u8IntId: The ID of the interrupt to clear the pending flag for.
 */
void NVIC_voidClearPendingFlag(u8 Copy_u8IntId)
{
    NVIC->ICPR[Copy_u8IntId / 32 ] = (1 << (Copy_u8IntId % 32));
}

/* 
 * Description: Reads the active flag for the interrupt with the given interrupt ID.
 * Parameters:
 *    - Copy_u8IntId: The ID of the interrupt to read the active flag for.
 * Returns:
 *    - An 8-bit value indicating the state of the active flag for the specified interrupt. 
 */
u8 NVIC_u8ReadActiveFlag(u8 Copy_u8IntId)
{
    u8 Local_u8ActiveFlag = 0 ;
    Local_u8ActiveFlag = GET_BIT(NVIC->IABR[ Copy_u8IntId / 32 ],(1 << (Copy_u8IntId % 32)));
    return Local_u8ActiveFlag;
}

/* 
 * Description: Sets the software priority for the interrupt with the given interrupt ID.
 *              This function sets both the group and sub-priority into the high 4 bits of the interrupt priority register (IPR).
 * Parameters:
 *    - Copy_u8SWPriority: The software priority to set, ranging from 0 to 15.
 *    - Copy_u8IntId: The ID of the interrupt to set the software priority for.
 */
void NVIC_voidSetSWPriority(u8 Copy_u8SWPriority , u8 Copy_u8IntId)
{
    /*setting both group and sub-priority into the high 4 bits */
    NVIC->IPR[Copy_u8IntId]  = (Copy_u8SWPriority << 4) ;
    /*
    * TODO -> enhance the function!!
    */
}
