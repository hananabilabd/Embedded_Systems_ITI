
#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


#define KEYPAD_u8_ROWS		                      3
#define KEYPAD_u8_COLS		                      3


#define KEYPAD_u8_OUTPUT_TYPE       DIO_OUTPUT_2M_PUSH_PULL
#define KEYPAD_u8_INPUT_TYPE        DIO_INPUT_PULLDOWN // this is for initialization

//  KEYPAD_u8_INPUT_TYPE   must be  = KEYPAD_u8_CONNECTION_PULLUP
#define KEYPAD_u8_ACTIVATION_TYPE	KEYPAD_u8_ACTIVE_COL
#define KEYPAD_u8_CONNECTION_TYPE	KEYPAD_u8_CONNECTION_PULLDOWN

u8 Keypad_Au8RowsPins[KEYPAD_u8_ROWS] =
{
		DIO_U8_PIN_B12,
		DIO_U8_PIN_B13,
		DIO_U8_PIN_B14
};

u8 Keypad_Au8ColsPins[KEYPAD_u8_COLS]  =
{
		DIO_U8_PIN_B15,
		DIO_U8_PIN_A8,
		DIO_U8_PIN_A9
};

#endif
