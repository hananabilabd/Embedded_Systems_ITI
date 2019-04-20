/*
 * Interrupt_prog.c
 *
 *  Created on: Mar 14, 2019
 *      Author: Hanna Nabil
 */


#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include <ExtInterrupt_interface.h>
#include "ExtInterrupt_private.h"


//void __vector_1 (void) __attribute__((signal,__INTR_ATTRS));
//void __vector_2 (void) __attribute__((signal,__INTR_ATTRS));

/*
 *  INT0 ==> D2
 *  INT1 ==> D3
 *  INT2 ==> B2
 */
static void (*PvoidCallback[3])(void)={NULL,NULL,NULL};

void ExtInterrupt_Initialize(u8 Copy_u8Index){
	switch(Copy_u8Index){
		case EXTINTERRUPT_INT0:
			DIO_u8SetPinDirection(DIO_U8_PIN_D2,DIO_U8_INPUT);//setting D2 as input internal pull up
				DIO_u8SetPinValue(DIO_U8_PIN_D2,DIO_U8_HIGH);// D2 should be connected to switch on one terminal and ground on the another terminal
				break;
		case EXTINTERRUPT_INT1:
			DIO_u8SetPinDirection(DIO_U8_PIN_D3,DIO_U8_INPUT);
				DIO_u8SetPinValue(DIO_U8_PIN_D3,DIO_U8_HIGH);
			break;
		case EXTINTERRUPT_INT2:
			DIO_u8SetPinDirection(DIO_U8_PIN_B2,DIO_U8_INPUT);
				DIO_u8SetPinValue(DIO_U8_PIN_B2,DIO_U8_HIGH);
			break;
		}
	set_bit(SREG,7); // Enable Global Interrupt
}
void ExtInterrupt_Enable(u8 Copy_u8Index)
{
	set_bit(SREG,7); // Enable Global Interrupt

	 // Mode of the peripheral interrupt to be falling edge  page 64 in datasheet
	switch(Copy_u8Index){
	case 0:set_bit(GICR,6);break;
	case 1:set_bit(GICR,7); break;
	case 2:set_bit(GICR,5);break;
	}
}
void ExtInterrupt_Disable(u8 Copy_u8Index)
{
	switch(Copy_u8Index){
		case EXTINTERRUPT_INT0:clr_bit(GICR,6);break;
		case EXTINTERRUPT_INT1:clr_bit(GICR,7); break;
		case EXTINTERRUPT_INT2:clr_bit(GICR,5);break;
		}
}
u8 ExtInterrupt_setLevel(u8 Copy_u8Index,u8 Copy_u8Level){
	u8 Local_u8ErrorState=0;
	if (Copy_u8Index == 2 && (Copy_u8Level == EXTINTERRUPT_LEVEL_ANY_LOGICAL_CHANGE ||Copy_u8Level == EXTINTERRUPT_LEVEL_LOW_LEVEL)){
		Local_u8ErrorState=1;
		return Local_u8ErrorState;
	}
	else {
	switch(Copy_u8Index){
			case EXTINTERRUPT_INT0:assign_2bits(MCUCR,0,Copy_u8Level);break;
			case EXTINTERRUPT_INT1:assign_2bits(MCUCR,2,Copy_u8Level); break;
			case EXTINTERRUPT_INT2:assign_2bits(MCUCSR,6,Copy_u8Level & 0b01);break;
			}
	}
	return Local_u8ErrorState;
}
void ExtInterrupt_voidSetCallback(u8 Copy_u8Index,void (*Copy_ptr)(void)){
	switch(Copy_u8Index){
				case EXTINTERRUPT_INT0:PvoidCallback[0] = Copy_ptr;break;
				case EXTINTERRUPT_INT1:PvoidCallback[1] = Copy_ptr; break;
				case EXTINTERRUPT_INT2:PvoidCallback[2] = Copy_ptr;break;

				}
}


void __vector_1 (void) // page 42 in datasheet
{
	if (PvoidCallback[0] !=NULL){
		PvoidCallback[0]();//or (*PvoidCallback)();
	}
}
void __vector_2 (void)
{
	if (PvoidCallback[1] !=NULL){
			PvoidCallback[1]();//or (*PvoidCallback)();
		}
}
void __vector_3 (void)
{
	if (PvoidCallback[2] !=NULL){
			PvoidCallback[2]();//or (*PvoidCallback)();
		}
}


