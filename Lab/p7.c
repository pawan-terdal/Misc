#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct
{
	char usn[12];
	char name[20];
	char branch[25];
	int sem;
	char phNo[12];
}student;

struct node
{
	student s;
	struct node *next;
}*first;
typedef struct node node;

void InsertBeg(student s, int *count)
{
	*count += 1;
	fflush(stdin);
	node *new = (node *)malloc(sizeof(node));
	if (new == NULL)
	{
		printf("Memory allocation failed.");
	}
	new->s = s;
	new->next = NULL;

	if (first == NULL)
	{
		first = new;
	}
	else
	{
		new->next = first;
		first = new;
	}
}

void InsertEnd(student s, int *count)
{
	*count += 1;
	fflush(stdin);
	node *new = (node *)malloc(sizeof(node));

	if (new == NULL)
	{
		printf("Memory allocation failed.");
	}
	new->next = NULL;
	new->s = s;

	if (first == NULL)
	{
		first = new;
	}
	else
	{
		node *temp = first;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}

void DeleteBeg(int *count)
{
	if (first == NULL)
	{
		printf("Underflow.\n");
		return;
	}
	*count -= 1;
	node *temp = first;
	first = first->next;
	free(temp);
}
void DeleteEnd(int *count)
{
	if (first == NULL)
	{
		printf("Underflow.\n");
		return;
	}
	*count -= 1;
	node *temp1 = first;
	node *temp2 = first->next;
	while (temp2->next != NULL)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	temp1->next = NULL;
	free(temp2);
}

void DisplayMenu()
{
	printf("------------Menu-------------\n");
	printf("1. Insert N Students.\n");
	printf("2. Insert At Beginning.\n");
	printf("3. Insert At End.\n");
	printf("4. Delete At Beginning\n");
	printf("5. Delete At End.\n");
	printf("6. Display.\n");
	printf("7. Use As Stack.\n");
	printf("8. Use As Queue.\n");
	printf("9. Exit.\n");
}

void GetStudentDetails(student *s)
{
	getchar();
	fflush(stdin);
	printf("Enter USN : ");
	fgets(s->usn, 12, stdin);
	printf("Enter Name : ");
	fgets(s->name, 20, stdin);
	printf("Enter Branch : ");
	fgets(s->branch, 25, stdin);
	printf("Enter Sem : ");
	scanf("%d", &s->sem);
	fflush(stdin);
	getchar();
	printf("Enter Phone Number : ");
	fgets(s->phNo, 12, stdin);
}

void PrintStudentDetails(student s)
{
	printf("USN : ");
	printf("%s", s.usn);
	printf("Name : ");
	printf("%s", s.name);
	printf("Branch : ");
	printf("%s", s.branch);
	printf("Sem : ");
	printf("%d", s.sem);
	printf("\nPhone Number : ");
	printf("%s", s.phNo);
	printf("*****************\n");
}

void AddStudents(int n, int *count)
{
	int i;
	for (i = 0; i < n; i++)
	{
		student s;
		GetStudentDetails(&s);
		InsertEnd(s, count);
	}
}

void DisplayStudents(int count)
{
	printf("Count : %d\n", count);
	printf("*****************\n");
	node *temp = first;
	while (temp != NULL)
	{
		PrintStudentDetails(temp->s);
		temp = temp->next;
	}
}

int main()
{
	int n;
	student s;
	first = NULL;

	DisplayMenu();
	int count = 0;
	while (1)
	{
		int choice;
		student s;
		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				printf("Enter number of students : ");
				scanf("%d", &n);
				AddStudents(n, &count);
				break;
			case 2:
				GetStudentDetails(&s);
				InsertBeg(s, &count);
				break;
			case 3:
				GetStudentDetails(&s);
				InsertEnd(s, &count);
				break;
			case 4:
				DeleteBeg(&count);
				break;
			case 5:
				DeleteEnd(&count);
				break;
			case 6:
				printf("The Students are as follows : \n");
				DisplayStudents(count);
				break;
			case 7:
				printf("\t1. Push\n\t2. Pop\n\tEnter : ");
				scanf("%d", &n);
				if (n == 1)
				{
					GetStudentDetails(&s);
					InsertBeg(s, &count);
				}
				else if (n == 2)
				{
					DeleteBeg(&count);
				}
				else
				{
					printf("Wrong Option.\n");
				}
				break;
			case 8:
				printf("\t1. Enqueue\n\t2. Dequeue\n\tEnter : ");
				scanf("%d", &n);
				if (n == 1)
				{
					GetStudentDetails(&s);
					InsertEnd(s, &count);
				}
				else if (n == 2)
				{
					DeleteBeg(&count);
				}
				else
				{
					printf("Wrong Option.\n");
				}
				break;
			case 9:
				exit(0);
			default:
				printf("Wrong choice.\n");
				break;

		}
		printf("************************************************************\n");

	}
}
