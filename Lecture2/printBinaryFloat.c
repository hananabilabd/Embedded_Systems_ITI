#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define BinarySize 8
#define mantissaSize 23
#define postive 0
#define negative 1
int floatArr[mantissaSize]={0};
int integerArr[mantissaSize]={0};
int intFloatArr[mantissaSize]={0};
int sign=postive;
void printBinary(signed char decimal ){
    int  c, k;
    printf("exp in binary= ");
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
void integerToBinaryArr(int decimal ){
    int  c, k,counter,foundOneFlag=0,firstTime=0,foundOneFlagLast=0,mantissaPoint=0,size=0;
    printf("Integer Binary number= ");
    for (c = 7,counter=0; c >= 0; c--,counter++)
  {
    k = decimal >> c;
    if (k & 1 ){
      printf("1");
      intFloatArr[counter]=1;
      if (firstTime ==0){
        firstTime=1;
      foundOneFlag=counter;}

    }
    else{
      printf("0");
      intFloatArr[counter]=0;
      }
  }
  printf("\n");

     size =counter-foundOneFlag;
     if (decimal ==0){size=0;}
    printf("\nsize=%d",size);
     printf("\ncomplete Array=");
    for (int i=0,counter=foundOneFlag;i<size;i++,counter++){//shifting the integer values t begin with ones
        intFloatArr[i]=intFloatArr[counter];
        printf("%d",intFloatArr[i]);
    }
    for (int i=size+1, j=0;i<mantissaSize;i++,j++){//append  float
        intFloatArr[i]=floatArr[j];
        printf("%d",intFloatArr[i]);
    }
  printf("\n");
  printf("complete Array=");
  for (int i=0;i<mantissaSize;i++){//print
         printf("%d",intFloatArr[i]);
        }
        printf("\n");

  if (intFloatArr[0]==1){
    mantissaPoint=size-1;
  }
  else {// =0
    for (int i=1;i<mantissaSize;i++){//for loop to search for the first 1 in the intFloatArray
        if (intFloatArr[i] ==1){
            mantissaPoint=-i;
            break;
        }
    }
  }
  printf("exp=%d\n",mantissaPoint);
  printBinary(mantissaPoint);



}



void FloatNumber(double realValue){

    int i=0;
    double temp;
	int intValue = (int)realValue;
	double floatValue = realValue - (double)intValue;
    if (intValue <0){
        intValue =-1*intValue;
        floatValue=floatValue*-1;
        sign =negative;
    }
    printf("number=%d.%.6f\n",intValue,floatValue);
    temp=floatValue;
    while (i<mantissaSize){
        temp=temp*2;
        if (temp >= 1){
            temp=temp-1;
            floatArr[i]=1;
        }
        else {
            floatArr[i]=0;
        }
        i++;
    }
    i=0;
     printf("Float Binary number=");
    while (i<mantissaSize){
        printf("%d",floatArr[i]);
        i++;
    }
    printf("\n");
    integerToBinaryArr(intValue);



}
int main (void){
    double floatNum;
    printf("Enter Float number = ");
    scanf("%lf", &floatNum);
    FloatNumber(floatNum);

    printf("Sign =%d",sign);

	return 0;
}
