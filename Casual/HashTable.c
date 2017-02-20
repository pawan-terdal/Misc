#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct Node
{
	int key;
	char name[20];
}Node;

Node *hashTable[100];

void Clear(int m)
{
	int i;
	for(i = 0; i < m; i++)
	{
		if(hashTable[i] != NULL)
		{
			free(hashTable[i]);
		}
		hashTable[i] = NULL;
	}
}

void Insert(int m, int key, char name[20])
{
	Node *n = (Node *)malloc(sizeof(Node));
	n->key = key;
	strcpy(n->name, name);

	int index = key % m;

	while(1)
	{
		if(hashTable[index] == NULL)
		{
			hashTable[index] = n;
			printf("Element inserted at %d.\n", index);
			break;
		}
		index = (index + 1)%m;
	}
}

Node * Search(int m, int key)
{
	int index = key % m;

	while(hashTable[index] != NULL)
	{
		if(hashTable[index]->key == key)
		{
			return hashTable[index];
		}
		index = (index + 1) % m;
	}
	return NULL;
}


int main()
{
	int m = 100;
	Clear(m);
	Insert(m, 199, "Nithin");
	Insert(m, 299, "Reddy");
	Insert(m, 4, "PG");
	Insert(m, 200, "Ankush");
	Node * n = Search(m, 199);
	printf("Name : %s\n", n->name);
	n = Search(m, 299);
	printf("Name : %s\n", n->name);
	n = Search(m, 4);
	printf("Name : %s\n", n->name);
	n = Search(m, 200);
	printf("Name : %s\n", n->name);

}
