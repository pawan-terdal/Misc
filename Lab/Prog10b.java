import java.io.*;
import java.util.*;

class Prog10b
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter number of vertices");
        int n = in.nextInt();
        System.out.println("Enter cost matrix");
        int tour[] = new int[n+1];
        int c[][] = new int[n+1][n+1];

        for(int i = 1; i <= n; i++)
        {
            tour[i] = i;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j<= n; j++)
            {
                c[i][j] = in.nextInt();
            }
        }

        int cost = tsp(c, tour, 1);
        for(int i = 1; i <= n; i++)
        {
            System.out.print(tour[i] + "-->");
        }
        System.out.println("1");
        System.out.println(cost);
    }

    public static int tsp(int c[][], int tour[], int start)
    {
        int n = tour.length - 1;
        int mintour[] = new int[n+1];
        int mincost = Integer.MAX_VALUE;

        if(start == n - 1)
        {
            return c[tour[n-1]][tour[n]] + c[tour[n]][1];
        }

        for(int i = start + 1; i <= n; i++)
        {
            int temp[] = new int[n+1];
            copy(temp, tour);

            temp[start+1] = tour[i];
            temp[i] = tour[start+1];

            int cost = tsp(c, temp, start + 1);
            if(c[temp[start]][temp[start+1]] + cost < mincost)
            {
                mincost = c[temp[start]][temp[start+1]] + cost;
                copy(mintour, temp);
            }
        }

        copy(tour, mintour);
        return mincost;
    }

    public static void copy(int arr1[], int arr2[])
    {
        for(int i = 0; i < arr1.length; i++)
        {
            arr1[i] = arr2[i];
        }
    }
}
