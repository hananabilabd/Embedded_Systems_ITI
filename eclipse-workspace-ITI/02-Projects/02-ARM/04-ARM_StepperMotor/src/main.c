

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
//#include "LedMatrix_config.h"
#include "LedMatrix_interface.h"

extern u8 LedMatrix_Au8Cols[8];
extern u8 LedMatrix_Au8Rows[8];

u8 hamoksha_left[8]={144, 215, 125, 125, 215, 144, 0, 0};
u8 hamoksha_middle[8]={0, 144, 215, 125, 125, 215, 144, 0};
u8 hamoksha_right[8]={0, 0, 144, 215, 125, 125, 215, 144};

u8 arrow_clockWise1[8]={0, 48, 0, 0, 0, 0, 0, 0};
u8 arrow_clockWise2[8]={0, 56, 4, 0, 0, 0, 0, 0};
u8 arrow_clockWise3[8]={0, 56, 4, 2, 2, 0, 0, 0};
u8 arrow_clockWise4[8]={0, 56, 4, 2, 2, 4, 8, 0};
u8 arrow_clockWise5[8]={0, 56, 4, 2, 2, 4, 56, 0};
u8 *arrow_clockWise[5]={arrow_clockWise1,arrow_clockWise2,arrow_clockWise3,arrow_clockWise4,arrow_clockWise5};
u8 arrow_anticlockWise1[8]={0, 0, 0, 0, 0, 0, 48, 0};
u8 arrow_anticlockWise2[8]={0, 0, 0, 0, 0, 4, 56, 0};
u8 arrow_anticlockWise3[8]={0, 0, 0, 2, 2, 4, 56, 0};
u8 arrow_anticlockWise4[8]={0, 8, 4, 2, 2, 4, 56, 0};
u8 arrow_anticlockWise5[8]={0, 56, 4, 2, 2, 4, 56, 0};
u8 *arrow_anticlockWise[5]={arrow_anticlockWise1,arrow_anticlockWise2,arrow_anticlockWise3,arrow_anticlockWise4,arrow_anticlockWise5};
u8 **selection[2]={arrow_clockWise,arrow_anticlockWise};
u8  LCD_clockWise[]="ClockWise";
u8  LCD_anticlockWise[]="Anti-ClockWise";
void LCD_clockwise(void){
	LCD_voidClearScreen();
	LCD_voidWriteString(LCD_clockWise);
}
void LCD_anticlockwise(void){
	LCD_voidClearScreen();
	LCD_voidWriteString(LCD_anticlockWise);
}
void (*ptr[2]) (void)={LCD_clockwise,LCD_anticlockwise};
int main(void)
{
	RCC_voidInitialize();
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOA,RCC_u8_ENABLE_CLK);
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOB,RCC_u8_ENABLE_CLK);
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOC,RCC_u8_ENABLE_CLK);

	DIO_u8SetPortDirection(DIO_U8_PORTA,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPortDirection(DIO_U8_PORTB,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPortDirection(DIO_U8_PORTC,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPortValue(DIO_U8_PORTA,0xFFFF);
	//DIO_u8SetPortValue(DIO_U8_PORTB,0xFFFF);
	//DIO_u8SetPortValue(DIO_U8_PORTC,0xFFFF);
	DIO_u8SetPinDirection(DIO_U8_PIN_C14,DIO_INPUT_PULLUP);
	DIO_u8SetPinDirection(DIO_U8_PIN_C15,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPinValue(DIO_U8_PIN_C15,DIO_U8_LOW);
	LCD_voidInitialize();
	//Keypad_u8Init();
	LedMatrix_voidInitialize();
	(*ptr[0])();
	u8 i =0 ,x=0,j=0,counter = 0 ;
	u8 states=0;
	u8 motorclockwise[4]={0,1,2,3};
	u8 motoranticlock[4]={3,2,1,0};
	u8 *motorcounterSelection[2]={motorclockwise , motoranticlock};
	while(1)
	{
		for ( i =0; i < 8 ; i++){
		DIO_u8SetPinValue(LedMatrix_Au8Cols[i], DIO_U8_LOW);
		DIO_u8SetPinValue(motorcounterSelection[states][i%4],DIO_U8_HIGH);

		DIO_u8SetArrayValue(LedMatrix_Au8Rows,  selection[states][j][i], 8) ;
		delay_ms(2);
		DIO_u8GetPinValue(DIO_U8_PIN_C14,&x);
		if ( x == DIO_U8_BUTTON_RELEASED ){
			DIO_u8SetPinValue(DIO_U8_PIN_C15,DIO_U8_HIGH);
			//if (state == 0){state = 1;}
			//else {state = 0;}
			toggle_bit(states,0);
			delay_ms(200);
			(*ptr[states])();
		}
		/*
		else {
			DIO_u8SetPinValue(DIO_U8_PIN_C15,DIO_U8_LOW);
		}*/
		DIO_u8SetPinValue(LedMatrix_Au8Cols[i], DIO_U8_HIGH);
		DIO_u8SetPinValue(motorcounterSelection[states][i%4],DIO_U8_LOW);
		}
		counter++ ;
		if (counter > 60){
			DIO_u8SetPinValue(DIO_U8_PIN_C15,DIO_U8_LOW);
			counter =0 ;
		j++;
		if (j == 5 ){j =0 ;}}




	}
	return 0;
}


