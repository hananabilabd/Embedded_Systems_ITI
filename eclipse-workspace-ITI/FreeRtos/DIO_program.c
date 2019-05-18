
/*********************************************************************/
/* Author  : Khlood Amin                                             */
/* Version : V01                                                     */
/* Date    : 4 FEB 2018                                              */
/*********************************************************************/
/* Description                                                       */
/* -------------                                                     */
/*                                                                   */
/* This file has the implementaion of both private and public        */
/* function corresponding to DIO Module                              */
/*********************************************************************/

#include "H:\Device Drivers\01-COTS\04-LIB\01-STD_TYPES\STD_type.h"
#include "H:\Device Drivers\01-COTS\04-LIB\02-BIT-CALC\bit_calc.h"
#include "DIO_Interface.h"
#include "DIO_config.h"
#include "DIO_private.h"
//_____________________________________________________________________

#define CONC_8BIT(b0,b1,b2,b3,b4,b5,b6,b7)        CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7)
#define CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7)      0b##b7##b6##b5##b4##b3##b2##b1##b0
#define DIO_MAXPINNB 31
#define DIO_MAXPORTNB 4
//_____________________________________________________________________________________________________________________
void DIO_voidIntialize(void) {
	DIO_u8_DDRA->ByteAccess = CONC_8BIT(DIO_u8_PIN_0_DIR, DIO_u8_PIN_1_DIR,
			DIO_u8_PIN_2_DIR, DIO_u8_PIN_3_DIR, DIO_u8_PIN_4_DIR,
			DIO_u8_PIN_5_DIR, DIO_u8_PIN_6_DIR, DIO_u8_PIN_7_DIR);
}

//______________________________________________________________________________________________________________________

u8 DIO_u8SetPinValue(u8 Copy_u8PinNumber, u8 Copy_u8PinValue) {
	/*local variables*/
	u8 u8ErrorState = 0;
	u8 u8PORT_ID;
	u8 u8PIN_ID;
	/*Validate Input*/
	if (Copy_u8PinNumber > DIO_MAXPINNB) {
		u8ErrorState = 1;
	} else if ((Copy_u8PinValue != DIO_u8_HIGH)
			&& (Copy_u8PinValue != DIO_u8_LOW)) {
		u8ErrorState = 1;
	} else {
		u8ErrorState = 0;
		u8PORT_ID = Copy_u8PinNumber / PINS_PER_PORT;
		u8PIN_ID = Copy_u8PinNumber % PINS_PER_PORT;
		switch (u8PORT_ID) {
		case 0:
			assignBit((DIO_u8_PORTA->ByteAccess), (u8PIN_ID),
					(Copy_u8PinValue));
			break;
		case 1:
			if (Copy_u8PinValue == DIO_u8_LOW) {
				clearBit((DIO_u8_PORTB->ByteAccess), u8PIN_ID);
			} else {
				setBit((DIO_u8_PORTB->ByteAccess), u8PIN_ID);
			}
			break;
		case 2:
			assignBit((DIO_u8_PORTC->ByteAccess), (u8PIN_ID),
					(Copy_u8PinValue));
			break;
		case 3:
			assignBit((DIO_u8_PORTD->ByteAccess), (u8PIN_ID),
					(Copy_u8PinValue));
			break;
		default:
			break;
		}

	}
	return u8ErrorState;

}

//___________________________________________________________________________________________________________________
u8 DIO_u8SetPinDirection(u8 Copy_u8PinNumber, u8 Copy_u8PinDirecection) {
	u8 u8ErrorState = 0;
	u8 u8PORT_ID;
	u8 u8PIN_ID;
	/*Validate Input*/
	if (Copy_u8PinNumber >= DIO_MAXPINNB) {
		u8ErrorState = 1;
	} else if ((Copy_u8PinDirecection != DIO_u8_INPUT)
			&& (Copy_u8PinDirecection != DIO_u8_OUTPUT)) {
		u8ErrorState = 1;
	} else {
		u8ErrorState = 0;
		u8PORT_ID = Copy_u8PinNumber / PINS_PER_PORT;
		u8PIN_ID = Copy_u8PinNumber % PINS_PER_PORT;
		switch (u8PORT_ID) {
		case 0:
			assignBit((DIO_u8_DDRA->ByteAccess), (u8PIN_ID),
					(Copy_u8PinDirecection));
			break;
		case 1:
			if (Copy_u8PinDirecection == DIO_u8_INPUT) {
				clearBit((DIO_u8_DDRB->ByteAccess), u8PIN_ID);
			} else {
				setBit((DIO_u8_DDRB->ByteAccess), u8PIN_ID);
			}
			break;
		case 2:
			assignBit((DIO_u8_DDRC->ByteAccess), (u8PIN_ID),
					(Copy_u8PinDirecection));
			break;
		case 3:
			assignBit((DIO_u8_DDRD->ByteAccess), (u8PIN_ID),
					(Copy_u8PinDirecection));
			break;
		default:
			break;
		}

	}
	return u8ErrorState;
}

