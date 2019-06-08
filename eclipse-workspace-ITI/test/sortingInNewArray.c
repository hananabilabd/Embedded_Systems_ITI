/*
 * sortingInNewArray.c
 *
 *  Created on: Jun 6, 2019
 *      Author: Hanna Nabil
 */


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
void SortInNewArray(int arr1[],int arr2[],int size ){
	signed int i,j ;
	int past_min =1000 , current_min=1000;
	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			if ( i ==0 || arr1[j] > past_min){
				if ( past_min == current_min || arr1[j] < current_min ){
						current_min=arr1[j];
							}
			}
		}
		arr2[i]=current_min;
		past_min=current_min;
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
	SortInNewArray(arr1,arr2,size);
	printArray(arr2,size);

	return 0;
}
