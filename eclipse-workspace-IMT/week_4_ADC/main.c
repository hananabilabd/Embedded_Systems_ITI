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
#include "ADC.h"
d64 analog;
int analog2;
u8 a;

int main(void)
{
	DIO_SetPinDirection('C',7,1);
	DIO_SetPinDirection('C',6,1);
	LCD_Init();
	//ADC_Init_NoInterrupt();
	ADC_Init_WithInterrupt();

	u8 s[]="   ";
	u8 n[]="Hanna";
	/*for (u16 i =0 ;  i<500 ;i++){
		analog =ADC_ReadOutput();
			//LCD_SetPosition(0,0);
			LCD_WriteString(s);
			LCD_SetPosition(0,0);

			LCD_Write_Float(analog);
	}*/

	while(1){

		/*
		analog =ADC_ReadOutput();
		analog2= (int) (analog * 10);
		a= analog2 / 3 ;

		LCD_SetPosition(0,a);
		LCD_WriteString(n);
		_delay_ms(200);
		LCD_Clear_Screen();

		 	*/


	}


	return 0;

}

