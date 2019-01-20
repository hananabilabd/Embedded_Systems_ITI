/*
 * LCD.h
 *
 *  Created on: Dec 2, 2017
 *      Author: Mina Medhat
 */

#ifndef LCD_H_
#define LCD_H_
void LCD_writedata(u8 data);
void LCD_writecommand(u8 data);
void LCD_init(void);
void LCD_writestring (u8 arr[]);
LCD_setposition(u8 row , u8 column);
void LCDWriteInt(s32 x);
#endif /* LCD_H_ */
