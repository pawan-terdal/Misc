#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define MAX 100

typedef struct Node
{
	int key;
	char name[20];
}Node;

Node *hashTable[100];

void Clear()
{
	int i;
	for(i = 0; i < MAX; i++)
	{
		if(hashTable[i] != NULL)
		{
			free(hashTable[i]);
		}
		hashTable[i] = NULL;
	}
}

void Display()
{
	int i;
	printf("HASHTABLE : \n");
	for(i = 0; i < MAX; i++)
	{
		if(hashTable[i] != NULL)
		{
			printf("Index Stored : %d\n\tKey : %d\n\tName : %s\n\n", i, hashTable[i]->key, hashTable[i]->name);	
		}
	}
}

Node * Search(int key)
{
	int index = key % MAX;
	int end = index;
	while(hashTable[index] != NULL)
	{
		if(hashTable[index]->key == key)
		{
			return hashTable[index];
		}
		index = (index + 1) % MAX;
		if(index == end)
		{
			return NULL;
		}
	}
	return NULL;
}

void Insert(int key, char name[20])
{
	if(Search(key) != NULL)
	{
		printf("Key isn't unique.\n");
		return;
	}
	Node *n = (Node *)malloc(sizeof(Node));
	n->key = key;
	strcpy(n->name, name);
	
	int index = key % MAX;

	while(1)
	{
		if(hashTable[index] == NULL)
		{
			hashTable[index] = n;
			printf("Element inserted at %d.\n", index);
			break;
		}
		printf("Collision occured at %d. Using Linear Probing.\n", index);
		index = (index + 1) % MAX;
	}
}



int main()
{
	Node *n;
	int choice, key;
	char name[20];
	
	Clear();
	
	printf("1. Insert an Element into HashTable.\n");
	printf("2. Search for an Element in HashTable.\n");
	printf("3. Display HashTable.\n");
	printf("0. Exit.\n");
	
	while(1)
	{
		printf("Enter choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 :
				printf("\tEnter Key : ");
				scanf("%d", &key);
				printf("\tEnter Name : ");
				scanf("%s", name);
				Insert(key, name);	
				break;
			case 2 :
				printf("\tEnter Key : ");
				scanf("%d", &key);
				n = Search(key);
				if(NULL == n)
				{
					printf("Employee Not found.\n");	
				}
				else
				{
					printf("Employee found.\n");
					printf("Key : %d\n", n->key);
					printf("Name : %s\n", n->name);
				}
				break;
			case 3 :
				Display();
				break;
			case 0 :
				exit(1);	
				break;
			default:
				printf("Wrong choice.\n");
				break;
		}
	}
}
