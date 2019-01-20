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
#include"LCD.h"
#include "Keypad.h"
#include "Timer.h"
#include "SevenSegment.h"


int main(void)
{	DIO_SetPinDirection('C',7,1); // to power up the 7 segment
	DIO_SetPinValue('C',7,1);


	LCD_Init();
	Timer0_Init();
	u8 arr[]="  ";


	while (1){
		if (m< 10){

		LCD_SetPosition(0,0);
		LCD_Write_Number(0);
		LCD_SetPosition(0,1);
		LCD_Write_Number(m);
		}
		else {
			LCD_SetPosition(0,0);
			LCD_Write_Number(m);
		}
		LCD_SetPosition(0,2);
		LCD_writeCharacter(':');
		if (s < 10){
			LCD_SetPosition(0,3);
			LCD_Write_Number(0);
			LCD_SetPosition(0,4);
			LCD_Write_Number(s);
		}
		else {
		LCD_SetPosition(0,3);
		LCD_Write_Number(s);
		}
		LCD_SetPosition(0,5);
		LCD_WriteString(arr);






	}
return 0;
}

