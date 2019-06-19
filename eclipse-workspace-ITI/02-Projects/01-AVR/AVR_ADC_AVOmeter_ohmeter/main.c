/*
 * main.c
 *
 *  Created on: Mar 14, 2019
 *      Author: Hanna Nabil
 */

#include "STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_interface.h"
//#include"DIO_config.h"
#define F_CPU 12000000UL
//#include <util/delay.h>
#include "DIO_private.h"
#include "LCD_interface.h"
#include"delay.h"
#include "Timer_interface.h"
#include "ADC_interface.h"



int main(void){
	LCD_voidInitialize();
	ADC_voidInitiliaze();
	ADC_voidSetPrescaler(ADC_PRESCALER_2);

	u16 v1,v2,v;
	u8 status;
	f64 ammeter,temp;
	u16 temp2;
	f64 z;
	DIO_u8SetPinDirection(DIO_U8_PIN_D0,0);
	DIO_u8SetPinValue(DIO_U8_PIN_D0,1);
	ADC_voidMultiplexerSelection(ADC_CHANNEL_SELECTED_ADC0);



	while(1){
		// LDR equation
		//ADC_voidGetAnalogVoltage(&x);
		//v=((f64)x*1000)/(50-x);
		////////////////////////////////////////////////////////////////////////////

		LCD_voidClearScreen();

		DIO_u8GetPinValue(DIO_U8_PIN_D0,&status);
		//status=0;
		LCD_voidSetPosition(0,0);
		if (status == 0){//pressed
			ADC_voidMultiplexerSelection(ADC_CHANNEL_SELECTED_ADC0);
			ADC_voidGetAnalogVoltage(&v);
			temp2=((f64)v*1000)/(500-v);
			LCD_voidWriteString("Ohmmeter:");
			LCD_voidWriteNumber(temp2);
		}
		else {
			ADC_voidMultiplexerSelection(ADC_CHANNEL_SELECTED_ADC0);
			ADC_voidGetAnalogVoltage(&v);
			LCD_voidWriteString("Voltmeter:");
			temp = (f64)v/100.0;
			LCD_voidWriteFloat(temp);
			//LCD_voidWriteString(' v');
		}


		ADC_voidMultiplexerSelection(ADC_CHANNEL_SELECTED_ADC1);
		ADC_voidGetAnalogVoltage(&v1);
		//delay_ms(1);
		ADC_voidMultiplexerSelection(ADC_CHANNEL_SELECTED_ADC2);
		ADC_voidGetAnalogVoltage(&v2);
		if ( v2 > v1 ) {
		ammeter = ((f64)v2-v1)/2;
		}
		else {
			ammeter=0;
		}
		LCD_voidSetPosition(1,0);
		LCD_voidWriteString("Ammeter:");
		LCD_voidWriteFloat(ammeter);
		LCD_voidWriteString("mA");

		delay_ms(200);



	}
return 0 ;
}
