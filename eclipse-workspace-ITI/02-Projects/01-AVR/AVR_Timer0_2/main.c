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
#include <ExternalInterrupt_interface.h>
u16 counter = 0;
 u32 i=0;

u16 offTime =0;
u16 onTime =0;
void test(void){
	static u8 flag =0 ;
	if ( flag ==0 ){
		offTime = TCNT1;
		TCNT1=0;
		Interrupt_setLevel(INTERRUPT_INT0,INTERRUPT_LEVEL_FALLING_EDGE);
		flag =1 ;
	}
	else {
		onTime = TCNT1;
		TCNT1 = 0;
		Interrupt_setLevel(INTERRUPT_INT0,INTERRUPT_LEVEL_RISING_EDGE);
		flag =0;
	}
}
int main(void){
	LCD_voidInitialize();
	//LCD_voidWriteString("hello");
	Interrupt_Initialize();
	Interrupt_Enable(INTERRUPT_INT0);
	Interrupt_setLevel(INTERRUPT_INT0,INTERRUPT_LEVEL_RISING_EDGE);
	Interrupt_voidSetCallback(INTERRUPT_INT0,test);
	//TCNT0=1;
	TIMSK |= 0x00;
	SREG |= 0x80;
	TCCR0 = 0b01100010;
	//TCCR0 = 0b00001011;//fast PWM
	OCR0=128;//

	TCCR1A |= 0x00;
	TCCR1B |= 0x02;

	DIO_u8SetPinDirection(DIO_U8_PIN_B3,DIO_U8_OUTPUT);




//Interrupt_Initialize();
//Interrupt_Enable(INTERRUPT_INT0);
//Interrupt_setLevel(INTERRUPT_INT0,INTERRUPT_LEVEL_FALLING_EDGE);
//Interrupt_voidSetCallback(INTERRUPT_INT0,blink);




while(1){

LCD_voidSetPosition(0,0);
LCD_voidWriteNumber(offTime);
LCD_voidSetPosition(1,0);
LCD_voidWriteNumber(onTime);

}
return 0 ;
}
