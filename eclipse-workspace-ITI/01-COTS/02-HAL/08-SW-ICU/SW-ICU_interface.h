/*
 * SW-ICU_interface.h
 *
 *  Created on: Apr 7, 2019
 *      Author: Hanna Nabil
 */

#ifndef SW_ICU_INTERFACE_H_
#define SW_ICU_INTERFACE_H_


#define SW_ICU_SELECT_EDGE_RISING                          EXTINTERRUPT_LEVEL_RISING_EDGE
#define SW_ICU_SELECT_EDGE_FALLING                         EXTINTERRUPT_LEVEL_FALLING_EDGE

#define SW_ICU_INDEX_EXTI0                                 EXTINTERRUPT_INT0
#define SW_ICU_INDEX_EXTI1                                 EXTINTERRUPT_INT1
#define SW_ICU_INDEX_EXTI2                                 EXTINTERRUPT_INT2

#define SW_ICU_INDEX_TIMER0									TIMER_INDEX_TIMER0
#define SW_ICU_INDEX_TIMER1                                 TIMER_INDEX_TIMER1
#define SW_ICU_INDEX_TIMER2                                 TIMER_INDEX_TIMER2

#define SW_ICU_TIMER_PRESCALER_1                              TIMER_PRESCALER_1
#define SW_ICU_TIMER_PRESCALER_8                              TIMER_PRESCALER_8
#define SW_ICU_TIMER_PRESCALER_64                             TIMER_PRESCALER_64
#define SW_ICU_TIMER_PRESCALER_256                            TIMER_PRESCALER_256
#define SW_ICU_TIMER_PRESCALER_1024                           TIMER_PRESCALER_1024

void SW_ICU_voidInitialize(u8 Copy_u8SW_ICU_IndexEXTI);
void SW_ICU_voidEnable(u8 Copy_u8SW_ICU_IndexEXTI);
void SW_ICU_voidDisable(u8 Copy_u8SW_ICU_IndexEXTI);
void SW_ICU_voidGetPeriod(u8 Copy_u8SW_ICU_IndexEXTI,u16 *Copy_u8SW_ICU_period);
void SW_ICU_voidGetDuty(u8 Copy_u8SW_ICU_IndexEXTI,u16 *Copy_u8SW_ICU_duty);
void SW_ICU_voidGetFrequency(u8 Copy_u8SW_ICU_IndexEXTI,u16 *Copy_u8SW_ICU_Frequency);
void SW_ICU_voidGetOnTime(u8 Copy_u8SW_ICU_IndexEXTI,u16 *Copy_u8ICU_OnTime);
void SW_ICU_voidGetOffTime(u8 Copy_u8SW_ICU_IndexEXTI,u16 *Copy_u8ICU_OffTime);

#endif /* SW_ICU_INTERFACE_H_ */
