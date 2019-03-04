/*
 * SevenSegment.c
 *
 *  Created on: Mar 24, 2018
 *      Author: Hanna Nabil
 */

// 7 Segment of IMT Tool kit is common anode ( connect the common to high from MC)
#include "typedef.h"
#include "IO.h"
#include "macros.h"
#include "DIO.h"

#define SegmentPort 'B' // output port for the 7segment Unit
#define SegmentPort2 'A' // output port for the 7segment Tenth




void SevenSegment_Init(void){
	DIO_setPortDirection(SegmentPort,0xFF);
	DIO_setPortDirection(SegmentPort2,0xFF);
}

void SevenSegment_print_fun(u8 time){
	int a =time % 10; //get unit
	int b= (time-a)/10; //get tenth

	if (a==0){
		DIO_setPortValue(SegmentPort,0xA0);
	}
	else if (a==1){
		DIO_setPortValue(SegmentPort,0xF9);
	}
	else if (a==2){
		DIO_setPortValue(SegmentPort,0xC4);
	}
	else if (a==3){
		DIO_setPortValue(SegmentPort,0xD0);
	}
	else if (a==4){
		DIO_setPortValue(SegmentPort,0x99);
	}
	else if (a==5){
		DIO_setPortValue(SegmentPort,0x92);
	}
	else if (a==6){
		DIO_setPortValue(SegmentPort,0x82);
	}
	else if (a==7){
		DIO_setPortValue(SegmentPort,0xF8);
	}
	else if (a==8){
		DIO_setPortValue(SegmentPort,0x80);
	}
	else if (a==9){
		DIO_setPortValue(SegmentPort,0x98);
	}
////////////////////////////////////////
	if (b==0){
		DIO_setPortValue(SegmentPort2,0xA0);
	}
	else if (b==1){
		DIO_setPortValue(SegmentPort2,0xF9);
	}
	else if (b==2){
		DIO_setPortValue(SegmentPort2,0xC4);
	}
	else if (b==3){
		DIO_setPortValue(SegmentPort2,0xD0);
	}
	else if (b==4){
		DIO_setPortValue(SegmentPort2,0x99);
	}
	else if (b==5){
		DIO_setPortValue(SegmentPort2,0x92);
	}
	else if (b==6){
		DIO_setPortValue(SegmentPort2,0x82);
	}
	else if (b==7){
		DIO_setPortValue(SegmentPort2,0xF8);
	}
	else if (b==8){
		DIO_setPortValue(SegmentPort2,0x80);
	}
	else if (b==9){
		DIO_setPortValue(SegmentPort2,0x98);
	}
}
/*
 0--0xA0
 1--0xF9
 2--0xC4
 3--0xD0
 4--0x99
 5--0x92
 6--0x82
 7--0xF8
 8--0x80
 9--0x98

 */


