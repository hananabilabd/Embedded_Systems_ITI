/*
 * UART_program.c
 *
 *  Created on: Apr 25, 2019
 *      Author: Hanna Nabil
 */

#include "STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_interface.h"
//#include"DIO_config.h"

#include "DIO_private.h"
#include "UART_interface.h"
void UART_voidIntialize(void){
	DIO_u8SetPinDirection(DIO_U8_PIN_D0,DIO_U8_INPUT);
	DIO_u8SetPinDirection(DIO_U8_PIN_D1,DIO_U8_OUTPUT);
	UCSRA=0x00;
	UCSRB=0b00011000;
	UCSRC=0b10000110;
	UBRRL= 51; //XXXX
	UBRRH=0;




}
void UART_TransmitData(u8 Data){
	while(get_bit(UCSRA,5)==0);
	UDR = Data;
}
u8 UART_ReceiveData(void){
	while(get_bit(UCSRA,7)==0);
	return UDR;
}
void UART_TransmitString(u8 *arr){
	u8 counter =0;
	while(arr[counter] != '\0'){ //Null character
		UART_TransmitData(arr[counter]);
		counter ++;
	}
	UART_TransmitData('\n');
}
