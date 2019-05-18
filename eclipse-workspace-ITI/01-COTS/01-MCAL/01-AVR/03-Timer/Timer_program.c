/*
 * Timer_interface.c
 *
 *  Created on: Apr 2, 2019
 *      Author: Hanna Nabil
 */
#include "STD_TYPES.h"
#include"BIT_CALC.h"
#include"Timer_interface.h"
#include"Timer_config.h"
#include"Timer_private.h"
#include "DIO_private.h"
#include "DIO_interface.h"
//#include <avr/io.h>
/******Instruction
 * 0- Timer_Initialize
 * 1- set pre-scaler
 * 2- set Mode
 * 3- Enable
 ******/
static void ICU_voidSelectEdge(u8 Copy_u8ICU_EdgeSelect);
static void (*PvoidCallback[8])(void)={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
static u8 Timer_Au8Prescaler[3]={TIMER_PRESCALER_UNINTIALIZED,TIMER_PRESCALER_UNINTIALIZED,TIMER_PRESCALER_UNINTIALIZED};
static u16 Timer_Au8ActualPrescaler[6]={0,1,8,64,256,1024};
static u8 Timer_Au8Timer1_TCCR1A_value[16]={0x00,0x01,0x10,0x11,0x00,0x01,0x10,0x11,0x00,0x01,0x10,0x11,0x00,0x01,0x10,0x11};
static u8 Timer_Au8Timer1_TCCR1B_value[16]={0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x10,0x10,0x10,0x10,0x18,0x18,0x18,0x18};
static u16 Timer_u16OffTime=0,Timer_u16OnTime=0;
static u8 Timer_u8Timer1Prescaler=0;
static u8 Timer_ICU_u8RisingEdge=0,Timer_ICU_u8FallingEdge=0;

 ///**** To use ICU you should call Timer_Initialize , then Timer_voidSetPrescaler ****
 // this is the hardware ICU
void ICU_voidInitialize(void){//D6
	DIO_u8SetPinDirection(DIO_U8_PIN_D6,DIO_U8_INPUT);
	SREG |= 0x80; // Enable Global Interrupt
	Timer_ICU_u8RisingEdge= 0x40|Timer_Au8Prescaler[1];
	Timer_ICU_u8FallingEdge= Timer_Au8Prescaler[1];
	ICU_voidSelectEdge(TIMER_ICU_RISING_EDGE);

}
void ICU_voidEnable(void){
	TIMSK |= TIMER_INTERRUPT_ENABLE_MASK_TIMER1_CAPTURE;
}
void ICU_voidDisable(void){
	TIMSK &=TIMER_INTERRUPT_DISABLE_MASK_TIMER1_CAPTURE;
}
static void ICU_voidSelectEdge(u8 Copy_u8ICU_EdgeSelect){
	//TCCR1B = (TCCR1B & 0xBF) | (Copy_u8ICU_EdgeSelect <6) ;
	TCCR1B=Copy_u8ICU_EdgeSelect;
	/*
	switch(Copy_u8ICU_EdgeSelect){
		case TIMER_ICU_RISING_EDGE : TCCR1B |= 0x40;break;
		case TIMER_ICU_FALLING_EDGE: TCCR1B &= 0xBF;break;
	}*/

}
void ICU_voidGetPeriod(u16 *Copy_u8ICU_period){
	*Copy_u8ICU_period=(Timer_u16OnTime +Timer_u16OffTime)*((f32)Timer_u8Timer1Prescaler/TIMER_CLOCK_FREQUENCY);
}
void ICU_voidGetDuty(u16 *Copy_u8ICU_duty){
	*Copy_u8ICU_duty= ((f32)Timer_u16OnTime/(Timer_u16OnTime +Timer_u16OffTime) ) *100;
}
void ICU_voidGetFrequency(u16 *Copy_u8ICU_Frequency){

	*Copy_u8ICU_Frequency=((f32)TIMER_CLOCK_FREQUENCY*1000000/(Timer_u8Timer1Prescaler * (Timer_u16OnTime +Timer_u16OffTime) ) );
}
void ICU_voidGetOnTime(u16 *Copy_u8ICU_OnTime){
	*Copy_u8ICU_OnTime= (Timer_u16OnTime )* ((f32)Timer_u8Timer1Prescaler/TIMER_CLOCK_FREQUENCY);
	//*Copy_u8ICU_OnTime= Timer_u16OnTime ;
}
void ICU_voidGetOffTime(u16 *Copy_u8ICU_OffTime){
	*Copy_u8ICU_OffTime= (Timer_u16OffTime )* ((f32)Timer_u8Timer1Prescaler/TIMER_CLOCK_FREQUENCY);
	//*Copy_u8ICU_OffTime= Timer_u16OffTime ;
}
/*********************************************************************************************************************/
void Timer_voidIntialize(void){
	SREG |= 0x80; // Enable Global Interrupt
}
void Timer_voidSetMode(u8 Copy_u8TimerIndex,u8 Copy_u8Mode){
	switch (Copy_u8TimerIndex){
			case TIMER_INDEX_TIMER0:TCCR0 &=0xB7; TCCR0 |=Copy_u8Mode ;break;
			case TIMER_INDEX_TIMER1: TCCR1A &=0xFC ;TCCR1A|=Timer_Au8Timer1_TCCR1A_value[Copy_u8Mode] ;TCCR1B &=0xC7;TCCR1B|=Timer_Au8Timer1_TCCR1B_value[Copy_u8Mode]  ;break;
			case TIMER_INDEX_TIMER2: TCCR2 &=0xB7;TCCR2|=Copy_u8Mode;break;
			}
}
void Timer_voidSetOCPinMode(u8 Copy_u8TimerIndex, u8 Copy_u8OC_PinMode){
	switch (Copy_u8TimerIndex){
			case TIMER_INDEX_TIMER0: TCCR0 &=0xCF; TCCR0 |= Copy_u8OC_PinMode ;break;
			case TIMER_INDEX_TIMER1:
				if (Copy_u8OC_PinMode > 0x31)
				{
					if (Copy_u8OC_PinMode == 0x32 ){Copy_u8OC_PinMode = 0x00;}
					TCCR1A &= 0x3F;
					TCCR1A|=Copy_u8OC_PinMode;
				}
				else {
					TCCR1A &= 0xCF;
					TCCR1A|=Copy_u8OC_PinMode;
				}
				break;
			case TIMER_INDEX_TIMER2: TCCR2 &=0xCF;TCCR2|=Copy_u8OC_PinMode;break;
			}
}
u8  Timer_voidEnableTimer(u8 Copy_u8TimerIndex){
	u8 Local_u8ErrorState=0;
	if ((Copy_u8TimerIndex == TIMER_INDEX_TIMER0 && Timer_Au8Prescaler[0] == TIMER_PRESCALER_UNINTIALIZED) \
			|| (Copy_u8TimerIndex == TIMER_INDEX_TIMER1 && Timer_Au8Prescaler[1] == TIMER_PRESCALER_UNINTIALIZED)\
			|| (Copy_u8TimerIndex == TIMER_INDEX_TIMER2 && Timer_Au8Prescaler[2] == TIMER_PRESCALER_UNINTIALIZED) )
			{
		Local_u8ErrorState =1;
			}
	else {
	switch (Copy_u8TimerIndex){
	case TIMER_INDEX_TIMER0: assign_3bits(TCCR0,0,Timer_Au8Prescaler[0]);break;
	case TIMER_INDEX_TIMER1: assign_3bits(TCCR1B,0,Timer_Au8Prescaler[1]);break;
	case TIMER_INDEX_TIMER2: assign_3bits(TCCR2,0,Timer_Au8Prescaler[2]);break;
	}
	}
	return Local_u8ErrorState;
}
void Timer_voidDisableTimer(u8 Copy_u8TimerIndex){
	switch (Copy_u8TimerIndex){
		case TIMER_INDEX_TIMER0: assign_3bits(TCCR0,0,TIMER_DISABLED);break;
		case TIMER_INDEX_TIMER1: assign_3bits(TCCR1B,0,TIMER_DISABLED);break;
		case TIMER_INDEX_TIMER2: assign_3bits(TCCR2,0,TIMER_DISABLED);break;
		}
}
void  Timer_voidGetPrescaler(u8 Copy_u8TimerIndex,u16 *Copy_u8TimerPrescaler){

	switch (Copy_u8TimerIndex){
		case TIMER_INDEX_TIMER0: *Copy_u8TimerPrescaler=Timer_Au8ActualPrescaler[ Timer_Au8Prescaler[0]];break;
		case TIMER_INDEX_TIMER1: *Copy_u8TimerPrescaler=Timer_Au8ActualPrescaler[ Timer_Au8Prescaler[1]];break;
		case TIMER_INDEX_TIMER2: *Copy_u8TimerPrescaler=Timer_Au8ActualPrescaler[ Timer_Au8Prescaler[2]];break;
		}
}
void Timer_voidSetPrescaler(u8 Copy_u8TimerIndex,u8 Copy_u8Prescaler){
	//u8 Local_u8ErrorState=0;
	switch (Copy_u8TimerIndex){
	case TIMER_INDEX_TIMER0: assign_3bits(Timer_Au8Prescaler[0],0,Copy_u8Prescaler);break;
	case TIMER_INDEX_TIMER1: assign_3bits(Timer_Au8Prescaler[1],0,Copy_u8Prescaler);Timer_u8Timer1Prescaler=Timer_Au8ActualPrescaler[ Copy_u8Prescaler];break;
	case TIMER_INDEX_TIMER2: assign_3bits(Timer_Au8Prescaler[2],0,Copy_u8Prescaler);break;
	}

}
void Timer_voidSetCallback(u8 Copy_u8TimerCallbackMode,void (*Copy_ptr)(void)){
	switch(Copy_u8TimerCallbackMode){
			case TIMER_CALLBACK_TIMER2_COMPARE :TIMSK |= TIMER_INTERRUPT_ENABLE_MASK_TIMER2_COMPARE;PvoidCallback[0] = Copy_ptr;break;
			case TIMER_CALLBACK_TIMER2_OVERFLOW:TIMSK |= TIMER_INTERRUPT_ENABLE_MASK_TIMER2_OVERFLOW;PvoidCallback[1] = Copy_ptr; break;
			/*case TIMER_CALLBACK_TIMER1_CAPTURE :TIMSK |= TIMER_INTERRUPT_ENABLE_MASK_TIMER1_CAPTURE;PvoidCallback[2] = Copy_ptr;break;*/
			case TIMER_CALLBACK_TIMER1_COMPARE_A:TIMSK|= TIMER_INTERRUPT_ENABLE_MASK_TIMER1_COMPARE_A;PvoidCallback[3] = Copy_ptr;break;
			case TIMER_CALLBACK_TIMER1_COMPARE_B:TIMSK|= TIMER_INTERRUPT_ENABLE_MASK_TIMER1_COMPARE_B;PvoidCallback[4] = Copy_ptr;break;
			case TIMER_CALLBACK_TIMER1_OVERFLOW: TIMSK|= TIMER_INTERRUPT_ENABLE_MASK_TIMER1_OVERFLOW;PvoidCallback[5] = Copy_ptr;break;
			case TIMER_CALLBACK_TIMER0_COMPARE :TIMSK |= TIMER_INTERRUPT_ENABLE_MASK_TIMER0_COMPARE ;PvoidCallback[6] = Copy_ptr;break;
			case TIMER_CALLBACK_TIMER0_OVERFLOW:TIMSK |= TIMER_INTERRUPT_ENABLE_MASK_TIMER0_OVERFLOW;PvoidCallback[7] = Copy_ptr;break;
				}
}
void Timer_voidWritePWM(u8 Copy_u8OCPinIndex,u8 Copy_u8PWMValue){
	switch (Copy_u8OCPinIndex){
		case TIMER_OC_PIN_INDEX_OCR0 :  OCR0=Copy_u8PWMValue;break;
		case TIMER_OC_PIN_INDEX_OCR1A : OCR1A = Copy_u8PWMValue;break;
		case TIMER_OC_PIN_INDEX_OCR1B : OCR1B = Copy_u8PWMValue;break;
		case TIMER_OC_PIN_INDEX_OCR2 :  OCR2 = Copy_u8PWMValue;break;
		}
}
void Timer_voidInitializeOCPin(u8 Copy_u8OCPinIndex){
	switch (Copy_u8OCPinIndex){
		case TIMER_OC_PIN_INDEX_OCR0 :  DIO_u8SetPinDirection(DIO_U8_PIN_B3,DIO_U8_OUTPUT);break;
		case TIMER_OC_PIN_INDEX_OCR1A : DIO_u8SetPinDirection(DIO_U8_PIN_D5,DIO_U8_OUTPUT);break;
		case TIMER_OC_PIN_INDEX_OCR1B : DIO_u8SetPinDirection(DIO_U8_PIN_D4,DIO_U8_OUTPUT);break;
		case TIMER_OC_PIN_INDEX_OCR2 :  DIO_u8SetPinDirection(DIO_U8_PIN_D7,DIO_U8_OUTPUT);break;
		}
}
void __vector_4 (void)//compare timer2
{
	if (PvoidCallback[0] !=NULL){
				PvoidCallback[0]();
			}
}
void __vector_5 (void)//overflow timer2
{
	if (PvoidCallback[1] !=NULL){
				PvoidCallback[1]();
			}
}
void __vector_6 (void)//capture timer1
{
	static u8 flag=0;
	if (flag ==0){ // will be entered when Rising edge happen
		Timer_u16OffTime=ICR1;
		TCNT1=0;
		ICU_voidSelectEdge(Timer_ICU_u8FallingEdge);
		flag =1;
	}else {// will be entered when falling edge happen
		Timer_u16OnTime=ICR1;
		TCNT1=0;
		ICU_voidSelectEdge(Timer_ICU_u8RisingEdge);
		flag =0;
	}
	/*
	if (PvoidCallback[2] !=NULL){
				PvoidCallback[2]();
			}*/
}
void __vector_7 (void)//compare A timer1
{


	if (PvoidCallback[3] !=NULL){
				PvoidCallback[2]();
			}
}
void __vector_8 (void)//compare B timer1
{
	if (PvoidCallback[4] !=NULL){
				PvoidCallback[2]();
			}
}
void __vector_9 (void)//overflow timer1
{
	if (PvoidCallback[5] !=NULL){
				PvoidCallback[2]();
			}
}
void __vector_10 (void)//compare timer0
{
	if (PvoidCallback[6] !=NULL){
				PvoidCallback[2]();
			}
}
void __vector_11 (void)//overflow timer0
{
	if (PvoidCallback[7] !=NULL){
				PvoidCallback[2]();
			}
}
