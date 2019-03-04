
#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

#define KEYPAD_u8_KEYS_NB		            9 // KEYPAD_u8_ROWS * KEYPAD_u8_COL

#define KEYPAD_u8_NOT_PRESSED		        0
#define KEYPAD_u8_PRESSED			        1

#define KEYPAD_u8_ACTIVE_COL		        0
#define KEYPAD_u8_ACTIVE_ROW		        1

#define KEYPAD_u8_CONNECTION_PULLDOWN		0
#define KEYPAD_u8_CONNECTION_PULLUP		    1

/* */
/* */
u8 Keypad_u8Init(void);
u8 Keypad_u8GetKeypadState(u8 Copy_Au8KeysState[KEYPAD_u8_KEYS_NB]);

#endif
