
#include<stdio.h>

signed int size=0;
void swap(int *x,int * y){
	int temp= *x;
	*x=*y;
	*y=temp;
}
int mirrorNumber(int num ){
	signed int i=0,j=0,reversed =0 ;
	int arr[100];
	while (num){
		arr[i]=num%10;
		num /= 10;
		i++;
	}
	i--;
	j=i;
	i=0;
	while ( i <=j){
		reversed= (reversed *10) +arr[i];
		printf("%d",arr[i]);
		i++;
	}
	printf("\n--------------------\n");
	return reversed;
}


int main()
{

	int number;
	printf("Enter number=");
	scanf("%d",&number);


	int reversed=mirrorNumber(number);
	printf("Reversed number=%d\n",reversed);

	return 0;
}

