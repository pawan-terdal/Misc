#include<stdio.h>
#include<math.h>
#include<malloc.h>

typedef struct node
{
	int co;
	int exp[3];
	struct node *next;
}node;


node * GetHeaderNode()
{
	node *header = (node *)malloc(sizeof(node));
	header->co = 0;
	header->next = header;
	return header;
}


void Insert(node *t, int co, int exp[3])
{
	node *new = (node *)malloc(sizeof(node));
	new->co = co;
	new->exp[0] = exp[0];
	new->exp[1] = exp[1];
	new->exp[2] = exp[2];
	new->next = t->next;
	t->next = new;
}


int IsPresent(node *t, int exp[3])
{
	node *temp = t->next;
	while(temp != t)
	{
		if(temp->exp[0] == exp[0] &&temp->exp[1] == exp[1] &&temp->exp[2] == exp[2])
			return 1;
		temp = temp->next;
	}
	return 0;
}


void PolyAdd(node *p1, node *p2, node *p3)
{
	node *t1 = p1->next;
	node *t2 = p2->next;
	
	while(t1 != p1)
	{
		t2 = p2->next;
		while(t2 != p2)
		{
			if(t1->exp[0] == t2->exp[0] &&t1->exp[1] == t2->exp[1] &&t1->exp[2] == t2->exp[2])
			{
				Insert(p3, t1->co + t2->co, t1->exp);
				break;
			}			
			t2 = t2->next;
		}
		if(!IsPresent(p3, t1->exp))
		{
			Insert(p3, t1->co, t1->exp);
		}
		t1 = t1->next;
	}

	t2 = p2->next;
	while(t2 != p2)
	{
		if(!IsPresent(p3, t2->exp))
		{
			Insert(p3, t2->co, t2->exp);
		}			
		t2 = t2->next;
	}
	
}

void Display(node *t)
{
	node *temp = t->next;
	while(temp != t)
	{
		printf("%d %d %d %d | ", temp->co, temp->exp[0], temp->exp[1], temp->exp[2]);
		temp = temp->next;
	}
	printf("\n");
}
int main()
{
	int n, i, co, exp[3];
	node *p1 = GetHeaderNode();
	node *p2 = GetHeaderNode();
	node *p3 = GetHeaderNode();
	printf("Enter number of terms for first polynomial : ");
	scanf("%d", &n);
	for( i = 0 ; i < n; i++)
	{
		printf("Enter the %d term : ", i + 1);
		scanf("%d%d%d%d", &co, exp, exp + 1, exp + 2);
		Insert(p1, co, exp);
	}
	printf("Enter number of terms for second polynomial : ");
	scanf("%d", &n);
	for( i = 0 ; i < n; i++)
	{
		printf("Enter the %d term : ", i + 1);
		scanf("%d%d%d%d", &co, exp, exp + 1, exp + 2);
		Insert(p2, co, exp);
	}
	PolyAdd(p1,p2,p3);
	Display(p1);
	Display(p2);
	Display(p3);
}
