#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int bin_verify(char str[])
{
    int i;

    for (i = 0; i < strlen(str); i++)
    {
        if ((str[i] - '0' != 1 ) && (str[i] - '0' != 0))
        {
            return 1;
        }
    }

    return 0;
}
int int_pow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}
int binaryParse(char arr[], int size){
	unsigned int num =0,temp,bit1=0;

	for ( int i=size,counter=0 ; i >= 0; i--,counter++){
	    bit1 = arr[i] - '0';

        if (bit1 == 1){
		temp =(int)pow(2,(double)counter);

        //printf("temp is = %d\n",temp);
		num =  temp +num;
		//printf("num is = %d\n",num);
		}
	}

	printf("number is = %d\n",num);
	return num;
}
unsigned char circularShift(int num ,int nOfShifts){
    printf("result before Circular shift = %d\n",num);
    unsigned char y = (num << nOfShifts) | (num >> (8 - nOfShifts));
    printf("result after Circular shift = %d\n",y);
    return y;
}
void printBinary(unsigned char decimal ){
    int  c, k;
    printf("binary number after shifting= ");
    for (c = 7; c >= 0; c--)
  {
    k = decimal >> c;

    if (k & 1)
      printf("1");
    else
      printf("0");
  }

  printf("\n");
}
int main (void){
	char bin1[33], bin2[33], result[33];
    int len1, len2, check,nOfShifts;

	 printf("Enter binary number = ");
    scanf("%s", bin1);

    check = bin_verify(bin1);
    if (check)
    {
        printf("Invalid binary number %s.\n", bin1);
        exit(0);
    }
	int i = strlen(bin1) - 1;
	printf("size %d\n", i);
	int intNum=binaryParse(bin1 ,i);
	printf("Enter number of shifts= ");
	scanf("%d", &nOfShifts);
	unsigned char y =circularShift(intNum,nOfShifts);

	printBinary(y);


	return 0;
}
