/*
 * p6.c
 *
 *  Created on: May 15, 2019
 *      Author: Hanna Nabil
 */
#include <stdio.h>
int size;
typedef enum state {repeated , NotRepeated}TYPE;


typedef struct occuranceStruct{
	int occuranceArray[10][10];
}occurance;

occurance MatrixSum(int arr[3][3] , int arr2[3][3]){
	signed char i =0 ,j=0;
	occurance occ;
	//put zeros in the array
	for ( i = 0 ; i< size ;i++){
		for (j=0 ; j< size ;j++ ){
			occ.occuranceArray[i][j]=0;}}

	for ( i=0 ;i<size;i++){
			for (j=0 ; j< size ;j++ ){
				occ.occuranceArray[i][j]=arr[i][j]+arr2[i][j];
			}
		}
	return occ;
}

int main (void) {
	int arr[3][3];
	int arr2[3][3];
	int i ,j=0 ;
	occurance occ1;
	printf("Enter First Matrix of size 3x3\n");
	size = 3;
	for ( i=0 ;i<size;i++){
		for (j=0 ; j< size ;j++ ){
		printf("array[%d][%d]=",i,j);
		scanf("%d",&arr[i][j]);
		}
	}
	printf("Enter Second Matrix of size 3x3\n");
	for ( i=0 ;i<size;i++){
			for (j=0 ; j< size ;j++ ){
			printf("array[%d][%d]=",i,j);
			scanf("%d",&arr2[i][j]);
			}
		}
	occ1=MatrixSum(arr,arr2);
	for ( i=0 ; i<size;i++){
		for (j=0 ; j< size ;j++ ){
		printf("arr[%d][%d]= %d\n",i,j,occ1.occuranceArray[i][j]);
		}
	}
	printf("******************************************");


	return 0 ;
}
