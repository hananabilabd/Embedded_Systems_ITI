/*
 * main.c
 *
 *  Created on: Feb 12, 2019
 *      Author: Hanna Nabil
 */
#include"STD_TYPES.h"
#include"DIO_interface.h"
//#include"LEDDriver_interface.h"
void delay_ms(u32 value){
	for (u32 i =0 ; i< value*150;i++){
		asm("NOP");
	}
}

u8 heart[8]={0,12,18,36,18,12,0,0};
u8 big_heart[8]={24,36,66,132,132,66,36,24};
u8 small_heart[8]={0,24,36,72,72,36,24,0};
u8 hamoksha_up[8]={132,136,215,125,125,215,136,132};
u8 hamoksha_middle[8]={144,144,215,125,125,215,144,144};
u8 hamoksha_down[8]={192,160,215,125,125,215,160,192};
/***********************************************************************/
u8 ball_down[8]={2, 132, 234, 61, 61, 234, 228, 98};
u8 ball_middle[8]={2, 132, 234, 61, 61, 106, 116, 50};
u8 ball_up[8]={2, 132, 234, 61, 61, 234, 156, 26};
/***************************************************************************/
u8 ball_down_2screens[8]={128, 199, 125, 199, 224, 96, 0, 0};
u8 ball_middle_2screens[8]={128, 199, 125, 71, 64, 48, 48, 0};
u8 ball_up_2screens[8]={128, 199, 125, 199, 128, 0, 24, 24};
u8 ball_up_2screens_out[8]={128, 199, 125, 199, 128, 0, 0, 12};
u8 ball_up_2screens_out_completely[8]={128, 199, 125, 199, 128, 0, 0, 0};
/**************************************************************************/
void draw(u8 arr[]){
	u8 i ;
	for (i=0;i<8;i++){
		DIO_u8SetPortValue(2,255&(~(1<<i)));//col
		DIO_u8SetPortValue(3,arr[i]);//rows
		delay_ms(2);
	}
}
int main (void){


	DIO_u8SetPortDirection(DIO_U8_PORT2,0xFF);
	DIO_u8SetPortDirection(DIO_U8_PORT3,0xFF);


	u8 j;
	while(1){

		for (j =0 ; j<12 ;j++){
			draw(big_heart);
		}
		for (j =0 ; j<12 ;j++){
			draw(small_heart);
		}


	}




	return 0;
}
