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
#include "ExtInterrupt_interface.h"
#include "SW-ICU_interface.h"

int main(void){
	u16 duty=0,period,frequency;
	u16 offTime =0,onTime =0;
	LCD_voidInitialize();
	Timer_voidIntialize();
	Timer_voidSetPrescaler(TIMER_INDEX_TIMER1,TIMER_PRESCALER_8);
	ICU_voidInitialize();
	ICU_voidEnable();

	//SW_ICU_voidInitialize(SW_ICU_INDEX_EXTI0);
	//SW_ICU_voidEnable(SW_ICU_INDEX_EXTI0);// this made you connect pin B3 to Ext0 pin which is D2

	/*output pwm signal of 50 duty and prescaler 8 from timer 0 on pin B3*/
	DIO_u8SetPinDirection(DIO_U8_PIN_B3,DIO_U8_OUTPUT);
	//TCNT0=1;
	//TIMSK |= 0x00;
	//SREG |= 0x80;
	TCCR0 = 0b01100010;
	//TCCR0 = 0b00001011;//fast PWM
	OCR0=128;//

	//TCCR1A |= 0x00;
	//TCCR1B |= 0x02;







	while(1){
		//ICU_voidGetDuty(&duty);
		ICU_voidGetOnTime(&onTime);
		ICU_voidGetOffTime(&offTime);
		//ICU_voidGetFrequency(&frequency);
		//ICU_voidGetPeriod(&period);

		//SW_ICU_voidGetOnTime(SW_ICU_INDEX_EXTI0,&onTime);
		//SW_ICU_voidGetOffTime(SW_ICU_INDEX_EXTI0,&offTime);
		//SW_ICU_voidGetDuty(SW_ICU_INDEX_EXTI0,&duty);
		//SW_ICU_voidGetPeriod(SW_ICU_INDEX_EXTI0,&period);
		//SW_ICU_voidGetFrequency(SW_ICU_INDEX_EXTI0,&frequency);
		LCD_voidClearScreen();
		LCD_voidSetPosition(0,0);
		LCD_voidWriteNumber(onTime);
		LCD_voidSetPosition(1,0);
		LCD_voidWriteNumber(onTime);
		delay_ms(200);

	}
return 0 ;
}
