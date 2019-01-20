/*
 * interupt.c
 *
 *  Created on: Nov 1, 2017
 *      Author: Hanna Nabil
 */


#include <AVR/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include "MACROS.h"
#include "typedef.h"
#include <avr/interrupt.h>

ISR(INT0_vect){//this is interrupt 0 for turn off the led
	set_bit(PORTA,0);// make the led on
}

int main(){
	set_bit(DDRA,0);

	clr_bit(DDRD,2);//make pin 2 in PORTD input
	set_bit(PORTD,2);//make it PULLUP

	clr_bit(MCUCR,0);//LOW LEVEL NTERRUPT -> ISC00 bit
	clr_bit(MCUCR,1);//LOW LEVEL NTERRUPT -> ISC01 bit

	set_bit(GICR,6);//EXTERNAL interrupt enable -> pin #6 = 1 for EXTERNAL INTERRUPT(PIE)
	set_bit(SREG,7);//GLOBAL interrupt enable -> pin #7 = 1 is I pin for global interrupt(GIE)

	while(1){
		clr_bit(PORTA,0);//make the led off
	}
	return 0;
}
