#include <stdio.h>
int size;
typedef enum state {repeated , NotRepeated}TYPE;


typedef struct occuranceStruct{
	int occuranceArray[10];
}occurance;

occurance func(int arr[] ){
	signed char i =0 ,j=0;
	occurance occ;
	//put zeros in the array
	int temp [50]={0};
	for ( i = 0 ; i< size ;i++){
			occ.occuranceArray[i]=0;}

	for ( i = size-1 ,j=0; i>=0 ;i--,j++){
		temp[j]=arr[i];

	}
	for ( i = 0 ; i<size ;i++){
		occ.occuranceArray[i]=temp[i];

		}

	return occ;
}

int main (void) {
	int arr[50];
	int i ;
	occurance occ1;
	printf("Enter array size=");
	scanf("%d",&size);

	for ( i=0 ;i<size;i++){
		printf("array[%d]=",i);
		scanf("%d",&arr[i]);
	}

	occ1=func(arr);
	for ( i=0 ; i<size;i++){
		printf("arr[%d]= %d\n",i,occ1.occuranceArray[i]);
	}
	printf("******************************************");


	return 0 ;
}
