#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MAX 10

void GetMatrix(int matrix[][MAX], int n)
{
	printf("Enter Matrix : \n");
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
}

void Push(int queue[], int *front, int *rear, int elem)
{
	if(*rear == MAX)
	{
		printf("Overflow\n.");
		return;
	}	
	queue[(*rear)++] = elem;
}

int Pop(int queue[], int *front, int *rear)
{
	if(*front == *rear)
	{
		return -1;
	}
	*front += 1;
	return queue[*front - 1];
}

void BFS(int matrix[][10], int start, int n)
{
	int i;
	int visited[11];
	int queue[11], front = 0, rear = 0;
	
	for(i = 0; i < n; i++)
	{
		visited[i] = 0;
	}
	Push(queue, &front, &rear, start);
	
	printf("Output : ");
	while(1)
	{
		int node = Pop(queue, &front, &rear);
		
		if(node == -1)
		{
			break;
		}

		printf("%d ", node);
		visited[node]++;
		
		for(i = 0; i < n; i++)
		{
			if(matrix[node][i] == 1 && visited[i] == 0)
			{
				Push(queue, &front, &rear, i);
				visited[i]++;
			}
		}
	}	
}

void DoDFS(int matrix[][10], int visited[], int start,int n)
{
	int i;
	printf("%d ", start);
	visited[start]++;
		
	for(i = 0; i < n; i++)
	{
		if(matrix[start][i] == 1 && visited[i] == 0)
		{
			DoDFS(matrix, visited, i, n);
		}		
	}	


}
void DFS(int matrix[][10], int start, int n)
{
	int i;
	int visited[10];
	
	for(i = 0; i < n; i++)
	{
		visited[i] = 0;
	}
	
	DoDFS(matrix, visited, start, n);		
		
}

int main()
{
	int choice, matrix[10][10], n;
	while(1)
	{
		int num;
		printf("Enter choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 :
				printf("Enter Number of Elements : ");
				scanf("%d", &n);
				GetMatrix(matrix, n);
				break;
			case 2 :
				printf("Enter Start : ");
				scanf("%d", &num);
				BFS(matrix, num, n);
				break;	
			case 3 :
				printf("Enter Start : ");
				scanf("%d", &num);
				DFS(matrix, num, n);
				break;	
		}
	}
}
