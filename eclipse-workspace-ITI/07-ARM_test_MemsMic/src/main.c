

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "delay.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
//#include "NVIC_interface.h"


#define STK_CTRL            *((u32*) 0xE000E010)
#define STK_LOAD            *((u32*) 0xE000E014)
#define STK_VAL             *((u32*) 0xE000E018)
#define STK_CALIB           *((u32*) 0xE000E01C)

static u8 flag=0;
u8 status;
u8 i =0;
 //minimum angle
 u32 load_low=19500;
 u32 load_high=500;

// maximum angle
u32 load_low_max=17600;
u32 load_high_max=2400;

void SysTick_Handler(void){
	if (flag ==0){
		STK_LOAD=90;
		STK_VAL=3;
		DIO_u8SetPinValue(DIO_U8_PIN_A0,DIO_U8_LOW);
		flag=1;
	}else {
		STK_LOAD=90;
		STK_VAL=3;
		DIO_u8SetPinValue(DIO_U8_PIN_A0,DIO_U8_HIGH);
		flag=0;

	}
	DIO_u8GetPinValue(DIO_U8_PIN_A2,&status);
	DIO_u8SetPinValue(DIO_U8_PIN_A1,(status));
}
void SysTick_init(void){
	clr_bit(STK_CTRL,2);//AHB CLK/8
	set_bit(STK_CTRL,1);
	set_bit(STK_CTRL,0);
	STK_LOAD=100;
	STK_VAL=1;

}
int main(void)
{
	//RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE);
	RCC_voidInitialize();
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOA,RCC_u8_ENABLE_CLK);
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOB,RCC_u8_ENABLE_CLK);
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOC,RCC_u8_ENABLE_CLK);
	//DIO_u8SetPortDirection(DIO_U8_PORTA,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPortDirection(DIO_U8_PORTB,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPortDirection(DIO_U8_PORTC,0XFFFF,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPortValue(DIO_U8_PORTA,0xFFFF);

	DIO_u8SetPinDirection(DIO_U8_PIN_A0,DIO_OUTPUT_2M_PUSH_PULL);//clk for MEMS
	DIO_u8SetPinDirection(DIO_U8_PIN_A1,DIO_OUTPUT_2M_PUSH_PULL);
	DIO_u8SetPinDirection(DIO_U8_PIN_A2,DIO_INPUT_PULLUP);//output of MEMS

	SysTick_init();

	while(1)
	{

		/*
		DIO_u8GetPinValue(DIO_U8_PIN_A2,&status);
		if (status == DIO_U8_BUTTON_PRESSED){
			DIO_u8SetPinValue(DIO_U8_PIN_A1,DIO_U8_HIGH);
		}
		else {
			DIO_u8SetPinValue(DIO_U8_PIN_A1,DIO_U8_LOW);
		}
		*/
		//delay_ms(500);
	}
	return 0;
}


