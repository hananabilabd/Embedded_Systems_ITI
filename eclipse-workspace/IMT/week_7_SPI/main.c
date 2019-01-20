/*
 * main.c
 *
 *  Created on: Feb 24, 2018
 *      Author: Hanna Nabil
 */

#include "typedef.h"
#include "IO.h"
#include "macros.h"
#define F_CPU 12000000UL
#include <util/delay.h>
#include "DIO.h"
//#include "Timer.h"
//00#include "UART.h"
#include "SPI.h"

//#define MasterOrSlave 'Slave'
// SPI control Led
/*
#if MasterOrSlave == 'Master'
int main(void)
{
	DIO_SetPinDirection('B',0,0); // as Input
	DIO_SetPinValue('B',0,1);// Pull-Up
	SPI_INIT();

	u8 x=0;
	while (1){
		x=DIO_ReadPinValue('B',0); // x is zero when pressed
		if (x== 0){
			SPI_Transceiver('1'); // key is pressed
		}
		else {
			SPI_Transceiver('0');
		}




	}
	return 0;
}
#elif  MasterOrSlave == 'Slave'
*/
	int main(void)
	{
		DIO_SetPinDirection('C',0,1); // as Output
		//DIO_SetPinValue('B',0,1);
		SPI_INIT();

		;

		while (1){
			u8 data = SPI_Transceiver('9');
			if (data == 1){
				DIO_SetPinValue('C',0,1);// Led on
			_delay_ms(1000);
			}
			else if (data == '0'){
				//DIO_SetPinValue('C',0,0);
				_delay_ms(1000);
			}




		}
		return 0;
	}

//#endif

