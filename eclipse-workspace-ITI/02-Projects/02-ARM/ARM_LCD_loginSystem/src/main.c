

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
#define incorrect 0
u8 username[]={3,4,2,1,7};
u8 password[]={7,1,2,4,3};
u8 verify (u8 *arr,u8 * correctArray){
	for (u8 i =0 ; i < 5 ; i++){
		if ( arr[i] != correctArray[i]){
			return incorrect;
		}
	}
	return correct;

}
void usernameScreen(void){
	LCD_voidClearScreen();
	LCD_voidSetPosition(0,0);
	LCD_voidWriteString("Enter User Name:");
	LCD_voidSetPosition(1,0);
}
void passwordScreen(void){
	LCD_voidClearScreen();
	LCD_voidSetPosition(0,0);
	LCD_voidWriteString("Enter Password:");
	LCD_voidSetPosition(1,0);
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
	u8 screenUser=1,screenPassword=0,screen_falseUser=0 , screen_falsePassword=0,screen_correctPassword=0;

	u8 usernameVerify[5]={0};u8 usernameCounter=0;
	u8 passwordVerify[5]={0};u8 passwordCounter=0;
	u8 passwordWrongTimes= 0;
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
					result=verify(usernameVerify,username);
					if ( result == correct){
						screenPassword =1 ;
						screenUser =0 ;
						usernameCounter=0;
						passwordScreen();
						delay_ms(100);
					}
					else {
						usernameCounter=0;
						usernameScreen();
					}
				}
				else {
				usernameCounter++;}
			}
			else if ( screenPassword ==1 ){
				LCD_voidWriteNumber(value);
				passwordVerify[passwordCounter]=value;
				if (passwordCounter == 4 ) {
					result=verify(passwordVerify,password);
					if ( result == correct){
						screenPassword =0 ;
						screenUser =0 ;
						passwordCounter=0;
						screen_correctPassword=1;
					}
					else {
						screenPassword =0 ;
						screenUser =0 ;
						passwordCounter=0;
						screen_falsePassword=1;
					}
				}
				else {
				passwordCounter++;}
			}
		 if (screen_correctPassword == 1 ){
				LCD_voidClearScreen();
				LCD_voidSetPosition(0,0);
				LCD_voidWriteString("Correct Password");
			}

			if (screen_falsePassword ==1 ){
				passwordWrongTimes++;
				LCD_voidClearScreen();
				LCD_voidSetPosition(0,0);
				LCD_voidWriteString("You've Entered");
				LCD_voidSetPosition(1,0);
				LCD_voidWriteString("Wrong Pass ");
				LCD_voidWriteNumber(passwordWrongTimes);
				LCD_voidWriteString("time");
				delay_ms(1999);
				if ( passwordWrongTimes  == 3 ){
					LCD_voidClearScreen();
					LCD_voidSetPosition(0,0);
					LCD_voidWriteString("You're Locked");
					LCD_voidSetPosition(1,0);
					LCD_voidWriteString("Now");
					screen_falsePassword =0 ;
				}
				else {
					screen_falsePassword =0 ;
					screenPassword =1 ;
					passwordScreen();
				}
			}



		}









	}
	return 0;
}


