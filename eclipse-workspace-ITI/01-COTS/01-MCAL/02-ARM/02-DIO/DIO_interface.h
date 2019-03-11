/*
 * DIO_interface.h
 *
 *  Created on: Feb 21, 2019
 *      Author: Hanna Nabil
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_U8_PORTA 0
#define DIO_U8_PORTB 1
#define DIO_U8_PORTC 2
#define DIO_U8_PORTD 3
#define DIO_U8_PIN_0  0
#define DIO_U8_PIN_1  1
#define DIO_U8_PIN_2  2
#define DIO_U8_PIN_3  3
#define DIO_U8_PIN_4  4
#define DIO_U8_PIN_5  5
#define DIO_U8_PIN_6  6
#define DIO_U8_PIN_7  7
#define DIO_U8_PIN_8  8
#define DIO_U8_PIN_9   9
#define DIO_U8_PIN_10  10
#define DIO_U8_PIN_11  11
#define DIO_U8_PIN_12  12
#define DIO_U8_PIN_13  13
#define DIO_U8_PIN_14  14
#define DIO_U8_PIN_15  15
#define DIO_U8_PIN_16  16
#define DIO_U8_PIN_17  17
#define DIO_U8_PIN_18  18
#define DIO_U8_PIN_19  19
#define DIO_U8_PIN_20  20
#define DIO_U8_PIN_21  21
#define DIO_U8_PIN_22  22
#define DIO_U8_PIN_23  23
#define DIO_U8_PIN_24  24
#define DIO_U8_PIN_25  25
#define DIO_U8_PIN_26  26
#define DIO_U8_PIN_27  27
#define DIO_U8_PIN_28  28
#define DIO_U8_PIN_29  29
#define DIO_U8_PIN_30  30
#define DIO_U8_PIN_31  31
#define DIO_U8_PIN_32  45
#define DIO_U8_PIN_33  46
#define DIO_U8_PIN_34  47
#define DIO_U8_PIN_35  48
#define DIO_U8_PIN_36  49

#define DIO_U8_PIN_A0  0
#define DIO_U8_PIN_A1  1
#define DIO_U8_PIN_A2  2
#define DIO_U8_PIN_A3  3
#define DIO_U8_PIN_A4  4
#define DIO_U8_PIN_A5  5
#define DIO_U8_PIN_A6  6
#define DIO_U8_PIN_A7  7
#define DIO_U8_PIN_A8  8
#define DIO_U8_PIN_A9   9
#define DIO_U8_PIN_A10  10
#define DIO_U8_PIN_A11  11
#define DIO_U8_PIN_A12  12
#define DIO_U8_PIN_A13  13
#define DIO_U8_PIN_A14  14
#define DIO_U8_PIN_A15  15
#define DIO_U8_PIN_B0  16
#define DIO_U8_PIN_B1  17
#define DIO_U8_PIN_B2  18
#define DIO_U8_PIN_B3  19
#define DIO_U8_PIN_B4  20
#define DIO_U8_PIN_B5  21
#define DIO_U8_PIN_B6  22
#define DIO_U8_PIN_B7  23
#define DIO_U8_PIN_B8  24
#define DIO_U8_PIN_B9  25
#define DIO_U8_PIN_B10  26
#define DIO_U8_PIN_B11  27
#define DIO_U8_PIN_B12 28
#define DIO_U8_PIN_B13  29
#define DIO_U8_PIN_B14  30
#define DIO_U8_PIN_B15  31
#define DIO_U8_PIN_C13  45
#define DIO_U8_PIN_C14  46
#define DIO_U8_PIN_C15  47
#define DIO_U8_PIN_D0  48
#define DIO_U8_PIN_D1  49

#define DIO_U8_INPUT  0
#define DIO_U8_OUTPUT 1

#define DIO_U8_BUTTON_PRESSED  1
#define DIO_U8_BUTTON_RELEASED 0
/*comment : DIO Pin Value */
#define DIO_U8_HIGH 1
#define DIO_U8_LOW  0

#define DIO_MAXPINNB 32
#define DIO_MAXPORTNB 4
#define DIO_MAXPORTNB 4
#define PINS_PER_PORT 16

#define DIO_INPUT_ANALOG               0b0000
#define DIO_INPUT_FLOATING             0b0100
#define DIO_INPUT_PULLDOWN             0b1000
#define DIO_INPUT_PULLUP               0b1100

#define DIO_OUTPUT_2M_PUSH_PULL        0b0010
#define DIO_OUTPUT_2M_OPEN_DRAIN       0b0110
#define DIO_OUTPUT_2M_AF_PUSH_PULL     0b1010
#define DIO_OUTPUT_2M_AF_OPEN_DRAIN    0b1110

#define DIO_OUTPUT_10M_PUSH_PULL       0b0001
#define DIO_OUTPUT_10M_OPEN_DRAIN      0b0101
#define DIO_OUTPUT_10M_AF_PUSH_PULL    0b1001
#define DIO_OUTPUT_10M_AF_OPEN_DRAIN   0b1101

#define DIO_OUTPUT_50M_PUSH_PULL       0b0011
#define DIO_OUTPUT_50M_OPEN_DRAIN      0b0111
#define DIO_OUTPUT_50M_AF_PUSH_PULL    0b1011
#define DIO_OUTPUT_50M_AF_OPEN_DRAIN   0b1111


void DIO_voidInitialize(void);
u8 DIO_u8SetPinValue(u8 Copy_u8PinNb, u8 Copy_u8Value);
u8 DIO_u8GetPinValue(u8 Copy_u8PinNb, u8* Copy_Pu8Value);
u8 DIO_u8SetPinDirection(u8 Copy_u8PinNb, u8 Copy_u8Mode) ;
u8 DIO_u8SetPortValue(u8 Copy_u8PortNb, u16 Copy_u16Value) ;
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNb ,u16 Copy_u16Value,u8 Copy_u8ModeInput,u8 Copy_u8ModeOutput);
u8 DIO_u8SetArrayValue(u8 * Copy_u8APins, u16 Copy_u16Value,u8 Copy_u8ArraySize) ;


#endif /* DIO_INTERFACE_H_ */
