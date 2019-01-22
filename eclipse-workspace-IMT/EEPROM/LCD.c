/*
 * LCD.C
 *
 *  Created on: Dec 2, 2017
 *      Author: Mina Medhat
 */

#include <util/delay.h>
#define F_CPU 8000000
#include "std_types.h"
#include "registers.h"
#include "DIO.h"
#include "LCD.h"
#include "LCD_cfg.h"

void LCD_writedata(u8 data){
	DIOSetPinValue(LCD_control,RS,1); // RS=0 for Command RS=1 for Data
	DIOSetPinValue(LCD_control,RW,0); // RW=0 for write RW=1 for read busy flag from LCD but it's not used
    DIOSetPortValue(LCD_port,data);    //set the output port (D0----D7) note we can use 4 bit mode instead
    DIOSetPinValue(LCD_control,EN,1);// Enable pin for 1 ms and then disable it
    _delay_ms(1);
    DIOSetPinValue(LCD_control,EN,0);
    _delay_ms(1);
}
void LCD_writecommand(u8 data){
	DIOSetPinValue(LCD_control,RS,0); // RS=0 for Command RS=1 for Data
	DIOSetPinValue(LCD_control,RW,0); // RW=0 for write RW=1 for read busy flag from LCD but it's not used
    DIOSetPortValue(LCD_port,data);    //set the output port (D0----D7) note we can use 4 bit mode instead
    DIOSetPinValue(LCD_control,EN,1);// Enable pin for 1 ms and then disable it
    _delay_ms(1);
    DIOSetPinValue(LCD_control,EN,0);
    _delay_ms(1);
}
void LCD_init(void){
	DIOSetPortDirection(LCD_port,255);// Set port as output for data (8bit mode)
	DIOSetPinDirection(LCD_control,RS,1); // set a pin in a port to be RS
	DIOSetPinDirection(LCD_control,RW,1);// set a pin in a port to be RW
	DIOSetPinDirection(LCD_control,EN,1);// set a pin in a port to be EN
	_delay_ms(50);
	LCD_writecommand(0b00111000);//
	_delay_ms(1);
	LCD_writecommand(0b00001100);//
	_delay_ms(1);
		LCD_writecommand(0b00000001);//
}
 void LCD_writestring (u8 arr[]){  // Function to write string

	 u8 x=0;
	 while(arr[x]!='\0'){
		 LCD_writedata(arr[x]);
		 x++;
}
}
LCD_setposition(u8 row , u8 column)
{
	if(row==0){
		LCD_writecommand(128+column);
	}
	else if (row==1){
		LCD_writecommand(128+64+column);
	}
	}
void LCDWriteInt(s32 x){
	s32 y=1;
		if(x==0){LCD_writedata('0');}
		if(x<0){LCD_writedata('-'); x*=-1;}
		while(x!=0){
			y=((y*10)+(x%10));
			x=(x/10);
		}
		while(y!=1){
		LCD_writedata((y%10)+48);
		y=(y/10);
		}
}




