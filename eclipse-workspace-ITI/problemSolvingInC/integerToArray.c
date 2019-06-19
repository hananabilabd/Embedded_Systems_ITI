/*
 * integerToArray.c
 *
 *  Created on: Jun 4, 2019
 *      Author: Hanna Nabil
 */


/*
 * test.c
 *
 *  Created on: Jun 4, 2019
 *      Author: Hanna Nabil
 */



#include<stdio.h>
int i;
void convertNumberIntoArray(unsigned int number , char arr[]) {



    do {
        arr[i] = number % 10; // get unit
        number /= 10;
        i++;
    } while (number != 0);
    while (i){
    	i--;
    printf("%d",arr[i]);

    }
}

int main()
{
	printf("Enter Number=");
	unsigned int num;
	scanf("%d",&num);
	char arr[100]={0};
   convertNumberIntoArray(num,arr);


    return 0;
}
