

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "delay.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
//#include "Keypad_config.h"
#include "Keypad_interface.h"

//#include "Keypad_config.h"
#include "LCD_interface.h"
//#include "LCD_config.h"
#include "LCD_private.h"
#define correct 1
#define incorrect 30

u8 hanna[]={1,2,3,4,5};
u8 hamoksha[]={5,4,3,2,1};
u8 bor3y[]={2,3,4,5,6};
u8 *numbers[]={hanna,hamoksha,bor3y};
int verify (u8 *arr){
	int i =0 , j =0,incorrectFlag =0 ;
	for ( j =0 ; j <3 ; j ++){
	for ( i =0 ; i < 5 ; i++){
		if ( arr[i] != numbers[j][i]){
			incorrectFlag =1 ;
			//break;
		}
	}
	if ( incorrectFlag ==0 ){return j ;}
	else {incorrectFlag =0;}
	}
	return incorrect;

}
void usernameScreen(void){
	LCD_voidClearScreen();
	LCD_voidSetPosition(0,0);
	LCD_voidWriteString("Enter no to dial:");
	LCD_voidSetPosition(1,0);
}
void dialScreen(u8 name){
	LCD_voidClearScreen();
	LCD_voidSetPosition(0,0);
	LCD_voidWriteString("calling :");
	LCD_voidSetPosition(1,0);
	if ( name == 0 ){
		LCD_voidWriteString("hanna");
	}
	else if ( name == 1 ){
			LCD_voidWriteString("hamoksha");
		}
	else if ( name == 2 ){
		LCD_voidWriteString("bor3y");
	}
	delay_ms(3500);
	LCD_voidClearScreen();
	usernameScreen();

}
void wrongNumberScreen(void){
	LCD_voidClearScreen();
	LCD_voidSetPosition(0,0);
	LCD_voidWriteString("You've Entered");
	LCD_voidSetPosition(1,0);
	LCD_voidWriteString("Unknown Number ");
	delay_ms(2000);
	LCD_voidClearScreen();
	usernameScreen();
}
int main(void)
{
	RCC_voidInitialize();
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOA,RCC_u8_ENABLE_CLK);
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOB,RCC_u8_ENABLE_CLK);
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOC,RCC_u8_ENABLE_CLK);

	DIO_u8SetPortDirection(DIO_U8_PORTA,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	DIO_u8SetPortDirection(DIO_U8_PORTB,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPortDirection(DIO_U8_PORTC,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);

	//DIO_u8SetPortValue(DIO_U8_PORTA,0xFFFF);
	//DIO_u8SetPortValue(DIO_U8_PORTB,0xFFFF);
	//DIO_u8SetPortValue(DIO_U8_PORTC,0xFFFF);

	LCD_voidInitialize();
	Keypad_u8Init();


	//u8 NULL=20;
	u8 i;
	u8 value,result;
	u8 screenUser=1,screenDial=0,screen_falseUser=0 , screen_falsePassword=0,screen_correctPassword=0;

	u8 usernameVerify[5]={0};u8 usernameCounter=0;


	usernameScreen();
	while(1)
	{
		value=Keypad_u8GetPressedKey();


		if ( value != NULL)
		{

			if ( screenUser == 1){
				LCD_voidWriteNumber(value);
				usernameVerify[usernameCounter]=value;
				if (usernameCounter == 4 ) {
					result=verify(usernameVerify);
					//LCD_voidWriteNumber(result);
					if ( result == 0 || result == 1 || result ==2 ){
						//screenDial =1 ;
						screenUser =1 ;
						usernameCounter=0;
						dialScreen(result);
						delay_ms(1900);
					}
					else {// result is incorrect
						screenUser =1 ;
						usernameCounter=0;
						wrongNumberScreen();
					}
				}
				else {
				usernameCounter++;}
			}




		}









	}
	return 0;
}


