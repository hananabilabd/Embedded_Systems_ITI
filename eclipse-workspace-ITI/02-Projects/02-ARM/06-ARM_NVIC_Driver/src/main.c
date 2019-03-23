

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "delay.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "NVIC_interface.h"
void blink1(void){
	DIO_u8SetPinValue(DIO_U8_PIN_C13,DIO_U8_LOW);
	NVIC_voidSetPendingFlag(NVIC_EXTI1);
	while(1);
}
void blink2(void){
	DIO_u8SetPinValue(DIO_U8_PIN_A0,DIO_U8_HIGH);
		while(1);
}
/*
void EXTI0_IRQHandler(void){
	DIO_u8SetPinValue(DIO_U8_PIN_C13,DIO_U8_LOW);
		NVIC_voidSetPendingFlag(NVIC_EXTI1);
		while(1);
}
void EXTI1_IRQHandler(void){
	DIO_u8SetPinValue(DIO_U8_PIN_A0,DIO_U8_HIGH);
			while(1);
}
*/
int main(void)
{
	RCC_voidInitialize();
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOA,RCC_u8_ENABLE_CLK);
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOB,RCC_u8_ENABLE_CLK);
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOC,RCC_u8_ENABLE_CLK);

	DIO_u8SetPortDirection(DIO_U8_PORTA,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPortDirection(DIO_U8_PORTB,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPortDirection(DIO_U8_PORTC,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPortValue(DIO_U8_PORTA,0xFFFF);
	//DIO_u8SetPortValue(DIO_U8_PORTB,0xFFFF);
	//DIO_u8SetPortValue(DIO_U8_PORTC,0xFFFF);
	DIO_u8SetPinDirection(DIO_U8_PIN_A0,DIO_OUTPUT_2M_PUSH_PULL);
	DIO_u8SetPinDirection(DIO_U8_PIN_C13,DIO_OUTPUT_2M_PUSH_PULL);


	NVIC_voidSetCallback(NVIC_EXTI0,blink1);
	NVIC_voidSetCallback(NVIC_EXTI1,blink2);
	NVIC_voidEnable(NVIC_EXTI0);
	NVIC_voidEnable(NVIC_EXTI1);
	NVIC_u8setGroupsAndSubPriorities(NVIC_GROUP_16_SUBPRIORITY_NONE_ID);
	NVIC_u8setPriority(NVIC_EXTI0,1,3);
	NVIC_u8setPriority(NVIC_EXTI1,0,3);
	NVIC_voidSetPendingFlag(NVIC_EXTI0);

	while(1)
	{
	}
	return 0;
}


