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
#include "ExtInterrupt_interface.h"
#include "SW-ICU_interface.h"

#define WATCHDOG_SLEEP_SECOND_16_3  0b000
#define WATCHDOG_SLEEP_SECOND_32_5  0b001
#define WATCHDOG_SLEEP_SECOND_65    0b010
#define WATCHDOG_SLEEP_SECOND_0_13  0b011
#define WATCHDOG_SLEEP_SECOND_0_26  0b100
#define WATCHDOG_SLEEP_SECOND_0_52  0b101
#define WATCHDOG_SLEEP_SECOND_1_0   0b110
#define WATCHDOG_SLEEP_SECOND_2_1   0b111

void WatchDog_off(void)
{
/* Write logical one to WDTOE and WDE */
WDTCR = (1<<4) | (1<<3);
/* Turn off WDT */
WDTCR = 0x00;
}
void WatchDog_sleep(u8 Copy_u8WatchDogSeconds)
{
	WDTCR =  ((WDTCR & 0xF8)|Copy_u8WatchDogSeconds);
}
void WatchDog_voidEnable(u8 Copy_u8WatchDogSeconds){
	WDTCR= 0x08|Copy_u8WatchDogSeconds;
}
int main(void){
	u16 duty=0,period,frequency;
	u16 offTime =0,onTime =0;
	LCD_voidInitialize();


	DIO_u8SetPinDirection(DIO_U8_PIN_D1,DIO_U8_OUTPUT);
	DIO_u8SetPinValue(DIO_U8_PIN_D1,DIO_U8_HIGH);
	delay_ms(1500);
	DIO_u8SetPinValue(DIO_U8_PIN_D1,DIO_U8_LOW);
	delay_ms(1500);
	WatchDog_voidEnable(WATCHDOG_SLEEP_SECOND_2_1);

	while(1){


	}
return 0 ;
}
