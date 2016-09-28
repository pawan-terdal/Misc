#include<stdio.h>
#include<stdlib.h>
#define MAX 3  

int count = 0;

void Enqueue(char queue[], int *front, int *rear, char elem)
{
	if(*front == -1)
	{
		count++;
		*front = *rear = 0;
		queue[*rear] = elem;
		return;
	}
	
	if((*rear+1)%MAX == *front)
	{
		printf("Overflow.\n");
		return;
	}
	count++;
	*rear= (*rear+1)%MAX;
	
	queue[*rear] = elem;
}

char Dequeue(char queue[], int *front,int *rear)
{
	char elem;
	
	if(*front == -1)
	{
		printf("Underflow.\n");
		return '\0';
	}
	count--;
	elem = queue[*front];
	
	if(*rear == *front)
	{
		*front = *rear = -1;
		return elem;
	}
	
	*front = (*front+1)%MAX;
	return elem;
}

void Display(char queue[], int front,int rear)
{
	int i;
	int k;
	if(front == -1)
	{
		printf("Oueue Empty.\n");
		return;
	}
	for(i = front, k = 0; k < count; k++,i++)
	{
		printf("%c ",queue[i%MAX]);
	}
	printf("\n");
}

void DisplayMenu()
{
	printf("------------Menu------------\n");
	printf("1. Enqueue an element.\n");
	printf("2. Dequeue an element.\n");
	printf("3. Display a queue.\n");
	printf("4. Exit.\n");
}

int main()
{
	char queue[MAX];
	int front=-1,rear=-1;
	DisplayMenu();
	while(1)
	{
		int choice;
		char elem;
		printf("\nEnter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				getchar();
				fflush(stdin);
				printf("Enter a character : ");
				scanf("%c",&elem);
				Enqueue(queue,&front,&rear,elem);
				break;
			case 2 :
				elem = Dequeue(queue,&front,&rear);
				if(elem != '\0')
				{
					printf("The element Dequeued is : %c\n",elem);
				}
				break;
			case 3 :
				Display(queue,front,rear);
				break;
			case 4 :
				exit(0);
			default :
				printf("Wrong choice. Enter again.\n");
				break;	
		}	
	}
}

