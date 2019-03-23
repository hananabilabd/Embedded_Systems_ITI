/*
 * DIO.c
 *
 *  Created on: Jan 30, 2019
 *      Author: Hanna Nabil
 * Description : 
 *-------------------------------------
 * This file has implementation
 */

#include"STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_private.h"
#include"DIO_interface.h"
#include"DIO_config.h"

#define PINS_PER_PORT 8

void DIO_voidInitialize(void){
	DIO_U8_DDRA->ByteAccess = CONC_8BIT(DIO_U8_PIN0_DIR,
										DIO_U8_PIN1_DIR,
										DIO_U8_PIN2_DIR,
										DIO_U8_PIN3_DIR,
										DIO_U8_PIN4_DIR,
										DIO_U8_PIN5_DIR,
										DIO_U8_PIN6_DIR,
										DIO_U8_PIN7_DIR);
	DIO_U8_DDRB->ByteAccess = CONC_8BIT(DIO_U8_PIN8_DIR,
										DIO_U8_PIN9_DIR,
										DIO_U8_PIN10_DIR,
										DIO_U8_PIN11_DIR,
										DIO_U8_PIN12_DIR,
										DIO_U8_PIN13_DIR,
										DIO_U8_PIN14_DIR,
										DIO_U8_PIN15_DIR);
	DIO_U8_DDRC->ByteAccess = CONC_8BIT(DIO_U8_PIN16_DIR,
										DIO_U8_PIN17_DIR,
										DIO_U8_PIN18_DIR,
										DIO_U8_PIN19_DIR,
										DIO_U8_PIN20_DIR,
										DIO_U8_PIN21_DIR,
										DIO_U8_PIN22_DIR,
										DIO_U8_PIN23_DIR);
	DIO_U8_DDRD->ByteAccess = CONC_8BIT(DIO_U8_PIN24_DIR,
										DIO_U8_PIN25_DIR,
										DIO_U8_PIN26_DIR,
										DIO_U8_PIN27_DIR,
										DIO_U8_PIN28_DIR,
										DIO_U8_PIN29_DIR,
										DIO_U8_PIN30_DIR,
										DIO_U8_PIN31_DIR);
								
}

u8 DIO_u8SetPinDirection(u8 u8PinNB, u8 u8Direction) {
	/*Local variable*/
	u8 u8ErrorState =0;
	u8 u8PORT_ID ,u8PIN_ID;

	/*validate Input*/
	if (u8PinNB >=  DIO_MAXPINNB){
		u8ErrorState =1;
	}else if ((u8Direction != DIO_U8_INPUT ) && (u8Direction != DIO_U8_OUTPUT)){
		u8ErrorState =1;
	}
	else{
		u8ErrorState =0 ;
		u8PORT_ID = u8PinNB /PINS_PER_PORT;
		u8PIN_ID = u8PinNB % PINS_PER_PORT;
		switch (u8PORT_ID){
		case 0:
			assign_bit(DIO_U8_DDRA->ByteAccess ,u8PIN_ID,u8Direction);
			break;
		case 1:
			assign_bit(DIO_U8_DDRB->ByteAccess ,u8PIN_ID,u8Direction);
			break;

		case 2:
			assign_bit(DIO_U8_DDRC->ByteAccess ,u8PIN_ID,u8Direction);
			break;
		case 3:
			assign_bit(DIO_U8_DDRD-> ByteAccess,u8PIN_ID,u8Direction);
			break;
		default :
			break;
		}
	}
	/*Function return */
	return u8ErrorState;
}
u8 DIO_u8SetPinValue(u8 u8PinNB, u8 u8Value) {
	/*Local variable*/
	u8 u8ErrorState =0;
	u8 u8PORT_ID ,u8PIN_ID;

	/*validate Input*/
	if (u8PinNB >=  DIO_MAXPINNB){
		u8ErrorState =1;
	}else if ((u8Value != DIO_U8_HIGH ) && (u8Value != DIO_U8_LOW)){
		u8ErrorState =1;
	}
	else{
		u8ErrorState =0 ;
		u8PORT_ID = u8PinNB /PINS_PER_PORT;
		u8PIN_ID = u8PinNB % PINS_PER_PORT;
		switch (u8PORT_ID){
		case 0:
			assign_bit(DIO_U8_PORTA->ByteAccess ,u8PIN_ID,u8Value);
			break;
		case 1:
			assign_bit(DIO_U8_PORTB->ByteAccess ,u8PIN_ID,u8Value);
			break;
		case 2:
			assign_bit(DIO_U8_PORTC->ByteAccess ,u8PIN_ID,u8Value);
			break;
		case 3:
			assign_bit(DIO_U8_PORTD-> ByteAccess,u8PIN_ID,u8Value);
			break;
		default :
			break;

		}
	}
	/*Function return */
	return u8ErrorState;
}
u8 DIO_u8GetPinValue(u8 u8PinNB, u8* Pu8Value){
	/*Local variable*/
		u8 u8ErrorState =0;
		u8 u8PORT_ID ,u8PIN_ID;

		/*validate Input*/
		if (u8PinNB >=  DIO_MAXPINNB){
			u8ErrorState =1;
		}
		else{
			u8ErrorState =0 ;
			u8PORT_ID = u8PinNB /PINS_PER_PORT;
			u8PIN_ID = u8PinNB % PINS_PER_PORT;
			switch (u8PORT_ID){
			case 0:
				*Pu8Value=get_bit(DIO_U8_PINA->ByteAccess ,u8PIN_ID);
				break;
			case 1:
				*Pu8Value=get_bit(DIO_U8_PINB->ByteAccess ,u8PIN_ID);
				break;
			case 2:
				*Pu8Value=get_bit(DIO_U8_PINC->ByteAccess ,u8PIN_ID);
				break;
			case 3:
				*Pu8Value=get_bit(DIO_U8_PIND->ByteAccess,u8PIN_ID);
				break;
			default :
				break;

			}
		}
		/*Function return */
		return u8ErrorState;
	}
