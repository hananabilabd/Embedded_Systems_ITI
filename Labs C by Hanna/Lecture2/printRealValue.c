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

int binaryParse(char arr[], int size){
	unsigned int num =0,temp,bit1=0;

	for ( int i=size,counter=0 ; i >= 0; i--,counter++){
	    bit1 = arr[i] - '0';

        if (bit1 == 1){
		temp =(int)pow(2,(double)counter);
		num =  temp +num;

		}
	}

	printf("number is = %d\n",num);
	return num;
}
int binaryParse_signMagnitude(char arr[], int size){
	unsigned int num =0,temp,bit1=0;
	printf("--------------------Sign Magnitude representation-------------------------\n");
    if ( arr[0] - '0' == 0){
	for ( int i=size,counter=0 ; i > 0; i--,counter++){
	    bit1 = arr[i] - '0';

        if (bit1 == 1){
		temp =(int)pow(2,(double)counter);
		num =  temp +num;
		}
	}
	printf("number is = %d\n",num);
    }
    else{//negative
	for ( int i=size,counter=0 ; i > 0; i--,counter++){
	    bit1 = arr[i] - '0';

        if (bit1 == 1){
		temp =(int)pow(2,(double)counter);
		num =  temp +num;

		}
	}
	printf("number is = %d\n",-num);
    }
	printf("--------------------------------------------------------------------------\n");
	return num;
}
int binaryParse_firstComplement(char arr[], int size){
	unsigned int num =0,temp,bit1=0;
	unsigned char x;
	int signed signednum;
	printf("--------------------First Complement representation-------------------------\n");

	for ( int i=size,counter=0 ; i >= 0; i--,counter++){
	    bit1 = arr[i] - '0';

        if (bit1 == 1){
		temp =(int)pow(2,(double)counter);
		num =  temp +num;

		}
	}

	if ( arr[0] - '0' == 1){//negative
        x= (unsigned char)~num;
        signednum = x ;
        num=-signednum ;
        printf("number is = %d\n",num);
	}
	printf("number is = %d\n",num);

	printf("--------------------------------------------------------------------------\n");
	return num;
}
int binaryParse_secondComplement(char arr[], int size){
	unsigned int num =0,temp,bit1=0;
	unsigned char x;
	int signed signednum;
	printf("--------------------Second Complement representation-------------------------\n");

	for ( int i=size,counter=0 ; i >= 0; i--,counter++){
	    bit1 = arr[i] - '0';

        if (bit1 == 1){
		temp =(int)pow(2,(double)counter);
		num =  temp +num;
		}
	}

	if ( arr[0] - '0' == 1){//negative
        x= (unsigned char)~num;
        signednum = x ;
        signednum++ ;
        num=-signednum ;
        printf("number is = %d\n",num);
	}
	printf("number is = %d\n",num);
	printf("--------------------------------------------------------------------------\n");
	return num;
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
    /////////////////////////////////////
	int i = strlen(bin1) - 1;

	int intNum=binaryParse_signMagnitude(bin1 ,i);
	int intNum2=binaryParse_firstComplement(bin1 ,i);
	int intNum3=binaryParse_secondComplement(bin1 ,i);



	//printBinary(y);


	return 0;
}
