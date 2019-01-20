/*
 * DIO.C
 *
 *  Created on: Nov 25, 2017
 *      Author: Mina Medhat
 */

#include "std_types.h"
#include "registers.h"
#include "DIO.h"
void DIOSetPortDirection (u8 portnumber,u8 value)
{
	switch(portnumber){
	case 0 : DDRA = value;
	break;
	case 1 : DDRB = value;
	break;
	case 2 : DDRC = value;
	break;
	case 3 : DDRD = value;
	break;
	default : break;
	}
}

void DIOSetPortValue (u8 portnumber,u8 value)
{
	switch(portnumber){
	case 0 : PORTA = value;
	break;
	case 1 : PORTB = value;
	break;
	case 2 : PORTC = value;
	break;
	case 3 : PORTD = value;
	break;
	default : break;
	}
}

void DIOSetPinDirection (u8 portnumber,u8 Pinnumber,u8 value){
	switch(portnumber){

	case 0 : if(value==1) {DDRA |= (1<<Pinnumber);}
	  else   if (value==0) {DDRA &= ~(1<<Pinnumber);}
	break;

	case 1 : if(value==1) {DDRB |= (1<<Pinnumber);}
	  else   if (value==0) {DDRB &= ~(1<<Pinnumber);}
	break;

	case 2 : if(value==1) {DDRC |= (1<<Pinnumber);}
	  else   if (value==0) {DDRC &= ~(1<<Pinnumber);}
	break;

	case 3 : if(value==1) {DDRD |= (1<<Pinnumber);}
	  else   if (value==0) {DDRD &= ~(1<<Pinnumber);}

	break;
	default : break;
	}
	}




void DIOSetPinValue (u8 portnumber,u8 Pinnumber,u8 value){

switch(portnumber){

case 0 : if(value==1) {PORTA |= (1<<Pinnumber);}
  else   if (value==0) {PORTA &= ~(1<<Pinnumber);}
break;

case 1 : if(value==1) {PORTB |= (1<<Pinnumber);}
  else   if (value==0) {PORTB &= ~(1<<Pinnumber);}
break;

case 2 : if(value==1) {PORTC |= (1<<Pinnumber);}
  else   if (value==0) {PORTC &= ~(1<<Pinnumber);}
break;

case 3 : if(value==1) {PORTD |= (1<<Pinnumber);}
  else   if (value==0) {PORTD &= ~(1<<Pinnumber);}

break;
default : break;
}
}

u8 DIOGetPort (u8 portnumber){
	u8 x;
	switch (portnumber){
		case 0 : x=PINA;
		break;
		case 1 : x=PINB;
		break;
		case 2 : x=PINC;
		break;
		case 3 : x=PIND;
		break;
		default : break;
	}
	return x;
}

u8 DIOGetPinValue (u8 portnumber , u8 Pinnumber){
u8 x;
switch(portnumber){
case 0 : x =  ((PINA >> Pinnumber)&1);
break;
case 1 : x =  ((PINB >> Pinnumber)&1);
break;
case 2 : x =  ((PINC >> Pinnumber)&1);
break;
case 3 : x =  ((PIND >> Pinnumber)&1);
break;
default : break;
}
return x;
}
