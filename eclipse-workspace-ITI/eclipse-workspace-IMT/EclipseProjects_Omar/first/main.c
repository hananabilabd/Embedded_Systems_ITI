/*
 * main.c

 *
 *  Created on: Oct 18, 2017
 *      Author: Hanna Nabil
 */
#define F_CPU 8000000
#include<util/delay.h>
#include <avr/io.h>
void main(void)
{
	DDRA =0xFF;
	DDRC =0xFF;
	while (1)
	{
	PORTA =0x01;PORTC =0x01;_delay_ms(100);
	PORTA =0x02;PORTC =0x02;_delay_ms(100);
	PORTA =0x04;PORTC =0x04;_delay_ms(100);
	PORTA =0x08;PORTC =0x08;_delay_ms(100);
		PORTA =0x10;PORTC =0x10;_delay_ms(100);
		PORTA =0x20;PORTC =0x20;_delay_ms(100);
		PORTA =0x40;PORTC =0x40;_delay_ms(100);
		PORTA =0x80;PORTC =0x80;_delay_ms(100);
	}
}
