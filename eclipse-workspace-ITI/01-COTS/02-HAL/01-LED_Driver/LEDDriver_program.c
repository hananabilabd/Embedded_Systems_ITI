/*
 * LEDDriver_program.c
 *
 *  Created on: FEB13, 2019
 *      Author: Hanna Nabil
 */
#include"../../04-LIB/STD_TYPES.h"
#include"../../01-MCAL/DIO_interface.h"
#include"LEDDriver_interface.h"
#include"LEDDriver_private.h"
#include"LEDDriver_config.h"
u8 LEDDriver_u8Enable(void){
	u8 u8ErrorState =0;
	u8ErrorState=DIO_u8SetPinValue(0,DIO_U8_HIGH);
	return u8ErrorState;
}
u8 LEDDriver_u8Disable(void){
	u8 u8ErrorState =0;
	u8ErrorState=DIO_u8SetPinValue(0,DIO_U8_HIGH);
	return u8ErrorState;
}
