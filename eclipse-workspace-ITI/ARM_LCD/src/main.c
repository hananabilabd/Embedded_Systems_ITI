

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "delay.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "Keypad_interface.h"
//#include "Keypad_private.h"
//#include "Keypad_config.h"
#include "LCD_interface.h"
//#include "LCD_config.h"
#include "LCD_private.h"



int main(void)
{
	RCC_voidInitialize();
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOA,RCC_u8_ENABLE_CLK);


	LCD_voidInitialize();

	LCD_voidWriteData('H');
	LCD_voidWriteData('a');
	LCD_voidWriteData('n');
	LCD_voidWriteData('n');
	LCD_voidWriteData('a');


	/*DIO_u8SetPinDirection(DIO_U8_PIN_A8,DIO_U8_HIGH);
	DIO_u8SetPinValue(DIO_U8_PIN_A8,DIO_U8_HIGH);*/
	while(1)
	{

	}
	return 0;
}


