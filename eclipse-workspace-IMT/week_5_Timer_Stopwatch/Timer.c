/*
 * Timer.c
 *
 *  Created on: Mar 24, 2018
 *      Author: Hanna Nabil
 */
#include "typedef.h"
#include "IO.h"
#include "macros.h"
#include "SevenSegment.h"

#define Mode 'Normal' // Normal (overflow)
#define Prescale '256' // 'NO' , 'clk/8' , clk /64 , clk/256 , clk /1024

#if (Mode == 'CTC')
	void __vector_10 (void) __attribute__((signal,__INTR_ATTRS));

#elif (Mode == 'Normal')
	void __vector_11 (void) __attribute__((signal,__INTR_ATTRS));
#endif

/*
 * Timer Tick = 1/ Frequency  =1 / 12*10^6 =
 * Timer Overflow = Timer Tick * 256 (register size) =
 * no of  ISR Accessing = Desired Time / Timer Overflow = 1 sec /
 */
void Timer0_Init (void){ // Normal mode
		set_bit(SREG,7); // Enable Global Interrupt

		#if (Mode == 'Normal')
				set_bit(TIMSK,0); // Timer/Counter0 Overflow Interrupt Enable

				clr_bit(TCCR0,3); // Normal Mode
				clr_bit(TCCR0,6);


		#elif (Mode == 'CTC')
				set_bit(TIMSK,1); //  Timer/Counter0 Output Compare Match Interrupt Enable

				set_bit(TCCR0,3); // CTC Mode
				clr_bit(TCCR0,6);
				OCR0=100; // Output Compare Register ,this is the register we want to compare with

		#endif

		#if (Prescale == 'NO')

				set_bit(TCCR0,0);// Datasheet Page 79 No prescaler
				clr_bit(TCCR0,1);
				clr_bit(TCCR0,2);



		#elif (Prescale == '8')
				clr_bit(TCCR0,0); // Datasheet Page 79 with prescaler ==> clk /8
				set_bit(TCCR0,1);
				clr_bit(TCCR0,2);


		#elif (Prescale == '64')
				set_bit(TCCR0,0);// Datasheet Page 79 with prescaler ==> clk /64
				set_bit(TCCR0,1);
				clr_bit(TCCR0,2);

		#elif (Prescale =='256')
				clr_bit(TCCR0,0);// Datasheet Page 79 with prescaler ==> clk /256
				clr_bit(TCCR0,1);
				set_bit(TCCR0,2);


		#elif (Prescale =='1024')
				set_bit(TCCR0,0);// Datasheet Page 79 with prescaler ==> clk /1024
				clr_bit(TCCR0,1);
				set_bit(TCCR0,2);


		#endif

	}



u32 counter =0;
u32 s=0;
u32 m=0;
void __vector_11 (void) // Mode0 Normal Mode
{
	counter ++;
		#if ( Prescale == 'NO' )
			if (counter == 46875){ // Normal Mode + No Prescaler
						toggle_bit(PORTA, 0);
						counter =0;
					}


		#elif (Prescale =='8')

			if (counter == 5859){ // Normal Mode +Prescaler clk /8
							toggle_bit(PORTA, 0);
							counter =0;
						}
		#elif (Prescale =='64')

			if (counter == 732){ // Normal Mode +Prescaler clk/64
							toggle_bit(PORTA, 0);
							counter =0;
						}
		#elif (Prescale =='256')

			if (counter == 183){ // Normal Mode +Prescaler clk /256


							if (s==59){s=0;m++;}
							else {s++;}
							counter =0;
						}
		#elif (Prescale =='1024')

			if (counter == 45){ // Normal Mode +Prescaler clk /1024
							toggle_bit(PORTA, 0);
							counter =0;
						}

		#endif



}



void __vector_10 (void) // Timer0 CTC Mode
{
	counter ++;

	if (counter == 120000){ // CTC +  No Prescaler
				toggle_bit(PORTA, 0);
				counter =0;
			}

}

