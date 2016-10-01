#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

struct node
{
	int co;
	int exp[3];
	struct node *next;
};

typedef struct node node;

int IsPresent(node **t,int arr[3])
{
	int pos=0;
	node **first = t;
	
	if(*first == NULL)
	{
		return -1;
	}	
	
	node **temp = &((*first)->next);
	do
	{	int i,isPresent = 1;
		for(i = 0; i<3; i++)
		{
			if((*temp)->exp[i] != arr[i])
			{
				isPresent = 0;
				break;
			}
		}
		if(isPresent)
		{
			return pos;
		}
		pos++;
		temp = &((*temp)->next);
	}while(*temp != (*first)->next);
	return -1;
}

int Insert(node **t, int co, int arr[3])
{
	int i;
	node **first = t;
	node *new = (node *)malloc(sizeof(node));
	
	new->next = NULL;
	if(*first == NULL)
	{
		new->co = co;
		for(i = 0; i<3 ; i++)
		{
			new->exp[i] = arr[i];
		}
		*first = new;
		(*first)->next = *first;
	}
	else
	{
		if(IsPresent(t,arr) == -1)
		{
			new->co = co;
			for(i = 0; i<3 ; i++)
			{
				new->exp[i] = arr[i];
			}
			new->next = (*first)->next;
			(*first)->next = new;
			*first = new;	
			return 1;
		}
		else
		{
			return 0;
		}
	}	
}

void Display(node **t)
{
	node **first = t;
	node **temp = &((*first)->next);
	
	if((*first) == NULL)
	{
		printf("Empty List.\n");
		return;
	}
	do
	{
		printf("+(%d x^%d y^%d z^%d) ",(*temp)->co,(*temp)->exp[0],(*temp)->exp[1],(*temp)->exp[2]);
		temp = &((*temp)->next);
	}while(*temp != (*first)->next);
	printf("\n");
}

int CheckExp(int arr1[],int arr2[])
{
	int isEqual = 1;
	int i;
	for(i = 0; i < 3; i++)
	{
		if(arr1[i] != arr2[i])
		{
			isEqual = 0;
			break;
		}
	}
	return isEqual;
}

void PolySum(node **p1, node **p2, node **p3)
{

	if(*p1 == NULL  && *p2	== NULL)
	{
		return;
	}
	else if(*p1 == NULL)
	{
		node **t = &((*p2)->next);
		do
		{
			Insert(p3,(*t)->co,(*t)->exp);
			t = &((*t)->next);					
		}while(*t != (*p2)->next);
		return;
	}
	else if(*p2 == NULL)
	{
		node **t = &((*p1)->next);
		do
		{
			Insert(p3,(*t)->co,(*t)->exp);					
			t = &((*t)->next);					
		}while(*t != (*p1)->next);
		return;
		return;
	}
	node **t1 = &((*p1)->next);
	do
	{
		int done = 0;
		node **t2 = &((*p2)->next);
		
		do
		{
			if(CheckExp((*t1)->exp,(*t2)->exp))
			{
				done = 1;
				Insert(p3,((*t1)->co + (*t2)->co),(*t1)->exp);					
			}
			t2 = &((*t2)->next);	
		}while(*t2 != (*p2)->next);
		
		if(!done)
		{
			Insert(p3,(*t1)->co,(*t1)->exp);			
		}		
		t1 = &((*t1)->next);
	}while(*t1 != (*p1)->next);
	
	node **t2 = &((*p2)->next);

	do
	{		
		Insert(p3,(*t2)->co,(*t2)->exp);
		t2 = &((*t2)->next);	
	}while(*t2 != (*p2)->next);
			
}

void Clear(node **t)
{
	if(*t == NULL)
	{
		return;
	}

	while(*t != NULL)
	{
		if(*t == (*t)->next)
		{
			(*t)->next = NULL;
			free(*t);
			*t = NULL;
			return;
		}
			
		node *temp = (*t)->next;
		(*t)->next = temp->next;
		temp->next = NULL;
		free(temp);
		
	}
	*t = NULL;
}
int main()
{
	node *p1 = NULL, *p2 = NULL, *p3 = NULL;
	int choice, co , exp[3];
	printf("1. Insert To Polynomial 1.\n");
	printf("2. Insert To Polynomial 2.\n");
	printf("3. Display Polynomials.\n");
	printf("4. Add Polynomials 1 and 2 to 3.\n");
	printf("5. Clear Polynomials.\n");
	printf("0. Exit.\n");
	while(1)
	{
		printf("Enter choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1 :
				printf("Enter Co efficient and Powers of x,y,z : ");
				scanf("%d %d %d %d", &co , exp , exp + 1, exp +2);
				if(!Insert(&p1,co,exp))
				{
					printf("Element already present.\n");
				}
				Clear(&p3);
				p3 = NULL;
				break;

			case 2 :
				printf("Enter Co efficient and Powers of x,y,z : ");
				scanf("%d %d %d %d", &co , exp , exp + 1, exp +2);
				if(!Insert(&p2,co,exp))
				{
					printf("Element already present.\n");
				}
				Clear(&p3);
				p3 = NULL;
				break;
			
			case 4 :
				Clear(&p3);
				p3 = NULL;
				PolySum(&p1,&p2,&p3);
				
			case 3 :
				printf("Polynomial 1 : ");
				Display(&p1);
				printf("Polynomial 2 : ");
				Display(&p2);
				printf("Polynomial 3 : ");
				Display(&p3);
				break;

			case 5 :
				Clear(&p1);
				Clear(&p2);
				Clear(&p3);
				p1 = p2 = p3 = NULL;
				printf("Polynomials Reseted.\n");
				break;								
			case 0 :
				exit(1);
		
			default :
				printf("Wrong Choice.\n");
				break;
				
		}
		printf("********************************************************************************\n");
	}
}
