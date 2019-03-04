

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "delay.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
//#include "Keypad_interface.h"
//#include "Keypad_private.h"
//#include "Keypad_config.h"
#include "LCD_interface.h"
//#include "LCD_config.h"
#include "LCD_private.h"



int main(void)
{



	LCD_voidInitialize();

	LCD_voidWriteData('H');
	LCD_voidWriteData('a');
	LCD_voidWriteData('n');
	LCD_voidWriteData('n');
	LCD_voidWriteData('a');


	while(1)
	{

	}
	return 0;
}


