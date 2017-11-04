import java.io.*;
import java.util.*;

class Prog10a
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        float matrix[][] = new float[n+1][n+1];
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                matrix[i][j] = in.nextInt();
                if(matrix[i][j] == -1)
                {
                    matrix[i][j] = 1.0f/0.0f;
                }
            }
        }

        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j< n; j++)
                {
                    float a = matrix[i][j];
                    float b = matrix[i][k] + matrix[k][j];
                    matrix[i][j] = (a > b)? b : a;
                }
            }
        }

        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
