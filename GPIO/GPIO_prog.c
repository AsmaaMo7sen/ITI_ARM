/*
 * GPIO_prog.c
 *
 *  Created on: May 11, 2023
 *      Author: 20115
 */

#include "GPIO_interface.h"
#include "..\..\LIB\BIT_MATH.h"



void GPIO_voidInitOutputPin(GPIO_Port_Type port, GPIO_Pin_Type pin, GPIO_Mode_Type mode, GPIO_Speed_Type speed)
{
    switch (port)
    {
    case GPIO_PORTA:
        /*Set the direction to be Output*/
        /*bit masking*/
        GPIOA->MODER &= ~((0b11<<(pin*2)));
        GPIOA->MODER |= ~((0b01<<(pin*2)));
        
        /*Set the speed to be Output*/
        /*bit masking*/
        GPIOA->OSPEEDR &= ~((0b11<<(pin*2)));
        GPIOA->OSPEEDR |= ~((speed<<(pin*2)));

        /*Set type of output pin*/
        WRT_BIT(GPIOA->OTYPER, pin , mode);
        

        
        break;
    
    case GPIO_PORTB:

        GPIOB->MODER &= ~(0b11 << (pin * 2));
        GPIOB->MODER |=  (0b01 << (pin * 2));
    
        /*Set type of output pin*/
        WRT_BIT(GPIOB->OTYPER, pin , mode);
        
        break;
    
    case GPIO_PORTC:

        GPIOC->MODER &= ~(0b11 << (pin * 2));
        GPIOC->MODER |= (0b01 << (pin * 2));

        /*Set type of output pin*/
        WRT_BIT(GPIOC->OTYPER, pin , mode);
        
        break;
    
    default:
        break;
    }
}

void GPIO_voidInitInputPin(GPIO_Port_Type port, GPIO_Pin_Type pin, GPIO_Mode_Type mode)
{
}

void GPIO_voidSetOutPinValue(GPIO_Port_Type port, GPIO_Pin_Type pin, GPIO_Pin_Level_Type value)
{
      switch (port)
    {
    case GPIO_PORTA:
       
        WRT_BIT(GPIOA->ODR,pin,value);

        break;
    
    case GPIO_PORTB:

        WRT_BIT(GPIOB->ODR,pin,value);

        break;
    
    case GPIO_PORTC:

        WRT_BIT(GPIOC->ODR,pin,value);

        break;
    
    default:
        break;
    }
}

GPIO_Pin_Level_Type GPIO_voidGetInputPinValue(GPIO_Port_Type port, GPIO_Pin_Type pin)
{
	
  GPIO_Pin_Level_Type value;

  switch (port)
  {
  case GPIO_PORTA:
    value = GPIOA->IDR & (1 << pin);
    break;

  case GPIO_PORTB:
    value = GPIOB->IDR & (1 << pin);
    break;

  case GPIO_PORTC:
    value = GPIOC->IDR & (1 << pin);
    break;

  default:
    value = 0;
    break;
  }

  return value;
}

void GPIO_voidSetOutPinValueFast(GPIO_Port_Type port, GPIO_Pin_Type pin, GPIO_Pin_Level_Type value)
{
    u32 local_u32RegVal=0;
    switch (port)
    {
    case GPIO_PORTA:
        {
            switch (value)
            {
            case GPIO_OUTPUT_HIGH:
                local_u32RegVal  = 1<<pin;
                break;
            
            case GPIO_OUTPUT_LOW:
                local_u32RegVal  = 1<<(pin+16);
                break;
            
            default:
                break;
            }
            GPIOA->BSRR = local_u32RegVal;
        }
        break;
    
    default:
        break;
    }
}
