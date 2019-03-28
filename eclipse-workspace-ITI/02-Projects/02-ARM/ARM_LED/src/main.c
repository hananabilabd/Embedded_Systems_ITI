

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

#define GPIOC_CRH ((Register_32Bit *) 0x40011004)
#define GPIOC_ODR ((Register_32Bit *) 0x4001100C)

int main(void)
{
	RCC_voidInitialize();
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOC,RCC_u8_ENABLE_CLK);

	GPIOC_CRH ->ByteAccess = 0x00200000;
	GPIOC_ODR ->ByteAccess = 0x00000000;


  return 0;
}


