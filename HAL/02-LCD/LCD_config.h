/*************************************/
/* Author:  Mena Ghobrial            */
/* Date:    16 OCT 2022              */
/* Version: V01                      */
/*************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H


/* LCD Mode -> {HLCD_4_BIT_MODE, HLCD_8_BIT_MODE} */
#define HLCD_MODE       HLCD_4_BIT_MODE

/* Control Pins */
#define HLCD_RS        GPIOC_PORT, GPIO_PIN8
#define HLCD_RW        GPIOC_PORT, GPIO_PIN9
#define HLCD_EN        GPIOC_PORT, GPIO_PIN10

/* Data pins */
#define HLCD_D0        GPIOC_PORT, GPIO_PIN0
#define HLCD_D1        GPIOC_PORT, GPIO_PIN1
#define HLCD_D2        GPIOC_PORT, GPIO_PIN2
#define HLCD_D3        GPIOC_PORT, GPIO_PIN3
#define HLCD_D4        GPIOC_PORT, GPIO_PIN4
#define HLCD_D5        GPIOC_PORT, GPIO_PIN5
#define HLCD_D6        GPIOC_PORT, GPIO_PIN6
#define HLCD_D7        GPIOC_PORT, GPIO_PIN7



#endif /* LCD_CONFIG_H */