//Program to Reverse Singly Linked List.

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node *next;
}*x;

typedef struct node node;

void InsertEnd(node **first, int value)
{
	node *new = (node *)malloc(sizeof(node));

	if(new == NULL)
	{
		printf("Memory Allocation Failed.");
		return;
	}

	new->value = value;
	new->next = NULL;

	if(NULL == *first)
	{
		*first = new;
	}
	else
	{
		node *temp = *first;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}

void DeleteBeg(node **first)
{
	if(NULL == *first)
	{
		printf("Underflow.\n");
	}
	else
	{
		node *temp = *first;
		*first = (*first)->next;
		printf("Deleted Value : %d\n", temp->value);
		free(temp);
	}
}

void Display(node **first)
{
	if(NULL == *first)
	{
		printf("Empty.\n");
	}
	else
	{
		node *temp = *first;
		while(temp != NULL)
		{
			printf("%d ", temp->value);
			temp = temp->next;
		}
		printf("\n");
	}
}

node** Reverse(node **first)
{
	if(NULL == *first)
	{
		return NULL;
	}
	if((*first)->next == NULL)
	{
		x = *first;
		return first;
	}
	node **temp = first;
	node **ret = Reverse(&((*temp)->next));
	(*ret)->next = *first;
	return first;
}
int main()
{
	int choice, value;
	node *f1 = NULL, **ret;

	printf("1. Insert End.\n");
	printf("2. Delete Beginning.\n");
	printf("3. Display List.\n");
	printf("4. Reverse List.\n");
	printf("5. Exit.\n");

	while(1)
	{
		printf("Enter choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1 :

				printf("Enter value : ");
				scanf("%d",&value);
				InsertEnd(&f1,value);
				break;
			case 2 :
				DeleteBeg(&f1);
				break;
			case 3 :
				printf("List : ");
				Display(&f1);
				break;
			case 4 :
				ret = Reverse(&f1);
				if(ret != NULL)
				{
					(*ret)->next = NULL;
					f1 = x;
					x = NULL;
				}
				printf("Reversed Successfully.\n");
				break;
			case 5 :
				printf("Exiting Program.\n");
				exit(0);
				break;
			default :
				printf("Wrong Choice.\n");
				break;
		}
		printf("--------------------------------\n");
	}
}
