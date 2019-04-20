/*
 * LCD_interface.h
 *
 *  Created on: Mar 3, 2019
 *      Author: Hanna Nabil
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInitialize(void);
void LCD_voidWriteCommand(u8 Copy_u8Write);
void LCD_voidWriteCharacter(u8 Copy_u8Data);
void LCD_voidClearScreen(void);
void LCD_voidWriteString(u8 *arr);
void LCD_voidSetPosition(u8 Copy_u8Row,u8 Copy_u8Column);
void LCD_voidWriteNumber(u64 number);

void LCD_voidWriteSpecialInitialize(u8 * Copy_u8Array);
void LCD_voidWriteFloat(f64 realValue);
void WriteHannaInitialize(void);
void WriteHanna(u8 Copy_u8Row , u8 Copy_column);

#endif /* LCD_INTERFACE_H_ */
