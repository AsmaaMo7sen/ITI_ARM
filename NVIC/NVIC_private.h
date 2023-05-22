/*
 * NVIC_program.c
 *
 *  Created on: 15May,2023
 *      Author: osama
 */

#ifndef MCAL_NVIC_NVIC_PROGRAM_C_
#define MCAL_NVIC_NVIC_PROGRAM_C_


/*another way  */
//typedef struct {
//	u32 ISRER[8] ;
//	u32 Reserved[24];
//	u32 ICER[32];
//	u32 ISPR[32];
//	u32 ICPR[32];
//	u32 IAPR[64];
//};
//#define NVIC ((volatile NVIC_ISR_t * )(0xE000E100))
#define SCB_AIRCR	((volatile NVIC_ISR_t * )(0xE000ED0C))

/*this register is for enable  interrupt for each peripheral */
#define 	ISR		((volatile NVIC_ISR_t * )(0xE000E100))

/*this register is for disable  interrupt for each peripheral */
#define     ICER	((volatile NVIC_ICER_t * )(0XE000E180))

/*this register is for setting the pending flag for each peripheral */
#define     ISPR	((volatile NVIC_ISPR_t * )(0XE000E200))


/*this register is for clearing  the pending flag for each peripheral */
#define     ICPR	((volatile NVIC_ICPR_t * )(0XE000E280))


/*this register is for Reading   the pending flag for each peripheral */
#define     IABR	((volatile NVIC_IABR_t * )(0xE000E300))

/*for IPR */
/*Vect Key = 0x05FA */
#define     IPR	   ((volatile u8 * )(0xE000E400))

#define   AIRCR 	((volatile  u32 *)(0xE000ED0C)
#endif /* MCAL_NVIC_NVIC_PROGRAM_C_ */
