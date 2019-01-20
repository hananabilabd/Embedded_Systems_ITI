/*
 * main.c
 *
 *  Created on: Feb 24, 2018
 *      Author: Hanna Nabil
 */

#include "typedef.h"
#include "IO.h"
#include "macros.h"
#define F_CPU 12000000UL
#include <util/delay.h>
#include "DIO.h"
//#include "Timer.h"
#include "LCD.h"
#include "I2C.h"
#include "EEPROM.h"

u8 x,v;
u8 h[]="hanna";

int main(void)
{

	LCD_Init();
	//LCD_WriteString(h);

	EEpromInit();
	_delay_ms(500);
	//LCD_WriteString(h);
	EEpromWriteByte(4,50);
	_delay_ms(500);
	LCD_WriteString(h);
	x =EEpromReadByte(4);
	_delay_ms(500);
	//LCD_writedata(x);
	//LCD_setposition(0,0);
	LCD_Write_Number(x);
	//LCD_WriteString(h);
	//_delay_ms(500);

	while(1)
	{

	}


	return 0;
}



