#include<stdio.h>
#define MAX 100

int Pop(int stack[],int *top)
{
	if(*top == -1)
	{
		printf("Underflow.\n");
		return;
	}
	*top -= 1;
	return stack[*top + 1];
}

void Push(int stack[], int *top, int elem)
{
	if(*top == MAX -1)
	{
		printf("Overflow.\n");
		return;
	}
	*top += 1;
	stack[*top] = elem;
}


