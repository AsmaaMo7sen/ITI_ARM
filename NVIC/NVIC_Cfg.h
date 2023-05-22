/*
 * NVIC_Cfg.h
 *
 *  Created on: May 22, 2023
 *      Author: shady
 */

#ifndef MCAL_NVIC_NVIC_CFG_H_
#define MCAL_NVIC_NVIC_CFG_H_

#include "NVIC_private.h"

/*this cfg parameter is to set how to divide sw priority */

/*
options:
GROUP4_SUB0
GROUP3_SUB1
GROUP2_SUB2
GROUP1_SUB3
GROUP0_SUB4
*/

#define PRIORITY_CONFIG       GROUP0_SUB4 




#endif /* MCAL_NVIC_NVIC_CFG_H_ */
