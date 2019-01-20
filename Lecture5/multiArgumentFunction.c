#include <stdio.h>
#include "typedef.h"
u32 add (u32 count, ...){
    u32 *ptr = &count ;
    u32 result =0;
    u8 i;
    for (i=0 ; i<count ;i++){
        ptr ++;
        result =result + *ptr ;
    }
    return result;
}
int main (void)
{

	int r1=add(2,3,4);
	printf("r1=%d\n",r1);
	int r2=add(3,3,4,5);
	printf("r2=%d\n",r2);
	int r3=add(4,3,4,5,6);
	printf("r3=%d\n",r3);

	return 0;
}
