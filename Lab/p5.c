#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#define MAX 100

typedef struct
{
	int arr[MAX];
	int top;
}tower;

tower *towerA,*towerB,*towerC;

void Reset(tower *t)
{
	t->top = -1;
}

int Pop(tower *t)
{
	if(t->top == -1)
	{
		printf("Underflow.");
		return -9999;
	}
	t->top--;
	return t->arr[t->top+1];
}

void Push(tower *t, int elem)
{
	if(t->top == MAX - 1)
	{
		printf("Overflow.");
		return;
	} 
	t->top++;
	t->arr[t->top] = elem;
}

void EvaluatePostfix(char postfix[])
{
	tower *t = malloc(sizeof(tower));
	t->top = -1;	
	int i = 0;
	while(postfix[i+1]!='\0')
	{
		char ch = postfix[i];
		if(isdigit(ch))
		{
			Push(t,(int)ch-48);
		}
		else
		{
			int op1 = Pop(t);
			int op2 = Pop(t);
			switch(ch)
			{
				case '^' :
					Push(t,(int)pow(op2,op1));
					break;
				case '/' :
					Push(t,op2/op1);
					break;
				case '*' :
					Push(t,op2*op1);
					break;
				case '%' :
					Push(t,op2%op1);
					break;
				case '+' :
					Push(t,op2+op1);
					break;
				case '-' :
					Push(t,op2-op1);
					break;
				default :
					break;	
			}
		}
		i++;
	}
	printf("The Result of Postfix : %d\n",Pop(t));
	free(t);
}

void Hanoi(char a , char b, char  c, int n)
{
	if(n>0)
	{
		Hanoi(a,c,b,n-1);
		printf("Move Disk %d from Tower %c to Tower %c\n",n,a,c);
		Hanoi(b,a,c,n-1);
	}
}

void DisplayMenu()
{
	printf("------------------MENU--------------\n");
	printf("1. To Evaluate a Postfix Expression.\n");
	printf("2. Solve Tower of Hanoi for n discs.\n");
	printf("3. Exit the program.\n");
}

int main()
{
	int choice,n;
	char postfix[MAX];
	
	DisplayMenu();
	
	while(1)
	{
		printf("Enter your choice : ");
		scanf("%d",&choice);
		getchar();
		switch(choice)
		{
			case 1 :				
				printf("Enter a postfix expression : ");
        			fgets(postfix,MAX,stdin);
				EvaluatePostfix(postfix);
				break;
			case 2 :
				fflush(stdin);
				getchar();
				printf("Enter number of disks : ");
				scanf("%d",&n);
				Hanoi('A','B','C',n);		
				break;
			case 3 :
				exit(0);
			default :
				printf("Wrong choice. Enter again.\n");
		
		}
	}
		
}
