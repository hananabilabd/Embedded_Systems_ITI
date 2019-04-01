/*
 * main.c
 *
 *  Created on: Mar 10, 2019
 *      Author: Hanna Nabil
 */
#include <stdio.h>
typedef unsigned char u8 ;
#define correct   20
#define incorrect 30
int hanna[]={1,2,3,4,5};
int hamoksha[]={5,4,3,2,1};
int bor3y[]={2,3,4,5,6};
int *numbers[]={hanna,hamoksha,bor3y};

int verify (int *arr){
	int i =0 , j =0,incorrectFlag =0 ;
	for ( j =0 ; j <3 ; j ++){
	for ( i =0 ; i < 5 ; i++){
		if ( arr[i] != numbers[j][i]){
			incorrectFlag =1 ;
			//break;
		}
	}
	if ( incorrectFlag ==0 ){return j ;}
	else {incorrectFlag =0;}
	}
	return incorrect;

}
void blink (void){
	printf("%d\n",2);
}
int main(void){
	int x=10;
	int y ;
	y=x++++1;
	int bor3y[]={2,3,4,5,7};
	void (*ptr)(void);
	ptr=&blink;
	//(*ptr)();
	printf("%d",y );
	return 0 ;
}

