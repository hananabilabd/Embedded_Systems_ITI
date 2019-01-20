#define F_CPU 12000000UL
#include <util/delay.h>
#include "registers.h"
#include "std_types.h"
#include "DIO.h"
#include "LCD.h"
#include "KeyPad.h"
#include "I2c.h"
#include "eeprom.h"

u8 x,v;
u8 h[]="hanna";
int main(void)
{
	LCD_init();
	//LCD_writestring(h);
	EEpromInit();
	_delay_ms(500);
	EEpromWriteByte(1,50);
	_delay_ms(500);
	x =EEpromReadByte(1);
	_delay_ms(500);
	//LCD_writedata(x);
	//LCD_setposition(0,0);
	LCDWriteInt(x);
	//_delay_ms(500);

	while (1)
	{

	}
}
