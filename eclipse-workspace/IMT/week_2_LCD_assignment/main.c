/*
 * main.c
 *
 *  Created on: Feb 24, 2018
 *      Author: Hanna Nabil
 */

#include "typedef.h"
#include"LCD.h"
#define F_CPU 12000000UL
#include <util/delay.h>
#include "DIO.h"

void check(void){
	u8 a=DIO_ReadPinValue('A',0);
	u8 b=DIO_ReadPinValue('A',1);
	u8 c=DIO_ReadPinValue('A',2);
	u8 d=DIO_ReadPinValue('A',3);

	if (a==0 && b ==0 && c==0 && d==0){
		u8 arr[]="Password Correct";
		LCD_Clear_Screen();
		LCD_SetPosition(0,0);
		LCD_WriteString(arr);
		DIO_SetPinValue('D',1,0);
		DIO_SetPinValue('D',0,1);
		_delay_ms(900);


	}
	else{
		u8 arr[]="Incorrect Pass";
		LCD_Clear_Screen();
		LCD_SetPosition(0,0);
		LCD_WriteString(arr);
		DIO_SetPinValue('D',0,0);
		DIO_SetPinValue('D',1,1);
		_delay_ms(900);


	}
}
int main(void)
{
	DIO_SetPinDirection('A',0,0);// A as input
	DIO_SetPinDirection('A',1,0);// A as input
	DIO_SetPinDirection('A',2,0);// A as input
	DIO_SetPinDirection('A',3,0);// A as input
	DIO_SetPinValue('A',0,1);
	DIO_SetPinValue('A',1,1);// pull up
	DIO_SetPinValue('A',2,1);
	DIO_SetPinValue('A',3,1);
	DIO_SetPinDirection('D',0,1);
	DIO_SetPinDirection('D',1,1);
	LCD_Init();



	u8 arr[]="Welcome Hanna";
			LCD_WriteString(arr);
			_delay_ms(6000);

	while(1){

		check();


	}

return 0;

}

