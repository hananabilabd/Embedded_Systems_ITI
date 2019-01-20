/*
 * EEPROM.h
 *
 *  Created on: Apr 22, 2018
 *      Author: Hanna Nabil
 */

#ifndef EEPROM_H_
#define EEPROM_H_
#include "typedef.h"

void EEpromInit(void);
void EEpromWriteByte(unsigned short address, u8 data);
u8 EEpromReadByte(unsigned short address);

#endif /* EEPROM_H_ */
