#include<stdio.h>
#include<malloc.h>

int main()
{
	int *a,*b,n,i;
	
	printf("Enter number of elements : ");
	scanf("%d",&n);
	
	a = malloc(n*sizeof(int));
	b = calloc(n,sizeof(int));
	a = realloc(a,n*sizeof(int));
	for(i = 0; i < n; i++ )
	{
		printf("A[%d] : %d ; B[%d] : %d\n",i,*(a+i),i,*(b+i));
	}	
}
