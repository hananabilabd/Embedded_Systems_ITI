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
// This assignment is to make a LDR controlling a Led in an inversely manner
int main(void)
{
	LCD_Init();
	ADC_Init_NoInterrupt();
	Timer0_Init();
	d64 x=0;
	u8 y ,m =0;
	u8 o[]="OCR: ";
	u8 s[]="  ";
	s16 z=0;
	while (1){
		x=ADC_ReadOutput();
		y = (x/5.0) * 256.0; //mapping from 0 to 5 to (0 to 256)
		z= ((-1)*y) +256; //mapping from 0 to 256 to (256 to 0)
		m=z;
		Timer0_PWM(z);
		//LCD_Clear_Screen();
		LCD_SetPosition(0,0);
		LCD_WriteString(o);
		LCD_Write_Number(z);
		LCD_WriteString(s);
		_delay_ms(100);

	}
	return 0;
}

