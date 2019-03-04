/*
 * RCC_interface.h
 *
 *  Created on: Feb 21, 2019
 *      Author: Hanna Nabil
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define ON  1
#define OFF 0

#define RCC_u8_ENABLE_CLK   1 
#define RCC_u8_DISABLE_CLK  0 

void RCC_voidInitialize(void);
void RCC_voidSetPeripheralClockState(u8 Copy_u8PeripheralNumber , u8 copy_u8State);

#define RCC_u8_GPIOA 2
#define RCC_u8_GPIOB 3
#define RCC_u8_GPIOC 4
#define RCC_u8_GPIOD 5


#endif /* RCC_INTERFACE_H_ */
