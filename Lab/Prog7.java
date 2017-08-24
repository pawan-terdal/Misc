import java.io.*;
import java.util.*;

class Prog7
{
    public static int findmin(int visited[], float dist[])
    {
        float min = 1f/0.0f;
        int minVertex = -1;
        for(int i = 0; i < dist.length; i++)
        {
            if(dist[i] < min && visited[i] == 0)
            {
                min = dist[i];
                minVertex = i;
            }
        }
        return minVertex;
    }

    public static void printMST(int parent[], int n, int graph[][])
    {
        System.out.println("Edge   Weight");
        for (int i = 1; i < n; i++)
            System.out.println(parent[i]+" - "+ i+"    "+
                               graph[i][parent[i]]);
    }

    public static void Prim(float matrix[][])
    {
        int V = matrix.length;
        int visited[] = new int[V];
        float dist[] = new float[V];
        int parent[] =  new int[V];
        for(int i = 0; i<V; i++)
            dist[i] = Integer.MAX_VALUE;

        dist[0] = 0;
        parent[0] = -1;

        for(int i = 0; i < V -1; i++)
        {
            int vertex = findmin(visited, dist);
            visited[vertex] = 1;

            for(int j = 0; j < V; j++)
            {
                if(dist[vertex] + matrix[vertex][j] < dist[j] && visited[j] == 0)
                {
                    dist[j] = dist[vertex] + matrix[vertex][j];
                    parent[j] = vertex;
                }
            }
        }

        //printMST(parent, V, matrix);

        for(int i = 0; i < V; i++)
        {
            System.out.print(dist[i] + " ");
        }
    }

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int V = in.nextInt();
        float matrix[][] = new float[V][V];
        for(int i =0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                matrix[i][j] = in.nextInt();
                if(matrix[i][j] == -1)
                    matrix[i][j] = 1f/0.0f;
            }
        }
        Prim(matrix);
    }
}
