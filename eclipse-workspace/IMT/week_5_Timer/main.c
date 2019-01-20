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


int main(void)
{
	DIO_SetPinDirection('A',0,1);
	Timer0_Init();



	while (1){





	}
return 0;
}

