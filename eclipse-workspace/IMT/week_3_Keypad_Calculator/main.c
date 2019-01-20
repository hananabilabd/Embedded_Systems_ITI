/*
 * main.c
 *
 *  Created on: Feb 24, 2018
 *      Author: Hanna Nabil
 */

#include "typedef.h"
#include "IO.h"
#include "macros.h"
#define F_CPU 12000000UL
#include <util/delay.h>
#include "DIO.h"
#include"LCD.h"
#include "Keypad.h"
// Calculator Assignment
u8 NULL=20;
u8 i;

u8 getKey(void){
	for ( i =0 ;i<=15;i++){
				//_delay_ms(5);

				u8 value = Keypad_GetButtonSatus(i);
				if (value ==1){

				return i;
				}
			}
	return NULL;
}
int main(void)
{

	LCD_Init();
	Keypad_Init();
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
	while(1){



			value= getKey();
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
				LCD_Write_Number(value);

			}
			else if (  (value ==12) || (value==13)|| (value ==14)  ){
				if (value==12){
					LCD_writeCharacter('+');
					operation[o]= '+';
					o++;
				}
				else if (value==13){
					LCD_writeCharacter('-');
					operation[o]= '-';
					o++;
				}
				else if (value==14){
					LCD_writeCharacter('*');
					operation[o]= '*';
					o++;
				}
			}
			else if ( value==11){ // Equal '='
				LCD_SetPosition(1,0);
				LCD_writeCharacter('=');

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
				LCD_Write_Number(result);

			}


}
else if ((value != NULL) &&( value =10)){
	LCD_Clear_Screen();
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

