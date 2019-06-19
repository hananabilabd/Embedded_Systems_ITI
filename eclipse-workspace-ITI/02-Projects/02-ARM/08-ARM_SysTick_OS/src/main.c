

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "delay.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "RTOS_interface.h"



 u32 load_low_min=19500;
 u32 load_high_min=500;
u32 load_low_max=17600;
u32 load_high_max=2400;
u32 load_low=19500;
u32 load_high=500;



void Task1(void){
	DIO_u8SetPinValue(DIO_U8_PIN_A0,1);

}
void Task2(void){
	DIO_u8SetPinValue(DIO_U8_PIN_A0,0);
}
int main(void)
{

	RCC_voidInitialize();
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOA,RCC_u8_ENABLE_CLK);
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOB,RCC_u8_ENABLE_CLK);
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOC,RCC_u8_ENABLE_CLK);
	//DIO_u8SetPortDirection(DIO_U8_PORTA,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPortDirection(DIO_U8_PORTB,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPortDirection(DIO_U8_PORTC,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPortValue(DIO_U8_PORTA,0xFFFF);

	DIO_u8SetPinDirection(DIO_U8_PIN_A0,DIO_OUTPUT_2M_PUSH_PULL);




	/***************** Handler , periodicity  , priority , First delay   */
	RTOS_u8CreateTask(Task1,10,0,0 , ACTIVE);
	RTOS_u8CreateTask(Task2,20,1,0,  ACTIVE);
	RTOS_StartOs();

	while(1)
	{


	}
return 0;
}


