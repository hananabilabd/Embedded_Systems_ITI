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
void LCD_voidWriteData(u8 Copy_u8Data);
void LCD_voidClearScreen(void);

#endif /* LCD_INTERFACE_H_ */
