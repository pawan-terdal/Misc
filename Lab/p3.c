#include<stdio.h>
#define MAX 100

int Pop(int arr[] , int *top)
{
	if(*top == -1)
	{
		printf("Underflow.\n");
		return -9999;
	}
	
	*top -= 1;	
	return arr[*top+1];
}

void Push(int arr[], int *top, int elem)
{
	if(*top == MAX - 1)
	{
		printf("Overflow.\n");
	}
	
	arr[++*top] = elem;
	return;
}

void DisplayMenu()
{
	printf("1. Push.\n");
        printf("2. Pop.\n");
	printf("3. Display Stack.\n");
        printf("4. Check If Palindrome.\n");
	printf("5.Exit.\n");
}

void DisplayStack(int arr[],int top)
{
	int i;
	if(top == -1)
	{
		printf("Empty.\n");
		return;
	}
	for(i = top; i>=0; i--)
	{
		printf("%d\n",arr[i]);
	}
	printf("\n");
}

Palindrome(int num)
{
	int i,arr[MAX],top = -1,temp = num,dig = 0,isPalin = 1;
	while(temp != 0)
	{
		Push(arr,&top,temp%10);
		temp/=10;
		dig++;
	}
	temp=num;
	for(i = 0 ; i <= dig/2 ; i++)
	{
		if(temp%10 != Pop(arr,&top))
		{
			isPalin = 0;
			break;
		}
		temp /= 10;
	}
	
	if(isPalin)
	{
		printf("Palindrome.\n");
	}
	else
	{
		printf("Not Palindrome.\n");
	}
		
}

int main()
{
	int arr[MAX],top = -1,choice,elem,num,exit = 0;

	DisplayMenu();
	
	while(1)
	{
		printf("Enter choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1 :
				printf("Enter an element : ");
				scanf("%d",&elem);
				Push(arr,&top,elem);
				break;
			case 2 :
				elem = Pop(arr,&top);
				if(elem != -9999)
				{
					printf("The element popped out : %d\n",elem);
				}
				break;
			case 3 :
				printf("The stack is : \n");
				DisplayStack(arr,top);
				break;
			case 4 :
				printf("Enter A Number : ");
				scanf("%d", &num);
				Palindrome(num);
				break;
			case 5 :
				exit = 1;
				break;
			default :
				printf("Wrong Choice. Try again.\n");
		}
		if(exit == 1)
		{
			break;
		}
	}	
}	
