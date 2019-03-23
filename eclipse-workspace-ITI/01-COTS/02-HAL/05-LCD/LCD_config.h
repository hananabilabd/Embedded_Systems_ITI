/*
 * LCD_config.h
 *
 *  Created on: Mar 3, 2019
 *      Author: Hanna Nabil
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_BIT_MODE LCD_4_MODE
#define LCD_DATA_PINS_NB 4

#define LCD_RS DIO_U8_PIN_B10
#define LCD_RW DIO_U8_PIN_B1
#define LCD_E  DIO_U8_PIN_B0
/**********
 * vo will be connected with 1K resistor on the ground
 */
#define MICROCONTROLLER ARM


u8 LCD_Au8DataPins[LCD_DATA_PINS_NB] =
{
		  DIO_U8_PIN_A7,// D4
		  DIO_U8_PIN_A6, //D5
		  DIO_U8_PIN_A5, //D6
		  DIO_U8_PIN_A4, //D7
		
};





#endif /* LCD_CONFIG_H_ */
