/*
 * enumTest.c
 *
 *  Created on: May 27, 2019
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
	char arr[50] , arr2[50];
	int i ,flag=0;
	occurance occ1;

	printf("Enter first String=");
	scanf("%s",&arr[0]);
	printf("\n%s\n",arr);

	printf("Enter second String=");
	scanf("%s",&arr2[0]);
	printf("\n%s\n",arr2);


	while (arr[i]!='\0'){
		if ( arr[i] != arr2[i]){
			flag=1;
		}
		i++;

	}
	if ( flag ==1){printf("Strings are not equal");}
	else {printf("Strings are equal");}

	printf("\n******************************************");


	return 0 ;
}
