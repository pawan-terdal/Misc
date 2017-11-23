import java.util.*;

/**
 * Prog8
 */
public class Prog8 {
  public static void bellmanFord(double matrix[][], double vector[], int n)
  {
    for(int i = 0; i < n - 1; i++) {
      for(int j = 0; j < n; j++) {
        double curr = vector[j];
        for(int k = 0; k < n; k++) {
          if (j != k)
          vector[k] = (vector[k] < curr + matrix[j][k])? vector[k]: curr + matrix[j][k];
        }
      }
    }
    for(int j = 0; j < n; j++) {
      double curr = vector[j];
      for(int k = 0; k < n; k++) {
        if (vector[k] > curr + matrix[j][k]) {
          System.out.println("Negative Cycle Found.");
          return;
        }
      }
    }
    System.out.println("The distance vector from 0 is as follows:");
    for(int i = 0; i < n; i++)
      System.out.print(i + "\t");
    System.out.println();
    for(int i = 0; i < n; i++)
      System.out.print(vector[i] + "\t");
    System.out.println();
  }
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.print("Number of nodes: ");
    int n = in.nextInt();
    double[][] matrix = new double[n][n];
    System.out.println("Enter adjacency matrix: ");
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        int num = in.nextInt();
        if(num == -99.00) {
          matrix[i][j] = 1/0.0;
          continue;
        }
        matrix[i][j] = num;
      }
    }
    double[] vector = new double[n];
    for(int i = 0; i < n; i++) {
      vector[i] = matrix[0][i];
    }

    bellmanFord(matrix, vector, n);
  }
}

/*
No Neg cycle.
6
0  10 -99  -99  -99  8
-99  0  -99  2  -99  -99
-99  1  0  -99  -99 -99
-99 -99  -2 0  -99  -99
-99 -4 -99  -1 0  -99
-99  -99  -99  -99  1  0

Neg cycle.
6
0  10 -99  -99  -99  8
-99  0  -99  -1  -99  -99
-99  1  0  -99  -99 -99
-99 -99  -2 0  -99  -99
-99 -4 -99  -1 0  -99
-99  -99  -99  -99  1  0
*/