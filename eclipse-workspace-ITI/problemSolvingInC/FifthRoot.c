/*
 * test.c
 *
 *  Created on: Jun 4, 2019
 *      Author: Hanna Nabil
 */



#include<stdio.h>

 unsigned int FifthRoot(unsigned int n)
{
if (n ==1 || n ==0 ){
	return n;
}
unsigned int s =0;
while (s *s*s*s*s < n)
{
	s++;
}
return s;
}

int main()
{
	int x =FifthRoot(32);

   printf("count is =%d",x);


    return 0;
}
