#include<stdio.h>
#define MAX 5

float sum(float*,int);

int main()
{
	int i;
	float arr[MAX];
	printf("Enter %d Elements : ",MAX);
	for(i=0;i<MAX;i++)
	{
		scanf("%f",arr + i);
	}
	printf("The sum is : %f\n",sum(arr,MAX));
}

float sum(float *arr,int n)
{
	float sum = 0;
	int i;
	for(i=0;i<n;i++)
	{
		sum += *(arr+i);
	}
	return sum;
}

