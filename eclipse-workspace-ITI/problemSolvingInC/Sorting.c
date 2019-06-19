/*
 * Sorting.c
 *
 *  Created on: Jun 1, 2019
 *      Author: Hanna Nabil
 */

#include <stdio.h>

void swap(int * x ,int *y){
	int temp  = *x ;
	*x = *y;
	*y = temp;
}
void printArray(int arr[], int size)
{
    int i;
    printf("Sorted array: \n");
    for (i=0; i < size; i++)
        printf("%d \n", arr[i]);
}

void ScanfArray(int arr[],int size){
	int i;
	for (i=0; i < size; i++){
			printf("arr[%d]=",i);
	        scanf("%d", &arr[i]);
	}
}
void Sort(int arr[], int size)
{
	int i,j;
	for(i = 0, j=i+1; i < size && j<size;)
	    {
	        if(arr[i] > arr[j])
	        {
	            swap(&arr[i],&arr[j]);
	            i=0;
	            j=i+1;
	        }
	        else
	        {
	            i++;
	            j++;
	        }
	    }
}
void SortMarina(int arr[], int size)
{
	int i,j =NULL;
	int sortedArray[size] ;
	for(i = 0 ; i < size ;i++ )
	{
		sortedArray[arr[i] ]=arr[i];
	}
	printArray(&sortedArray[0],size);
}
void insertionSort(int arr[], int size)
{
	//https://www.youtube.com/watch?v=OGzPmgsI-pQ
	int i,j ,temp;
	for (i=0 ; i< size ; i++){
		temp=arr[i];
	  for ( j= i-1; j >=0 && arr[j] >temp ; j--){
		  arr[j+1]=arr[j];
	  }
	  arr[j+1]=temp;
  }
}
void bubbleSort(int arr[], int size)
{
	//https://www.youtube.com/watch?v=nmhjrI-aW5o
	int i,j ;
	for (i=0 ; i< size -1 ; i++){
	  for ( j=0 ; j < size -i-1 ; j++){
		  if ( arr[j] > arr[j+1]){
			  swap(&arr[j] , &arr[j+1]);
		  }
	  }
  }
}

void selectionSort(int arr[],int size ){
	// https://www.youtube.com/watch?v=xWBP4lzkoyM
	int i ,j,min_i;
	for (i =0; i < size ; i++){
		min_i=i;
		for (j = i+1 ; j < size  ;j++){
			if ( arr[min_i] > arr[j]){
				min_i = j;
			}
		}
		swap ( &arr[i] ,&arr[min_i]);
	}
}
int binarySearch(int arr[],int size,int num ){
	int min = 0,max=size-1 ,mid;
	bubbleSort(arr,size);
	while (min<=max){
		mid =(max+min)/2;
		if (arr[mid] == num){
			return mid;
		}
		else if (num < arr[mid]){
			max=mid-1;
		}
		else {
			min = mid+1;
		}
	}
	return -1;
}


int main(void)
{
    int arr[50] ;
    int n ;
    printf("Enter array size=");
    scanf("%d",&n);
    ScanfArray(arr,n);

    //Sort(arr, n);
    //printArray(arr, n);
    /************************/
    SortMarina(arr,n);
    return 0;
}
