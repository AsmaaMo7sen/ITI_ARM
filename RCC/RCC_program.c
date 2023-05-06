
/**********************************************************************/
/* Author  : Osama Gamil 											  */
/* Date    : 29/4/2023 												  */
/* Version : V01									   				  */
/**********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_VoidEnableClock(u8 Copy_u8BusId ,  u8  Copy_u8PeriphId)
{
	if(Copy_u8PeriphId <= 31  )
	{
		switch(Copy_u8BusId)
		{

			case RCC_AHB1   : SET_BIT(RCC_AHB1ENR  , Copy_u8PeriphId);  break;
			case RCC_AHB2   : SET_BIT(RCC_AHB2ENR  , Copy_u8PeriphId); 	break;
			case RCC_APB1   : SET_BIT(RCC_APB1ENR  , Copy_u8PeriphId); 	break;
			case RCC_APB2   : SET_BIT(RCC_APB2ENR  , Copy_u8PeriphId); 	break;

			/*default		   : /*return error  */				/*			break; 	*/	
		}
	}
	else 
	{
		/*return error */
	}
	
	
}
void RCC_VoidDisableClock(u8 Copy_u8BusId ,  u8  Copy_u8PeriphId)
{
	if(Copy_u8PeriphId <= 31)
	{
		switch(Copy_u8BusId)
		{

			case RCC_AHB1   : CLR_BIT(RCC_AHB1ENR  , Copy_u8PeriphId);  break;
			case RCC_AHB2   : CLR_BIT(RCC_AHB2ENR  , Copy_u8PeriphId); 	break;
			case RCC_APB1   : CLR_BIT(RCC_APB1ENR  , Copy_u8PeriphId); 	break;
			case RCC_APB2   : CLR_BIT(RCC_APB2ENR  , Copy_u8PeriphId); 	break;


			/*default		   : /*return error  */				/*			break; 	*/	
		}
	}
	else 
	{
		/*return error */
	}
	
	
}


/*Prebuild Config */
void RCC_voidInitSysClk(void)
{	
	#if RCC_CLOCK_TYPE	==	RCC_HSE_CRYSTAL
	
		SET_BIT(RCC_CR,BIT_NUM16);	/*Enable HSE withpybass */
		CLR_BIT(RCC_CR,BIT_NUM18);  /* choose Crystal external (enable by pass bass mode )*/

		SET_BIT(RCC_CFGR,BIT_NUM0); /*choose the system clock that go to processor  */
		CLR_BIT(RCC_CFGR,BIT_NUM1);
	
	#elif 	RCC_CLOCK_TYPE == RCC_HSE_RC
	

		SET_BIT(RCC_CR,BIT_NUM16);	/*Enable HSE withpybass */
		SET_BIT(RCC_CR,BIT_NUM18);  /* choose RC external (enable by pass bass mode )*/

		SET_BIT(RCC_CFGR,BIT_NUM0); /*choose the system clock that go to processor  */
		CLR_BIT(RCC_CFGR,BIT_NUM1);


	#elif	RCC_CLOCK_TYPE	== RCC_HSI
	
		SET_BIT(RCC_CR,BIT_NUM0); /*Enable HSI + Triming = 0 */

		CLR_BIT(RCC_CFGR,BIT_NUM0);	//Select HSI system clock
		CLR_BIT(RCC_CFGR,BIT_NUM1);


	#elif	RCC_CLOCK_TYPE  == RCC_RLL

		SET_BIT(RCC_CR,BIT_NUM24);  /*to enable the PLL in RC */
	
		#if		 RCC_PLL_INPUT	== 	RCC_PLL_IN_HSI_DIV_2


		#elif 	 RCC_PLL_INPUT	==  RCC_PLL_IN_HSE_DIV_2


		#elif 	 RCC_PLL_INPUT  ==  RCC_PLL_IN_HSE



		#else

			#error "Didn't chose the right clk type "

		#endif
	
	#else 
		
		#error("You choosed wrong clock type ")

	#endif
}
