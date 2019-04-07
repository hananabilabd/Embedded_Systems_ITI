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
//#include"Interrupt_interface.h"
#define F_CPU 12000000UL
//#include <util/delay.h>
#include "DIO_private.h"
#include "danger.h"
#include "help.h"
#include "hungry.h"
#include "LCD_interface.h"
#include"delay.h"
u16 counter = 0;
 u32 i=0;
 u8 flag1=1,flag2=0,flag3=0;
void __vector_11 (void) __attribute__((signal));
void __vector_10 (void) __attribute__((signal));
void __vector_11 (void)//normal mode
{

	counter ++;
	if (counter  ==2){
			counter =0;
			TCNT0=137;

				//toggle_bit(var,0);
				//DIO_u8SetPinValue(DIO_U8_PIN_C0,var);
			if (flag1 == 1){
				asm("LPM %0,Z" "\n\t" : "=r" (DIO_U8_PORTD->ByteAccess): "z" (&danger_raw[i]));
									i++;
									if ( i == 4086){
										i =0;
									}
			}
			else if (flag2 == 1){
				asm("LPM %0,Z" "\n\t" : "=r" (DIO_U8_PORTD->ByteAccess): "z" (&help_raw[i]));
									i++;
									if ( i == 2367 ){
										i =0;
									}
			}
			else if (flag3 == 1){
				asm("LPM %0,Z" "\n\t" : "=r" (DIO_U8_PORTD->ByteAccess): "z" (&hungry_raw[i]));
									i++;
									if ( i == 3575 ){
										i =0;
									}
			}

		}
}
void __vector_10 (void)//ocr interrupt
{


/*
		asm("LPM %0,Z" "\n\t" : "=r" (DIO_U8_PORTD->ByteAccess): "z" (&hannon_raw[i]));
		i++;
		if ( i == 23869 ){
			i =0;
		}
*/
}


int main(void){

	TCNT0=137;
	TIMSK |= 0x01;
	SREG |= 0x80;
	TCCR0 = 0b00000010;
	//TCCR0 = 0b00001011;//fast PWM
	//OCR0=187;// for 8k sampling
	//OCR0=255;// for 4k sampling
	DIO_u8SetPortDirection(DIO_U8_PORT_D,0b11111111);
	DIO_u8SetPortDirection(DIO_U8_PORT_C,0xFF);
	DIO_u8SetPinDirection(DIO_U8_PIN_A0,DIO_U8_INPUT);
	DIO_u8SetPinDirection(DIO_U8_PIN_A1,DIO_U8_INPUT);
	DIO_u8SetPinDirection(DIO_U8_PIN_A2,DIO_U8_INPUT);
	DIO_u8SetPinValue(DIO_U8_PIN_A0,DIO_U8_HIGH);
	DIO_u8SetPinValue(DIO_U8_PIN_A1,DIO_U8_HIGH);
	DIO_u8SetPinValue(DIO_U8_PIN_A2,DIO_U8_HIGH);
	u8 status1=1,status2=1,status3 =1;
	LCD_voidInitialize();

//Interrupt_Initialize();
//Interrupt_Enable(INTERRUPT_INT0);
//Interrupt_setLevel(INTERRUPT_INT0,INTERRUPT_LEVEL_FALLING_EDGE);
//Interrupt_voidSetCallback(INTERRUPT_INT0,blink);

LCD_voidWriteString("ya Welcome");


while(1){

DIO_u8GetPinValue(DIO_U8_PIN_A0,&status1);
DIO_u8GetPinValue(DIO_U8_PIN_A1,&status2);
DIO_u8GetPinValue(DIO_U8_PIN_A2,&status3);
if (status1 == 0){
	flag1=1;flag2=0;flag3=0;
	LCD_voidClearScreen();
	LCD_voidWriteString("Dangerous");
	delay_ms(400);
	status1=1;
	i=0;
	counter=0;
	TCNT0=140;


}
else if (status2 == 0){
	flag1=0;flag2=1;flag3=0;
	LCD_voidClearScreen();
	LCD_voidWriteString("Help");
		delay_ms(400);
		status2=1;
		i=0;
		counter=0;
		TCNT0=140;

}
else if (status3 == 0){
	flag1=0;flag2=0;flag3=1;
	LCD_voidClearScreen();
		LCD_voidWriteString("Hungry");
			delay_ms(400);
			status3 =1;
			i=0;
			counter=0;
			TCNT0=140;
}
}
return 0 ;
}
