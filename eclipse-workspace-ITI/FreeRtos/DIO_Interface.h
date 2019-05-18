/*********************************************************************/
/* Author  : Khlood Amin                                             */
/* Version : V01                                                     */
/* Date    : 4 FEB 2018                                              */
/*********************************************************************/
/* Description                                                       */
/* -------------                                                     */
/*                                                                   */
/* This file defines the APIs corresponding to DIO                   */
/*********************************************************************/


/* Component : Header file guard                                     */
#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

/* DIO pin numbers*/
#define DIO_u8_PIN_0     0
#define DIO_u8_PIN_1     1
#define DIO_u8_PIN_2     2
#define DIO_u8_PIN_3     3
#define DIO_u8_PIN_4     4
#define DIO_u8_PIN_5     5
#define DIO_u8_PIN_6     6
#define DIO_u8_PIN_7     7
#define DIO_u8_PIN_8     8
#define DIO_u8_PIN_9     9
#define DIO_u8_PIN_10    10
#define DIO_u8_PIN_11    11
#define DIO_u8_PIN_12    12
#define DIO_u8_PIN_13    13
#define DIO_u8_PIN_14    14
#define DIO_u8_PIN_15    15
#define DIO_u8_PIN_16    16
#define DIO_u8_PIN_17    17
#define DIO_u8_PIN_18    18
#define DIO_u8_PIN_19    19
#define DIO_u8_PIN_20    20
#define DIO_u8_PIN_21    21
#define DIO_u8_PIN_22    22
#define DIO_u8_PIN_23    23
#define DIO_u8_PIN_24    24
#define DIO_u8_PIN_25    25
#define DIO_u8_PIN_26    26
#define DIO_u8_PIN_27    27
#define DIO_u8_PIN_28    28
#define DIO_u8_PIN_29    29
#define DIO_u8_PIN_30    30
#define DIO_u8_PIN_31    31

#define DIO_u8_PORT_A    1
#define DIO_u8_PORT_B    2
#define DIO_u8_PORT_C    3
#define DIO_u8_PORT_D    4

#define DIO_MAXPINNB     31
#define DIO_MAXPORTNB    4
/*  Component : DIO Pin Value                                          */

#define DIO_u8_HIGH      1
#define DIO_u8_LOW       0

/*  Component : DIO Pin Direction                                     */
                            
#define DIO_u8_INPUT     0
#define DIO_u8_OUTPUT    1       
 
/** Description : This function shall intialize the direction and    */
/* 				  intial value for pins                              */

void DIO_voidIntialize(void);
u8 DIO_u8SetPinValue( u8 Copy_u8PinNumber , u8 Copy_u8PinValue);
u8 DIO_u8SetPinDirection (u8 Copy_u8PinNumber , u8 Copy_u8PinDirecection);
u8 DIO_u8GetPinValue( u8 Copy_u8PinNumber , u8 *Copy_Pu8PinValue);
u8 DIO_u8SetPortValue ( u8 Copy_u8PortNumber , u8 Copy_u8PortValue);
u8 DIO_u8SetPortDirection (u8 Copy_u8PortNumber , u8 Copy_u8PortDirection);
u8 DIO_u8GetPortValue (u8 Copy_u8PortNumber , u8 Copy_Pu8PortValue);
u8 DIO_u8AssignPortValue(u8 Copy_u8PortNumber, u8 Copy_Pu8PortValue);

#endif
