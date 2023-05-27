/*******************************************/
/* Author: Mena Ghobrial                   */
/* Date:   18 SEP 2022                     */
/* Version: V01                            */
/*******************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


void MGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void MGPIO_voidSetPinOutputType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8OutputType);
void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8OutputType);
void MGPIO_voidSetPinPullType(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PullType);
u8 MGPIO_u8ReadPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);
void MGPIO_voidWritePinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue);
void MGPIO_voidSetPinAltFn(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8ALF);

/* GPIO Ports */
#define GPIOA_PORT        0
#define GPIOB_PORT        1
#define GPIOC_PORT        2
#define GPIOD_PORT        3
#define GPIOE_PORT        4
#define GPIOH_PORT        5

/* GPIO Pins */
#define GPIO_PIN0               0
#define GPIO_PIN1               1
#define GPIO_PIN2               2
#define GPIO_PIN3               3
#define GPIO_PIN4               4
#define GPIO_PIN5               5
#define GPIO_PIN6               6
#define GPIO_PIN7               7
#define GPIO_PIN8               8
#define GPIO_PIN9               9
#define GPIO_PIN10              10
#define GPIO_PIN11              11
#define GPIO_PIN12              12
#define GPIO_PIN13              13
#define GPIO_PIN14              14
#define GPIO_PIN15              15
						        
/* GPIO Modes */                
#define GPIO_INPUT              0b00
#define GPIO_OUTPUT             0b01
#define GPIO_ALTF               0b10
#define GPIO_ANALOG             0b11

/* Output Values */
#define GPIO_LOW                0
#define GPIO_HIGH               1
		        
/* Output Type */               
#define GPIO_PUSH_PULL          0
#define GPIO_OPEN_DRAIN         1

/* Output Speed */
#define GPIO_LOW_SPEED          0b00
#define GPIO_MEDIUM_SPEED       0b01
#define GPIO_HIGH_SPEED         0b10
#define GPIO_VERY_HIGH_SPEED    0b11

/* Pull Type */
#define GPIO_NO_PULL            0b00
#define GPIO_PULL_UP            0b01
#define GPIO_PULL_DOWN          0b10


/* Alternate Functions */
#define GPIO_AF0          0b0000
#define GPIO_AF1          0b0001
#define GPIO_AF2          0b0010
#define GPIO_AF3          0b0011
#define GPIO_AF4          0b0100
#define GPIO_AF5          0b0101
#define GPIO_AF6          0b0110
#define GPIO_AF7          0b0111
#define GPIO_AF8          0b1000
#define GPIO_AF9          0b1001
#define GPIO_AF10         0b1010
#define GPIO_AF11         0b1011
#define GPIO_AF12         0b1100
#define GPIO_AF13         0b1101
#define GPIO_AF14         0b1110
#define GPIO_AF15         0b1111


#endif /* GPIO_INTERFACE_H */