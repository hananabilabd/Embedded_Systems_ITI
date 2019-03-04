/*
 * SSD_program.c
 *
 *  Created on: Feb 13, 2019
 *      Author: Hanna Nabil
 */
#include "../../04-LIB/STD_TYPES.h"
#include"../../01-MCAL/01-DIO/DIO_interface.h"
#include"SSD_interface.h"
#include"SSD_config.h"
#include"SSD_private.h"

/******* This array begin with zero to 9 representations on the 7 segments*****************************/
u8 SSD_Au8BCDValues[SDD_U8_AVAILABLE_VALUES]={0b00111111,0b00000110,0b01011011,0b11001111,0b01100110,0b1101101,0b01111101,0b00000111,0b01111111,0b01100111}; // if cathode
/*****************************************this if you wanna put just dashes on 7 segment*****************************/
u8 SSD_Au8DashValues[SDD_U8_AVAILABLE_DASHES]={0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0b00100000,0b01000000,0b10000000}; // if cathode
u8 SSD_Au8LastStates[SSD_U8_NB]={0};
u8 SSD_Au8LastValues[SSD_U8_NB]={0};
u8 SSD_u8DisplayON(u8 Copy_u8ID){
	u8 Local_u8ErrorState =0;
	if (Copy_u8ID >= SSD_U8_NB){
		Local_u8ErrorState=1;
	}
	else{
		if (SSD_Au8SSDtype[Copy_u8ID]==SSD_U8_COMMON_CATHODE){
			DIO_u8SetPinValue(SSD_Au8SSDpin[Copy_u8ID],DIO_U8_LOW) ;
			DIO_u8SetPortValue(SSD_Au8SSDport[Copy_u8ID],SSD_Au8LastValues[Copy_u8ID]);
		}
		else {//common anode
			DIO_u8SetPinValue(SSD_Au8SSDpin[Copy_u8ID],DIO_U8_HIGH) ;
			DIO_u8SetPortValue(SSD_Au8SSDport[Copy_u8ID],~SSD_Au8LastValues[Copy_u8ID]);
		}

	}
	return Local_u8ErrorState;
}
u8 SSD_u8DisplayOFF(u8 Copy_u8ID){
	u8 Local_u8ErrorState =0;
	if (Copy_u8ID >= SSD_U8_NB){
		Local_u8ErrorState=1;
	}else{
		if (SSD_Au8SSDtype[Copy_u8ID]==SSD_U8_COMMON_CATHODE){//common cathode
			DIO_u8SetPinValue(SSD_Au8SSDpin[Copy_u8ID],DIO_U8_HIGH) ;

		}
		else {//common anode
			DIO_u8SetPinValue(SSD_Au8SSDpin[Copy_u8ID],DIO_U8_LOW) ;
		}
	}

	return Local_u8ErrorState;

}
u8 SSD_u8WriteNumber(u8 Copy_u8ID,u8 Copy_u8Number){
	u8 Local_u8ErrorState =0;
	if (Copy_u8ID >= SSD_U8_NB){
		Local_u8ErrorState=1;
	}else if (Copy_u8Number >10 ){
		Local_u8ErrorState=1;
	}
	else{
		SSD_Au8LastValues[Copy_u8ID]=SSD_Au8BCDValues[Copy_u8Number];
		if (SSD_Au8SSDtype[Copy_u8ID]==SSD_U8_COMMON_CATHODE){//common cathode
			DIO_u8SetPortValue(SSD_Au8SSDport[Copy_u8ID],SSD_Au8BCDValues[Copy_u8Number]);
		}else{// common anode
			DIO_u8SetPortValue(SSD_Au8SSDport[Copy_u8ID],~SSD_Au8BCDValues[Copy_u8Number]);

		}


	}
	return Local_u8ErrorState;
}
u8 SSD_u8WriteDashChar(u8 Copy_u8ID,u8 Copy_u8DashChar){ // this Function should take character from 'a' to 'h' as "h" is  the dot
	u8 Local_u8ErrorState =0;
	u8 Local_u8CharA ='a';
	if (Copy_u8ID >= SSD_U8_NB){
		Local_u8ErrorState=1;
	}else if (Copy_u8DashChar <'a' || Copy_u8DashChar > 'h' ){
		Local_u8ErrorState=1;
	}
	else{
		SSD_Au8LastValues[Copy_u8ID]=SSD_Au8DashValues[Copy_u8DashChar-Local_u8CharA];
		if (SSD_Au8SSDtype[Copy_u8ID]==SSD_U8_COMMON_CATHODE){//common cathode
			DIO_u8SetPortValue(SSD_Au8SSDport[Copy_u8ID],SSD_Au8DashValues[Copy_u8DashChar-Local_u8CharA]);
		}else{// common anode
			DIO_u8SetPortValue(SSD_Au8SSDport[Copy_u8ID],~SSD_Au8DashValues[Copy_u8DashChar- Local_u8CharA]);

		}


	}
	return Local_u8ErrorState;
}
