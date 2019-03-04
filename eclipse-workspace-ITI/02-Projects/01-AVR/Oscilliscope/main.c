/*
 * main.c
 *
 *  Created on: Jan 23, 2019
 *      Author: Hanna Nabil
 */
typedef unsigned char u8 ;
typedef union {
	struct {
		u8 BIT0:1;
		u8 BIT1:1;
		u8 BIT2:1;
		u8 BIT3:1;
		u8 BIT4:1;
		u8 BIT5:1;
		u8 BIT6:1;
		u8 BIT7:1;
	}BitAccess;
	u8 ByteAccess;
}Register;
void delay(unsigned short int value){
	unsigned short int count ,i;
	for (i=0 ; i< value-1 ; i++){
		asm("NOP");
	}
}
int main (void){
	/* DDRD bit 0 =1 to be output*/
	//*((u8*) 0x31) = 0x01;

	//((Register*) 0x31)->BitAccess.BIT0= 0x01;
	/* PORTD bit 0 =1 to be HIGH*/
	//*((u8*) 0x32 ) = 0x01;
	while(1){
	*((unsigned short int *) 0x32)= 1;
	delay(10);
	*((unsigned short int *) 0x32) = 0;

	}
	return 0;
}
