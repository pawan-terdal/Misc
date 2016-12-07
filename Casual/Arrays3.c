#include<stdio.h>
#include<malloc.h>

int main()
{
	int **a;
	int *b;
	printf("%lu %lu %lu", sizeof(*a),sizeof(**a), sizeof(*b));
}
