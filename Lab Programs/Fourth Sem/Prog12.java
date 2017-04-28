import java.io.*;
import java.util.*;

class Prog12
{
	public static boolean Hamilton(int vertex, int matrix[][], int visited[], Stack stack, int count, int vertices)
	{
		visited[vertex]++;
		count++;
		stack.Push(new Integer(vertex));
		if(count == vertices)
		{
			if(matrix[vertex][0] != -1)
			{
				System.out.println("The Hamilton path is : ");
				System.out.print("A, ");
				for(int i = 0; i < count; i++)
				{
					System.out.print((char)(65 + (int) stack.Pop()) + ", ");
				}
				System.out.println();
				return true;
			}
			return false;
		}

		for(int j = 0; j < vertices; j++)
		{
			if(j == vertex)
			{
				continue;
			}
			if(matrix[vertex][j] != -1 && visited[j] == 0)
			{
				if(Hamilton(j, matrix, visited, stack, count, vertices))
				{
					return true;
				}
				visited[j] = 0;
				stack.Pop();
			}
		}
		return false;
	}

	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		System.out.println("Enter number of vertices : ");
		int vertices = in.nextInt();
		int matrix[][] = new int[vertices][vertices];
		System.out.println("Enter NxN adjacency matrix : ");
		for(int i = 0; i < vertices; i++)
		{
			for(int j = 0; j < vertices; j++)
			{
				matrix[i][j] = in.nextInt();
			}
		}
		int visited[] = new int[vertices];
		int count = 0;
		Stack stack = new Stack();
		if(! Hamilton(0, matrix, visited, stack, count, vertices))
		{
			System.out.println("No Hamilton Circuit.");
		}
	}
}
/*
0 1 -1 1 1
1 0 1 -1 -1
-1 1 0 -1 1
1 -1 -1 0 1
1 -1 1 1 0

0 1 -1 -1 1
1 0 1 -1 -1
-1 1 0 -1 1
-1 -1 -1 0 1
1 -1 1 1 0
*/
