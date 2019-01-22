/*
 * EEPROM.c
 *
 *  Created on: Apr 22, 2018
 *      Author: Hanna Nabil
 */

#include "eeprom.h"
#include "I2C.h"
#include "typedef.h"

void EEpromInit(void)
{

	I2C_INIT_master();
}



void EEpromWriteByte(unsigned short address, u8 data)
{

    I2C_Start();

	I2C_Send_slave_address_with_write_req(0b01010000 /*| ((address & 0x0700)>>8) */);


	I2C_Write_byte((u8)address);
	I2C_Write_byte(data);

	I2C_Stop();
	return;

}



u8 EEpromReadByte(unsigned short address)
{
	u8  data;
	I2C_Start();


	I2C_Send_slave_address_with_write_req(0b01010000 /*| ((address & 0x07)>>8) */);

    I2C_Write_byte((u8)address);

	I2C_Repeated_start();

	I2C_Send_slave_address_with_read_req(0b01010000 /*| ((address & 0x07)>>8)*/ );


	data = I2C_Read_byte();

	I2C_Stop();
    return data;
}

