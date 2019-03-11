/*
 * LedMatrix_program.c
 *
 *  Created on: Mar 10, 2019
 *      Author: Hanna Nabil
 */
#include "STD_TYPES.h"
#include"BIT_CALC.h"
//MCAL includes
#include "DIO_interface.h"
#include "LedMatrix_config.h"
#include "LedMatrix_interface.h"
/*******************/
#include "delay.h"
void LedMatrix_voidInitialize(void){
	u8 i=0;
	for (i = 0 ; i < LEDMATRIX_COLS_NB; i++){
		DIO_u8SetPinDirection(LedMatrix_Au8Cols[i],DIO_OUTPUT_2M_PUSH_PULL);
		#if LEDMATRIX_u8_ACTIVATION_TYPE == LEDMATRIX_u8_ACTIVE_COL
		#if LEDMATRIX_u8_ACTIVATE_ELEMENT_TYPE == LEDMATRIX_u8_LOW
		 DIO_u8SetPinValue(LedMatrix_Au8Cols[i],DIO_U8_HIGH);//leaving them unactivated
		#else //columns is activated by putting high on it
		 DIO_u8SetPinValue(LedMatrix_Au8Cols[i],DIO_U8_LOW);
		#endif

		#endif
	}
	for (i = 0 ; i < LEDMATRIX_ROWS_NB; i++){
		DIO_u8SetPinDirection(LedMatrix_Au8Rows[i],DIO_OUTPUT_2M_PUSH_PULL);
		#if LEDMATRIX_u8_ACTIVATION_TYPE == LEDMATRIX_u8_ACTIVE_COL
		#if LEDMATRIX_u8_ACTIVATE_ELEMENT_TYPE == LEDMATRIX_u8_LOW
		 DIO_u8SetPinValue(LedMatrix_Au8Rows[i],DIO_U8_LOW);//leaving then unactivated
		#else //columns is activated by putting high on it
		 DIO_u8SetPinValue(LedMatrix_Au8Rows[i],DIO_U8_HIGH);
		#endif

		#endif
	}
}
u8 LedMatrix_u8draw(u8 arr[]){
	u8 i ;
	u8 Local_u8Errorstate=0;
	for (i=0;i<LEDMATRIX_COLS_NB;i++){
		DIO_u8SetPinValue(LedMatrix_Au8Cols[i], DIO_U8_LOW);
		DIO_u8SetArrayValue(LedMatrix_Au8Rows,  arr[i], 8) ;
		//DIO_u8SetPortValue(2,255&(~(1<<i)));//col
		//DIO_u8SetPortValue(3,arr[i]);//rows
		delay_ms(2);
		DIO_u8SetPinValue(LedMatrix_Au8Cols[i], DIO_U8_HIGH);
	}
	return Local_u8Errorstate;
}
u8 LedMatrix_u8drawForSeconds(u8 arr[],u8 seconds){// arr is the drawing
	u8 i ,j;
	u8 Local_u8Errorstate=0;
	for (j =0 ; j<seconds ;j++){
	for (i=0;i<8;i++){
		DIO_u8SetPortValue(2,255&(~(1<<i)));//col
		DIO_u8SetPortValue(3,arr[i]);//rows
		delay_ms(2);
	}
	}
	return Local_u8Errorstate;
}


