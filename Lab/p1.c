#include<stdio.h>
#define MAX 100

int arr[MAX];
int N=-1;

void Create(int n)
{
	int i;
	N=n;
	printf("\nEnter %d Elements : ",N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
}

void Display()
{
	if(N==-1)
	{
		printf("\nCreate an Array first.");
		return;
	}
	int i;
	for(i=0;i<N;i++)
	{
		printf("%d ",arr[i]);
	}
}

void Insert(int elem, int pos)
{
	int i;
	pos--;
	if(N==-1)
	{
		printf("\nCreate an Array first.");
		return;
	}
	if(pos>N || pos<0)
	{
		printf("\nInvalid Position.");
		return;
	}
	if(N==MAX-1)
	{
		printf("\nOverflow detected.");
		return;
	}
	for(i = N; i>=0; i--)
	{
		if(i!=pos)
		{
			arr[i]=arr[i-1];
		}
		else
		{
			arr[i]=elem;
			N++;
			break;
		}		
	} 		
}

void Delete(int pos)
{
	int i;
	pos--;
	if(N==-1)
        {
                printf("\nCreate an Array first.");
                return;
        }
        if(pos>=N || pos<0)
        {
                printf("\nInvalid Position.");
                return;
        }
        if(N==0)
        {
                printf("\nUnderflow detected.");
                return;
        }
	for(i = pos;i<N-1;i++)
	{
		arr[i]=arr[i+1];
	}
	N--;
}

int main()
{
	int choice,a,b,exit=0;
	 printf("\n1.Create An Array.");
         printf("\n2.Display Elements.");
         printf("\n3.Insert an Element.");
         printf("\n4.Delete an Element.");
         printf("\n5.Exit.");

	while(1)
	{
		printf("\nEnter your choice :");
		scanf("%d",&choice);
		

		switch(choice)
		{
			case 1 :
				printf("\nEnter number of elements : ");
				scanf("%d",&a);
				Create(a);
				break;
			case 2 :
				printf("\nThe Array is as follows : ");
				Display();
				break;
			case 3 :
				printf("\nEnter element and position to insert: ");
				scanf("%d %d",&a,&b);
				Insert(a,b);
				break;
			case 4 :
				printf("\nEnter position to delete : ");
				scanf("%d",&b);
				Delete(b);
				break;
			case 5 :
				exit=1;
				break;
			default :
				printf("\nWrong Choice.Enter again.\n");
		}
		if(exit==1)
		{
			break;
		}
		getchar();
		getchar();
	}
}

