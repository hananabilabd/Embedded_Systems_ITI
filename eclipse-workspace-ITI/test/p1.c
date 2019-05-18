#include <stdio.h>
int size;
struct result{
	int element1;
	int element2 ;
	int MaxDiff;
};
typedef struct result output;

output func(int arr[] ){
	unsigned char i =0 , j =0,temp,z;
	output output1;
	
	output1.MaxDiff=arr[1]-arr[0];
	for ( i = 0 ; i< size ;i++){
		for ( j =i+1 ; j<size;j++){
			if (arr[j] - arr[i] > output1.MaxDiff){
				output1.element1=arr[i];
				output1.element2=arr[j];
				output1.MaxDiff=arr[j] - arr[i];
			}
		}
		
	}
	return output1;
}
int main (void) {
	int arr[50];
	int i ;
	printf("Enter array size=");
	scanf("%d",&size);
	
	for ( i=0 ;i<size;i++){
		printf("array[%d]=",i);
		scanf("%d",&arr[i]);
	}
	output output1;
	output1=func(arr);

	
		printf("element1=%d\n",output1.element1);
		printf("element2=%d\n",output1.element2);
		printf("Maximum=%d\n",output1.MaxDiff);
	
	return 0 ;
}