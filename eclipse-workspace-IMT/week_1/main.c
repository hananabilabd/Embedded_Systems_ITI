/*
 * main.c
 *
 *  Created on: Feb 17, 2018
 *      Author: Hanna Nabil
 */
#define F_CPU 12000000UL
#include <util/delay.h>
#include "typedef.h"
//#include "IO.h"
#include "DIO.h"
//#define DDRA *((volatile u8*)0x3A);
int main(void)
{
	DIO_setPortDirection('D',0xFF);
	//DIO_setPortDirection('D',0xFF);//Set Port D as output
	//DIO_setPortValue('D',0xFF);
	/* lab2 to read High values from switch connected to PortD and present it on LEDS on PortD
	DIO_setPortDirection('D',0x00);//Set Port D as input
	DIO_setPortDirection('B',0xFF); // set Port B as output for the leds
	*/
	while(1){
		/* lab2
		  u8 x =DIO_ReadPortValue('D');
		DIO_setPortValue('B',x);
*/
   // bnwr led 3 we 4 fl nos we b3dan 2 & 5 ((mn gwa l7ad bra ))
		DIO_SetPinValue('D',3,1);DIO_SetPinValue('D',4,1);_delay_ms(100);
		DIO_SetPinValue('D',3,0);DIO_SetPinValue('D',4,0);_delay_ms(100);
		DIO_SetPinValue('D',2,1);DIO_SetPinValue('D',5,1);_delay_ms(100);
		DIO_SetPinValue('D',2,0);DIO_SetPinValue('D',5,0);_delay_ms(100);
		DIO_SetPinValue('D',1,1);DIO_SetPinValue('D',6,1);_delay_ms(100);
		DIO_SetPinValue('D',1,0);DIO_SetPinValue('D',6,0);_delay_ms(100);
		DIO_SetPinValue('D',0,1);DIO_SetPinValue('D',7,1);_delay_ms(100);
		DIO_SetPinValue('D',0,0);DIO_SetPinValue('D',7,0);_delay_ms(100);


/*
// Kharb Experiment
		PORTB =0x01;_delay_ms(50);
		PORTB =0x02;_delay_ms(50);
		PORTB =0x04;_delay_ms(50);
		PORTB =0x08;_delay_ms(50);
		PORTB =0x10;_delay_ms(50);
		PORTB =0x20;_delay_ms(50);
		PORTB =0x40;_delay_ms(50);
		PORTB =0x80;_delay_ms(50);
*/

	}

return 0;
}

