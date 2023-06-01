/*
 * NVIC_private.h
 *
 *  Created on: May 22, 2023
 *      Author: shady
 */
#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

/* 
 * Description: This struct defines the layout of the Nested Vectored Interrupt Controller (NVIC) registers.
 *              It is used to access and manipulate the NVIC registers.
 */
typedef struct
{
	u32 ISER[8];         // Interrupt Set-Enable Registers
	u32 RESERVED1[24];   // Reserved space
	u32 ICER[8];         // Interrupt Clear-Enable Registers
	u32 RESERVED2[24];   // Reserved space
	u32 ISPR[32];        // Interrupt Set-Pending Registers
	u32 ICPR[32];        // Interrupt Clear-Pending Registers
	u32 IABR[64];        // Interrupt Active Bit Registers
	u8  IPR[240];		
}NVIC_t;

/* 
 * Description: This macro defines a pointer to the NVIC_t struct at the base address of the NVIC registers.
 *              It is used to access and manipulate the NVIC registers.
 */
#define  NVIC  			 		((volatile NVIC_t *)(0xE000E100))

/* 
 * Description: This macro defines a pointer to the Application Interrupt and Reset Control Register (AIRCR) of the System Control Block (SCB) at address 0xE000ED0C.
 *              It is used to access and manipulate the AIRCR register.
 */
#define  SCB_AIRCR  			(*(volatile u32*)    (0xE000ED0C)) 


#define GROUP4_SUB0             (0)  //support 16 groups    (nesting level up to 16)
#define GROUP3_SUB1             (4)  //support  8 groups and 2 sub-priorities
#define GROUP2_SUB2             (5)  //support  4 groups and 4 sub-priorities
#define GROUP1_SUB3             (6)  //support  2 groups and 8 sub-priorities
#define GROUP0_SUB4             (7)  //support 0 groups and 16 sub-priorities   (no nesting)

#define  VECT_KEY  				 (0x0F5A0000)

#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
