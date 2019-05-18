/*
 * main.c
 *
 *  Created on: Mar 14, 2019
 *      Author: Hanna Nabil
 */

#include "STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_interface.h"
//#include"DIO_config.h"
#define F_CPU 12000000UL
//#include <util/delay.h>
#include "DIO_private.h"
#include "LCD_interface.h"
#include"delay.h"
#include "Timer_interface.h"
#include "UART_interface.h"



int main(void){

	UART_voidIntialize();
	UART_TransmitString("Hanna");



	while(1){




	}
return 0 ;
}
