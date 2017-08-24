import java.io.*;
import java.util.*;

class Prog6
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter n :");
        int n = in.nextInt();
        System.out.println("Enter Knapsack weight : ");
        int W = in.nextInt();
        System.out.println("Enter weights and corresponding values");
        int w[] = new int[n];
        int v[] = new int[n];
        float vbyw[] = new float[n];
        int V[][] = new int[n+1][W+1];
        for(int i = 0; i < n; i++)
        {
            w[i] = in.nextInt();
            v[i] = in.nextInt();
            vbyw[i] = v[i]/w[i];
        }
        for(int i = 0; i <=n ; i++)
        {
            for(int j=0; j <=W ; j++)
            {
                if(i==0 || j ==0)
                {
                    V[i][j] = 0;
                    continue;
                }
                else if(j < w[i-1])
                {
                    V[i][j] = V[i-1][j];
                }
                else
                {
                    int a = V[i-1][j];
                    int b = v[i-1] + V[i-1][j - w[i-1]];
                    V[i][j] = (a > b)? a : b;
                }
            }
        }
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= W; j++)
            {
                System.out.print(V[i][j] + " ");
            }
            System.out.println();
        }
        int sackWeights[] = new int[n];
        int i = n;
        int j = W;
        while(i>0 && j>0)
        {
            if(V[i][j] == V[i-1][j])
            {
                i--;
            }
            else
            {
                j = j - w[i-1];
                sackWeights[i-1] = 1;
                i--;
            }
        }
        System.out.println("The sack weights are : ");
        for(i = 0; i < n; i++)
        {
            if(sackWeights[i] != 0)
            {
                System.out.println(w[i]);
            }
        }

    }
}
