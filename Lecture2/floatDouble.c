#include <stdio.h>


int main (void){
	float x =0.11 ; 
	double y =0.11;
	if (x >y)
		printf("float is bigger");
	else if (y >x)
		printf("double is bigger");
	else 
		printf("they are the same");
	//0.75 they are the same
	//0.11 double is bigger 
	//0.1 float id bigger

	return 0;
}