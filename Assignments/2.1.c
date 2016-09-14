//Find the length of the circular linked list.

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node *next;
}*first;

typedef struct node node;

void InsertEnd(int value)
{
	node *new = (node *)malloc(sizeof(node));

	if(NULL == new)
	{
		printf("Memory Allocation Failed.\n");
		return;
	}

	new->value = value;
	new->next = NULL;
	
	if(first == NULL)
	{
		first = new;
		first->next = first;
	}
	else
	{
		new->next = first->next;
		first->next = new;
		first = new;
	}
}

void DeleteBeg()
{
	if(NULL == first)
	{
		printf("Underflow.\n");
		return;
	}

	if(first == first->next)
	{
		printf("Element Deleted : %d\n", first->value);
		first->next = NULL;
		free(first);
		first = NULL;	
	}
	else
	{
		node *temp = first->next;
		printf("Element Deleted : %d\n", temp->value);
		first->next = temp->next;
		temp->next = NULL;
		free(temp);
	}
}

void Display()
{
	if(NULL == first)
	{
		printf("No Circular Queue.\n");
	}	
	else
	{
		printf("Circular Queue : ");
		node *temp = first->next;
		do
		{
			printf("%d ",temp->value);
			temp = temp->next;
		}while(temp != first->next);
		printf("\n");
	}
}

void Count()
{
	if(NULL == first)
	{
		printf("Count : 0\n");
	}
	else
	{
		int count = 0;
		node *temp = first;
		do
		{
			count++;
			temp = temp->next;
		}while(temp != first);
		printf("Count : %d\n",count);
	}
}

void DisplayMenu()
{
	printf("1. Insert at End.\n");
	printf("2. Delete at Beginning.\n");
	printf("3. Display Circular Queue.\n");
	printf("4. Number Of Elements.\n");
	printf("5. Exit.\n");
}

int main()
{
	int choice, value;
	first = NULL;

	DisplayMenu();

	while(1)
	{
		printf("Enter choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1 :
				printf("Enter Element : ");
				scanf("%d", &value);
				InsertEnd(value);
				break;
			case 2 :
				DeleteBeg();
				break;
			case 3 :
				Display();
				break;
			case 4 :
				Count();
				break;
			case 5 :
				printf("Exiting Program.\n");
				exit(0);
				break;
			default :
				printf("Wrong Choice.\n");
				break;
		}
		printf("--------------------\n");
	}
}

