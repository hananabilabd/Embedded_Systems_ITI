

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
#include "LCD_interface.h"
#include "LedMatrix_interface.h"

#define STK_CTRL            *((u32*) 0xE000E010)
#define STK_LOAD            *((u32*) 0xE000E014)
#define STK_VAL             *((u32*) 0xE000E018)
#define STK_CALIB           *((u32*) 0xE000E01C)

static u8 flag=0;
u8 i =0;
 //minimum angle
 u32 load_low=19500;
 u32 load_high=500;

// maximum angle
u32 load_low_max=17600;
u32 load_high_max=2400;

u8 motor_1[8]={0, 0, 0, 32, 32, 32, 32, 32};
u8 motor_2[8]={0, 0, 0, 0, 32, 16, 8, 4};
u8 motor_3[8]={0, 0, 0, 0, 48, 8, 4, 0};
u8 motor_4[8]={0, 0, 0, 0, 62, 0, 0, 0};
u8 motor_5[8]={2, 4, 8, 48, 0, 0, 0, 0};
u8 motor_6[8]={4, 8, 16, 32, 0, 0, 0, 0};
u8 motor_7[8]={32, 32, 32, 32, 32, 0, 0, 0};


u8 *motor[7]={motor_1,motor_2,motor_3,motor_4,motor_5,motor_6,motor_7};
u8 motor_test[8]={255, 255, 255, 255, 255, 255, 255, 255};
void SysTick_Handler(void){
	if (flag ==0){
		STK_LOAD=load_low;
		STK_VAL=1;
		DIO_u8SetPinValue(DIO_U8_PIN_A0,DIO_U8_LOW);
		flag=1;
	}else {
		STK_LOAD=load_high;
		STK_VAL=1;
		DIO_u8SetPinValue(DIO_U8_PIN_A0,DIO_U8_HIGH);
		flag=0;

	}
	load_high++;
	load_low--;
	if (load_high % 320==0){
						i++;

					}
	if (load_high== load_high_max){
		load_low=19500;
		 load_high=500;
		 i =0;
	}
}
void SysTick_init(void){
	clr_bit(STK_CTRL,2);
	set_bit(STK_CTRL,1);
	set_bit(STK_CTRL,0);
	STK_LOAD=load_high;
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

	DIO_u8SetPinDirection(DIO_U8_PIN_A0,DIO_OUTPUT_2M_PUSH_PULL);

	LCD_voidInitialize();
	LedMatrix_voidInitialize();
	SysTick_init();
	while(1)
	{
		if (i == 8 ){i=0;}
		LedMatrix_u8draw(motor[i]);

		/*
		LCD_voidSetPosition(0,0);
		LCD_voidWriteNumber(load_low);
		LCD_voidSetPosition(1,0);
		LCD_voidWriteNumber(load_high);
		*/
		//delay_ms(500);
	}
	return 0;
}


