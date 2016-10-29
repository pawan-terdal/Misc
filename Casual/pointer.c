#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int a;
	struct node *next;
}node;

node * GetNode()
{
	node * new = (node *)malloc(sizeof(node));
	new->next = NULL;
	return new;
}

node * Lol(node *first)
{
	if(first == NULL)
	{
		first = GetNode();
		printf("In Func : %p\n",first);
		return first;
	}
	(first)->next = GetNode();
	return first;
}

int main()
{
	node *first = NULL;
	Lol(first);
	printf("%p\n", first);
	Lol(first);
	printf("%p\n",first->next);
}
