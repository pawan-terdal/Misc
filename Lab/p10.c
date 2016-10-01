#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *left;
	struct node *right;
};

typedef struct node node;

node * RecClear(node **root)
{
	if (NULL == *root)
	{
		return NULL;
	}
	if ((*root)->left != NULL)
	{
		(*root)->left = RecClear(&((*root)->left));
	}
	if ((*root)->right != NULL)
	{
		(*root)->right = RecClear(&((*root)->right));
	}

	free(*root);
	return NULL;

}
void RecInsert(node **root, node *new)
{

	if (new->val >= (*root)->val)
	{
		if ((*root)->right == NULL)
		{
			(*root)->right = new;
			return;
		}
		else
		{
			RecInsert(&((*root)->right), new);
		}
	}
	else
	{
		if ((*root)->left == NULL)
		{
			(*root)->left = new;
			return;
		}
		else
		{
			RecInsert(&((*root)->left), new);
		}
	}

}

void Insert(node **root, int val)
{
	node *new = (node *)malloc(sizeof(node));
	new->val = val;
	new->left = NULL;
	new->right = NULL;

	if (NULL == *root)
	{
		*root = new;
		return;
	}
	else
	{
		RecInsert(root, new);
	}
}

int Search(node **root, int val)
{
	if (NULL == *root)
	{
		return 0;
	}
	if ((*root)->val == val)
	{
		return 1;
	}
	else if ((*root)->val < val)
	{
		return Search(&((*root)->right), val);
	}
	else
	{
		return Search(&((*root)->left), val);
	}
}

void InOrder(node **root)
{
	if (NULL == *root)
	{
		return;
	}
	InOrder(&((*root)->left));
	printf("%d ", (*root)->val);
	InOrder(&((*root)->right));
}


void PreOrder(node **root)
{
	if (NULL == *root)
	{
		return;
	}
	printf("%d ", (*root)->val);
	PreOrder(&((*root)->left));
	PreOrder(&((*root)->right));
}



void PostOrder(node **root)
{
	if (NULL == *root)
	{
		return;
	}
	PostOrder(&((*root)->left));
	PostOrder(&((*root)->right));
	printf("%d ", (*root)->val);
}


int main()
{
	int choice, n, i, elem;
	node *root = NULL;

	printf("1. Insert N elements.\n");
	printf("2. Inorder Display.\n");
	printf("3. Preorder Display.\n");
	printf("4. Postorder Display.\n");
	printf("5. Binary Search.\n");
	printf("0. Exit.\n");

	while (1)
	{
		printf("Enter choice : ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				root = RecClear(&root);
				printf("Enter number of elements : ");
				scanf("%d", &n);
				printf("Enter %d elements : ", n);
				for (i = 0; i < n; i++)
				{
					scanf("%d", &elem);
					Insert(&root, elem);
				}
				break;
			case 2:
				printf("Inorder : ");
				InOrder(&root);
				printf("\n");
				break;
			case 3:
				printf("Preorder : ");
				PreOrder(&root);
				printf("\n");
				break;
			case 4:
				printf("Postorder : ");
				PostOrder(&root);
				printf("\n");
				break;
			case 5:
				printf("Enter an element to search : ");
				scanf("%d", &elem);
				if (Search(&root, elem))
				{
					printf("Element FOUND.\n");
				}
				else
				{
					printf("Element NOT FOUND.\n");
				}
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Wrong choice.\n");
		}
		printf("**************************************************************\n");
	}

}























