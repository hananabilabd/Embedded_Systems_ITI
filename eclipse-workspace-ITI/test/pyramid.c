/*
 * integerToArray.c
 *
 *  Created on: Jun 4, 2019
 *      Author: Hanna Nabil
 */



#include<stdio.h>
void space(int num){
	unsigned int i ;
	for ( i =0;i<num ; i++){
		printf(" ");
	}
}
void stars(int num){
	unsigned int i ;
	for ( i =0;i<num ; i++){
		printf("*");
	}
}
void Pyramid(unsigned int height) {
	unsigned int base = (height*2) -1;
	signed int wing =height -1;
	unsigned int i;
	unsigned int star=1;
	for (i =0;i<height ;i++){

    space(wing);
    stars(star);
    space(wing);
    printf("\n");
    wing--;
    star+=2;

	}
}

int main()
{
	printf("Enter Pyramid Height=");
	unsigned int num;
	scanf("%d",&num);

   Pyramid(num);


    return 0;
}
