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
//Assignment to control servo from Potentiometer
// Potentiometer ==> ADC ==> Servo
int main(void)
{

LCD_Init();
ADC_Init_NoInterrupt();

Servo_Init();
d64 x=0;
d64 y =0;
u8 z[]= "  ";

	while (1){


x=ADC_ReadOutput();
y =36.0 * x;
Servo_WriteAngle((u8)y);
LCD_SetPosition(0,0);

LCD_Write_Number((u64)y);
LCD_WriteString(z);

_delay_ms(100);



	}
return 0;
}

