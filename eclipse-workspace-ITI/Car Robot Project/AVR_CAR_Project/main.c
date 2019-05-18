/*
 * main.c
 *
 *  Created on: Mar 14, 2019
 *      Author: Hanna Nabil
 */

#include "STD_TYPES.h"
#include"BIT_CALC.h"
#include"DIO_interface.h"
//#include"DIO_config.h"
#define F_CPU 12000000UL
//#include <util/delay.h>
#include "DIO_private.h"
#include "LCD_interface.h"
#include"delay.h"
#include "Timer_interface.h"
#include "UART_interface.h"



int main(void){
	DIO_u8SetPinDirection(DIO_U8_PIN_B1,DIO_U8_OUTPUT);
	DIO_u8SetPinValue(DIO_U8_PIN_B1,DIO_U8_OUTPUT);

	Timer_voidIntialize();
	Timer_voidInitializeOCPin(TIMER_OC_PIN_INDEX_OCR0);
	Timer_voidSetPrescaler(TIMER_INDEX_TIMER0,TIMER_PRESCALER_8);
	Timer_voidSetMode(TIMER_INDEX_TIMER0,TIMER_MODE_TIMER0_PWM_FAST);
	Timer_voidSetOCPinMode(TIMER_INDEX_TIMER0,TIMER_OC_PIN_MODE_TIMER0_OC0_CLEAR);

	Timer_voidInitializeOCPin(TIMER_OC_PIN_INDEX_OCR1A);
	Timer_voidInitializeOCPin(TIMER_OC_PIN_INDEX_OCR1B);
	Timer_voidSetPrescaler(TIMER_INDEX_TIMER1,TIMER_PRESCALER_8);
	Timer_voidSetMode(TIMER_INDEX_TIMER1,TIMER_MODE_TIMER1_PWM_FAST_8BIT);
	Timer_voidSetOCPinMode(TIMER_INDEX_TIMER1,TIMER_OC_PIN_MODE_TIMER1_OC1A_CLEAR);
	Timer_voidSetOCPinMode(TIMER_INDEX_TIMER1,TIMER_OC_PIN_MODE_TIMER1_OC1B_CLEAR);

	Timer_voidInitializeOCPin(TIMER_OC_PIN_INDEX_OCR2);
	Timer_voidSetPrescaler(TIMER_INDEX_TIMER2,TIMER_PRESCALER_8);
	Timer_voidSetMode(TIMER_INDEX_TIMER2,TIMER_MODE_TIMER2_PWM_FAST);
	Timer_voidSetOCPinMode(TIMER_INDEX_TIMER2,TIMER_OC_PIN_MODE_TIMER0_OC2_CLEAR);

	Timer_voidEnableTimer(TIMER_INDEX_TIMER0);
	Timer_voidEnableTimer(TIMER_INDEX_TIMER1);
	Timer_voidEnableTimer(TIMER_INDEX_TIMER2);




	UART_voidIntialize();
	u8 state =0;





	while(1){

		state=UART_ReceiveData();
		if (state == 0){//stop
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR0 ,0);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR1A,0);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR1B,0);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR2 ,0);
		}
		else if (state ==1 ){//forward
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR0 ,255);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR1A,0);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR1B,255);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR2 ,0);
		}
		else if (state ==2 ){//backward
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR0 ,0);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR1A,255);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR1B,0);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR2 ,255);
		}
		else if (state ==3 ){//right
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR0 ,135);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR1A,0);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR1B,255);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR2 ,0);
		}
		else if (state ==4 ){//left
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR0 ,255);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR1A,0);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR1B,135);
			Timer_voidWritePWM(TIMER_OC_PIN_INDEX_OCR2 ,0);
		}


	}
return 0 ;
}
