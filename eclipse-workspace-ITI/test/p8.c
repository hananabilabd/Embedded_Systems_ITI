/*
 * p8.c
 *
 *  Created on: May 15, 2019
 *      Author: Hanna Nabil
 */


#include <stdio.h>
int size;



typedef struct occuranceStruct{
	int occuranceArray[10];
}occurance;

occurance func(int arr[] ){
	signed char i =0 ,j=0;
	occurance occ;
	//put zeros in the array
	int * ptr = &arr[0];
	for ( i = 0 ; i< size ;i++){
			occ.occuranceArray[i]=0;}

	for ( i=size-1 , j=0; i>=0;i--,j++){
		occ.occuranceArray[j]=*(ptr+i);
	}
	return occ;
}

int main (void) {
	char arr[50];
	int i ;
	occurance occ1;



		printf("Enter any String=");
		scanf("%s",&arr[0]);
		printf("\n%s\n",arr);

	/*occ1=func(arr);*/
	while (arr[i]!='\0'){
		i++;
	}
	printf("Length = %d",i);
	printf("\n******************************************");


	return 0 ;
}