//_______________________________________________________________________________________________________________________
u8 DIO_u8GetPinValue(u8 Copy_u8PinNumber, u8 *Copy_Pu8PinValue) {
	u8 u8ErrorState = 0;
	u8 u8PORT_ID;
	u8 u8PIN_ID;
	/*Validate Input*/
	if (Copy_u8PinNumber >= DIO_MAXPINNB) {
		u8ErrorState = 1;
	} else {
		u8ErrorState = 0;
		u8PORT_ID = Copy_u8PinNumber / PINS_PER_PORT;
		u8PIN_ID = Copy_u8PinNumber % PINS_PER_PORT;
		switch (u8PORT_ID) {
		case 0:
			*Copy_Pu8PinValue = ((DIO_u8_PINA->ByteAccess) & (1 << u8PIN_ID))
					>> (u8PIN_ID);
			break;
		case 1:
			*Copy_Pu8PinValue = ((DIO_u8_PINB->ByteAccess) & (1 << u8PIN_ID))
					>> (u8PIN_ID);
			break;
		case 2:
			*Copy_Pu8PinValue = ((DIO_u8_PINC->ByteAccess) & (1 << u8PIN_ID))
					>> (u8PIN_ID);
			break;
		case 3:
			*Copy_Pu8PinValue = ((DIO_u8_PIND->ByteAccess) & (1 << u8PIN_ID))
					>> (u8PIN_ID);
			break;
		default:
			break;
		}
	}
	return 0;
}
//_______________________________________________________________________________________________________________________
u8 DIO_u8SetPortValue(u8 Copy_u8PortNumber, u8 Copy_u8PortValue) {
	/*local variables*/
	u8 u8ErrorState = 0;
	u8 u8PORT_ID;
	u8 u8PIN_ID;
	/*Validate Input*/
	if (Copy_u8PortNumber >= DIO_MAXPINNB) {
		u8ErrorState = 1;
	} else if ((Copy_u8PortValue != DIO_u8_HIGH)
			&& (Copy_u8PortValue != DIO_u8_LOW)) {
		u8ErrorState = 1;
	} else {
		switch (Copy_u8PortNumber) {
		case 1:
			assignPort((DIO_u8_PORTA->ByteAccess), (Copy_u8PortValue));

			break;
		case 2:
			assignPort((DIO_u8_PORTB->ByteAccess), (Copy_u8PortValue));

			break;
		case 3:
			assignPort((DIO_u8_PORTC->ByteAccess), (Copy_u8PortValue));
			break;
		case 4:
			assignPort((DIO_u8_PORTD->ByteAccess), (Copy_u8PortValue));
			break;
		default:
			break;
		}

	}
	return u8ErrorState;
}
//_______________________________________________________________________________________________________________________
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNumber, u8 Copy_u8PortDirection) {
	u8 u8ErrorState = 0;
	u8 u8PORT_ID;
	/*validate inputs*/
	if (Copy_u8PortNumber > DIO_MAXPORTNB) {
		u8ErrorState = 1;
	} else if ((Copy_u8PortDirection != DIO_u8_INPUT)
			&& (Copy_u8PortDirection != DIO_u8_OUTPUT)) {
		u8ErrorState = 1;
	} else {
		u8ErrorState = 0;
		switch (Copy_u8PortNumber) {
		case 1:
			if (Copy_u8PortDirection == DIO_u8_INPUT) {
				clearPort((DIO_u8_DDRA->ByteAccess));
			} else {
				setPort((DIO_u8_DDRA->ByteAccess));
			}
			break;
		case 2:
			if (Copy_u8PortDirection == DIO_u8_INPUT) {
				clearPort((DIO_u8_DDRB->ByteAccess));
			} else {
				setPort((DIO_u8_DDRB->ByteAccess));
			}
			break;
		case 3:
			if (Copy_u8PortDirection == DIO_u8_INPUT) {
				clearPort((DIO_u8_DDRC->ByteAccess));
			} else {
				setPort((DIO_u8_DDRC->ByteAccess));
			}
			break;
		case 4:
			if (Copy_u8PortDirection == DIO_u8_INPUT) {
				clearPort((DIO_u8_DDRD->ByteAccess));
			} else {
				setPort((DIO_u8_DDRD->ByteAccess));
			}
			break;
		default:
			break;
		}
	}

	return u8ErrorState;
}
u8 DIO_u8GetPortValue(u8 Copy_u8PortNumber, u8 Copy_Pu8PortValue) {
	return 0;
}

u8 DIO_u8AssignPortValue(u8 Copy_u8PortNumber, u8 Copy_Pu8PortValue) {
	u8 u8ErrorState = 0;
	u8 u8PORT_ID;
	/*validate inputs*/
	if (Copy_u8PortNumber > DIO_MAXPORTNB) {
		u8ErrorState = 1;
	} else {
		u8ErrorState = 0;
		switch (Copy_u8PortNumber) {
		case 1:
			assignPort(DIO_u8_PORTA->ByteAccess, Copy_Pu8PortValue);
			break;
		case 2:
			assignPort(DIO_u8_PORTB->ByteAccess, Copy_Pu8PortValue);
			break;
		case 3:
			assignPort(DIO_u8_PORTC->ByteAccess, Copy_Pu8PortValue);
			break;
		case 4:
			assignPort(DIO_u8_PORTD->ByteAccess, Copy_Pu8PortValue);
			break;
		default:
			break;
		}
	}

	return u8ErrorState;
}




										




										
