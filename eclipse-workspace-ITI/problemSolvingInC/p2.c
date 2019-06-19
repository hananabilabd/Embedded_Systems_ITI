#include <stdio.h>
int size;
typedef enum state {repeated , NotRepeated}TYPE;
struct result{
	int number;
	int numOfOcurrence ;
	TYPE type;
};
typedef struct result output;

typedef struct occuranceStruct{
	int occuranceArray[10];
}occurance;

occurance func(int arr[] ){
	unsigned char i =0 ;
	occurance occ;
	TYPE Type;
	output output1[size];
	for ( i = 0 ; i< size ;i++)
			occ.occuranceArray[i]=0;

	for ( i = 0 ; i< size ;i++){
		occ.occuranceArray[arr[i]]++;
		//arrr[arr[i]]++;
	}

	return occ;
}
void AnotherSol (int *arr){
	unsigned char i =0,j=0 ;
	int occurance[50]={0};
	for ( i =0 ;i<size;i++){
		for (j=0 ;j< size ;j++){
			if (arr[i] == arr[j]){
				occurance[i]++;
			}
		}
	}
	for ( i=0 ; i<size;i++){
			printf("%d occur %d\n",arr[i],occurance[i]);
		}
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
		printf("%d occur %d\n",i,occ1.occuranceArray[i]);
	}
	printf("******************************************");
	/*****************/
	AnotherSol(arr);

	return 0 ;
}
