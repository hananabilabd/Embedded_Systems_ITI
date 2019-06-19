/*
 * Search.c
 *
 *  Created on: Jun 5, 2019
 *      Author: Hanna Nabil
 */




#include<stdio.h>

void swap(int *x,int * y){
	int temp= *x;
	*x=*y;
	*y=temp;
}
void bubbleSort(int arr[],int size ){
	signed int i,j ;
	for (i=0;i<size-1;i++){
		for (j =0 ; j< size -1-i ; j++){
			if ( arr[j] > arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}
void Sort(int arr[],int size ){
	signed int i,j ;
	for (i=0 , j=i+1;i<size && j<size;){
		if (arr[i] >arr[j]){
			swap(&arr[i],&arr[i+1]);
			i=0;
			j=i+1;
		}
		else {
			i++;
			j++;
		}
	}
}
int binarySearch(int arr[],int size,int number ){
	signed int min =0,max =size-1,mid =0;


	while ( min <= max ){
		mid =(min+max) /2;
		if (arr[mid] ==number){
			return mid ;
		}
		else if (number > arr[mid]){
			min=mid+1;
		}
		else {
			max = mid -1;
		}

	}
	return -1;
}
void printArray(int arr[],int size){
	int i=0;
	printf("\n------------------\n");
	for (i=0;i<size ;i++){
		printf("arr[%d]=%d\n",i,arr[i]);
	}
}

void scanArray( int *arr,int size){
	int i=0;

	for (i=0;i<size ;i++){
		printf("arr[%d]=",i);
		scanf("%d",&arr[i]);
	}
}
int main()
{
	int arr[100]={0};
	unsigned int size ,search;
	typedef enum {
			x=1,
			y=2
		}test;
	test t = x;
	printf("x=%d",t);
	printf("y=%d",y);
	printf("Enter array Size=");
	scanf("%d",&size);
	scanArray(arr,size);
	Sort(arr,size);
	printArray(arr,size);
	printf("Search =");
	scanf("%d",&search);
	int result =binarySearch(arr,size,search);
	printf("\nResult=%d",result);

	return 0;
}
