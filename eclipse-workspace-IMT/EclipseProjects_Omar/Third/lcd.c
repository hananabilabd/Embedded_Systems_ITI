/*
 * main.c
 *
 *  Created on: Oct 23, 2017
 *      Author: Hanna Nabil
 */
/*
Rs----------Ao
RW ---------A1
E-----------A2
D0 ----------D0
D7-----------D7
*/
#define F_CPU 8000000
#include<util/delay.h>
#include <AVR/io.h>
#include "macros.h"
#include "typedef.h"
void main(void)
{
	lcd_init();
	lcd_writecharacter('h');
	while (1)
	{


}
void lcd_init(void){
	DDRD=0xFF;
	set_bit(DDRA,0);
	set_bit(DDRA,1);
	set_bit(DDRA,2);
	clr_bit(PORTA,2);
	lcd_sendcommand(0x38);_delay_ms(1);
	lcd_sendcommand(0x0c);_delay_ms(1);
	lcd_sendcommand(0x01);_delay_ms(1);//clear lcd
}
void lcd_sendcommand(u8 command){
	clr_bit(PORTA,0);
	clr_bit(PORTA,1);
	PORTD =command;
	set_bit(PORTA,2);
	_delay_ms(2);
	clr_bit(PORTA,2);

}
void lcd_writecharacter(u8 character){
	set_bit(PORTA,0);
	clr_bit(PORTA,1);
	PORTD = character;
	set_bit(PORTA,2);
	_delay_ms(2);
	clr_bit(PORTA,2);

}
