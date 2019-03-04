/*
 * LCD_config.h
 *
 *  Created on: Mar 3, 2019
 *      Author: Hanna Nabil
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_RS DIO_U8_PIN_A8
#define LCD_RW DIO_U8_PIN_A9
#define LCD_E  DIO_U8_PIN_A10

#define LCD_DATA_PINS_NB 8

u8 LCD_Au8DataPins[LCD_DATA_PINS_NB] =
{
		  DIO_U8_PIN_A0,
		  DIO_U8_PIN_A1,
		  DIO_U8_PIN_A2,
		  DIO_U8_PIN_A3,
		  DIO_U8_PIN_A4,
		  DIO_U8_PIN_A5,
		  DIO_U8_PIN_A6,
		  DIO_U8_PIN_A7
		
};





#endif /* LCD_CONFIG_H_ */
