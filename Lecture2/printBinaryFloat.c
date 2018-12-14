#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define intBeforePoint 0
#define intAfterPoint 1
#define BinarySize 8
void printBinary(int decimal ){
    char bin1[30];
    int  c, k,slicer=0,counter,i=0;
    printf("binary number= ");
    for (c = BinarySize; c >= 0; c--)
  {
    k = decimal >> c;

    if (k & 1){
      printf("1");
      bin1[c]='1';
    }
    else{
      printf("0");
      bin1[c]='0';
    }
  }
  printf("\n");

for (i=0 ; i<=BinarySize;i++){
        printf("%c",bin1[i]);
  }
  printf("\n");


}




int toString(char a[],int from,int to , int flag) {
  int c, sign, n;
  int offset=from;
    if (flag ==intBeforePoint){
  if (a[0] == '-') {  // Handle negative integers
    sign = -1;
  }

  if (sign == -1) {  // Set starting position to convert
    offset = 1;
  }
  else {
    offset = 0;
  }
    }

  n = 0;

  for (c = offset; c <= to; c++) {
    n = n * 10 + a[c] - '0';
  }

  if (sign == -1 && flag ==intBeforePoint) {
    n = -n;
  }
  return n;
}
int FloatParse(char arr[], int size){
	unsigned int num =0,temp,bit1=0;
	signed int beforePointInt;
	int afterPointInt=0;
	int pointTemp;
    for ( int i=0 ; i <=size; i++){
        if (arr[i]==46){
                pointTemp =i;
        }
    }
	afterPointInt=toString(arr,pointTemp+1,size,intAfterPoint);
    beforePointInt=toString(arr,0,pointTemp-1,intBeforePoint);
     printf("beforePointInt = %d\n",beforePointInt);
	printf("afterPointInt = %d\n",afterPointInt);
	printBinary(beforePointInt);

	return num;
}


int main (void){
	char floatNum[33], result[33];
    int len1, len2, check,nOfShifts;

	 printf("Enter Float number = ");
    scanf("%s", floatNum);
    int i = strlen(floatNum) - 1;
    FloatParse(floatNum,i);

    /////////////////////////////////////





	//printBinary(y);


	return 0;
}
