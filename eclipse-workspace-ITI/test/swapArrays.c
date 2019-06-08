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

void swapArrays(int arr1[],int arr2[],int size ){
	signed int i ,j;
	for (i=0 ,j=size-1;i<size;i++,j--){
		swap(&arr1[i],&arr2[j]);

	}
}

void printArray(int arr[],int size){
	int i=0;
	printf("\n------------------\n");
	for (i=0;i<size ;i++){
		printf("arr[%d]=%d\n",i,arr[i]);
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
	int arr1[100]={0};
	int arr2[100]={0};
	printf("Enter array Size=");
	scanf("%d",&size);

	scanArray(arr1,size);
	printf("\n-------------\n");
	scanArray(arr2,size);
	swapArrays(arr1,arr2,size);
	printArray(arr1,size);
	printf("\n-------------\n");
	printArray(arr2,size);



	return 0;
}
