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
//#include "Timer.h"
#include "LCD.h"
#include "I2C.h"
#include "EEPROM.h"
#include "Keypad.h"
u8 v;
u8 h[]="WELCOME";
u8 h2[]="Cal Mode Activated";
u8 u[]="1st Operand Add";
u8 l[]="Mem Mode Activated";
u8 l1[]="12 to save";
u8 l2[]="13 to show";
u8 l3[]="Address to save:";
u8 l4[]="Address to show:";
u8 l5[]="Result Saved";
u8 l6[]="Successfully";
u8 l7[]="Val In Req Add.:";
u8 temp2;
u8 k;
u8 i;
u8 value;
u8 value2;
u8 f=0;
u8 f1,f2,f3,f4=0;
u8 ff1,ff2=0;
u8 fff1,fff2=0;
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
void calculator(void);
int main(void)
{

	LCD_Init();
	Keypad_Init();

	EEpromInit();
	_delay_ms(500);
	LCD_WriteString(h);
	_delay_ms(2000);
	LCD_SetPosition(1,0);
	LCD_WriteString(h2);
	_delay_ms(1500);
	LCD_Clear_Screen();




	while(1)
	{
		value2 = Keypad_GetKey();
		if (value2 != NULL || fff1==1 || fff2==1) {
			fff1=0;fff2=0;
		if (value2==15){if (f==1){f=0;LCD_Clear_Screen();LCD_WriteString(h2);_delay_ms(1500);LCD_Clear_Screen();}else if (f==0) {f=1;}}

		if (f== 0){calculator();}
		else if (f==1){

		if (value2 == 12 ){f1=1;f2=0;}// save mode activated
		else if (value2 ==13 ){f2=1;f1=0;}// show mode activated
		else if (value2 ==11 ){f3=1;} // save or show

		if (f1==0 && f2==0 && f3 ==0){ // Main Memory Screen
			LCD_Clear_Screen();
			LCD_WriteString(l);
			_delay_ms(1500);
			LCD_Clear_Screen();
			LCD_WriteString(l1);
			LCD_SetPosition(1,0);
			LCD_WriteString(l2);
			_delay_ms(2000);
		}
		else if ( f1==1 && f2==0 && f3==0 && ff1==0){ // Chose to save Result

			LCD_Clear_Screen();
			LCD_WriteString(l3);

			value2=0;
			//temp2 = (temp2 *10) +value2;
			//LCD_Write_Number(temp2);
			ff1=1;

		}
		else if ( f1==1 && f2==0 && f3==0 && ff1==1){ // Chose to save Result


					LCD_SetPosition(1,0);

					temp2 = (temp2 *10) +value2;
					LCD_Write_Number(temp2);

				}
		else if ( f1==0 && f2==1 && f3==0 && ff2==0){ // Chose to show Result
			LCD_Clear_Screen();
			LCD_WriteString(l4);

			value2=0;
			//temp2 = (temp2 *10) +value2;
			//LCD_Write_Number(temp2);
			ff2=1;

		}
		else if ( f1==0 && f2==1 && f3==0 && ff2==1){ // Chose to show Result

					LCD_SetPosition(1,0);

					temp2 = (temp2 *10) +value2;
					LCD_Write_Number(temp2);

				}
		else if ( f1==1 && f2==0 && f3==1){// save result
			EEpromWriteByte(temp2,(u8)result);
			_delay_ms(500);
			temp2=0;
			LCD_Clear_Screen();
			LCD_WriteString(l5);
			LCD_SetPosition(1,0);
			LCD_WriteString(l6);
			_delay_ms(2000);
			f1=0;f3=0;ff1=0;fff1=1;
		}
		else if ( f1==0 && f2==1 && f3==1){// show result
			v =EEpromReadByte(temp2);
			_delay_ms(500);
			LCD_Clear_Screen();
			LCD_SetPosition(0,0);
			LCD_WriteString(l7);
			LCD_SetPosition(1,0);
			LCD_Write_Number(v);
			temp2=0;
			_delay_ms(3000);
			f2=0;f3=0;ff2=0;fff2=1;
		}

		}
		}

	}


	return 0;
}
void calculator(void){
	value= Keypad_GetKey();
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


