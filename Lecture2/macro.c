#include <stdio.h>
#define printName(f,l) func(f##_##l) 
#define func(x) printf(#x);

int main (void){
	printName(Ahmed,Assaf);
	return 0;
}