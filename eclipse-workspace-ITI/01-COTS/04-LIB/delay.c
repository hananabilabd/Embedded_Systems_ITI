#include"STD_TYPES.h"
#include"delay.h"
void delay_ms(u32 value){
	for (u32 i =0 ; i< value*122;i++){
		asm("NOP");
	}
}

void delay_us(u32 value){
	u32 v =((value/3) -40);
		for (u32 i =0 ; i< v ;i++){
			asm("NOP");
		}
}
void delay_ms_arm(u32 value){
	for (u32 i =0 ; i< value*122*7;i++){
		asm("NOP");
	}
}
