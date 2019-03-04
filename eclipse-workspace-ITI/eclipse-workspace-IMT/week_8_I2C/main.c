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
#include "I2C.h"

u8 address=0x20, read=1, write=0;
u8 write_data=0x01, recv_data;

	int main(void)
	{
		_delay_ms(2000);
		DIO_setPortDirection('B',0xFF);

		I2C_INIT_master();  // Function to initialize TWI
		while(1)
		{
		if(write_data==0x00)
		write_data=1;

		I2C_Start(); // Function to send start condition
		TWI_write_address(address+write); // Function to write address and data direction bit(write) on SDA
		TWI_write_data(write_data);      // Function to write data in slave
		TWI_stop(); // Function to send stop condition


		_delay_ms(10); // Delay of 10 milli second

		TWI_start();
		TWI_read_address(address+read); // Function to write address and data direction bit(read) on SDA
		TWI_read_data(); // Function to read data from slave
		TWI_stop();

		_delay_ms(1000);

		write_data = write_data * 2;
		}


		return 0;
	}



