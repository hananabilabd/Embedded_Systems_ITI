/*
 * SW-ICU_program.c
 *
 *  Created on: Apr 7, 2019
 *      Author: Hanna Nabil
 */

#include "STD_TYPES.h"
#include"BIT_CALC.h"
#include"Timer_interface.h"
#include"Timer_config.h"
#include"Timer_private.h"
#include "DIO_private.h"
//#include "DIO_interface.h"
#include "ExtInterrupt_interface.h"
#include "SW-ICU_interface.h"
#include "SW-ICU_config.h"

static u16 SW_ICU_Au16OffTime[3];
static u16 SW_ICU_Au16OnTime[3];
static u16 SW_ICU_Timer_Au8ActualPrescaler[6]={0,1,8,64,256,1024};
static u16 SW_ICU_Timer_Au8SelectedPrescaler[3]={0,0,0};


static void SW_ICU_ExtInterrupt0(void){
	static u8 flag =0 ;
	if ( flag ==0 ){
		#if SW_ICU_EXTI0_SELECTED_TIMER == SW_ICU_INDEX_TIMER0
				SW_ICU_Au16OffTime[0]= TCNT0;
				TCNT0 =0;
		#elif SW_ICU_EXTI0_SELECTED_TIMER == SW_ICU_INDEX_TIMER1
				SW_ICU_Au16OffTime[0]= TCNT1;
				TCNT1 =0;
		#else
				SW_ICU_Au16OffTime[0]= TCNT2;
				TCNT2 =0;
		#endif
		ExtInterrupt_setLevel(SW_ICU_INDEX_EXTI0,SW_ICU_SELECT_EDGE_FALLING);
		flag =1 ;
	}
	else {
		#if SW_ICU_EXTI0_SELECTED_TIMER == SW_ICU_INDEX_TIMER0
				SW_ICU_Au16OnTime[0]= TCNT0;
				TCNT0 =0;
		#elif SW_ICU_EXTI0_SELECTED_TIMER == SW_ICU_INDEX_TIMER1
				SW_ICU_Au16OnTime[0]= TCNT1;
				TCNT1 =0;
		#else
				SW_ICU_Au16OnTime[0]= TCNT2;
				TCNT2 =0;
		#endif
		ExtInterrupt_setLevel(SW_ICU_INDEX_EXTI0,SW_ICU_SELECT_EDGE_RISING);
		flag =0;
	}
}
void SW_ICU_voidInitialize(u8 Copy_u8SW_ICU_IndexEXTI){
	SREG |= 0x80; // Enable Global Interrupt
	switch(Copy_u8SW_ICU_IndexEXTI){
	case SW_ICU_INDEX_EXTI0:ExtInterrupt_Initialize(Copy_u8SW_ICU_IndexEXTI);ExtInterrupt_voidSetCallback(Copy_u8SW_ICU_IndexEXTI,SW_ICU_ExtInterrupt0);break;
	case SW_ICU_INDEX_EXTI1:ExtInterrupt_Initialize(Copy_u8SW_ICU_IndexEXTI);ExtInterrupt_voidSetCallback(Copy_u8SW_ICU_IndexEXTI,SW_ICU_ExtInterrupt0);break;
	case SW_ICU_INDEX_EXTI2:ExtInterrupt_Initialize(Copy_u8SW_ICU_IndexEXTI);ExtInterrupt_voidSetCallback(Copy_u8SW_ICU_IndexEXTI,SW_ICU_ExtInterrupt0);break;
	}
	SW_ICU_Timer_Au8SelectedPrescaler[0]=SW_ICU_Timer_Au8ActualPrescaler[SW_ICU_EXTI0_SELECTED_TIMER_PRESCALER];
	SW_ICU_Timer_Au8SelectedPrescaler[1]=SW_ICU_Timer_Au8ActualPrescaler[SW_ICU_EXTI1_SELECTED_TIMER_PRESCALER];
	SW_ICU_Timer_Au8SelectedPrescaler[2]=SW_ICU_Timer_Au8ActualPrescaler[SW_ICU_EXTI2_SELECTED_TIMER_PRESCALER];
}
void SW_ICU_voidEnable(u8 Copy_u8SW_ICU_IndexEXTI){
	ExtInterrupt_Enable(Copy_u8SW_ICU_IndexEXTI);
	switch (Copy_u8SW_ICU_IndexEXTI){
	case SW_ICU_INDEX_EXTI0:
		Timer_voidSetPrescaler(SW_ICU_EXTI0_SELECTED_TIMER,SW_ICU_EXTI0_SELECTED_TIMER_PRESCALER);
		Timer_voidEnableTimer(SW_ICU_EXTI0_SELECTED_TIMER);
		break;
	case SW_ICU_INDEX_EXTI1:
		Timer_voidSetPrescaler(SW_ICU_EXTI1_SELECTED_TIMER,SW_ICU_EXTI0_SELECTED_TIMER_PRESCALER);
		Timer_voidEnableTimer(SW_ICU_EXTI1_SELECTED_TIMER);
		break;
	case SW_ICU_INDEX_EXTI2:
		Timer_voidSetPrescaler(SW_ICU_EXTI2_SELECTED_TIMER,SW_ICU_EXTI0_SELECTED_TIMER_PRESCALER);
		Timer_voidEnableTimer(SW_ICU_EXTI2_SELECTED_TIMER);
		break;
	}

}
void SW_ICU_voidDisable(u8 Copy_u8SW_ICU_IndexEXTI){
	ExtInterrupt_Disable(Copy_u8SW_ICU_IndexEXTI);
	switch (Copy_u8SW_ICU_IndexEXTI){
		case SW_ICU_INDEX_EXTI0:
			Timer_voidDisableTimer(SW_ICU_EXTI0_SELECTED_TIMER);
			break;
		case SW_ICU_INDEX_EXTI1:
			Timer_voidDisableTimer(SW_ICU_EXTI1_SELECTED_TIMER);
			break;
		case SW_ICU_INDEX_EXTI2:
			Timer_voidDisableTimer(SW_ICU_EXTI2_SELECTED_TIMER);
			break;
		}
}
void SW_ICU_voidGetPeriod(u8 Copy_u8SW_ICU_IndexEXTI,u16 *Copy_u8SW_ICU_period){
	*Copy_u8SW_ICU_period=(SW_ICU_Au16OnTime[Copy_u8SW_ICU_IndexEXTI] +SW_ICU_Au16OffTime[Copy_u8SW_ICU_IndexEXTI])* ((f32)SW_ICU_Timer_Au8SelectedPrescaler[Copy_u8SW_ICU_IndexEXTI]/TIMER_CLOCK_FREQUENCY);
}
void SW_ICU_voidGetDuty(u8 Copy_u8SW_ICU_IndexEXTI,u16 *Copy_u8SW_ICU_duty){
	*Copy_u8SW_ICU_duty= ((f32)SW_ICU_Au16OnTime[Copy_u8SW_ICU_IndexEXTI]/(SW_ICU_Au16OnTime[Copy_u8SW_ICU_IndexEXTI] +SW_ICU_Au16OffTime[Copy_u8SW_ICU_IndexEXTI]) ) *100;
}
void SW_ICU_voidGetFrequency(u8 Copy_u8SW_ICU_IndexEXTI,u16 *Copy_u8SW_ICU_Frequency){
	*Copy_u8SW_ICU_Frequency=((f32)TIMER_CLOCK_FREQUENCY*1000000/(SW_ICU_Timer_Au8SelectedPrescaler[Copy_u8SW_ICU_IndexEXTI] * (SW_ICU_Au16OnTime[Copy_u8SW_ICU_IndexEXTI] +SW_ICU_Au16OffTime[Copy_u8SW_ICU_IndexEXTI]) ) );
}
void SW_ICU_voidGetOnTime(u8 Copy_u8SW_ICU_IndexEXTI,u16 *Copy_u8ICU_OnTime){
	*Copy_u8ICU_OnTime= (SW_ICU_Au16OnTime[Copy_u8SW_ICU_IndexEXTI] )* ((f32)SW_ICU_Timer_Au8SelectedPrescaler[Copy_u8SW_ICU_IndexEXTI]/TIMER_CLOCK_FREQUENCY);
	//*Copy_u8ICU_OnTime= (SW_ICU_Au16OnTime[Copy_u8SW_ICU_IndexEXTI] );
}
void SW_ICU_voidGetOffTime(u8 Copy_u8SW_ICU_IndexEXTI,u16 *Copy_u8ICU_OffTime){
	*Copy_u8ICU_OffTime= (SW_ICU_Au16OffTime[Copy_u8SW_ICU_IndexEXTI] )* ((f32)SW_ICU_Timer_Au8SelectedPrescaler[Copy_u8SW_ICU_IndexEXTI]/TIMER_CLOCK_FREQUENCY);
}

