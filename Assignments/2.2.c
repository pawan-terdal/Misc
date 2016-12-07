// Program to Concatenate Two Linked Lists.

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node *next;
};

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

void Join(node **ptr1, node **ptr2)
{
	if(*ptr2 != NULL)
	{
		if(*ptr1 != NULL)
		{
			node *temp = *ptr1;
			
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = *ptr2;
		}
		else
		{
			*ptr1 = *ptr2;
		}

		*ptr2 = NULL;
	}
	printf("Join Successful.\n");
}

int main()
{
	int choice, value;
	node *f1 = NULL, *f2 = NULL;
	
	printf("1. Insert End.\n"); 
	printf("2. Delete Beginning.\n"); 
	printf("3. Display Lists.\n"); 
	printf("4. Join Lists.\n");
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
				
				printf("\t1. First List.\n");
				printf("\t2. Second List.\n");
				printf("\tEnter choice : ");
				scanf("%d", &choice);
				
				if(choice == 1)
				{
					InsertEnd(&f1,value);
				}
				else if(choice == 2)
				{
					InsertEnd(&f2,value);
				}
				else
				{
					printf("Wrong Choice.\n");
				}
				break;
			case 2 :
				
				printf("\t1. First List.\n");
                printf("\t2. Second List.\n");
                printf("\tEnter choice : ");
                scanf("%d", &choice);

                if(choice == 1)
                {
					DeleteBeg(&f1);
                }
                else if(choice == 2)
                {
					DeleteBeg(&f2);
                }
                else
                {
                    printf("Wrong Choice.\n");
                }
				break;
			case 3 :
				printf("First List : ");
				Display(&f1);
				printf("Second List : ");
				Display(&f2);
				break;
			case 4 :
				Join(&f1,&f2);
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

