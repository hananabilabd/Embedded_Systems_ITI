/*
 * Version
 * DIO.h
 *
 *  Created on: Jan 30, 2019
 *      Author: Hanna Nabil
 */

#ifndef DIO_H_

#define DIO_U8_PORT_A   0
#define DIO_U8_PORT_B   1
#define DIO_U8_PORT_C   2
#define DIO_U8_PORT_D   3

#define DIO_U8_PIN_A0     0
#define DIO_U8_PIN_A1     1
#define DIO_U8_PIN_A2     2
#define DIO_U8_PIN_A3     3
#define DIO_U8_PIN_A4     4
#define DIO_U8_PIN_A5     5
#define DIO_U8_PIN_A6     6
#define DIO_U8_PIN_A7     7
#define DIO_U8_PIN_B0     8
#define DIO_U8_PIN_B1     9
#define DIO_U8_PIN_B2     10
#define DIO_U8_PIN_B3     11
#define DIO_U8_PIN_B4     12
#define DIO_U8_PIN_B5     13
#define DIO_U8_PIN_B6     14
#define DIO_U8_PIN_B7     15
#define DIO_U8_PIN_C0     16
#define DIO_U8_PIN_C1     17
#define DIO_U8_PIN_C2     18
#define DIO_U8_PIN_C3     19
#define DIO_U8_PIN_C4     20
#define DIO_U8_PIN_C5     21
#define DIO_U8_PIN_C6     22
#define DIO_U8_PIN_C7     23
#define DIO_U8_PIN_D0     24
#define DIO_U8_PIN_D1     25
#define DIO_U8_PIN_D2     26
#define DIO_U8_PIN_D3     27
#define DIO_U8_PIN_D4     28
#define DIO_U8_PIN_D5     29
#define DIO_U8_PIN_D6     30
#define DIO_U8_PIN_D7     31

/*comment : DIO Pin Direction */
#define DIO_U8_INPUT  0
#define DIO_U8_OUTPUT 1
/*comment : DIO Pin Value */
#define DIO_U8_HIGH 1
#define DIO_U8_LOW  0

#define DIO_MAXPINNB 32
#define DIO_MAXPORTNB 4



#define DIO_MAXPORTNB 4


/*
 * Description : set PIN direction
input : u8 PinNB -> pin number
      : u8 Direction -> pin Direction
output : function Error state */
void DIO_voidInitialize(void);
u8 DIO_u8SetPinDirection(u8 u8PinNB, u8 u8Direction);
u8 DIO_u8SetPinValue(u8 u8PinNB, u8 u8Value);
u8 DIO_u8GetPinValue(u8 u8PinNB, u8* Pu8Value);
u8 DIO_u8SetPortDirection(u8 u8PortNB, u8 u8Direction);
u8 DIO_u8SetPortValue(u8 u8PortNB, u8 u8Value);
u8 DIO_u8GetPortValue(u8 u8PortNB, u8* Pu8Value);
u8 DIO_u8SetPortPullUp(u8 u8PortNB,u8 u8Value);
u8 DIO_u8SetPinPullUp(u8 u8PinNB);
#endif /* DIO_H_ */
