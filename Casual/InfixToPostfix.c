#include<stdio.h>
#include<ctype.h>
#define MAX 100

char Pop(char stack[],int *top)
{
	if(*top == -1)
	{
		printf("Underflow.\n");
	}
	*top -= 1;
	return stack[*top + 1];
}

void Push(char stack[], int *top, char elem)
{
	if(*top == MAX - 1)
	{
		printf("Overflow.\n");
	}
	*top += 1;
	stack[*top] = elem;
}

int GetPreference(char ch)
{
	switch(ch)
	{
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
		default :
			return 0;
	}
}

void ConvertToPostfix(char infix[],char postfix[])
{
	char stack[MAX];
	int i=0,j=0,top = -1;

	while(infix[i+1] != '\0')
	{
		int pres,prev;
		char ch = infix[i];
		
		if(isalnum(ch))
		{
			postfix[j] = ch;
			j++;
		}
		else if(ch == ';')
		{
			while(top >= 0)
			{
				postfix[j] = Pop(stack,&top);
				j++;
			}
		}			
		else if(ch == ')')
		{
			while(stack[top] != '(')
			{
				postfix[j] = Pop(stack,&top);
				j++;
			}
			Pop(stack,&top);
		}
		else if(ch == '(')
		{
			Push(stack,&top,ch);
		}
		else
		{
			
			pres = GetPreference(ch);
			prev = GetPreference(stack[top]);
			printf("%d\n",prev);
			while(!(pres>prev))
			{
				postfix[j] = Pop(stack,&top);
				j++;
				prev = GetPreference(stack[top]);					
			}
			Push(stack,&top,ch);
		}
		i++;
	}
	postfix[j] = '\0';		
}

int main()
{
	char infix[MAX],postfix[MAX];
	printf("Infix : ");
	fgets(infix,MAX,stdin);
	
	ConvertToPostfix(infix,postfix);
	
	printf("Postfix : ");
	puts(postfix);
}	
