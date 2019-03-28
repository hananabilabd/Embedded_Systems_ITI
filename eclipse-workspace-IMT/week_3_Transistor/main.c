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
#include "Keypad.h"
int main(void)
{// Relay



 DIO_SetPinDirection('C',0,1);// output
 DIO_SetPinDirection('C',2,1);// output
 DIO_SetPinValue('C',2,1);// output


	while(1){

		 DIO_SetPinValue('C',0,1);
		 _delay_ms(500);
		 DIO_SetPinValue('C',0,0);
		 _delay_ms(500);



	}

return 0;

}
/*
int main(void)
{// optocoupler



 DIO_SetPinDirection('C',0,1);// output
 DIO_SetPinValue('C',0,1);
 DIO_SetPinDirection('C',2,1);// output

	while(1){

		 DIO_SetPinValue('C',2,1);
		 _delay_ms(500);
		 DIO_SetPinValue('C',2,0);
		 _delay_ms(500);



	}

return 0;

}
*/
/* H-bridge
int main(void)
{

 DIO_SetPinDirection('C',0,1);// output
 DIO_SetPinDirection('C',1,1);// output
 DIO_SetPinDirection('C',2,1);// output
 DIO_SetPinDirection('C',3,1);// output

	while(1){

		DIO_SetPinValue('C',0,1);
		DIO_SetPinValue('C',1,0);
		DIO_SetPinValue('C',2,1);
		DIO_SetPinValue('C',3,0);
		//_delay_ms(10000);
		for(u8 i =0 ; i<1000;i++){

		}
		DIO_SetPinValue('C',0,0);
		DIO_SetPinValue('C',1,0);
		DIO_SetPinValue('C',2,0);
		DIO_SetPinValue('C',3,0);
		_delay_ms(4000);
		DIO_SetPinValue('C',0,0);
		DIO_SetPinValue('C',1,1);
		DIO_SetPinValue('C',2,0);
		DIO_SetPinValue('C',3,1);
		_delay_ms(10000);



	}

return 0;

}
*/
