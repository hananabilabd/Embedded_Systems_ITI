/*
 * umberRepetitionChecking.c
 *
 *  Created on: Jun 6, 2019
 *      Author: Hanna Nabil
 */
#include<stdio.h>

void swapWithoutTemp(int *x,int * y){
	*x = *x * *y;
	*y= *x / *y;
	*x = *x/ *y;
}
void swapWithoutTemp2(int *x,int * y){
	*x = *x + *y;
	*y= *x  - *y;
	*x = *x - *y;
}

int main()
{
	 int num1,num2 ;

	printf("Enter 1st number=");
	scanf("%d",&num1);
	printf("Enter 2nd number=");
	scanf("%d",&num2);

	swapWithoutTemp2(&num1,&num2);
	printf("num1=%d\n",num1);
	printf("num2=%d\n",num2);

	return 0;
}
