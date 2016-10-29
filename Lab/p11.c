#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct node
{
	char name[50];
	struct node *next;
}node;

typedef struct queue
{
	node *front;
	node *rear;
	int n;
}queue;

queue * InitQueue()
{
	queue *myQueue = (queue *)malloc(sizeof(queue));
	myQueue->front = myQueue->rear = NULL;
	return myQueue;
}

void Enqueue(queue *myQueue, char name[50])
{
	node *new = (node *)malloc(sizeof(node));
	strcpy(new->name, name);
	new->next = NULL;
	
	if(myQueue->front == NULL)
	{
		myQueue->front = myQueue->rear = new;
		return;
	}

	myQueue->rear->next = new;
	myQueue->rear = myQueue->rear->next;
}

char * Dequeue(queue *myQueue)
{
	if(myQueue->front == NULL)
	{
		printf("Underflow.\n");
		return "";
	}	
	
	if(myQueue->front == myQueue->rear)
	{
		char *name = myQueue->front->name;
		node *temp = myQueue->front;
		myQueue->front = myQueue->rear = NULL;
		temp->next = NULL;
		free(temp);
		return name;
	}

	char *name = myQueue->front->name;
	node *temp = myQueue->front;
	myQueue->front = myQueue->front->next;
	temp->next = NULL;
	free(temp);	
	return name;
}

void GetDGraph(int dgraph[10][10],queue *cities)
{
	int i,j;
	node *temp = cities->front;
	printf("\t");
	for(i = 0; i < cities->n; i++)
	{
		printf("%s\t", temp->name);
		temp = temp->next;
	}
	printf("\n");

	temp = cities->front;
	for(i = 0; i < cities->n; i++)
	{
		printf("%s\t", temp->name);
		for(j = 0; j < cities->n; j++)
		{
			scanf("%d",&dgraph[i][j]);
		}
		temp = temp->next;
	}
}

int GetIndex(queue *cities, char name[20])
{
	int i;
	node *temp = cities->front;
	for(i = 0; i < cities->n; i++)
	{
		if(!strcmp(temp->name, name))
		{
			return i;
		}
		temp = temp->next;
	}
	
	return -1;
}

char * GetName(queue *myQueue, int index)
{
	node *temp = myQueue->front;
	while(index)
	{
		index--;
		temp = temp->next;
	}

	return temp->name;
}

void DoBFS(queue *visited, queue *cities, queue *myQueue, int dgraph[][10])
{
	while(myQueue->front)
	{
		int i, j;
		printf("%s ",myQueue->front->name);		
		Enqueue(visited, myQueue->front->name);
		visited->n += 1;

		int index = GetIndex(cities, myQueue->front->name);
		
		for(i = 0; i < cities->n; i++)
		{
			if(dgraph[index][i] != 0)
			{
				char *name = GetName(cities, i);
				if(GetIndex(visited,name) == -1 && GetIndex(myQueue,name) == -1)
				{
					Enqueue(myQueue, name);
					myQueue->n += 1;
				}
			}
		}
		Dequeue(myQueue);
		myQueue->n -= 1;
	}
}

void BFS(queue *cities, int dgraph[10][10])
{
	queue *visited = InitQueue(), *myQueue = InitQueue();
	char name[20];
	node *temp = cities->front;
	int i = 0;
	printf("Enter City Name : ");
	scanf("%s",name);
	
	if(GetIndex(cities, name) == -1)
	{
		printf("No City Present Like That.\n");
		return;
	}
	while(temp != NULL)
	{
		if(!strcmp(name,temp->name))
		{			
			Enqueue(myQueue, name);	
			myQueue->n = 1;
		}
		i++;
		temp = temp->next;
	}
	
	printf("The cities which can be visited : ");
	DoBFS(visited,cities,myQueue,dgraph);	
	printf("\n");
}

void DoDFS(char name[20], queue *cities, queue * visited,  int dgraph[10][10])
{
	int i;
	printf("%s ", name);
	int index = GetIndex(cities,name);
	Enqueue(visited, name);
	visited->n += 1;
	for(i = 0; i < cities->n; i++)
	{
		if(dgraph[index][i] != 0)
		{
			strcpy(name, GetName(cities, i));
			if(GetIndex(visited, name) == -1)
			{
				DoDFS(name, cities, visited, dgraph);
			}
		}
	}
}
void DFS(queue *cities, int dgraph[10][10])
{
	int num = 0;
	queue *visited = InitQueue();
    char name[20];
    node *temp = cities->front;
    int i = 0;
    printf("Enter City Name : ");
    scanf("%s",name);
	
	if(GetIndex(cities,name) == -1)
	{
		printf("No City Present Like That. \n");
		return;
	}
	
	printf("The cities which can be visited : ");
	DoDFS(name, cities, visited, dgraph);
	printf("\n");
}
int main()
{
	char name[20];
	queue *cities = InitQueue();
	int dgraph[10][10], n, i;
	int choice;

	printf("1. Create a Graph.\n");
	printf("2. Print all nodes reachable from a given node using BFS.\n");
	printf("3. Print all nodes reachable from a given node using DFS.\n");
	printf("0. Exit\n");
		
	while(1)
	{
		printf("Enter choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 :
				getchar();
				printf("Enter Number Of Cities : ");
				scanf("%d", &n);
				cities->n = n;
				for(i = 0; i < n; i++)
				{
					printf("Name of City %d : ",i);
					scanf("%s",name);
					Enqueue(cities, name);						
				}
				GetDGraph(dgraph, cities);
				break;
			
			case 2 :
				BFS(cities, dgraph);
				break;
			
			case 3 :
				DFS(cities, dgraph);	
				break;
			
			case 0 :
				exit(0);
		
			default :
				printf("Wrong Option.\n");	
		}
	}
}
