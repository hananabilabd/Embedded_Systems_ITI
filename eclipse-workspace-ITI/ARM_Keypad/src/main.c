

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "Keypad_interface.h"
//#include "Keypad_private.h"
//#include "Keypad_config.h"
u8 checkarray(u8 arr[]){
		for (u8 i =0 ;i< 16 ;i++){
			if (arr[i]==KEYPAD_u8_PRESSED ){
				return 1;
			}
		}
		return 0;
}
int main(void)
{
	RCC_voidInitialize();
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOA,RCC_u8_ENABLE_CLK);

	u8 x=0;

	Keypad_u8Init();


	DIO_u8SetPinDirection(DIO_U8_PIN_A8,DIO_OUTPUT_2M_PUSH_PULL);
	DIO_u8SetPinValue(DIO_U8_PIN_A8,DIO_U8_HIGH);
	//u8 KeysState[KEYPAD_u8_KEYS_NB];
	while(1)
	{
		/*
		Keypad_u8GetKeypadState(KeysState);
		x=checkarray(KeysState);
		//DIO_u8GetPinValue(DIO_U8_PIN_A9,&x);
		if (x ==1){DIO_u8SetPinValue(DIO_U8_PIN_A9,DIO_U8_HIGH);}
		else if (x ==0){DIO_u8SetPinValue(DIO_U8_PIN_A9,DIO_U8_LOW);}
*/
	}
  return 0;
}


