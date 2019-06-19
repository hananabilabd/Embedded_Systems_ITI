/*
 * countConsecutiveBinaryOnes.c
 *
 *  Created on: Jun 6, 2019
 *      Author: Hanna Nabil
 */


/*
 * countBinaryOnes.c
 *
 *  Created on: Jun 4, 2019
 *      Author: Hanna Nabil
 */


#include<stdio.h>
#define cat(x,y) x##y

 unsigned int countConsecutiveOnes(unsigned int n)
{
unsigned int count = 0;
int max =0;
while (n)
{
	if ( (n & 1) ==1){
		count ++;
		if (count > max ){
			max=count;
		}
	}
	else {
		count =0;
	}
    //count += n & 1;
    n >>= 1;
}
return max;
}

int main()
{
	unsigned int z= countConsecutiveOnes((unsigned int)239);

   printf("count is =%d",z);
   int const x =9;
   int *ptr = &x;
   *ptr =4;

    return 0;
}
