
#include<stdio.h>

signed int size=0;
void swap(int *x,int * y){
	int temp= *x;
	*x=*y;
	*y=temp;
}
void reverseArray(int arr[] ){
	signed int i,j ;
	for (i=0,j=size-1;i<size/2;i++,j--){
		swap(&arr[i],&arr[j]);
	}
}

void printArray(int arr[]){
	int i=0;
	printf("\n------------------\n");
	for (i=0;i<size ;i++){
		printf("arr[%d]=%d\n",i,arr[i]);
	}
}
void scanArray(int arr[]){
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

	scanArray(arr);
	reverseArray(arr);
	printArray(arr);

	return 0;
}

