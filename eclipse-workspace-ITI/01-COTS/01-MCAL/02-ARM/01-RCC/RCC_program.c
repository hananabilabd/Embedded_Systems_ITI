/*
 * RCC_program.c
 *
 *  Created on: Feb 21, 2019
 *      Author: Hanna Nabil
 */

#include "../../../04-LIB/STD_TYPES.h"
#include "../../../04-LIB/BIT_CALC.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
void RCC_voidInitialize(void){
	RCC_u32_CR->ByteAccess =0x00000001;
	RCC_u32_CFGR ->ByteAccess=0x00000000;

	assign_bit(RCC_u32_APB2ENR->ByteAccess ,0 ,RCC_u8_ENABLE_CLK); // this to enable the clock on alternative function pins ==> to disable debug on them later
	//afio_cfg_debug_ports(AFIO_DEBUG_SW_ONLY );
	assign_nibble(AFIO_MAPR,6,0b0010);
}
void RCC_voidSetPeripheralClockState(u8 Copy_u8PeripheralNumber , u8 Copy_u8State){
	switch(Copy_u8PeripheralNumber){
		case RCC_u8_GPIOA: 
		case RCC_u8_GPIOB:
		case RCC_u8_GPIOC:
		case RCC_u8_GPIOD:assign_bit(RCC_u32_APB2ENR->ByteAccess ,Copy_u8PeripheralNumber ,Copy_u8State);break;
	}
}

