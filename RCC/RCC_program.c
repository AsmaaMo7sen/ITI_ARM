/*
 * RCC_program.c
 *
 *  Created on: May 6, 2023
 *      Author: ss210
 */
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"
#include "RCC_config.h"
#include "RCC_interface.h"
#include "RCC_private.h"

void RCC_enable_preihreal_clock(u8 bus_id,u8 peripheral_id){
	switch(bus_id){
	case RCC_AHB1:
		set_bit(RCC_AHB1ENR,peripheral_id);
		break;
	case RCC_AHB2:
		set_bit(RCC_AHB2ENR,peripheral_id);
		break;
	case RCC_APB1:
		set_bit(RCC_APB1ENR,peripheral_id);
		break;
	case RCC_APB2:
		set_bit(RCC_APB2ENR,peripheral_id);
		break;
	}
}
void RCC_disable_preihreal_clock(u8 bus_id,u8 peripheral_id){
	switch(bus_id){
	case RCC_AHB1:
		clr_bit(RCC_AHB1ENR,peripheral_id);
		break;
	case RCC_AHB2:
		clr_bit(RCC_AHB2ENR,peripheral_id);
		break;
	case RCC_APB1:
		clr_bit(RCC_APB1ENR,peripheral_id);
		break;
	case RCC_APB2:
		clr_bit(RCC_APB2ENR,peripheral_id);
		break;
	}
}
void RCC_set_system_clock(System_clock_source source){
	switch(source){
	case HSI:
		set_bit(RCC_CR,0);
		clr_bit(RCC_CFGR,0);
		clr_bit(RCC_CFGR,1);
		break;
	case HSE_RC:
		set_bit(RCC_CR,16);
		set_bit(RCC_CR,18);
		set_bit(RCC_CFGR,0);
		clr_bit(RCC_CFGR,1);
		break;
	case HSE_CRYSTAL:
		set_bit(RCC_CR,16);
		clr_bit(RCC_CR,18);
		set_bit(RCC_CFGR,0);
		clr_bit(RCC_CFGR,1);
		break;
	case PLL:
		/**/
		break;
	}
}
