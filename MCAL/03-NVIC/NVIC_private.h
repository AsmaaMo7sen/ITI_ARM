/*****************************************/
/* Author:    Mena Ghobrial              */
/* Date:      22 SEP 2022                */
/* Version:   V01                        */
/*****************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS 0xE000E100


typedef struct
{
	volatile u32 ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
	volatile u32 RESERVED0[24U];
	volatile u32 ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
	volatile u32 RESERVED1[24U];
	volatile u32 ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
	volatile u32 RESERVED2[24U];
	volatile u32 ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
	volatile u32 RESERVED3[24U];
	volatile u32 IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
	volatile u32 RESERVED4[56U];
	volatile u8  IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
	volatile u32 RESERVED5[644U];
	volatile u32 STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}NVIC_t;


#define NVIC    ((NVIC_t *) NVIC_BASE_ADDRESS)

#define SCB_BASE_ADDRESS         0xE000ED00
#define SCB_AIRCR               (*((volatile u32*)0xE000ED0C))
#define VECTKEY                  0x05FA0000

#endif /* NVIC_PRIVATE_H */