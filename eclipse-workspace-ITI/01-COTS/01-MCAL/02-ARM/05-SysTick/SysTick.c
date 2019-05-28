/*
 * SysTick.c
 *
 *  Created on: May 23, 2019
 *      Author: Hanna Nabil
 */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "delay.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "SysTick.h"

static u8 flag=0;
void (*Callback_ptr)(void) = NULL_ADDRESS;
void SysTick_setcallback(void (*ptr)(void) ){
	ptr =Callback_ptr;
}
void SysTick_Handler(void){
	Callback_ptr();
}

void SysTick_Initialize(u16 period){
	clr_bit(STK_CTRL,2);
	set_bit(STK_CTRL,1);
	set_bit(STK_CTRL,0);
	STK_LOAD=period;
	STK_VAL=1;

}
void SysTick_Disable(void){
	//clr_bit(STK_CTRL,2);
	clr_bit(STK_CTRL,1);
	clr_bit(STK_CTRL,0);
}
