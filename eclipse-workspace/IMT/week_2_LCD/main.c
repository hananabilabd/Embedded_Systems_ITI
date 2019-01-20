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


int main(void)
{
	LCD_Init();

	/*
	LCD_SetPosition(0,3);
	LCD_writeCharacter('*');

	u8 arr[]="Hello HANNA";
	u8 *u[]={"Ahmed","Amr" ,"Wael"};
	LCD_WriteString(arr);
	LCD_SetPosition(1,0);
	LCD_WriteString(u[1]);

	LCD_Write_Number(030);

*/

	while(1){

		LCD_Write_Special();

	}

return 0;

}

