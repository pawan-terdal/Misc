import java.util.*;
import java.io.*;

class Prog6
{
	public static float KnapsackGreedy(int weights[], int[] values)
	{
		int [] valueByWeights = new int[n - 1];
	}
	public static int Max(int a, int b)
	{
		return (a > b)? a : b;
	}
	public static int KnapsackDP(int [][] arr, int [] weights , int [] values , int i, int j)
	{
		if(i == 0 || j == 0)
		{
			return 0;
		}
		System.out.println(i + " " + j);
		if(j < weights[i])
		{
			arr[i][j] = KnapsackDP(arr,weights,values,i-1,j);
		}
		else
		{
			arr[i][j] = Max(KnapsackDP(arr,weights,values,i-1,j),values[i] + KnapsackDP(arr, weights, values, i-1, j-weights[i]));
		}
		return arr[i][j];
	}

	public static int FindMaxIndex(int [] arr,int max)
	{
		for(int i = arr.length - 1; i >= 1; i--)
		{
			if(arr[i] <= max)
			{
				return i;
			}
		}
		return -1;
	}

	public static void main(String args[])
	{
		int n;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter number of weight/value pairs  : ");
		n = in.nextInt();
		System.out.println("Enter weights (in ascending order) and corresponding values : ");
		int [] weights = new int[n+1];
		int [] values = new int[n+1];
		for(int i = 1; i < n + 1; i++)
		{
			weights[i] = in.nextInt();
			values[i] = in.nextInt();
		}
		System.out.println("Enter knapsack threshold weight : ");
		int threshold = in.nextInt();
		int maxweightIndex = FindMaxIndex(weights, threshold);
		int [][] arr = new int[maxweightIndex + 1][threshold + 1];
		System.out.println("Maximized Value(DP) : " + KnapsackDP(arr,weights,values,maxweightIndex,threshold));
	}
}