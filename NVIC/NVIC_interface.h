/*
 * NVIC_interface.h
 *
 *  Created on: 15May,2023
 *      Author: osama
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_


typedef struct {
	u32 ISR0 ;	/*for interrupt from 0 to 31*/
	u32 ISR1 ;  /*for interrupt from 32 to 63*/
	u32 ISR2 ;  /*for interrupt from 64 to 83*/

}NVIC_ISR_t;

typedef struct {
	u32 ICER0 ;	/*for interrupt from 0 to 31*/
	u32 ICER1 ;  /*for interrupt from 32 to 63*/
	u32 ICER2 ;  /*for interrupt from 64 to 83*/

}NVIC_ICER_t;

typedef struct {
	u32 ISPR0 ;	/*for interrupt from 0 to 31*/
	u32 ISPR1 ;  /*for interrupt from 32 to 63*/
	u32 ISPR2 ;  /*for interrupt from 64 to 83*/

}NVIC_ISPR_t;

typedef struct {
	u32 ICPR0 ;	/*for interrupt from 0 to 31*/
	u32 ICPR1 ;  /*for interrupt from 32 to 63*/
	u32 ICPR2 ;  /*for interrupt from 64 to 83*/

}NVIC_ICPR_t;


typedef struct {
	u32 IABR0 ;	/*for interrupt from 0 to 31*/
	u32 IABR1 ;  /*for interrupt from 32 to 63*/
	u32 IABR2 ;  /*for interrupt from 64 to 83*/

}NVIC_IABR_t;

#define 	GROUP4_SUB0		0	//16 Group bits for group (IPR) =>group
#define 	GROUP3_SUB1		4	// 8 group bit for group and 1 bit for sub priorty
#define 	GROUP2_SUB2		5	// 4 groups bit for group and 2 bit for sub
#define 	GROUP1_SUB3		6	// 2 groups bit for group and 3bit for sub
#define 	GROUP0_SUB4		7   // 0 groups no group and 4 bit for sub

//#define 	GROUP4_SUB0		0x05FA0300	//16 Group bits for group (IPR) =>group
//#define 	GROUP3_SUB1		0x05FA0300	// 8 group bit for group and 1 bit for sub priorty
//#define 	GROUP2_SUB2		0x05FA0300	// 4 groups bit for group and 2 bit for sub
//#define 	GROUP1_SUB3		0x05FA0300	// 2 groups bit for group and 3bit for sub
//#define 	GROUP0_SUB4		0x05FA0300   // 0 groups no group and 4 bit for sub

/*enable interrupt
 * 1 enable
 * 0 has no effect
 * Read operation
 * 0 interrupt disable ??
 * 1 interrupt enable ?? */
void MNVIC_voidEnableInt(u8 Copy_u8IntNumber);

/*this function is to disable interrupt  */
void MNVIC_voidDisableInt(u8 Copy_u8IntNumber);

/*this function is to disable interrupt  */
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);

/*this function is to disable interrupt  */
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);


void MVIC_voidReadingPending(u8 Copy_u8IntNumber);

void MNVIC_voidSetPriorty(s8 Copy_s8priorty , u8 Copy_u8GropyPriorty,u8 Copy_u8SubGroup, u32 Copy_u8Grop);
#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
