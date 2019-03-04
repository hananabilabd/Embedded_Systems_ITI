/*
 * main.c
 *
 *  Created on: Feb 12, 2019
 *      Author: Hanna Nabil
 */
#include"STD_TYPES.h"
#include"DIO_interface.h"
//#include"LEDDriver_interface.h"
void delay_ms(u32 value){
	for (u32 i =0 ; i< value*150;i++){
		asm("NOP");
	}
}
int main (void){
	//DIO_voidInitialize();
	DIO_u8SetPinDirection(0,1);
	DIO_u8SetPinDirection(1,1);
	DIO_u8SetPortDirection(3,0b11111111);

	DIO_u8SetPinValue(0,0);//Enable screen1
	DIO_u8SetPinValue(1,1);//Enable screen2



	//LEDDriver_u8Enable();
	while(1){



		DIO_u8SetPinValue(1,0);//disable screen2
		DIO_u8SetPortValue(3,0b11101111);
		DIO_u8SetPinValue(0,0);//Enable screen1
		delay_ms(100);

		DIO_u8SetPinValue(0,1);//disable screen1
		DIO_u8SetPortValue(3,0b00010010);
		DIO_u8SetPinValue(1,1);//Enable screen2
		delay_ms(100);

	}
	return 0;
}
