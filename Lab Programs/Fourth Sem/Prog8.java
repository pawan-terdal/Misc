import java.io.*;
import java.util.*;

class Edge
{
	public int sv;
	public int ev;
	public int dist;
	Edge(int sv, int ev, int dist)
	{
		this.sv = sv;
		this.ev = ev;
		this.dist = dist;
	}
}
class Prog8
{
	public static int curr = 1;

	public static void Swap(int edges[][], int i, int j, int k)
	{
		int temp = edges[i][k];
		edges[i][k] = edges[j][k];
		edges[j][k] = temp;
	}
	public static void Sort(int edges[][])
	{
		for(int i = 0; i < edges.length - 1; i++)
		{
			for(int j = i+1; j < edges.length; j++)
			{
				if(edges[j][2] < edges[i][2])
				{
					Swap(edges, i,j,0);
					Swap(edges, i,j,1);
					Swap(edges, i,j,2);
				}
			}
		}
	}
	public static boolean IsAcyclic(int freq[], int vertices, int start, int end)
	{ 
		if((freq[start] == 0 && freq[end] == 0))
		{
			freq[start] = freq[end] = curr;
			curr++;
			return true;
		}
		if(freq[start] != freq[end])
		{
			int max = (freq[start] > freq[end])? freq[start] : freq[end];
			int min = (freq[start] < freq[end])? freq[start] : freq[end];
			int minIndex = (freq[start] < freq[end])? start : end;
			if(min == 0)
			{
				freq[minIndex] = max;
			}
			else
			{
				for(int i = 0; i < vertices; i++)
				{
					if(freq[i] == min)
					{
						freq[i] = max;
					}
				}
			}
			return true;
		}
		return false;
	}

	public static ArrayList<Edge> Kruskals(int edges[][], int vertices)
	{
		Sort(edges);
		int freq[] = new int[vertices];
		ArrayList<Edge> presentEdges = new ArrayList<Edge>();
		int i = 0;
		int ecounter = 0;
		while(ecounter < vertices - 1)
		{
			if(IsAcyclic(freq, vertices, edges[i][0], edges[i][1]))
			{
				presentEdges.add(new Edge(edges[i][0], edges[i][1], edges[i][2]));
				ecounter++;
			}
			i++;
		}
		return presentEdges;

	}
	public static void main(String args[])
	{
		int count = 0;
		Scanner in = new Scanner(System.in);
		int vertices;
		System.out.print("Enter number of vertices : ");
		vertices = in.nextInt();
		int matrix[][] = new int[vertices][vertices];
		
		System.out.println("Enter adjacency matrix for weighted digraph of n * n dimensions.");
		for(int i = 0; i < vertices; i++)
		{
			for(int j = 0; j < vertices; j++)
			{
				matrix[i][j] = in.nextInt();
				if(matrix[i][j] != -1 && i > j)
				{
					count++;
				}
			}
		}
		int ecounter = 0;
		int edges[][] = new int[count][3];
		for(int i = 0; i < vertices; i++)
		{
			for(int j = 0; j < vertices; j++)
			{
				if(matrix[i][j] != -1 && i > j)
				{
					edges[ecounter][0] = i;
					edges[ecounter][1] = j;
					edges[ecounter][2] = matrix[i][j];
					ecounter++;
				}
			}
		}
		ArrayList<Edge> presentEdges = Kruskals(edges,vertices);
		for(int i = 0; i < presentEdges.size(); i++)
		{
			System.out.println("Starting Vertex : " + presentEdges.get(i).sv +
								" Ending Vertex : " + presentEdges.get(i).ev +
								" Distance : " + presentEdges.get(i).dist);
		}
	}
}
