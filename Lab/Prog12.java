import java.io.*;
import java.util.*;

class Prog12
{
    public static void Hamilton(int[][] matrix,int[] visited, int start, int n, String str)
    {
        n++;
        visited[start] = 1;
        str += start+"-";
        if(n == visited.length)
        {
            System.out.println(str + "0");
            return;
        }
        for(int i = 0; i < visited.length; i++)
        {
            if(matrix[start][i] != 0 && visited[i] == 0)
            {
                Hamilton(matrix,visited,i,n,str);
                visited[i] = 0;
            }
        }
    }

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int V = in.nextInt();
        int matrix[][] = new int[V][V];
        for(int i =0; i< V; i++)
        {
            for(int j =0; j< V; j++)
            {
                matrix[i][j] = in.nextInt();
            }
        }
        int visited[] = new int[V];
        Hamilton(matrix, visited, 0,0, "");
    }
}
