#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_


/*System Clock Configurations*/
#define HSI              1
#define HSE_RC           2
#define HSE_CRYSTAL      3
#define PLL              4

//RCC registers
#define RCC_CR 		  *((volatile u32 *)(0x40023800))
#define RCC_CFGR   	  *((volatile u32 *)(0x40023808))

#define RCC_AHB1ENR   *((volatile u32 *)(0x40023830))
#define RCC_AHB2ENR   *((volatile u32 *)(0x40023834))
#define RCC_APB1ENR   *((volatile u32 *)(0x40023840))
#define RCC_APB2ENR   *((volatile u32 *)(0x40023844))


#endif
