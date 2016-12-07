#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>

struct NODE
{
	int co;
	int ex;
	int ey;
	int ez;
	struct NODE *next;
};

typedef struct NODE node;

node *h1 = NULL;

void Attach(node *);
int Eval();
node *GetHead();

node *GetHead()
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->co = 0;
	newNode->ex = 0;
	newNode->ey = 0;
	newNode->ez = 0;
	newNode->next = newNode;
	return newNode;
}

void main()
{
	h1 = GetHead();
	int ch;
	for(;;)
	{
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
					printf("%d", Eval());
					break;
		}
	}
}

int Eval()
{
	int i, val = 0;
	int x, y, z;
	scanf("%d", &h1->co);
	for(i=0; i<h1->co; i++)
		Attach(h1);
	printf("x,y,z");
	scanf("%d%d%d", &x, &y, &z);
	node *last = h1->next;
	while(last != h1)
	{
		val += last->co * pow(x, last->ex) * pow(y, last->ey) * pow(z, last->ez);
		last = last->next;
	}
	return val;
}

void Attach(node *h)
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->next = h->next;
	h->next = newNode;
	printf("c,x,y,z");
	scanf("%d%d%d%d", &newNode->co, &newNode->ex, &newNode->ey, &newNode->ez);
}
