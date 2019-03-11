

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
#include "LedMatrix_interface.h"


u8 hamoksha_left[8]={144, 215, 125, 125, 215, 144, 0, 0};
u8 hamoksha_middle[8]={0, 144, 215, 125, 125, 215, 144, 0};
u8 hamoksha_right[8]={0, 0, 144, 215, 125, 125, 215, 144};
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
	LedMatrix_voidInitialize();

	//u8 NULL=20;
	u8 i;
	u8 value;
	s8 horizontalCounter=0,VerticalCounter=0;
	u8 LCD_hamoksha[8]={14, 10, 14, 4, 14, 4, 14, 10};
	LCD_voidWriteSpecialInitialize(LCD_hamoksha);

	while(1)
	{
		value=Keypad_u8GetPressedKey();
		if (value !=NULL){
			if (value == 2 ){
				horizontalCounter++;
				if (horizontalCounter >18){horizontalCounter=0;LCD_voidClearScreen();}
			}
			else if (value == 0 ){
				horizontalCounter--;
				if (horizontalCounter < 0){horizontalCounter=18;}
			}
			if (horizontalCounter > 1){
				LCD_voidClearScreen();
				LCD_voidSetPosition(0,horizontalCounter-3);
				LCD_voidWriteCharacter(0);
			}
			if (horizontalCounter < 2){
				LCD_voidClearScreen();
			}
		}


		if (horizontalCounter ==0){
			LedMatrix_u8draw(hamoksha_middle);
		}
		else if (horizontalCounter ==1){
			LedMatrix_u8draw(hamoksha_right);
		}




	}
	return 0;
}


