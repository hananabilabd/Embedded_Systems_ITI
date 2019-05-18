/*********************************************************************/
/* Author  : Khlood Amin                                             */
/* Version : V01                                                     */
/* Date    : 4 FEB 2018                                              */
/*********************************************************************/
/* Description                                                       */
/* -------------                                                     */
/*                                                                   */
/* This component is used to define the private data and function                       */
/*********************************************************************/

/* Component : Header file guard                                     */

#ifndef _DIO_PRIVATE_H
#define _DIO_PRIVATE_H

#define DIO_u8_PORTA ((Register_8Bit*)0x3B)
#define DIO_u8_DDRA  ((Register_8Bit*)0x3A)
#define DIO_u8_PINA  ((Register_8Bit*)0x39)
#define DIO_u8_PORTB ((Register_8Bit*)0x38)
#define DIO_u8_DDRB  ((Register_8Bit*)0x37)
#define DIO_u8_PINB  ((Register_8Bit*)0x36)
#define DIO_u8_PORTC ((Register_8Bit*)0x35)
#define DIO_u8_DDRC  ((Register_8Bit*)0x34)
#define DIO_u8_PINC  ((Register_8Bit*)0x33)
#define DIO_u8_PORTD ((Register_8Bit*)0x32)
#define DIO_u8_DDRD  ((Register_8Bit*)0x31)
#define DIO_u8_PIND  ((Register_8Bit*)0x30)
#define PINS_PER_PORT 8
#define  DIO_ERROE_OK		0
#define  DIO_ERROE_NOK		1

#endif 
