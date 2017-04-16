import java.io.*;
import java.util.*;

class Prog9a
{
	public static void Floyds(int matrix[][], int vertices)
	{
		for(int k = 0; k < vertices; k++)
		{
			for(int i = 0; i < vertices; i++)
			{
				for(int j = 0; j < vertices; j++)
				{
					int alternate = 0;
					if(matrix[i][k] == Integer.MAX_VALUE || matrix[k][j] == Integer.MAX_VALUE)
					{
						alternate = Integer.MAX_VALUE;
					}
					else
					{
						alternate = matrix[i][k] + matrix[k][j];
					}
					matrix[i][j] = (matrix[i][j] > alternate)? alternate : matrix[i][j];
				}
			}
		}
	}
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		int vertices;
		System.out.print("Enter number of vertices : ");
		vertices = in.nextInt();
		int matrix[][] = new int[vertices][vertices];
		int floyds[][] = new int[vertices][vertices];
		System.out.println("Enter adjacency matrix for weighted digraph of n * n dimensions.");
		for(int i = 0; i < vertices; i++)
		{
			for(int j = 0; j < vertices; j++)
			{
				matrix[i][j] = in.nextInt();
				if(matrix[i][j] == -1)
				{
					matrix[i][j] = Integer.MAX_VALUE;
				}
				floyds[i][j] = matrix[i][j];
			}
		}
		Floyds(floyds, vertices); 
		System.out.print("Floyds Matrix : \n\t");
		for(int i = 1; i <= vertices; i++)
		{
			System.out.print(i + "\t");
		}
		System.out.print("\n\t");
		for(int i = 1; i <= vertices; i++)
		{
			System.out.print("-\t");
		}
		System.out.println();
		for(int i = 0; i < vertices; i++)
		{
			System.out.print(i+1 + "|\t");
			for(int j = 0; j < vertices; j++)
			{
				if(floyds[i][j] == Integer.MAX_VALUE)
				{
					System.out.print("I\t");
				}
				else
				{
					System.out.print(floyds[i][j] + "\t");
				}
			}
			System.out.println();
		}
	}	
}
/*
0 2 7 -1 13
-1 0 3 15 -1
6 -1 0 2 -1
7 -1 -1 0 9
-1 -1 8 -1 0
*/