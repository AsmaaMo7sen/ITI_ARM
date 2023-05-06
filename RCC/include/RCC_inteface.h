/*
 * RCC_inteface.h
 *
 *  Created on: May 4, 2023
 *      Author: 20115
 */

#ifndef RCC_INTEFACE_H_
#define RCC_INTEFACE_H_

#include "STD_TYPES.h"
/*******************************Interfacing Macros*******************************/



/********************************************************************************/

/*******************************Interfacing Funcs*******************************/

void RCC_voidSetSystemClock(void);
void RCC_voidEnablePeripheralClock(u8 BusID, u8 PeripheralID);
void RCC_voidDisablePeripheralClock(u8 BusID, u8 PeripheralID);

/********************************************************************************/


#endif /* RCC_INTEFACE_H_ */
