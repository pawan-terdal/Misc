#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

char Pop(char stack[],int *top)
{
	if(*top == -1)
	{
		printf("Underflow. Not an infix expression.\n");
		exit(1)	;
	}	
	*top -= 1;
	return stack[*top+1];
}

void Push(char stack[],int *top, char elem)
{
	if(*top == MAX - 1)
	{
		printf("Overflow.\n");
		return;
	}
	*top += 1;
	stack[*top] = elem;
}

int GetPreference(char ch)
{
	switch(ch)
	{
		case ';' :
			return 6;
		case ')' :
			return 5;
		case '^' :
			return 4;
		case '*' :
		case '/' :
		case '%' :
			return 3;
		case '+' :
		case '-' :
			return 2;
		case '(' :
			return 1;
	}
}

ConvertToPostfix(char infix[],char postfix[])
{
	printf("The infix : ");
	puts(infix);
	int i,j = 0,top = -1;
	char stack[MAX];
	for(i = 0; i < strlen(infix) - 1; i++)
	{
		int pres = 0,prev = 0;
		char ch = infix[i];
		
		if(isalnum(ch))
		{
			postfix[j] = ch;
			j++;
			continue;		
		}
		if(ch == ' ')
		{
			continue;
		}
		if(ch == '(')
		{
			Push(stack,&top,ch);
			continue;
		}
		if(top != -1)
		{
			prev = GetPreference(stack[top]);
		}
		pres = GetPreference(ch);
		
		if(pres == 6)
		{
			while(top != -1)
			{
				postfix[j] = Pop(stack,&top);
				j++;
			}
			break;
		}
		else if(pres == 5)
		{
			while(stack[top] != '(')
			{
				postfix[j] = Pop(stack,&top);
				j++;
			}
			Pop(stack,&top);
			continue;
		}
		else if(pres > prev)
		{
			Push(stack,&top,ch);
			continue;
		}
		else
		{
			while( prev >=  pres && top!= -1)
			{
				postfix[j] = Pop(stack,&top);
				prev = GetPreference(stack[top]);
				j++;
			}
			Push(stack,&top,ch);
		}
	}
	postfix[j] = '\0';
}

int main()
{
	char infix[MAX], postfix[MAX];
	printf("Enter an infix expression : ");
	fgets(infix,MAX,stdin);
	
	ConvertToPostfix(infix,postfix);
	
	printf("The postfix is : ");
	
	puts(postfix);
}
