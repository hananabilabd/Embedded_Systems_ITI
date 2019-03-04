/*
 * Version
 * DIO.h
 *
 *  Created on: Jan 30, 2019
 *      Author: Hanna Nabil
 */

#ifndef DIO_H_

#define DIO_U8_PORT0 0
#define DIO_U8_PORT1 1
#define DIO_U8_PORT2 2
#define DIO_U8_PORT3 3
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

#define DIO_U8_PIN_A1  DIO_U8_PIN_0  
#define DIO_U8_PIN_A2  DIO_U8_PIN_1  
#define DIO_U8_PIN_A3  DIO_U8_PIN_2  
#define DIO_U8_PIN_A4  DIO_U8_PIN_3  
#define DIO_U8_PIN_A5  DIO_U8_PIN_4  
#define DIO_U8_PIN_A6  DIO_U8_PIN_5  
#define DIO_U8_PIN_A7  DIO_U8_PIN_6  
#define DIO_U8_PIN_A8  DIO_U8_PIN_7  
#define DIO_U8_PIN_B1  DIO_U8_PIN_8  
#define DIO_U8_PIN_B2  DIO_U8_PIN_9 
#define DIO_U8_PIN_B3  DIO_U8_PIN_10
#define DIO_U8_PIN_B4  DIO_U8_PIN_11
#define DIO_U8_PIN_B5  DIO_U8_PIN_12
#define DIO_U8_PIN_B6  DIO_U8_PIN_13
#define DIO_U8_PIN_B7  DIO_U8_PIN_14
#define DIO_U8_PIN_B8  DIO_U8_PIN_15
#define DIO_U8_PIN_C1  DIO_U8_PIN_16
#define DIO_U8_PIN_C2  DIO_U8_PIN_17
#define DIO_U8_PIN_C3  DIO_U8_PIN_18
#define DIO_U8_PIN_C4  DIO_U8_PIN_19
#define DIO_U8_PIN_C5  DIO_U8_PIN_20
#define DIO_U8_PIN_C6  DIO_U8_PIN_21
#define DIO_U8_PIN_C7  DIO_U8_PIN_22
#define DIO_U8_PIN_C8  DIO_U8_PIN_23
#define DIO_U8_PIN_D1  DIO_U8_PIN_24
#define DIO_U8_PIN_D2  DIO_U8_PIN_25
#define DIO_U8_PIN_D3  DIO_U8_PIN_26
#define DIO_U8_PIN_D4  DIO_U8_PIN_27
#define DIO_U8_PIN_D5  DIO_U8_PIN_28
#define DIO_U8_PIN_D6  DIO_U8_PIN_29
#define DIO_U8_PIN_D7  DIO_U8_PIN_30
#define DIO_U8_PIN_D8  DIO_U8_PIN_31

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
