/*
 * main.c
 *
 *  Created on: Mar 14, 2019
 *      Author: Hanna Nabil
 */
#include "STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_interface.h"
#include"DIO_config.h"
#include"Interrupt_interface.h"
#define F_CPU 12000000UL
#include <util/delay.h>
#include "DIO_private.h"
u16 counter = 0;
static u8 var=0;
static u8 flag =0;
void blink(void){
	static u8 var=0;
	toggle_bit(var,0);
	DIO_u8SetPinValue(DIO_U8_PIN_C0,var);
		//_delay_ms(100);
}
void __vector_11 (void) __attribute__((signal));
void __vector_10 (void) __attribute__((signal));
void __vector_11 (void)
{

	counter ++;
	if (counter  ==5860){
			counter =0;
			TCNT0=160;

				toggle_bit(var,0);
				DIO_u8SetPinValue(DIO_U8_PIN_C0,var);
		}
}
void __vector_10 (void)//ocr interrupt
{

		var +=1;



		if ( var == 255 ){
			flag =1;
		}
		DIO_u8SetPortValue(DIO_U8_PORT_C,var);
}
int main(void){
	DIO_u8SetPinDirection(DIO_U8_PIN_C0,DIO_U8_OUTPUT);
	TCNT0=0;
	TIMSK |= 0x02;
	SREG |= 0x80;
	TCCR0 = 0b00001010;
	OCR0=50;
	DIO_u8SetPortDirection(DIO_U8_PORT_C,0b11111111);
	u8 x =0;

//Interrupt_Initialize();
//Interrupt_Enable(INTERRUPT_INT0);
//Interrupt_setLevel(INTERRUPT_INT0,INTERRUPT_LEVEL_FALLING_EDGE);
//Interrupt_voidSetCallback(INTERRUPT_INT0,blink);



while(1){


}
return 0 ;
}
