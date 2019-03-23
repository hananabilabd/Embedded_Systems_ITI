/*
 * LedMatrix_config.h
 *
 *  Created on: Mar 10, 2019
 *      Author: Hanna Nabil
 */

#ifndef LEDMATRIX_CONFIG_H_
#define LEDMATRIX_CONFIG_H_

#define LEDMATRIX_ROWS_NB   8
#define LEDMATRIX_COLS_NB   8
#define LEDMATRIX_u8_ACTIVATION_TYPE          LEDMATRIX_u8_ACTIVE_COL
#define LEDMATRIX_u8_ACTIVATE_ELEMENT_TYPE    LEDMATRIX_u8_LOW  // it is activated by putting high or low ==> in my case by putting low
u8 LedMatrix_Au8Rows[LEDMATRIX_ROWS_NB]= {
		//DIO_U8_PIN_B12,
		DIO_U8_PIN_B13,
		DIO_U8_PIN_B14,
		DIO_U8_PIN_B15,
		DIO_U8_PIN_A8,
		DIO_U8_PIN_A9,
		DIO_U8_PIN_A10,
		DIO_U8_PIN_A11,
		DIO_U8_PIN_A12,
};
u8 LedMatrix_Au8Cols[LEDMATRIX_COLS_NB]= {//COLS are grounded in my led Matrix
		//DIO_U8_PIN_A12,
		DIO_U8_PIN_A15,
		DIO_U8_PIN_B3,
		DIO_U8_PIN_B4,
		DIO_U8_PIN_B5,
		DIO_U8_PIN_B6,
		DIO_U8_PIN_B7,
		DIO_U8_PIN_B8,
		DIO_U8_PIN_B9
};

#endif /* LEDMATRIX_CONFIG_H_ */
