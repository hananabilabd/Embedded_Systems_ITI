#include"STD_TYPES.h"
#include"delay.h"
#if MICROCONTROLLER == AVR
void delay_ms(u32 value){
	for (u32 i =0 ; i< value*122;i++){
		asm("NOP");
	}
}

void delay_us(u32 value){
		for (u32 i =0 ; i< value*12 ;i++){
			asm("NOP");
		}
}
#elif MICROCONTROLLER == ARM
void delay_ms(u32 value){
	for (u32 i =0 ; i< value*122*7;i++){
		asm("NOP");
	}
}
#endif
