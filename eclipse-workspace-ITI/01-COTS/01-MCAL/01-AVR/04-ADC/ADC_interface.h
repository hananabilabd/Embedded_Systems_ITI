/*
 * ADC_interface.h
 *
 *  Created on: Apr 12, 2019
 *      Author: Hanna Nabil
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_CHANNEL_SELECTED_ADC0                                            0b00000
#define ADC_CHANNEL_SELECTED_ADC1                                            0b00001
#define ADC_CHANNEL_SELECTED_ADC2                                            0b00010
#define ADC_CHANNEL_SELECTED_ADC3                                            0b00011
#define ADC_CHANNEL_SELECTED_ADC4                                            0b00100
#define ADC_CHANNEL_SELECTED_ADC5                                            0b00101
#define ADC_CHANNEL_SELECTED_ADC6                                            0b00110
#define ADC_CHANNEL_SELECTED_ADC7                                            0b00111
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC0_NEGATIVE_ADC0_GAIN_10              0b01000
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC1_NEGATIVE_ADC0_GAIN_10              0b01001
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC0_NEGATIVE_ADC0_GAIN_200             0b01010
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC1_NEGATIVE_ADC0_GAIN_200             0b01011
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC2_NEGATIVE_ADC2_GAIN_10              0b01100
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC3_NEGATIVE_ADC2_GAIN_10              0b01101
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC2_NEGATIVE_ADC2_GAIN_200             0b01110
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC3_NEGATIVE_ADC2_GAIN_200             0b01111
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC0_NEGATIVE_ADC1_GAIN_1               0b10000
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC1_NEGATIVE_ADC1_GAIN_1               0b10001
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC2_NEGATIVE_ADC1_GAIN_1               0b10010
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC3_NEGATIVE_ADC1_GAIN_1               0b10011
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC4_NEGATIVE_ADC1_GAIN_1               0b10100
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC5_NEGATIVE_ADC1_GAIN_1               0b10101
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC6_NEGATIVE_ADC1_GAIN_1               0b10110
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC7_NEGATIVE_ADC1_GAIN_1               0b10111
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC0_NEGATIVE_ADC2_GAIN_1               0b11000
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC1_NEGATIVE_ADC2_GAIN_1               0b11001
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC2_NEGATIVE_ADC2_GAIN_1               0b11010
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC3_NEGATIVE_ADC2_GAIN_1               0b11011
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC4_NEGATIVE_ADC2_GAIN_1               0b11100
#define ADC_CHANNEL_SELECTED_POSTIVE_ADC5_NEGATIVE_ADC1_GAIN_1               0b11101
#define ADC_CHANNEL_SELECTED_1_22V                                           0b11110
#define ADC_CHANNEL_SELECTED_0V                                              0b11111



#define ADC_AUTO_TRIGGER_SOURCE_FREE_RUNNING_MODE                            0x00
#define ADC_AUTO_TRIGGER_SOURCE_ANALOG_COMPARATOR                            0x20
#define ADC_AUTO_TRIGGER_SOURCE_EXTERNAL_INTERRUPT_REQUEST0                  0x40
#define ADC_AUTO_TRIGGER_SOURCE_TIMER0_COMPARE_MATCH                         0x60
#define ADC_AUTO_TRIGGER_SOURCE_TIMER0_OVERFLOW                              0x80
#define ADC_AUTO_TRIGGER_SOURCE_TIMER_COMPARE_MATCH_B                        0xA0
#define ADC_AUTO_TRIGGER_SOURCE_TIMER1_OVERFLOW                              0xC0
#define ADC_AUTO_TRIGGER_SOURCE_TIMER1_CAPTURE_EVENT                         0xE0

#define ADC_PRESCALER_2                                                      0x00
#define ADC_PRESCALER_4                                                      0x02
#define ADC_PRESCALER_8                                                      0x03
#define ADC_PRESCALER_16                                                     0x04
#define ADC_PRESCALER_32                                                     0x05
#define ADC_PRESCALER_64                                                     0x06
#define ADC_PRESCALER_128                                                    0x07

#define ADC_ENABLE                                                           0x80

void ADC_voidInitiliaze(void);
void ADC_voidMultiplexerSelection(u8 Copy_u8ADC_ChannelSelected);
void ADC_voidSetPrescaler(u8 Copy_u8ADC_Prescaler);
void ADC_voidSelectAutoTriggerSource(u8 Copy_u8ADC_autoTriggerSource);
void ADC_voidEnableAutoTriggerSource(void);
void ADC_voidDisableADC(void);
void ADC_voidEnableADC(void);
void ADC_voidGetADC(u16 * Copy_u8ADC_Value);
void ADC_voidGetAnalogVoltage(u16 * Copy_u8Analog_Value);





#endif /* ADC_INTERFACE_H_ */
