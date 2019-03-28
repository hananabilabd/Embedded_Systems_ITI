/*
 * dio.c
 *
 *  Created on: Oct 30, 2017
 *      Author: Hanna Nabil
 */


#include <AVR/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include "macros.h"
#include "typedef.h"

#define port_A 0
#define port_B 1
#define port_C 2
#define port_D 3

#define input 0
#define output 1

#define low 0
#define high 1

void setPinDirection(u8,u8,u8);
void setPinValue(u8,u8,u8);

void keypad_Init(void){
	DDRA = 0x0F;
	_delay_ms(1);
	PORTA = 0xF0;
	_delay_ms(1);
//	setPinDirection(port_A,0,output);
//	setPinDirection(port_A,1,output);
//	setPinDirection(port_A,2,output);
//	setPinDirection(port_A,3,output);
//	setPinDirection(port_A,4,input);
//	setPinDirection(port_A,5,input);
//	setPinDirection(port_A,6,input);
//	setPinDirection(port_A,7,input);
//	_delay_ms(1);
//	//	-----------------------------------//
//	//	initial input value POTRA 1111 as PULLUP connected
//	setPinValue(port_A,4,high);
//	setPinValue(port_A,5,high);
//	setPinValue(port_A,6,high);
//	setPinValue(port_A,7,high);
//	_delay_ms(1);
}

u8 Keypad_Getkey(void){
	u8 x;
	//CASE ONE
	PORTA = 0xFE;//1111 for input pins & 1110 for output pins
	x = PINA >> 4;
	switch(x){
	case (0x0E)://0000 1110 -> 0 now in pin 4
		return 1;
		break;
	case (0x0D)://0000 1101 -> 0 now in pin 5
		return 2;
		break;
	case (0x0B)://0000 1011 -> 0 now in pin 6
		return 3;
		break;
	case (0x07)://0000 0111 -> 0 now in pin 7
		return '+';
		break;
	}
	//CASE TWO
	PORTA = 0xFD;//1111 for input pins & 1101 for output pins
	x = PINA >> 4;
	switch(x){
	case (0x0E)://0000 1110 -> 0 now in pin 4
		return 4;
		break;
	case (0x0D)://0000 1101 -> 0 now in pin 5
		return 5;
		break;
	case (0x0B)://0000 1011 -> 0 now in pin 6
		return 6;
		break;
	case (0x07)://0000 0111 -> 0 now in pin 7
		return '-';
		break;
	}
	//CASE THREE
	PORTA = 0xFB;//1111 for input pins & 1011 for output pins
	x = PINA >> 4;
	switch(x){
	case (0x0E):
		return 7;
		break;
	case (0x0D):
		return 8;
		break;
	case (0x0B):
		return 9;
		break;
	case (0x07):
		return '*';
		break;
	}
	//CASE FOUR
	PORTA = 0xF7;//1111 for input pins & 0111 for output pins
	x = PINA >> 4;
	switch(x){
	case (0x0E):
		return 'c';
		break;
	case (0x0D):
		return 0;
		break;
	case (0x0B):
		return '=';
		break;
	case (0x07):
		return '/';
		break;
	}
	return 0xFF;
}

int main(){
	u8 key;
	DDRC = 0xFF;
	PORTC = 0x3F;
	keypad_Init();
	while(1){
	key = Keypad_Getkey();
	switch(key){
	case (1):
			PORTC = 0x06;//1
	break;
	case(5):
			PORTC = 0x6D;//5
	break;
	case(9):
			PORTC = 0x6F;//9
	break;
	case(0):
			PORTC = 0x3F;//0
	break;
	case (2):
			PORTC = 0x5B;//2
	break;
	case(3):
			PORTC = 0x4F;//3
	break;
	case(4):
			PORTC = 0x66;//4
	break;
	case(6):
			PORTC = 0x7D;//6
	break;
	case (7):
			PORTC = 0x07;//7
	break;
	case(8):
			PORTC = 0xFF;//8
	break;

	}

	}
	return 0;
}

void setPinDirection(u8 PORT,u8 PinNum,u8 Dirct){

	switch(PORT) {
	case (0):
			if( Dirct == output){
				set_bit(DDRA,PinNum);
			}
			else {//input
				clr_bit(DDRA,PinNum);
			}
	break;
	case (1):
			if( Dirct == output){
				set_bit(DDRB,PinNum);
			}
			else {//input
				clr_bit(DDRB,PinNum);
			}
	break;
	case (2):
			if( Dirct == output){
				set_bit(DDRC,PinNum);
			}
			else {//input
				clr_bit(DDRC,PinNum);
			}
	break;
	case (3):
			if( Dirct == output){
				set_bit(DDRD,PinNum);
			}
			else {//input
				clr_bit(DDRD,PinNum);
			}
	break;
	}
}
//----------------------------------------------------//
void setPinValue(u8 PORT,u8 PinNum,u8 value){

	switch(PORT) {
	case (0):
			if( value == high){
				set_bit(PORTA,PinNum);
			}
			else {
				clr_bit(PORTA,PinNum);
			}
	break;
	case (1):
			if( value == high){
				set_bit(PORTB,PinNum);
			}
			else {
				clr_bit(PORTB,PinNum);
			}
	break;
	case (2):
			if( value == high){
				set_bit(PORTC,PinNum);
			}
			else {
				clr_bit(PORTC,PinNum);
			}
	break;
	case (3):
			if( value == high){
				set_bit(PORTD,PinNum);
			}
			else {
				clr_bit(PORTD,PinNum);
			}
	break;
	}
}
//----------------------------------------------------//
