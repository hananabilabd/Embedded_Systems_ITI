/*
 * main.c
 *
 *  Created on: Feb 24, 2018
 *      Author: Hanna Nabil
 */

#include "typedef.h"
#include"LCD.h"
#define F_CPU 12000000UL
#include <util/delay.h>
#include "DIO.h"
#include "Keypad.h"

int main(void)
{

 LCD_Init();
 Keypad_Init();
u8 x =0;
//LCD_writeCharacter('S');
	while(1){


		for (u8 i =0 ;i<=15;i++){
			_delay_ms(20);

			u8 value = Keypad_GetButtonSatus(i);
			if (value ==1){
				/*LCD_SetPosition(0,0);
				u8 y[]= "  ";
				LCD_WriteString(y);
				*/
				x++;
				//
				LCD_SetPosition(0,x);
				LCD_Write_Number(i);
			}
		}

	}

return 0;

}

