

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"
static inline void afio_cfg_debug_ports(afio_debug_cfg config) {
     u32 *mapr = &AFIO_BASE->MAPR;
    *mapr = (*mapr & ~AFIO_MAPR_SWJ_CFG) | config;
}
int main(void)
{

	afio_cfg_debug_ports(AFIO_DEBUG_SW_ONLY );
	//*((volatile   u32 *)0x40010004)= 0x0200;
	RCC_voidInitialize();
	RCC_voidSetPeripheralClockState(RCC_u8_GPIOA,RCC_u8_ENABLE_CLK);

	//DIO_u8SetPortDirection(DIO_U8_PORTA,0xF00F,DIO_INPUT_PULLUP,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPortValue(DIO_U8_PORTA,0x00FF);
	u8 x=0;
	DIO_u8SetPinDirection(DIO_U8_PIN_A15,DIO_OUTPUT_2M_PUSH_PULL);
	//DIO_u8SetPinDirection(DIO_U8_PIN_A7,DIO_INPUT_PULLUP);
	DIO_u8SetPinValue(DIO_U8_PIN_A15,DIO_U8_HIGH);
	while(1){
		//DIO_u8GetPinValue(DIO_U8_PIN_A7,&x);
		//if (x == DIO_U8_BUTTON_PRESSED){DIO_u8SetPinValue(DIO_U8_PIN_A15,DIO_U8_HIGH);}
		//else if (x ==DIO_U8_BUTTON_RELEASED){DIO_u8SetPinValue(DIO_U8_PIN_A15,DIO_U8_LOW);}

	}
  return 0;
}


