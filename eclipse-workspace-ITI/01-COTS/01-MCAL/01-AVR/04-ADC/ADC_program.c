/*
 * ADC_program.c
 *
 *  Created on: Apr 12, 2019
 *      Author: Hanna Nabil
 */

#include "STD_TYPES.h"
#include"BIT_CALC.h"
#include"Timer_interface.h"
#include"Timer_config.h"
#include"Timer_private.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include "delay.h"

void ADC_voidInitiliaze(void){
	ADMUX = (ADMUX & 0x00) | ADC_VOLTAGE_REFERENCE_SELECTED |ADC_ADJUSTMENT_SELECTED;
	ADCSRA = (ADCSRA & 0X70) | ADC_ENABLE;
}
void ADC_voidMultiplexerSelection(u8 Copy_u8ADC_ChannelSelected){
	ADMUX = (ADMUX & 0xE0) | Copy_u8ADC_ChannelSelected;
}
void ADC_voidSetPrescaler(u8 Copy_u8ADC_Prescaler){
	ADCSRA= (ADCSRA & 0xF8)| Copy_u8ADC_Prescaler;
}
void ADC_voidSelectAutoTriggerSource(u8 Copy_u8ADC_autoTriggerSource){
	SFIOR = (SFIOR & 0x1F) | Copy_u8ADC_autoTriggerSource;
}
void ADC_voidEnableAutoTriggerSource(void){
	ADCSRA = 0x20;
}
void ADC_voidDisableADC(void){
	ADCSRA &= 0x7F;
}
void ADC_voidEnableADC(void){
	ADCSRA |= ADC_ENABLE;
}
void ADC_voidGetADC(u16 * Copy_u8ADC_Value){
	ADCSRA |= 0x40;
	while (ADCSRA >> 4 == 0); // checking if ADC interrupt flag to check if conversion has ended
#if ADC_ADJUSTMENT_SELECTED == ADC_ADJUSTMENT_LEFT
	*Copy_u8ADC_Value = (ADCL >> 6 )+  ((u16)ADCH <<2);
#elif ADC_ADJUSTMENT_SELECTED == ADC_ADJUSTMENT_RIGHT
	*Copy_u8ADC_Value = (u16)ADCL + (u16)ADCH*256;
#endif
}
void ADC_voidGetAnalogVoltage(u16 * Copy_u8Analog_Value){
	ADCSRA |= 0x40;
	while (ADCSRA >> 4 == 0); // checking if ADC interrupt flag to check if conversion has ended
	delay_us(10);
#if ADC_ADJUSTMENT_SELECTED == ADC_ADJUSTMENT_LEFT
	*Copy_u8Analog_Value = ((ADCL >> 6 )+  ((u16)ADCH <<2) ) * (f64)500 / 1024;
#elif ADC_ADJUSTMENT_SELECTED == ADC_ADJUSTMENT_RIGHT
	*Copy_u8Analog_Value = ((u16)ADCL + (u16)ADCH*256 )* (f64)50 / 1024.0;
#endif
}
