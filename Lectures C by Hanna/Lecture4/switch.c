#include <stdio.h>


int main (void)
{
	int x =4;
	switch (x)
	{
		case 1 :
		case 2 : 
		case 3 : printf("%d\n",x); break;
		case 4 ... 7 : printf("%d\n",x); break;
		default : printf("%d\n",x);
	
	}
	return 0;
}
