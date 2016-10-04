#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int a;
	struct node * next;
};

typedef struct node node;

node * Hello(node *first)
{
	printf("[Hello Fn] Addresses : %p\t %p \n", first , first->next);
	first->a = first->next->a = 10;
	printf("[Hello] Values : %d %d \n", first->a , first->next->a);
	first->next->next = (node *)malloc(sizeof(node));
	first->next->next->a = 15;
	return first;
}

node * Lol(node *first)
{
	first = (node *)malloc(sizeof(node));
	printf("address of first :  %p\n",first);
	return first;
}
int main()
{
	node *first = (node *)malloc(sizeof(node));
	first->next = (node *)malloc(sizeof(node));
	first->next->next = 0;
	printf("[Main] Addresses : %p\t %p\t %p \n", first , first->next, first->next->next);
	first->a = first->next->a = 5;
	node *second = Hello(first);
	printf("[Main] Addresses : %p\t %p\t %p \n", first , first->next, first->next->next);
	printf("[Main] Values : %d %d \n", first->a , first->next->a);
	
	if(first->next->next != NULL)
	{
		printf("[Main] : After adding the node : %d \n", first->next->next->a);
	}
	
	printf("[Main] Addresses : %p\t %p \n", second , second->next);
	second->a = 1000;
	printf("Value of first : %d\n", first->a);
	node * third = NULL;
	third = Lol(third);
	printf("address of third : %p\n", third);
}
