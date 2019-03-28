

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


u8 getKeystatus(void){
		u8 arr[16]={0};
		Keypad_u8GetKeypadState(arr);
		for ( u8 i =0 ; i< 16 ; i++){
					if (arr[i]==KEYPAD_u8_PRESSED ) {

						//arr[i]=KEYPAD_u8_NOT_PRESSED;
						delay_ms(400);
						return i;
					}
				}
		return 20;
	}
int main(void)
{
	RCC_voidInitialize();
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOA,RCC_u8_ENABLE_CLK);
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOB,RCC_u8_ENABLE_CLK);
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOC,RCC_u8_ENABLE_CLK);

	DIO_u8SetPortDirection(DIO_U8_PORTA,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	DIO_u8SetPortDirection(DIO_U8_PORTB,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	DIO_u8SetPortDirection(DIO_U8_PORTC,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);

	//DIO_u8SetPortValue(DIO_U8_PORTA,0xFFFF);
	//DIO_u8SetPortValue(DIO_U8_PORTB,0xFFFF);
	//DIO_u8SetPortValue(DIO_U8_PORTC,0xFFFF);

	LCD_voidInitialize();
	Keypad_u8Init();


	u8 NULL=20;
	u8 i;
	u8 value;

		u16 temp[5]={0};
		u8 x =0;
		u16 temp0=0;
		u16 result =0;

		u8 operation[5];

		u8 o =0;
		u8 o2=0;
		u8 y =0;
		u8 z =0;
		u8 c =0;

	while(1)
	{
		 value=getKeystatus();
		//if ( x != NULL){
		//LCD_voidWriteNumber(x);}

		 if ((value != NULL) && (value != 10) )
		 	{
		 				if (value <10){ // if value not equal 10 , 11 , 12 , 13 , 14 ,15
		 					if (o != c){
		 						temp0 =0;
		 						c++;
		 						x++;
		 						//LCD_Write_Number(555);
		 					}
		 					temp0 = (temp0 *10) +value;
		 					temp[x] =temp0;

		 					//LCD_SetPosition(0,x);
		 					LCD_voidWriteNumber(value);

		 				}
		 				else if (  (value ==12) || (value==13)|| (value ==14)  ){
		 					if (value==12){
		 						LCD_voidWriteCharacter('+');
		 						operation[o]= '+';
		 						o++;
		 					}
		 					else if (value==13){
		 						LCD_voidWriteCharacter('-');
		 						operation[o]= '-';
		 						o++;
		 					}
		 					else if (value==14){
		 						LCD_voidWriteCharacter('*');
		 						operation[o]= '*';
		 						o++;
		 					}
		 				}
		 				else if ( value==11){ // Equal '='
		 					LCD_voidSetPosition(1,0);
		 					LCD_voidWriteCharacter('=');

		 					for ( i =0 ; i<= x ; i++){
		 						if ((y %2 ==0 )&& (y != 0)){
		 							o2++;
		 						}
		 					switch (operation[o2]){
		 					case '+' :

		 						result +=temp[y] ;
		 						y++;
		 						break;
		 					case '-' :
		 						if (y==0){
		 							result = temp[y];
		 							y++;
		 							break;
		 						}
		 						else{
		 						result -= temp[y] ;
		 						y++;
		 						break;
		 						}
		 					case '*' :
		 						if (y==0){
		 							result = temp[y]  ;
		 							y++;

		 							break;
		 						}

		 						else {
		 						result *= temp[y]  ;
		 						y++;

		 						break;
		 						}
		 					}

		 					}
		 					LCD_voidWriteNumber(result);

		 				}


		 	}
		 	else if ((value != NULL) &&( value =10)){
		 		LCD_voidClearScreen();
		 		temp[0]=temp[1]=temp[2]=temp[3]=temp[4]=0;
		 			x =0;
		 			temp0=0;
		 			result =0;

		 			operation[0] =operation[1] =operation[2] =operation[3] =operation[4] =0;

		 			o =0;
		 			o2=0;
		 			y =0;

		 			c =0;
		 	}


	}
	return 0;
}


