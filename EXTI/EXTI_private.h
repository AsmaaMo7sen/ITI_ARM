/*
 * EXTI_private.h
 *
 *  Created on: May 22, 2023
 *      Author: shady
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

typedef struct 
{
    u32 IMR;        // Interrupt Mask Register
    u32 EMR;        // Event Mask Register
    u32 RTSR;       // Rising Edge Trigger Selection Register
    u32 FTSR;       // Falling Edge Trigger Selection Register
    u32 SWIER;      // Software Interrupt Event Register
    u32 PR;         // Pending Register
} EXTI_t;

#define EXTI ((volatile EXTI_t *)(0x40013C00))

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
