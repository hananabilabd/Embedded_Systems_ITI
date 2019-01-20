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
#include "Interrupt.h"
int main(void)
{

DIO_SetPinDirection('C',7,1);
//DIO_SetPinDirection('D',2,0);
DIO_SetPinValue('D',2,1);// enable pull-up
DIO_SetPinValue('D',3,1);
DIO_SetPinValue('B',2,1);
Interrupt_Init_INT0();
Interrupt_Init_INT1();
Interrupt_Init_INT2();
	while(1){





	}

return 0;

}

