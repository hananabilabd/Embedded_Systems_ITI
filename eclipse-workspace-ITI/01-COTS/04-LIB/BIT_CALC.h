
#ifndef MACROS_H_
#define MACROS_H_

#define set_bit(reg,bit) (reg=reg |(1<<bit))
#define clr_bit(reg,bit) (reg=reg &(~(1<<bit)))
#define get_bit(reg,bit) ((reg >> bit) & 1) // output of the shift & 1 --> to terminate the 7 higher bits of shifting result
#define toggle_bit(reg,bit) (reg=(reg ^ (1<<bit)))
/*
#define assign_bit(reg ,bitNum, value) \
	do { if (value ==0){ reg=reg &(~(1<<bitNum));}\
		else if (value ==1){reg=reg |(1<<bitNum));}}while(0);
*/
#define assign_bit(reg ,bitNum,value) (reg = ( ( reg & ~(1<<bitNum) ) | ( value<<bitNum ) ) )

#define sethigh_bit(reg) (reg=reg | 0xF0)
#define setlow_bit(reg) (reg=reg | 0x0F)
#define clrhigh_bit(reg) (reg=reg & 0x0F)
#define clrlow_bit(reg) (reg=reg & 0xF0)

#define CONC_8BIT(b0,b1,b2,b3,b4,b5,b6,b7) CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7)
#define CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7) 0b##b7##b6##b5##b4##b3##b2##b1##b0

#define assign_nibble(reg,pin,value)     reg=(reg & (~(0xF << pin*4)))| (value << pin*4)
#define assign_3bits(reg,pin,value)     reg=(reg & (~(0x7 << pin*3)))| (value << pin*3)
#define assign_2bits(reg,pin,value)     reg=(reg & (~(0x3 << pin*2)))| (value << pin*2)
#define get_nibble(reg , pin)            ((reg >> pin*4) & 0xF)
#define get_8Bits(reg , pin)             ((reg >> pin*8) & 0xFF)
#endif /* MACROS_H_ */
