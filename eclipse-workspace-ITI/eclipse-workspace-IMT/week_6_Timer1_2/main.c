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
#include "ADC.h"
#include "Servo.h"

int main(void)
{
LCD_Init();
Timer0_Init();
Timer1_Init();
d64 duty ,periodicity=0;
//u32 duty ,periodicity=0;
	while (1){
			if (flag ==3){
				duty = (d64)(c2-c1)*100.0/(c3-c1);
				periodicity =(d64)(c3-c1)/12.0; //periodicity = c3-c1 /frequency
				LCD_SetPosition(0,0);
				LCD_Write_Float(duty);
				//LCD_Write_Number(duty);
				LCD_SetPosition(1,0);
				LCD_Write_Float(periodicity);
				//LCD_Write_Number(periodicity);
				set_bit(TIMSK,5); // To Enable Peripheral Interrupt
				set_bit(TIFR,5); // Read datasheet page 111
				flag=0;
			}
	}
return 0;
}


