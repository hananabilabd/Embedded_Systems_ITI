#include <stdio.h>


int main (void){
	int x =10; 
	int y=2;
	int z1 = (x=0);
	int z2 = (x=10);
	//y= x+++1;
	//y=x++++1;
	//y=x+++ +1;
	x=y=3;
		printf("y=%d\n",y);
		printf("x=%d\n",x);
		printf("x=%d\n",z1);
		printf("x=%d\n",z2);
	//0.75 they are the same
	//0.11 double is bigger 
	//0.1 float id bigger

	return 0;
}