u8 DIO_u8SetPortDirection(u8 u8PortNB, u8 u8Direction){
	/*Local variable*/
		u8 u8ErrorState =0;


		/*validate Input*/
		if (u8PortNB >=  DIO_MAXPORTNB){
			u8ErrorState =1;
		}
		else{
			u8ErrorState =0 ;

			switch (u8PortNB){
			case 0:
				DIO_U8_DDRA->ByteAccess =u8Direction;
				break;
			case 1:
				DIO_U8_DDRB->ByteAccess=u8Direction;
				break;

			case 2:
				DIO_U8_DDRC->ByteAccess=u8Direction;
				break;
			case 3:
				DIO_U8_DDRD-> ByteAccess=u8Direction;
				break;
			default :
				break;
			}
		}
		/*Function return */
		return u8ErrorState;
	}
u8 DIO_u8SetPortValue(u8 u8PortNB, u8 u8Value){
	/*Local variable*/
		u8 u8ErrorState =0;


		/*validate Input*/
		if (u8PortNB >=  DIO_MAXPORTNB){
			u8ErrorState =1;
		}
		else{
			u8ErrorState =0 ;

			switch (u8PortNB){
			case 0:
				DIO_U8_PORTA->ByteAccess =u8Value;
				break;
			case 1:
				DIO_U8_PORTB->ByteAccess=u8Value;
				break;
			case 2:
				DIO_U8_PORTC->ByteAccess =u8Value;
				break;
			case 3:
				DIO_U8_PORTD-> ByteAccess=u8Value;
				break;
			default :
				break;

			}
		}
		/*Function return */
		return u8ErrorState;
	}
u8 DIO_u8GetPortValue(u8 u8PortNB, u8* Pu8Value){
	/*Local variable*/
			u8 u8ErrorState =0;


			/*validate Input*/
			if (u8PortNB >=  DIO_MAXPORTNB){
				u8ErrorState =1;
			}
			else{
				u8ErrorState =0 ;

				switch (u8PortNB){
				case 0:
					*Pu8Value =DIO_U8_PINA->ByteAccess;
					break;
				case 1:
					*Pu8Value=DIO_U8_PINB->ByteAccess;
					break;
				case 2:
					*Pu8Value=DIO_U8_PINC->ByteAccess;
					break;
				case 3:
					*Pu8Value=DIO_U8_PIND->ByteAccess;
					break;
				default :
					break;

				}
			}
			/*Function return */
			return u8ErrorState;
		}
u8 DIO_u8SetPortPullUp(u8 u8PortNB,u8 u8Value){
	/*Local variable*/
		u8 u8ErrorState =0;


		/*validate Input*/
		if (u8PortNB >=  DIO_MAXPORTNB){
			u8ErrorState =1;
		}
		else{
			u8ErrorState =0 ;

			switch (u8PortNB){
			case 0:
				DIO_U8_DDRA->ByteAccess =u8Value;
				DIO_U8_PORTA->ByteAccess =u8Value;
				break;
			case 1:
				DIO_U8_DDRB->ByteAccess =u8Value;
				DIO_U8_PORTB->ByteAccess=u8Value;
				break;
			case 2:
				DIO_U8_DDRC->ByteAccess =u8Value;
				DIO_U8_PORTC->ByteAccess =u8Value;
				break;
			case 3:
				DIO_U8_DDRD->ByteAccess =u8Value;
				DIO_U8_PORTD-> ByteAccess=u8Value;
				break;
			default :
				break;

			}
		}
		/*Function return */
		return u8ErrorState;
	}
u8 DIO_u8SetPinPullUp(u8 u8PinNB){
	/*Local variable*/
	u8 u8ErrorState =0;
	u8 u8PORT_ID ,u8PIN_ID;

	/*validate Input*/
	if (u8PinNB >=  DIO_MAXPINNB){
		u8ErrorState =1;
	}
	else{
		u8ErrorState =0 ;
		u8PORT_ID = u8PinNB /PINS_PER_PORT;
		u8PIN_ID = u8PinNB % PINS_PER_PORT;
		switch (u8PORT_ID){
		case 0:
			clr_bit(DIO_U8_PINA->ByteAccess,u8PIN_ID);
			set_bit(DIO_U8_PORTA->ByteAccess,u8PIN_ID);
			break;
		case 1:
			clr_bit(DIO_U8_PINB->ByteAccess,u8PIN_ID);
			set_bit(DIO_U8_PORTB->ByteAccess,u8PIN_ID);
			break;
		case 2:
			clr_bit(DIO_U8_PINC->ByteAccess,u8PIN_ID);
			set_bit(DIO_U8_PORTC->ByteAccess,u8PIN_ID);
			break;
		case 3:
			clr_bit(DIO_U8_PIND->ByteAccess,u8PIN_ID);
			set_bit(DIO_U8_PORTD->ByteAccess,u8PIN_ID);
			break;
		default :
			break;

		}
	}
	/*Function return */
	return u8ErrorState;
}
