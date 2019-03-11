
#include "STD_TYPES.h"
#include"BIT_CALC.h"
//MCAL includes
#include "DIO_interface.h"
#include "Keypad_config.h"
#include "Keypad_interface.h"
#include "Keypad_private.h"
/*******************/
#include "delay.h"

u8 Keypad_u8Init(void){
	u8 Local_u8ErrorState=0;
	for ( u8 i =0 ; i<KEYPAD_u8_ROWS ; i++){
		#if (KEYPAD_u8_ACTIVATION_TYPE == KEYPAD_u8_ACTIVE_COL)
				DIO_u8SetPinDirection(Keypad_Au8RowsPins[i],KEYPAD_u8_INPUT_TYPE);
		#else
				DIO_u8SetPinDirection(Keypad_Au8RowsPins[i],KEYPAD_u8_OUTPUT_TYPE);
		#endif
	}
	for ( u8 j=0; j <KEYPAD_u8_COLS ; j++){
			#if (KEYPAD_u8_ACTIVATION_TYPE == KEYPAD_u8_ACTIVE_COL)
					DIO_u8SetPinDirection(Keypad_Au8ColsPins[j],KEYPAD_u8_OUTPUT_TYPE);
			#else
					DIO_u8SetPinDirection(Keypad_Au8ColsPins[j],KEYPAD_u8_INPUT_TYPE);
			#endif

		}
	return Local_u8ErrorState;
}
u8 Keypad_u8GetKeypadState(u8 Copy_Au8KeysState[KEYPAD_u8_KEYS_NB])
{
	u8 Local_ErrorState=0;
	u8 Local_u8ColIndex = 0;
	u8 Local_u8RowIndex = 0;
	u8 Local_u8CurrentPinValue;
	u8 Local_u8KeyIndex=0;
	// check on Activation type
#if KEYPAD_u8_ACTIVATION_TYPE== KEYPAD_u8_ACTIVE_COL  // keypad is active column

	for(Local_u8ColIndex = 0; Local_u8ColIndex < KEYPAD_u8_COLS; Local_u8ColIndex ++ )
	{
		//activate current column
		#if KEYPAD_u8_CONNECTION_TYPE==KEYPAD_u8_CONNECTION_PULLUP
			DIO_u8SetPinValue(Keypad_Au8ColsPins[Local_u8ColIndex], DIO_U8_LOW);
		#else
			DIO_u8SetPinValue(Keypad_Au8ColsPins[Local_u8ColIndex], DIO_U8_HIGH);
		#endif
		
		//Check on active ROW
		
		for(Local_u8RowIndex = 0; Local_u8RowIndex < KEYPAD_u8_ROWS; Local_u8RowIndex ++)
		{
			Local_ErrorState=DIO_u8GetPinValue(Keypad_Au8RowsPins[Local_u8RowIndex], &Local_u8CurrentPinValue);
			Local_u8KeyIndex = Local_u8ColIndex + (Local_u8RowIndex*KEYPAD_u8_COLS);
			if(DIO_U8_BUTTON_PRESSED == Local_u8CurrentPinValue)
			{
				Copy_Au8KeysState[Local_u8KeyIndex]= KEYPAD_u8_PRESSED;
			}else
			{
				Copy_Au8KeysState[Local_u8KeyIndex]= KEYPAD_u8_NOT_PRESSED;
			}
		}
		#if KEYPAD_u8_CONNECTION_TYPE==KEYPAD_u8_CONNECTION_PULLUP
			DIO_u8SetPinValue(Keypad_Au8ColsPins[Local_u8ColIndex], DIO_U8_HIGH);
		#else
			DIO_u8SetPinValue(Keypad_Au8ColsPins[Local_u8ColIndex], DIO_U8_LOW);
		#endif
	}
#else // Keypad is active Row
	for(Local_u8RowIndex = 0; Local_u8RowIndex < KEYPAD_u8_ROWS; Local_u8RowIndex ++ )
		{
			//activate current column
			#if KEYPAD_u8_CONNECTION_TYPE==KEYPAD_u8_CONNECTION_PULLUP
				DIO_u8SetPinValue(Keypad_Au8ColsPins[Local_u8ColIndex], DIO_U8_LOW);
			#else
				DIO_u8SetPinValue(Keypad_Au8ColsPins[Local_u8ColIndex], DIO_U8_HIGH);
			#endif

			//Check on active ROW

			for(Local_u8ColIndex = 0; Local_u8ColIndex < KEYPAD_u8_COLS; Local_u8ColIndex ++)
			{
				Local_ErrorState=DIO_u8GetPinValue(Keypad_Au8ColsPins[Local_u8ColIndex], &Local_u8CurrentPinValue);
				Local_u8KeyIndex = Local_u8RowIndex + (Local_u8ColIndex*KEYPAD_u8_ROWS);
				if(DIO_U8_BUTTON_PRESSED == Local_u8CurrentPinValue)
				{
					Copy_Au8KeysState[Local_u8KeyIndex]= KEYPAD_u8_PRESSED;
				}else
				{
					Copy_Au8KeysState[Local_u8KeyIndex]= KEYPAD_u8_NOT_PRESSED;
				}
			}
			#if KEYPAD_u8_CONNECTION_TYPE==KEYPAD_u8_CONNECTION_PULLUP
				DIO_u8SetPinValue(Keypad_Au8RowsPins[Local_u8RowIndex], DIO_U8_HIGH);
			#else
				DIO_u8SetPinValue(Keypad_Au8RowsPins[Local_u8RowIndex], DIO_U8_LOW);
			#endif
		}
#endif
	return Local_ErrorState;
}
u8 Keypad_u8GetPressedKey(void){
	u8 arr[16]={0};
	u8 i =0;
	Keypad_u8GetKeypadState(arr);
	for ( i =0 ; i< 16 ; i++){
		if (arr[i]==KEYPAD_u8_PRESSED ) {

			//arr[i]=KEYPAD_u8_NOT_PRESSED;
			delay_ms(400);
			return i;
		}
	}
	return NULL;
}
