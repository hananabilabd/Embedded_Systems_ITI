/*
 * countBinaryOnes.c
 *
 *  Created on: Jun 4, 2019
 *      Author: Hanna Nabil
 */


#include<stdio.h>
#define cat(x,y) x##y

 unsigned int countSetBits(unsigned int n)
{
unsigned int count = 0;
while (n)
{
	if ( n & 1 ==1){
		count ++;
	}
    //count += n & 1;
    n >>= 1;
}
return count;
}

int main()
{
	unsigned int z=countSetBits((unsigned int)3);

   printf("count is =%d",z);


    return 0;
}
