#include<stdio.h>
#define MAX 10

typedef struct
{
	int value;
	int row;
	int column;
}Cell;

void ConvertToSparse(int arr[][MAX],int rows,int columns, Cell cells[])
{
	int i,j,k=1,n = 0;
	cells[0].row = rows;
	cells[0].column = columns;

	for(i = 0;i < rows;i++)
	{
		for(j = 0;j < columns;j++)
		{
			if(arr[i][j] != 0)
			{
				cells[k].value = arr[i][j];
				cells[k].row = i;
				cells[k].column = j;
				k++;
				n++;
			}			
		}
	}
	cells[0].value = n;
}

void Transpose(Cell cells[],Cell tcells[])
{
	int i,j,n,k=1;

	n = tcells[0].value = cells[0].value;
	tcells[0].row = cells[0].column;
	tcells[0].column = cells[0].row;

	if(n <= 0)
	{
		return;
	}
	for(i = 0; i < cells[0].column; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(cells[j].column == i)
			{
				tcells[k].value = cells[j].value;
				tcells[k].row = cells[j].column;
				tcells[k].column = cells[j].row;
				k++;
			}
		}
	}
}

void FastTranspose(Cell cells[],Cell tcells[])
{
	int i,j,k=0,n,columns;
	n = tcells[0].value = cells[0].value;
	columns = tcells[0].row = cells[0].column;
	tcells[0].column = cells[0].row;
	
	int columnTerms[columns],startingPos[columns];
	startingPos[0] = 1;
	
	for(i = 0; i < columns; i++)
	{
		columnTerms[i] = 0;
	}
	for(i = 1; i <= n; i++)
	{
		columnTerms[cells[i].column]++;
	}
	for(i = 1; i < columns; i++)
	{
		startingPos[i] = startingPos[i-1] + columnTerms[i-1];
	}
	for(i = 1; i < n; i++)
	{
		j = startingPos[cells[i].column]++;
		tcells[j].value = cells[i].value;
		tcells[j].column = cells[i].row;
		tcells[j].row = cells[i].column;
	}

}

void Display(Cell cells[])
{
	printf("**********************************\n");
	int i;
	for(i = 1 ; i <= cells[0].value ; i++)
        {
                printf("Value : %d; Row : %d; Column : %d\n",cells[i].value,cells[i].row,cells[i].column);
        }

}
int main()
{
	int arr[MAX][MAX];
	Cell cells[MAX*MAX],tcells[MAX*MAX];
	int i,j,rows, columns;
	printf("Rows : ");
	scanf("%d",&rows);
	printf("Columns : ");
	scanf("%d",&columns);
	
	printf("Enter Matrix : \n");
	for(i = 0;i < rows;i++)
	{
		for(j = 0; j < columns; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	
	ConvertToSparse(arr,rows,columns,cells);
	Display(cells);

	Transpose(cells,tcells);
	Display(tcells); 

	FastTranspose(cells,tcells);
	Display(tcells);
}
