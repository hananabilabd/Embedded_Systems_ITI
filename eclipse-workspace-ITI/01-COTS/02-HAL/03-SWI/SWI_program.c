/*
 * SWI_program.c
 *
 *  Created on: Feb 14, 2019
 *      Author: Hanna Nabil
 */
#include"../../04-LIB/STD_TYPES.h"
#include"../../01-MCAL/01-DIO/DIO_interface.h"
#include"SWI_interface.h"
#include"SWI_private.h"
#include"SWI_config.h"
u8 SWI_u8GetSwitchState(u8 Copy_u8ID,u8* Pcopy_u8SwitchState){
	u8 Local_u8ErrorState =0;
	u8 Local_u8SwitchPressed=0;
	if (Copy_u8ID >= SWI_U8_NB){
		Local_u8ErrorState=1;
	}
	else {
		Local_u8ErrorState=0;
		if ( SWI_Au8ConnectionType[Copy_u8ID]== SWI_U8_INTERNAL_PULL_UP){
			Local_u8ErrorState=DIO_u8GetPinValue(SWI_Au8ConnectedPins[Copy_u8ID],&Local_u8SwitchPressed);
			if (Local_u8SwitchPressed== 0){
				*Pcopy_u8SwitchState =SWI_U8_KEY_PRESSED;
			}
			else {
				*Pcopy_u8SwitchState =SWI_U8_KEY_NOT_PRESSED;}
		}
	}
	return Local_u8ErrorState;
}
