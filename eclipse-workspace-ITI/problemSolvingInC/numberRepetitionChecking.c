/*
 * umberRepetitionChecking.c
 *
 *  Created on: Jun 6, 2019
 *      Author: Hanna Nabil
 */


#include<stdio.h>
void swap(int *x,int * y){
	int temp= *x;
	*x=*y;
	*y=temp;
}

void checkRepetition(int arr[],int size,int occArray[] ){
	signed int i ;
	for (i=0 ;i<size;i++){
		occArray[arr[i]]++;

	}
}

void printArray(int arr[],int size){
	int i=0;
	printf("\n------------------\n");
	for (i=0;i<size ;i++){
		printf("occurance of %d is %d\n",i,arr[i]);
	}
}
void scanArray(int arr[],int size){
	int i=0;
	for (i=0;i<size ;i++){
		printf("arr[%d]=",i);
		scanf("%d",&arr[i]);
	}
}
int main()
{
	unsigned int size ;
	int arr[100]={0};
	int occArray[100]={0};
	printf("Enter array Size=");
	scanf("%d",&size);

	scanArray(arr,size);
	checkRepetition(arr,size,occArray);
	printArray(occArray,size);



	return 0;
}
