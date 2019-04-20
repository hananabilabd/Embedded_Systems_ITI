

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
#include"Keypad_interface.h"
#include"delay.h"

#define STK_CTRL            *((u32*) 0xE000E010)
#define STK_LOAD            *((u32*) 0xE000E014)
#define STK_VAL             *((u32*) 0xE000E018)
#define STK_CALIB           *((u32*) 0xE000E01C)

static u8 flag=0;

 u32 load_low_min=19500;
 u32 load_high_min=500;
u32 load_low_max=17600;
u32 load_high_max=2400;
u32 load_low=19500;
u32 load_high=500;
u8  setAngle (u8 angle ){
	u8 Local_u8ErrorState=0;
	if ( angle > 90){Local_u8ErrorState =1;}
	else {
	load_low = load_low_min-angle *21;
	load_high = load_high_min+angle *21;
	STK_LOAD=load_high;
	STK_VAL=1;
	}
	return Local_u8ErrorState;
}
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
}

void SysTick_init(void){
	clr_bit(STK_CTRL,2);
	set_bit(STK_CTRL,1);
	set_bit(STK_CTRL,0);
	STK_LOAD=load_high;
	STK_VAL=1;

}
void SysTick_Disable(void){
	//clr_bit(STK_CTRL,2);
	clr_bit(STK_CTRL,1);
	clr_bit(STK_CTRL,0);
}
void assign_value(u8 v1,u8 v2,u8 v3,u8 v4){
	DIO_u8SetPinValue(DIO_U8_PIN_A12,v1);
	DIO_u8SetPinValue(DIO_U8_PIN_A15,v2);
	DIO_u8SetPinValue(DIO_U8_PIN_B3,v3);
	DIO_u8SetPinValue(DIO_U8_PIN_B4,v4);
}
void stepper_half (void){
	assign_value(0,0,0,0);
	delay_ms(5);
	assign_value(0,0,1,1);
	delay_ms(5);
	assign_value(0,0,1,0);
	delay_ms(5);
	assign_value(0,1,1,0);
	delay_ms(5);
	assign_value(0,1,0,0);
	delay_ms(5);
	assign_value(1,1,0,0);
	delay_ms(5);
	assign_value(1,0,0,0);
	delay_ms(5);
	assign_value(1,0,0,1);
	delay_ms(5);
}
void stepper_half_anti (void){
	assign_value(1,0,0,1);
	delay_ms(5);
	assign_value(1,0,0,0);
	delay_ms(5);
	assign_value(1,1,0,0);
	delay_ms(5);
	assign_value(0,1,0,0);
	delay_ms(5);
	assign_value(0,1,1,0);
	delay_ms(5);
	assign_value(0,0,1,0);
	delay_ms(5);
	assign_value(0,0,1,1);
	delay_ms(5);
	assign_value(0,0,0,0);
		delay_ms(5);
}
void stepper_full_cw(void){
	assign_value(1,0,0,0);
	delay_ms(5);
	assign_value(0,1,0,0);
	delay_ms(5);
	assign_value(0,0,1,0);
	delay_ms(5);
	assign_value(0,0,0,1);
	delay_ms(5);
	assign_value(0,0,1,1);
}
void stepper_full_Anticw(void){
	assign_value(0,0,0,1);
	delay_ms(5);
	assign_value(0,0,1,0);
	delay_ms(5);
	assign_value(0,1,0,0);
	delay_ms(5);
	assign_value(1,0,0,0);
	delay_ms(5);
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
	DIO_u8SetPinDirection(DIO_U8_PIN_A10,DIO_OUTPUT_2M_PUSH_PULL);
	DIO_u8SetPinDirection(DIO_U8_PIN_A11,DIO_OUTPUT_2M_PUSH_PULL);
	DIO_u8SetPinDirection(DIO_U8_PIN_A12,DIO_OUTPUT_2M_PUSH_PULL);
	DIO_u8SetPinDirection(DIO_U8_PIN_A15,DIO_OUTPUT_2M_PUSH_PULL);
	DIO_u8SetPinDirection(DIO_U8_PIN_B3,DIO_OUTPUT_2M_PUSH_PULL);
	DIO_u8SetPinDirection(DIO_U8_PIN_B4,DIO_OUTPUT_2M_PUSH_PULL);

	LCD_voidInitialize();
	Keypad_u8Init();
	SysTick_init();
	u8 x=NULL_Key,stepper_forward=0;
	u8 state0=1,state_servo=0,state_dc=0,state_stepper=0;
	while(1)
	{
		if (stepper_forward ==1 ){
			stepper_half();}
		else {stepper_full_cw();}


		if (state0==1){
			LCD_voidSetPosition(0,0);
			LCD_voidWriteString("Enter Motor ID:");
			LCD_voidSetPosition(1,0);
			x=Keypad_u8GetPressedKey();
			if (x != NULL_Key ){
				LCD_voidWriteNumber(x);
				delay_ms(1000);
				if (x == 0){state_servo=1;state0=0;}
				else if (x == 1){state_dc=1;state0=0;}
				else if (x == 2){state_stepper=1;state0=0;}
				else {LCD_voidSetPosition(1,0);LCD_voidWriteString("Enter Correct Motor ID");delay_ms(1000);}
				LCD_voidClearScreen();
			}
		}
		else if (state_servo ==1){
			LCD_voidSetPosition(0,0);
			LCD_voidWriteString("Enter Angle,8 to enter");
			LCD_voidSetPosition(1,0);
			LCD_voidWriteString(" ");
			u8 value=0;
			x=0;
			while (x !=8 ){
				x=Keypad_u8GetPressedKey();
				if (x != NULL_Key  && x != 8){
					LCD_voidWriteNumber(x);
					value = value * 10 + x ;
				}
			}
			setAngle(value);
			state0=1;state_servo=0;
			LCD_voidClearScreen();
		}
		else if (state_dc ==1){
			LCD_voidSetPosition(0,0);
			LCD_voidWriteString("EnterDir:0,1,2");
			LCD_voidSetPosition(1,0);
			x=Keypad_u8GetPressedKey();
			if (x != NULL_Key ){
				LCD_voidWriteNumber(x);
				delay_ms(1000);
				if ( x ==0){DIO_u8SetPinValue(DIO_U8_PIN_A10,DIO_U8_LOW);DIO_u8SetPinValue(DIO_U8_PIN_A11,DIO_U8_LOW);}
				else if (x ==1){DIO_u8SetPinValue(DIO_U8_PIN_A10,DIO_U8_HIGH);DIO_u8SetPinValue(DIO_U8_PIN_A11,DIO_U8_LOW);}
				else if (x ==2){DIO_u8SetPinValue(DIO_U8_PIN_A10,DIO_U8_LOW);DIO_u8SetPinValue(DIO_U8_PIN_A11,DIO_U8_HIGH);}
				else {LCD_voidSetPosition(1,0);LCD_voidWriteString("Enter Correct Direction");delay_ms(1300);}
				state0=1;state_dc =0;
				LCD_voidClearScreen();
			}
		}
		else if (state_stepper ==1){
			LCD_voidSetPosition(0,0);
			LCD_voidWriteString("Enter Dir:0,1");
			LCD_voidSetPosition(1,0);
			x=Keypad_u8GetPressedKey();
			if (x != NULL_Key ){
				LCD_voidWriteNumber(x);
				delay_ms(1000);
				 if (x ==0){stepper_forward=0;}
					else if (x ==1){stepper_forward=1;}
				state0=1;state_stepper =0;
			}

	}

	}
return 0;
}


