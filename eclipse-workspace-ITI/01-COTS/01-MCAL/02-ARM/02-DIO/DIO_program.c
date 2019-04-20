/*
 * DIO_program.c
 *
 *  Created on: Feb 21, 2019
 *      Author: Hanna Nabil
 */

#include "../../../04-LIB/STD_TYPES.h"
#include "../../../04-LIB/BIT_CALC.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
static u8 u8ApplySetPinValue(u8 Copy_u8PinNb,u32 *(Copy_Low_High[]) );
u32 *(arr_low[4])={&(DIO_GPIOA->BRR.ByteAccess),&(DIO_GPIOB->BRR.ByteAccess),&(DIO_GPIOC->BRR.ByteAccess),&(DIO_GPIOD->BRR.ByteAccess)};
u32 *(arr_high[4])={&(DIO_GPIOA->BSRR.ByteAccess),&(DIO_GPIOB->BSRR.ByteAccess),&(DIO_GPIOC->BSRR.ByteAccess),&(DIO_GPIOD->BSRR.ByteAccess)};

u32 *(arr_ODR[4])={&(DIO_GPIOA->ODR.ByteAccess),&(DIO_GPIOB->ODR.ByteAccess),&(DIO_GPIOC->ODR.ByteAccess),&(DIO_GPIOD->ODR.ByteAccess)};
u32 *(arr_CRL[4])={&(DIO_GPIOA->CRL.ByteAccess),&(DIO_GPIOB->CRL.ByteAccess),&(DIO_GPIOC->CRL.ByteAccess),&(DIO_GPIOD->CRL.ByteAccess)};
u32 *(arr_CRH[4])={&(DIO_GPIOA->CRH.ByteAccess),&(DIO_GPIOB->CRH.ByteAccess),&(DIO_GPIOC->CRH.ByteAccess),&(DIO_GPIOD->CRH.ByteAccess)};

u8 DIO_u8SetPinValue(u8 Copy_u8PinNb, u8 Copy_u8Value) {
	/*Local variable*/
	u8 Local_u8ErrorState =0;
	switch (Copy_u8Value){
	case DIO_U8_HIGH:
		Local_u8ErrorState=u8ApplySetPinValue(Copy_u8PinNb,arr_high);
		break;
	case DIO_U8_LOW:
		Local_u8ErrorState=u8ApplySetPinValue(Copy_u8PinNb,arr_low);
		break;
	default:
		Local_u8ErrorState =1;
		break;
	}

	return Local_u8ErrorState;
}
static u8 u8ApplySetPinValue(u8 Copy_u8PinNb,u32 *(Copy_Low_High[]) ){
	u8 Local_u8ErrorState=0;
	u8 Local_u8ActualPortNb =Copy_u8PinNb / 16 ;
	u8 Local_u8ActualPinNb =Copy_u8PinNb % 16 ;
	switch (Local_u8ActualPortNb){
	case DIO_U8_PORTA: *Copy_Low_High[0] =(1<<Local_u8ActualPinNb);break;
	case DIO_U8_PORTB: *Copy_Low_High[1] =(1<<Local_u8ActualPinNb);break;
	case DIO_U8_PORTC: *Copy_Low_High[2] =(1<<Local_u8ActualPinNb);break;
	case DIO_U8_PORTD: *Copy_Low_High[3] =(1<<Local_u8ActualPinNb);break;
	default :Local_u8ErrorState =1;break;
	}
	return Local_u8ErrorState;
}
/*
 * this function setPortValue is well designed for good use
 * so that if you used it while you've set a pin input
 * it'll just ignore your value ( if you have set any input pins)
 */
