/*
 * ExtInterrupt_interface.h
 *
 *  Created on: Mar 14, 2019
 *      Author: Hanna Nabil
 */

#ifndef EXTINTERRUPT_INTERFACE_H_
#define EXTINTERRUPT_INTERFACE_H_

void ExtInterrupt_voidSetCallback(u8 Copy_u8Index,void (*Copy_ptr)(void));
u8   ExtInterrupt_setLevel(u8 Copy_u8Index,u8 Copy_u8Level);
void ExtInterrupt_Disable(u8 Copy_u8Index);
void ExtInterrupt_Enable(u8 Copy_u8Index);
void ExtInterrupt_Initialize(u8 Copy_u8Index);
void __vector_1 (void) __attribute__((signal));
void __vector_2 (void) __attribute__((signal));
void __vector_3 (void) __attribute__((signal));

#define EXTINTERRUPT_INT0    0
#define EXTINTERRUPT_INT1    1
#define EXTINTERRUPT_INT2    2
#define EXTINTERRUPT_LEVEL_RISING_EDGE          0b11
#define EXTINTERRUPT_LEVEL_FALLING_EDGE         0b10
#define EXTINTERRUPT_LEVEL_ANY_LOGICAL_CHANGE   0b01
#define EXTINTERRUPT_LEVEL_LOW_LEVEL            0b00

#endif /* EXTINTERRUPT_INTERFACE_H_ */
