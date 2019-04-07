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
void __vector_4 (void) __attribute__((signal));
void __vector_5 (void) __attribute__((signal));
void __vector_6 (void) __attribute__((signal));
void __vector_7 (void) __attribute__((signal));
void __vector_8 (void) __attribute__((signal));
void __vector_9 (void) __attribute__((signal));
void __vector_10 (void) __attribute__((signal));
void __vector_11 (void) __attribute__((signal));

/******Instruction
 * 0- Timer_Initialize
 * 1- set pre-scaler
 * 2- set Mode
 * 3- Enable
 ******/
static void (*PvoidCallback[8])(void)={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
static u8 Timer_Au8Prescaler[3]={TIMER_PRESCALER_UNINTIALIZED,TIMER_PRESCALER_UNINTIALIZED,TIMER_PRESCALER_UNINTIALIZED};

static u8 Timer_Au8Timer1_TCCR1A_value[16]={0x00,0x01,0x10,0x11,0x00,0x01,0x10,0x11,0x00,0x01,0x10,0x11,0x00,0x01,0x10,0x11};
static u8 Timer_Au8Timer1_TCCR1B_value[16]={0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x10,0x10,0x10,0x10,0x18,0x18,0x18,0x18};
static u16 Timer_u16OffTime=0,Timer_u16OnTime=0;
void ICU_voidInitialize(void){//D6
	SREG |= 0x80; // Enable Global Interrupt
	Timer_voidSelectEdgeICU(TIMER_ICU_RISING_EDGE);
	DIO_u8SetPinDirection(DIO_U8_PIN_D6,DIO_U8_INPUT);
}
void ICU_voidEnable(void){
	TIMSK |= TIMER_INTERRUPT_ENABLE_MASK_TIMER1_CAPTURE;
}
void ICU_voidDisable(void){
	TIMSK &=TIMER_INTERRUPT_DISABLE_MASK_TIMER1_CAPTURE;
}
static void ICU_voidSelectEdge(u8 Copy_u8ICU_EdgeSelect){
TCCR1B = (TCCR1B & 0xBF) | (Copy_u8ICU_EdgeSelect <6) ;

}
void ICU_voidGetPeriod(u8 *Copy_u8ICU_period){

}
void ICU_voidGetDuty(u8 *Copy_u8ICU_duty){

}
void ICU_voidGetFrequency(u8 *Copy_u8ICU_Frequency){

}
void ICU_voidGetOnTime(u8 *Copy_u8ICU_OnTime){

}
void ICU_voidGetOffTime(u8 *Copy_u8ICU_OffTime){

}
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
					TCCR1B &= 0xCF;
					TCCR1B|=Copy_u8OC_PinMode;
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
u8 Timer_u8prescaler(u8 Copy_u8TimerIndex,u8 Copy_u8Prescaler){
	u8 Local_u8ErrorState=0;
	switch (Copy_u8TimerIndex){
	case TIMER_INDEX_TIMER0: assign_3bits(Timer_Au8Prescaler[0],0,Copy_u8Prescaler);break;
	case TIMER_INDEX_TIMER1: assign_3bits(Timer_Au8Prescaler[1],0,Copy_u8Prescaler);break;
	case TIMER_INDEX_TIMER2: assign_3bits(Timer_Au8Prescaler[2],0,Copy_u8Prescaler);break;
	}
	return Local_u8ErrorState;
}
void Timer_voidSetCallback(u8 Copy_u8TimerCallbackMode,void (*Copy_ptr)(void)){
	switch(Copy_u8TimerCallbackMode){
			case TIMER_CALLBACK_TIMER2_COMPARE :TIMSK |= TIMER_INTERRUPT_ENABLE_MASK_TIMER2_COMPARE;PvoidCallback[0] = Copy_ptr;break;
			case TIMER_CALLBACK_TIMER2_OVERFLOW:TIMSK |= TIMER_INTERRUPT_ENABLE_MASK_TIMER2_OVERFLOW;PvoidCallback[1] = Copy_ptr; break;
			case TIMER_CALLBACK_TIMER1_CAPTURE :TIMSK |= TIMER_INTERRUPT_ENABLE_MASK_TIMER1_CAPTURE;PvoidCallback[2] = Copy_ptr;break;
			case TIMER_CALLBACK_TIMER1_COMPARE_A:TIMSK|= TIMER_INTERRUPT_ENABLE_MASK_TIMER1_COMPARE_A;PvoidCallback[3] = Copy_ptr;break;
			case TIMER_CALLBACK_TIMER1_COMPARE_B:TIMSK|= TIMER_INTERRUPT_ENABLE_MASK_TIMER1_COMPARE_B;PvoidCallback[4] = Copy_ptr;break;
			case TIMER_CALLBACK_TIMER1_OVERFLOW: TIMSK|= TIMER_INTERRUPT_ENABLE_MASK_TIMER1_OVERFLOW;PvoidCallback[5] = Copy_ptr;break;
			case TIMER_CALLBACK_TIMER0_COMPARE :TIMSK |= TIMER_INTERRUPT_ENABLE_MASK_TIMER0_COMPARE ;PvoidCallback[6] = Copy_ptr;break;
			case TIMER_CALLBACK_TIMER0_OVERFLOW:TIMSK |= TIMER_INTERRUPT_ENABLE_MASK_TIMER0_OVERFLOW;PvoidCallback[7] = Copy_ptr;break;
				}
}
void __vector_4 (void)//compare timer2
{
	if (PvoidCallback[0] !=NULL){
				PvoidCallback[2]();
			}
}
void __vector_5 (void)//overflow timer1
{
	if (PvoidCallback[1] !=NULL){
				PvoidCallback[2]();
			}
}
void __vector_6 (void)//capture timer1
{
	if (PvoidCallback[2] !=NULL){
				PvoidCallback[2]();
			}
}
void __vector_7 (void)//compare A timer1
{
	static flag=0;
	if (flag ==0){ // will be entered when Rising edge happen
		Timer_u16OffTime=ICR1;
		TCNT1=0;
		ICU_voidSelectEdge(TIMER_ICU_FALLING_EDGE);
		flag =1;
	}else {// will be entered when falling edge happen
		Timer_u16OnTime=ICR1;
		TCNT1=0;
		ICU_voidSelectEdge(TIMER_ICU_RISING_EDGE);
		flag =0;
	}
	/*
	if (PvoidCallback[3] !=NULL){
				PvoidCallback[2]();
			}*/
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
