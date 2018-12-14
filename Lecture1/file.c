#include <stdio.h>
#define x z
//#define z x
#define z 10
int main (void){
	printf("%d\n",x);
	//printf("%d\n"z);
	//#include "../file.h"
	// ../                        =======>1 backward step
	// ../../                     =======> 2 backward steps
	// /file/file.h               =======>  1 step forward
	return 0;
}