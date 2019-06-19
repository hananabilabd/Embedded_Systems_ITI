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
signed int size ;
void swapReplace(int *x,int * y){
	*x=*y;
}

void removeArrayDuplication(int arr[] ){
	signed int i,j ,flag=0;
	for (i=0;i<size;i++){
		for (j=i+1;j<size;j++){
			if (arr[i]==arr[j]  && flag != 1){
				flag =1;
			}
			if (flag ==1 &&  (j != size-1)){
				swapReplace(&arr[j],&arr[j+1]);
			}
			else if (flag ==1 && (j == size-1)){
				swapReplace(&arr[j-1],&arr[j]);
				printf("pope kerolos  i love you i=%d j=%d\n",i,j);
						}
		}
		if (flag==1){
			i--;
			flag =0;
			size--;
		}
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

	int arr[100]={0};
	printf("Enter array Size=");
	scanf("%d",&size);

	scanArray(arr,size);
	removeArrayDuplication(arr);
	printArray(arr,size);

	return 0;
}