u8 DIO_u8SetPortValue(u8 Copy_u8PortNb, u16 Copy_u16Value) {
	u8 Local_u8ErrorState =0;
	for (u8 i =0; i<8 ;i++){ // this check not to manipulate input pins
		if (get_nibble(*arr_CRL[Copy_u8PortNb],i) == DIO_INPUT_PULLDOWN ) {
			assign_bit(Copy_u16Value,i,get_bit(*arr_ODR[Copy_u8PortNb],i));
		}
		if (get_nibble(*arr_CRH[Copy_u8PortNb],i)==  DIO_INPUT_PULLDOWN){
			assign_bit(Copy_u16Value,(i+8),get_bit(*arr_ODR[Copy_u8PortNb],(i+8)));
		}
	}
	switch(Copy_u8PortNb){
	case DIO_U8_PORTA :DIO_GPIOA->ODR.ByteAccess = Copy_u16Value;break;
	case DIO_U8_PORTB :DIO_GPIOB->ODR.ByteAccess = Copy_u16Value;break;
	case DIO_U8_PORTC :DIO_GPIOC->ODR.ByteAccess = Copy_u16Value;break;
	case DIO_U8_PORTD :DIO_GPIOD->ODR.ByteAccess = Copy_u16Value;break;
	default : Local_u8ErrorState =1;break;
	}
	return Local_u8ErrorState;
}
u8 DIO_u8SetArrayValue(u8 * Copy_u8APins, u16 Copy_u16Value,u8 Copy_u8ArraySize) {// this Function is  given array of pins
	u8 Local_u8ErrorState =0;
	u8 i =0;
	for ( i =0 ; i <  Copy_u8ArraySize ; i++){
		DIO_u8SetPinValue( Copy_u8APins[i],get_bit(Copy_u16Value,i));
	}
	return Local_u8ErrorState;
}
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNb,u16 Copy_u16Value,u8 Copy_u8ModeInput,u8 Copy_u8ModeOutput){
	u8 Local_u8ErrorState =0;
	u32 Local_u32CRLValue=0;
	u32 Local_u32CRHValue=0;
	u8 Local_Au8Mode[2]={Copy_u8ModeInput,Copy_u8ModeOutput};
	if (Copy_u8ModeInput == DIO_INPUT_PULLUP){
		Local_Au8Mode[0] =DIO_INPUT_PULLDOWN;
		*arr_ODR[Copy_u8PortNb]=*arr_ODR[Copy_u8PortNb] | ~Copy_u16Value;
			}
	else if (Copy_u8ModeInput == DIO_INPUT_PULLDOWN){
		*arr_ODR[Copy_u8PortNb]=*arr_ODR[Copy_u8PortNb] & Copy_u16Value;
	}
	for (u8 i =0, j=8 ; i<8 ;i++,j++){
		assign_nibble(Local_u32CRLValue,i,Local_Au8Mode[get_bit(Copy_u16Value,i)]);
		assign_nibble(Local_u32CRHValue,i,Local_Au8Mode[get_bit(Copy_u16Value,j)]);
	}

	switch(Copy_u8PortNb){
	case DIO_U8_PORTA :DIO_GPIOA->CRL.ByteAccess=Local_u32CRLValue;DIO_GPIOA->CRH.ByteAccess=Local_u32CRHValue;break;
	case DIO_U8_PORTB :DIO_GPIOB->CRL.ByteAccess=Local_u32CRLValue;DIO_GPIOB->CRH.ByteAccess=Local_u32CRHValue;break;
	case DIO_U8_PORTC :DIO_GPIOC->CRL.ByteAccess=Local_u32CRLValue;DIO_GPIOC->CRH.ByteAccess=Local_u32CRHValue;break;
	case DIO_U8_PORTD :DIO_GPIOD->CRL.ByteAccess=Local_u32CRLValue;DIO_GPIOD->CRH.ByteAccess=Local_u32CRHValue;break;
	default : Local_u8ErrorState =1;break;
	}
	return Local_u8ErrorState;
}
u8 DIO_u8SetPinDirection(u8 Copy_u8PinNb, u8 Copy_u8Mode) {
	u8 Local_u8ErrorState=0;
	u8 Local_u8ActualPortNb =Copy_u8PinNb / 16 ;
	u8 Local_u8ActualPinNb =Copy_u8PinNb % 16 ;
	if (Copy_u8Mode == DIO_INPUT_PULLUP){
		Copy_u8Mode =DIO_INPUT_PULLDOWN	;
		//u8ApplySetPinValue(Copy_u8PinNb,arr_high); // put 1
		set_bit(*arr_ODR[Local_u8ActualPortNb],Local_u8ActualPinNb);
		//ODR =0 pull-down Resistor, odr =1 pull-up Resistor
	}
	else if (Copy_u8Mode == DIO_INPUT_PULLDOWN){
		//u8ApplySetPinValue(Copy_u8PinNb,arr_low);//put zero
		clr_bit(*arr_ODR[Local_u8ActualPortNb],Local_u8ActualPinNb);
	}
	if (Local_u8ActualPinNb <=7){

		switch(Local_u8ActualPortNb){
		case DIO_U8_PORTA  : assign_nibble(DIO_GPIOA->CRL.ByteAccess,Local_u8ActualPinNb,Copy_u8Mode);break;
		case DIO_U8_PORTB  : assign_nibble(DIO_GPIOB->CRL.ByteAccess,Local_u8ActualPinNb,Copy_u8Mode);break;
		case DIO_U8_PORTC  : assign_nibble(DIO_GPIOC->CRL.ByteAccess,Local_u8ActualPinNb,Copy_u8Mode);break;
		case DIO_U8_PORTD  : assign_nibble(DIO_GPIOD->CRL.ByteAccess,Local_u8ActualPinNb,Copy_u8Mode);break;
		}
	}
	else {
		Local_u8ActualPinNb = Local_u8ActualPinNb -8;
		switch(Local_u8ActualPortNb){
		case DIO_U8_PORTA  : assign_nibble(DIO_GPIOA->CRH.ByteAccess,Local_u8ActualPinNb,Copy_u8Mode);break;
		case DIO_U8_PORTB  : assign_nibble(DIO_GPIOB->CRH.ByteAccess,Local_u8ActualPinNb,Copy_u8Mode);break;
		case DIO_U8_PORTC  : assign_nibble(DIO_GPIOC->CRH.ByteAccess,Local_u8ActualPinNb,Copy_u8Mode);break;
		case DIO_U8_PORTD  : assign_nibble(DIO_GPIOD->CRH.ByteAccess,Local_u8ActualPinNb,Copy_u8Mode);break;
		}
	}
	return Local_u8ErrorState;
}
u8 DIO_u8GetPinValue(u8 Copy_u8PinNb, u8* Copy_Pu8Value){
	u8 Local_u8ErrorState=0;
	u8 Local_u8ActualPortNb=Copy_u8PinNb / 16 ;
	u8 Local_u8ActualPinNb =Copy_u8PinNb % 16 ;
	u8 Local_u8IDRStatus=0;
	u8 Local_u8Mode=0;
	u8 Local_u8GetPullStatus=0;
	switch(Local_u8ActualPortNb){
			case DIO_U8_PORTA  : Local_u8IDRStatus=get_bit(DIO_GPIOA->IDR.ByteAccess,Local_u8ActualPinNb);break;
			case DIO_U8_PORTB  : Local_u8IDRStatus=get_bit(DIO_GPIOB->IDR.ByteAccess,Local_u8ActualPinNb);break;
			case DIO_U8_PORTC  : Local_u8IDRStatus=get_bit(DIO_GPIOC->IDR.ByteAccess,Local_u8ActualPinNb);break;
			case DIO_U8_PORTD  : Local_u8IDRStatus=get_bit(DIO_GPIOD->IDR.ByteAccess,Local_u8ActualPinNb);break;
			}
	// check input mode
	if (Local_u8ActualPinNb <=7){
			switch(Local_u8ActualPortNb){
			case DIO_U8_PORTA  : Local_u8Mode=get_nibble(DIO_GPIOA->CRL.ByteAccess,Local_u8ActualPinNb);break;
			case DIO_U8_PORTB  : Local_u8Mode=get_nibble(DIO_GPIOB->CRL.ByteAccess,Local_u8ActualPinNb);break;
			case DIO_U8_PORTC  : Local_u8Mode=get_nibble(DIO_GPIOC->CRL.ByteAccess,Local_u8ActualPinNb);break;
			case DIO_U8_PORTD  : Local_u8Mode=get_nibble(DIO_GPIOD->CRL.ByteAccess,Local_u8ActualPinNb);break;
			}
		}
		else {
			u8 temp = Local_u8ActualPinNb -8;
			switch(Local_u8ActualPortNb){
			case DIO_U8_PORTA  : Local_u8Mode=get_nibble(DIO_GPIOA->CRH.ByteAccess,temp);break;
			case DIO_U8_PORTB  : Local_u8Mode=get_nibble(DIO_GPIOB->CRH.ByteAccess,temp);break;
			case DIO_U8_PORTC  : Local_u8Mode=get_nibble(DIO_GPIOC->CRH.ByteAccess,temp);break;
			case DIO_U8_PORTD  : Local_u8Mode=get_nibble(DIO_GPIOD->CRH.ByteAccess,temp);break;
			}
		}
		// to check if it was pull-up and pull-down
			if (Local_u8Mode ==DIO_INPUT_PULLDOWN){
				switch(Local_u8ActualPortNb){
				case DIO_U8_PORTA  : Local_u8GetPullStatus=get_bit(DIO_GPIOA->ODR.ByteAccess,Local_u8ActualPinNb);break;
				case DIO_U8_PORTB  : Local_u8GetPullStatus=get_bit(DIO_GPIOB->ODR.ByteAccess,Local_u8ActualPinNb);break;
				case DIO_U8_PORTC  : Local_u8GetPullStatus=get_bit(DIO_GPIOC->ODR.ByteAccess,Local_u8ActualPinNb);break;
				case DIO_U8_PORTD  : Local_u8GetPullStatus=get_bit(DIO_GPIOD->ODR.ByteAccess,Local_u8ActualPinNb);break;
				}
				if (Local_u8GetPullStatus ==0){//pull-down resistor

					if (Local_u8IDRStatus == 0)
					{
						*Copy_Pu8Value=DIO_U8_BUTTON_RELEASED;
					}
					else
					{
						*Copy_Pu8Value=DIO_U8_BUTTON_PRESSED;
					}
					}
				else {//pull-up resistor

					if (Local_u8IDRStatus == 1){*Copy_Pu8Value=DIO_U8_BUTTON_RELEASED;}
					else {*Copy_Pu8Value=DIO_U8_BUTTON_PRESSED;}}
			}
			else if (Local_u8Mode ==DIO_INPUT_FLOATING){
					*Copy_Pu8Value=Local_u8IDRStatus;
			}

	return Local_u8ErrorState;
}
