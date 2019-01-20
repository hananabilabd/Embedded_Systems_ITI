#include <stdio.h>
#include "typedef.h"
typedef struct employee {
    u32 x ;
};
typedef struct employee employee ;

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
    int count  =0;
    Employee emp ={1,2,3};
    scanf("%d",&count);
    int *arr =(int*)malloc(count *sizeof(int));

    employee * p=(employee*) malloc (n*sizeof(employee));

    for (int i=0 ; i<count ; i++){
        scanf("%d",&arr[i]);

    }
	int r1=add(count,emp);
	printf("result=%d\n",r1);



	return 0;
}
