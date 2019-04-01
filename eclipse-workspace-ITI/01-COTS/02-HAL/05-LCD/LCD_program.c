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
	#if LCD_BIT_MODE == LCD_8_MODE
		delay_ms(40);
		LCD_voidWriteCommand(0b00111000);
		delay_ms(1);
		LCD_voidWriteCommand(0b00001100);
		delay_ms(1);
		LCD_voidWriteCommand(0b00000001);
		delay_ms(2);
	/********************4_bit Mode******************************************************/
	#elif LCD_BIT_MODE == LCD_4_MODE
			delay_ms(40);
			LCD_voidWriteCommand(0x33);
			LCD_voidWriteCommand(0x32);
			delay_ms(1);
			LCD_voidWriteCommand(0x28);
			LCD_voidWriteCommand(0x02);
			delay_ms(1);
			LCD_voidWriteCommand(0x0C);
			delay_ms(1);
			LCD_voidWriteCommand(0x06);
			delay_ms(2);
			LCD_voidWriteCommand(0b00000001);// to clear screen
			delay_ms(2);
	#endif
}
void LCD_voidClearScreen(void){
	LCD_voidWriteCommand(0b00000001);
}
void LCD_voidWriteCommand(u8 Copy_u8Write){
	DIO_u8SetPinValue(LCD_RS ,DIO_U8_LOW); // RS = 0 for writing command
	LCD_voidWrite(Copy_u8Write);// to avoid redundant code ,we used same function for both writecommand and writeCharacter
}
void LCD_voidWriteCharacter(u8 Copy_u8Data){
	DIO_u8SetPinValue(LCD_RS ,DIO_U8_HIGH); // RS =1 for writing command
	LCD_voidWrite(Copy_u8Data);
}
static void LCD_voidWrite(u8 Copy_u8Write){
			DIO_u8SetPinValue(LCD_RW ,DIO_U8_LOW); // to write
			#if LCD_BIT_MODE == LCD_8_MODE
			for ( u8 i =0 ; i<LCD_DATA_PINS_NB;i++){
				DIO_u8SetPinValue(LCD_Au8DataPins[i],get_bit(Copy_u8Write,i));
			}
			DIO_u8SetPinValue(LCD_E ,DIO_U8_HIGH);
			delay_ms(1);
			DIO_u8SetPinValue(LCD_E ,DIO_U8_LOW);
			delay_ms(1);
			#elif LCD_BIT_MODE == LCD_4_MODE
				for (s8 i =4,j=0 ; i< 8 ;i++,j++){
					DIO_u8SetPinValue(LCD_Au8DataPins[j],get_bit(Copy_u8Write,i));
				}
				DIO_u8SetPinValue(LCD_E ,DIO_U8_HIGH);
				delay_ms(1);
				DIO_u8SetPinValue(LCD_E ,DIO_U8_LOW);
				delay_ms(1);
				for (s8 i =0,j=0 ; i<4;i++,j++){
					DIO_u8SetPinValue(LCD_Au8DataPins[j],get_bit(Copy_u8Write,i));
				}
				DIO_u8SetPinValue(LCD_E ,DIO_U8_HIGH);
				delay_ms(1);
				DIO_u8SetPinValue(LCD_E ,DIO_U8_LOW);
				delay_ms(1);
			#endif
}
// Array is passed always to function by reference but there is a special case in array of character we can know the end of array with the help of Null character
void LCD_voidWriteString(u8 *arr){// same as arr[]
	u8 counter =0;
	while(arr[counter] != '\0'){ //Null character
		LCD_voidWriteCharacter(arr[counter]);
		counter ++;
	}

}

