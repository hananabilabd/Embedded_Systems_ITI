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
#include "Timer.h"
#include "UART.h"
#define v 100
// This assignment is to make Piano with Buzzer
int main(void)
{
	u8 arr []="Hannon";
	u8 a []="han";

	int i =0;
	UART_INIT();
	Timer1_Init();
	u8 Data;
	while (1){
		Data = UART_ReceiveData();


		if (Data=='a'){


			Timer1_PWM(v,2872);
			_delay_ms(1000);
		}
		else if (Data=='s'){

			Timer1_PWM(v,2558);
			_delay_ms(1000);

		}
		else if (Data=='d'){

					Timer1_PWM(v,2278);
					_delay_ms(1000);

				}
		else if (Data=='f'){
			Timer1_PWM(v,2147);
				_delay_ms(1000);

						}
		else if (Data=='g'){
					Timer1_PWM(v,1912);
						_delay_ms(1000);

								}
		else if (Data=='h'){
					Timer1_PWM(v,1703);
						_delay_ms(1000);

								}
		else if (Data=='j'){
					Timer1_PWM(v,1520);
						_delay_ms(1000);

								}
		else if (Data=='k'){
							Timer1_PWM(v,1433);
								_delay_ms(1000);

										}
		else if (Data=='l'){
									Timer1_PWM(v,1276);
										_delay_ms(1000);

												}
		Timer1_PWM(0,0);


	}
	return 0;
}

