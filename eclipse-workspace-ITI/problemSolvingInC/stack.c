/*
 * stack.c
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
#include <stdlib.h>
typedef struct {
	unsigned int capacity;
	signed int top;
	int *arr;
}Stack;

 Stack * createStack(unsigned int capacity)
{
Stack * stack = (Stack*)malloc(sizeof(Stack)*1);
(*stack).top=-1;
stack->capacity=capacity;
stack->arr  =(int*)malloc(sizeof(int) *capacity);
return stack;
}
int IsFull(Stack * stack){
	return stack->top == stack->capacity -1;
}
int IsEmpty(Stack * stack){
	return stack->top == -1;
}
int push (Stack *stack , int item){
	unsigned char Local_u8ErrorState=0;
	if (IsFull(stack) == 1){
		return ++Local_u8ErrorState;
	}
	else {
		stack->top++;
		stack->arr[stack->top]=item;
		printf("%d pushed to stack\n", item);
	}
	return Local_u8ErrorState;
}
int pop(Stack *stack , int * ptr){
	char Local_u8ErrorState=0;
	if (IsEmpty(stack)){
		return ++Local_u8ErrorState;
	}
	else {
		*ptr = stack->arr[stack->top];
		stack->top--;
	}
	return Local_u8ErrorState;
}
int main()
{
	Stack *stack=createStack(100);
	push(stack, 10);
	    push(stack, 20);
	    push(stack, 30);
	    int t;
	    pop(stack,&t);
	    printf("%d popped from stack\n",t );


    return 0;
}
