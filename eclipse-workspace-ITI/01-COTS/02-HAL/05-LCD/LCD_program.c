/*
 * LCD_program.c
 *
 *  Created on: Mar 3, 2019
 *      Author: Hanna Nabil
 */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "delay.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"


void LCD_voidInitialize(void){

	for ( u8 i =0 ; i < LCD_DATA_PINS_NB ; i ++){
		DIO_u8SetPinDirection(LCD_Au8DataPins[i],DIO_U8_OUTPUT);
	}
	DIO_u8SetPinDirection(LCD_RS,DIO_U8_OUTPUT);
	DIO_u8SetPinDirection(LCD_RW,DIO_U8_OUTPUT);
	DIO_u8SetPinDirection(LCD_E,DIO_U8_OUTPUT);

	delay_ms_arm(40);
	//delay2(40);
	LCD_voidWriteCommand(0b00111000);
	//delay_ms(1);
	delay_ms_arm(1);
	//delay2(1);
	LCD_voidWriteCommand(0b00001100);
	//delay_ms(1);
	delay_ms_arm(1);
	//delay2(1);
	LCD_voidWriteCommand(0b00000001);
	//delay_ms(2);
	delay_ms_arm(2);
	//delay2(2);
}
void LCD_voidClearScreen(void){
	LCD_voidWriteCommand(0b00000001);
}

void LCD_voidWriteCommand(u8 Copy_u8Write){
	DIO_u8SetPinValue(LCD_RS ,DIO_U8_LOW); // RS = 0 for writing command
	LCD_voidWrite(Copy_u8Write);
}
void LCD_voidWriteData(u8 Copy_u8Data){
	DIO_u8SetPinValue(LCD_RS ,DIO_U8_HIGH); // RS =1 for writing command
	LCD_voidWrite(Copy_u8Data);
}
static void LCD_voidWrite(u8 Copy_u8Write){
			DIO_u8SetPinValue(LCD_RW ,DIO_U8_LOW); // to write
			for ( u8 i =0 ; i<LCD_DATA_PINS_NB;i++){
				DIO_u8SetPinValue(LCD_Au8DataPins[i],get_bit(Copy_u8Write,i));
			}
			DIO_u8SetPinValue(LCD_E ,DIO_U8_HIGH);
			delay_ms_arm(2);
			DIO_u8SetPinValue(LCD_E ,DIO_U8_LOW);
}
