import java.io.*;
import java.util.*;

class Edge
{
    public int src,dest,weight;
    Edge(int src,int dest, int weight)
    {
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }
}
class Prog8
{
    public static int find(int parray[], int node)
    {
        if(parray[node] == -1)
            return node;
        else
            return find(parray, parray[node]);
    }

    public static void Kruskal(ArrayList<Edge> edges, int V)
    {
        Collections.sort(edges, new Comparator<Edge>() {
            @Override
            public int compare(Edge edge1, Edge edge2)
            {
                if(edge1.weight > edge2.weight)
                    return 1;
                else if(edge1.weight < edge2.weight)
                    return -1;
                else
                    return 0;
            }
        });

        int parray[] = new int[V];
        for(int i = 0; i < V; i++)
            parray[i] = -1;

        ArrayList<Edge> solution = new ArrayList<Edge>();

        for(int i = 0; i < edges.size(); i++)
        {
            Edge edge = edges.get(i);
            int parentsrc = find(parray, edge.src);
            int parentdest = find(parray, edge.dest);
            if(parentsrc != parentdest)
            {
                if(parentsrc > parentdest)
                    parray[parentsrc] = parentdest;
                else
                    parray[parentdest] = parentsrc;
                solution.add(edge);
            }
        }

        for(int i = 0; i < V-1; i++)
        {
            Edge edge = solution.get(i);
            System.out.println(edge.src + " " + edge.dest + " " + edge.weight);
        }
    }

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
		int V,E;
		System.out.print("Enter number of vertices: ");
		V = in.nextInt();
		System.out.print("Enter number of Edges: ");
		E = in.nextInt();
		ArrayList<Edge> edges = new ArrayList<>();
		int choice;
		for(int i=0; i<E; i++)
		{
			int src,des,weight;
			System.out.println("Enter Source, Destination, Weight : ");
			src = in.nextInt();
			des = in.nextInt();
			weight = in.nextInt();
			edges.add(new Edge(src,des,weight));
		}
		Kruskal(edges,V);
    }
}
