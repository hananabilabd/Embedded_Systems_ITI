/*
 * Timer_interface.h
 *
 *  Created on: Apr 2, 2019
 *      Author: Hanna Nabil
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define TIMER_PRESCALER_1     0b001
#define TIMER_PRESCALER_8     0b010
#define TIMER_PRESCALER_64    0b011
#define TIMER_PRESCALER_256   0b100
#define TIMER_PRESCALER_1024  0b101

#define TIMER_INDEX_TIMER0    0
#define TIMER_INDEX_TIMER1    1
#define TIMER_INDEX_TIMER2    2

#define TIMER_CALLBACK_TIMER2_COMPARE                  0
#define TIMER_CALLBACK_TIMER2_OVERFLOW                 1
#define TIMER_CALLBACK_TIMER1_CAPTURE                  2
#define TIMER_CALLBACK_TIMER1_COMPARE_A                3
#define TIMER_CALLBACK_TIMER1_COMPARE_B                4
#define TIMER_CALLBACK_TIMER1_OVERFLOW                 5
#define TIMER_CALLBACK_TIMER0_COMPARE                  6
#define TIMER_CALLBACK_TIMER0_OVERFLOW                 7

#define TIMER_MODE_TIMER0_OVERFLOW                     0x00
#define TIMER_MODE_TIMER0_PWM_PHASE                    0x40
#define TIMER_MODE_TIMER0_COMPARE                      0x08
#define TIMER_MODE_TIMER0_PWM_FAST                     0x48
#define TIMER_MODE_TIMER1_OVERFLOW                     0
#define TIMER_MODE_TIMER1_PWM_PHASE_8BIT               1
#define TIMER_MODE_TIMER1_PWM_PHASE_9BIT               2
#define TIMER_MODE_TIMER1_PWM_PHASE_10BIT              3
#define TIMER_MODE_TIMER1_COMPARE_OCR1A                4
#define TIMER_MODE_TIMER1_PWM_FAST_8BIT                5
#define TIMER_MODE_TIMER1_PWM_FAST_9BIT                6
#define TIMER_MODE_TIMER1_PWM_FAST_10BIT               7
#define TIMER_MODE_TIMER1_PWM_PHASE_AND_FREQUENCY_ICR1      8
#define TIMER_MODE_TIMER1_PWM_PHASE_AND_FREQUENCY_OCR1A      9
#define TIMER_MODE_TIMER1_PWM_PHASE_ICR1                    10
#define TIMER_MODE_TIMER1_PWM_PHASE_OCR1A                    11
#define TIMER_MODE_TIMER1_COMPARE                      12
#define TIMER_MODE_TIMER1_PWM_FAST_ICR1                14
#define TIMER_MODE_TIMER1_PWM_FAST_OCR1A               15
#define TIMER_MODE_TIMER2_OVERFLOW                     0x00
#define TIMER_MODE_TIMER2_PWM_PHASE                    0x40
#define TIMER_MODE_TIMER2_COMPARE_ICR1                 0x08
#define TIMER_MODE_TIMER2_PWM_FAST                     0x48



#define TIMER_OC_PIN_MODE_TIMER0_OC0_DISCONNECTED                 0x00
#define TIMER_OC_PIN_MODE_TIMER0_OC0_TOGGLE                       0x10
#define TIMER_OC_PIN_MODE_TIMER0_OC0_CLEAR                        0x20
#define TIMER_OC_PIN_MODE_TIMER0_OC0_SET                          0x30
#define TIMER_OC_PIN_MODE_TIMER1_OC1A_DISCONNECTED                0x32//wrong number just to make difference between OC1A and OC1B
#define TIMER_OC_PIN_MODE_TIMER1_OC1A_TOGGLE                      0x40
#define TIMER_OC_PIN_MODE_TIMER1_OC1A_CLEAR                       0x80
#define TIMER_OC_PIN_MODE_TIMER1_OC1A_SET                         0xC0
#define TIMER_OC_PIN_MODE_TIMER1_OC1B_DISCONNECTED                0x00
#define TIMER_OC_PIN_MODE_TIMER1_OC1B_TOGGLE                      0x10
#define TIMER_OC_PIN_MODE_TIMER1_OC1B_CLEAR                       0x20
#define TIMER_OC_PIN_MODE_TIMER1_OC1B_SET                         0x30

#define TIMER_OC_PIN_MODE_TIMER0_OC2_DISCONNECTED                 0x00
#define TIMER_OC_PIN_MODE_TIMER0_OC2_TOGGLE                       0x10
#define TIMER_OC_PIN_MODE_TIMER0_OC2_CLEAR                        0x20
#define TIMER_OC_PIN_MODE_TIMER0_OC2_SET                          0x30

#define TIMER_DISABLED    0b000
#define TIMER_ICU_RISING_EDGE     1
#define TIMER_ICU_FALLING_EDGE    0
u8 Timer_u8prescaler(u8 Copy_u8TimerIndex,u8 Copy_u8Prescaler);

#endif /* TIMER_INTERFACE_H_ */
