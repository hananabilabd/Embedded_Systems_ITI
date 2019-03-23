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
void blink(void){
	static u8 var=0;
	toggle_bit(var,0);
	DIO_u8SetPinValue(DIO_U8_PIN_C0,var);
		//_delay_ms(100);
}
int main(void){
	DIO_u8SetPinDirection(DIO_U8_PIN_C0,DIO_U8_OUTPUT);
Interrupt_Initialize();
Interrupt_Enable(INTERRUPT_INT0);
Interrupt_setLevel(INTERRUPT_INT0,INTERRUPT_LEVEL_FALLING_EDGE);
Interrupt_voidSetCallback(INTERRUPT_INT0,blink);



while(1){
	//DIO_u8SetPinValue(DIO_U8_PIN_C0,DIO_U8_LOW);
}
return 0 ;
}
