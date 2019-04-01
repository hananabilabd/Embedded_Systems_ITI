/*
 * Interrupt_interface.h
 *
 *  Created on: Mar 14, 2019
 *      Author: Hanna Nabil
 */

#ifndef INTERRUPT_INTERFACE_H_
#define INTERRUPT_INTERFACE_H_

void Interrupt_voidSetCallback(u8 Copy_u8Index,void (*Copy_ptr)(void));
u8 Interrupt_setLevel(u8 Copy_u8Index,u8 Copy_u8Level);
void Interrupt_Disable(u8 Copy_u8Index);
void Interrupt_Enable(u8 Copy_u8Index);
void Interrupt_Initialize(void);
void __vector_1 (void) __attribute__((signal));
void __vector_2 (void) __attribute__((signal));
void __vector_3 (void) __attribute__((signal));

#define INTERRUPT_INT0    0
#define INTERRUPT_INT1    1
#define INTERRUPT_INT2    2
#define INTERRUPT_LEVEL_RISING_EDGE          0b11
#define INTERRUPT_LEVEL_FALLING_EDGE         0b10
#define INTERRUPT_LEVEL_ANY_LOGICAL_CHANGE   0b01
#define INTERRUPT_LEVEL_LOW_LEVEL            0b00
#endif /* INTERRUPT_INTERFACE_H_ */
