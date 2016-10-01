#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct
{
	char ssn[20];
	char name[20];
	char dept[20];
	char desg[20];
	int sal;
	char phNo[20];
}Employee;

struct node
{
	Employee e;
	struct node *right;
	struct node *left;	
}*first = NULL,*last = NULL;

typedef struct node node;

void InsertBeg(Employee e, int *count)
{
	node *new = (node *)malloc(sizeof(node));
	if(NULL == new)
	{
		printf("Memory Allocation Failed.\n");
		return;
	}
	*count += 1;
	new->e = e;
	new->right = NULL;
	new->left = NULL;
	
	if(NULL == first)
	{
		first = last = new;
	}
	else
	{
		new->right = first;
		first->left = new;
		first = new;
	}
} 

void InsertEnd(Employee e, int *count)
{
	
	node *new = (node *)malloc(sizeof(node));
	if(NULL == new)
	{
		printf("Memory Allocation Failed.\n");
		return;
	}
	*count += 1;
	new->e = e;
	new->right = NULL;
	new->left = NULL;
	
	if(NULL == first)
	{
		first = last = new;
	}
	else
	{
		new->left = last;
		last->right = new;
		last = new;
	}
}

void DeleteBeg(int *count)
{
	if(NULL != first)
	{
		*count -= 1;
		node *temp = first;
		if(NULL == first->right)
		{
			first = last = NULL;
			temp->right = NULL;
			temp->left = NULL;
			free(temp);
		}
		else
		{
			first = first->right;
			first->left = NULL;
			temp->right = NULL;
			free(temp);
		}
	}
}


void DeleteEnd(int *count)
{
	if(NULL != last)
	{
		*count -= 1;
		node *temp = last;
		if(NULL == last->left)
		{
			first = last = NULL;
			temp->left = NULL;
			temp->right = NULL;
			free(temp);
		}
		else
		{
			last = last->left;
			last->right = NULL;
			temp->left = NULL;
			free(temp);
		}
	}
}

void DisplayMenu()
{
	printf("------------Menu-------------\n");
	printf("1. Insert N Employees.\n");
	printf("2. Insert At Beginning.\n");
	printf("3. Insert At End.\n");
	printf("4. Delete At Beginning\n");
	printf("5. Delete At End.\n");
	printf("6. Display.\n");
	printf("7. Use As Double Ended Queue(Output Restricted).\n");
	printf("8. Exit.\n");
}

void GetEmployeeDetails(Employee *e)
{
	getchar();
	fflush(stdin);
	printf("Enter SSN : ");
	fgets(e->ssn,20,stdin);
	printf("Enter Name : ");
	fgets(e->name,20,stdin);
	printf("Enter Department : ");
	fgets(e->dept,20,stdin);
	printf("Enter Designation: ");
	fgets(e->desg,20,stdin);
	printf("Enter Salary : ");
	scanf("%d",&e->sal);
	fflush(stdin);
	getchar();
	printf("Enter Phone Number : ");
	fgets(e->phNo,20,stdin); 
}

void PrintEmployeeDetails(Employee e)
{
	printf("SSN : ");
	printf("%s",e.ssn);
	printf("Name : ");
	printf("%s",e.name);
	printf("Department : ");
	printf("%s",e.dept);
	printf("Designation: ");
	printf("%s",e.desg);
	printf("Salary : %d\n",e.sal);
	printf("Enter Phone Number : ");
	printf("%s",e.phNo); 
}

void AddEmployees(int n,int *count)
{
	int i;
	for(i = 0; i < n;i++)
	{		
		Employee e;
		GetEmployeeDetails(&e);
		InsertEnd(e,count);		
	}
}

void DisplayEmployeesRight(int count)
{
	printf("Count : %d\n",count);
	printf("*****************\n"); 
	node *temp = first;
	while(temp != NULL)
	{
		PrintEmployeeDetails(temp->e);
		temp = temp->right;
        	printf("*****************\n");
	}
}

void DisplayEmployeesLeft(int count)
{
        printf("Count : %d\n",count);
        printf("*****************\n");
        node *temp = last;
        while(temp != NULL)
        {
                PrintEmployeeDetails(temp->e);
                temp = temp->left;
        	printf("*****************\n");
        }
}

int main()
{
	int n;
	first = NULL;
	last = NULL;
	
	DisplayMenu();
	int count = 0;		
	while(1)
	{
		int choice;
		Employee e;
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1 :
				printf("Enter number of Employees : ");
				scanf("%d",&n);
				AddEmployees(n,&count);
				break;
			case 2 :
				GetEmployeeDetails(&e);
				InsertBeg(e,&count);
				break;		
			case 3 :		
				GetEmployeeDetails(&e);
				InsertEnd(e,&count);
				break;
			case 4 :
				DeleteBeg(&count);
				break;
			case 5 :
				DeleteEnd(&count);
				break;		
			case 6 :
				printf("\t1. DisplayTowardsRight\n\t2. DisplayTowardsLeft\n\tEnter :");
				scanf("%d",&n);
				if(n == 1)
				{
					printf("The Employees are as follows(Left to Right) : \n");
					DisplayEmployeesRight(count);
				}
				else if(n == 2)
				{
					printf("The Employees are as follows(Right to Left) : \n");
					DisplayEmployeesLeft(count);
				}
				else
				{
					printf("Wrong Choice\n");
					break;
				}
				break;
			case 7 :
				printf("\t1. Enqueue Front\n\t");
				printf("2. Enqueue Rear\n\t3. Dequeue Front\n\tEnter :");
				scanf("%d",&n);
				if(n == 1)
				{
					GetEmployeeDetails(&e);
                                	InsertBeg(e,&count);                              
				}
				else if(n == 2)
				{
					GetEmployeeDetails(&e);
                               		InsertEnd(e,&count);
				}
				else if(n == 3)
				{
					DeleteBeg(&count);
				}
				else
				{
					printf("Wrong Choice\n");
					break;
				}
				break;				
			case 8 :
				exit(0);
			default :
				printf("Wrong choice.\n");
			break;
				
		}	
		printf("*****************************************************\n");	
	}
}
