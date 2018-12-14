#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



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
	unsigned char decimal;
	printf("Enter Decimal Number= ");


	scanf("%d", &decimal);


	printBinary(decimal);


	return 0;
}
