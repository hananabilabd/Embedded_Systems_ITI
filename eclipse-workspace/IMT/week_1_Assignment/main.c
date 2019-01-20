/*
 * main.c
 *
 *  Created on: Feb 24, 2018
 *      Author: Hanna Nabil
 */


#define F_CPU 12000000UL
#include <util/delay.h>
#include "typedef.h"

#include "DIO.h"
void print_fun(u8 time);
int main(void)
{
	DIO_setPortDirection('A',0xFF);//7 segment
	DIO_setPortDirection('C',0xFF);
	DIO_setPortDirection('B',0xFF);// Leds

	//DIO_setPortValue('A',0xF9);
	//DIO_setPortValue('C',0xA0);
	u8 i;
	while(1){
		for (i=0;i<=60;i++){
			print_fun(i);

		DIO_SetPinValue('B',0,1);_delay_ms(50);DIO_SetPinValue('B',0,0);_delay_ms(50);
		DIO_SetPinValue('B',4,1);_delay_ms(50);DIO_SetPinValue('B',4,0);_delay_ms(50);
		DIO_SetPinValue('B',7,1);_delay_ms(50);DIO_SetPinValue('B',7,0);_delay_ms(50);
		//DIO_SetPinValue('B',0,1);_delay_ms(100);
		//DIO_SetPinValue('B',0,0);_delay_ms(100);



		}
		for (i=0;i<=10;i++){
			print_fun(i);
			DIO_SetPinValue('B',1,1);DIO_SetPinValue('B',6,1);_delay_ms(200);
			DIO_SetPinValue('B',1,0);DIO_SetPinValue('B',6,0);_delay_ms(200);

		}
		for (i=0;i<=60;i++){
					print_fun(i);
				DIO_SetPinValue('B',2,1);DIO_SetPinValue('B',5,1);_delay_ms(200);
				DIO_SetPinValue('B',2,0);DIO_SetPinValue('B',5,0);_delay_ms(200);

				}


	}

return 0;
}
void print_fun(u8 time){
	int a =time % 10; //get unit
	int b= (time-a)/10; //get tenth

	if (a==0){
		DIO_setPortValue('A',0xA0);
	}
	else if (a==1){
		DIO_setPortValue('A',0xF9);
	}
	else if (a==2){
		DIO_setPortValue('A',0xC4);
	}
	else if (a==3){
		DIO_setPortValue('A',0xD0);
	}
	else if (a==4){
		DIO_setPortValue('A',0x99);
	}
	else if (a==5){
		DIO_setPortValue('A',0x92);
	}
	else if (a==6){
		DIO_setPortValue('A',0x82);
	}
	else if (a==7){
		DIO_setPortValue('A',0xF8);
	}
	else if (a==8){
		DIO_setPortValue('A',0x80);
	}
	else if (a==9){
		DIO_setPortValue('A',0x98);
	}
////////////////////////////////////////
	if (b==0){
		DIO_setPortValue('C',0xA0);
	}
	else if (b==1){
		DIO_setPortValue('C',0xF9);
	}
	else if (b==2){
		DIO_setPortValue('C',0xC4);
	}
	else if (b==3){
		DIO_setPortValue('C',0xD0);
	}
	else if (b==4){
		DIO_setPortValue('C',0x99);
	}
	else if (b==5){
		DIO_setPortValue('C',0x92);
	}
	else if (b==6){
		DIO_setPortValue('C',0x82);
	}
	else if (b==7){
		DIO_setPortValue('C',0xF8);
	}
	else if (b==8){
		DIO_setPortValue('C',0x80);
	}
	else if (b==9){
		DIO_setPortValue('C',0x98);
	}
}
/*
 0--0xA0
 1--0xF9
 2--0xC4
 3--0xD0
 4--0x99
 5--0x92
 6--0x82
 7--0xF8
 8--0x80
 9--0x98

 */

