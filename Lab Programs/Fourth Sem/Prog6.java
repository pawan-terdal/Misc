import java.util.*;
import java.io.*;

class Prog6
{
	public static void Swap(int [] arr, int i, int j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	public static void Swap(float [] arr, int i, int j)
	{
		float temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	public static void SortThree(int weights[], int values[], float valueByWeights[])
	{

		int n = valueByWeights.length;
		for(int i = 0; i < n - 1; i++)
		{
			for(int j = 0; j < n - i - 1; j++)
			{
				if(valueByWeights[j] > valueByWeights[j+1])
				{
					Swap(values, j, j+1);
					Swap(weights, j, j+1);
					Swap(valueByWeights, j, j+1);
				}
			}
		}
	}

	public static float KnapsackGreedy(int weights[], int[] values, int threshold, int sackWeights[])
	{
		float value = 0;
		int currentWeight = 0;
		int n = weights.length;
		float [] valueByWeights = new float[n];
		for(int i = 1; i < n; i++)
		{
			valueByWeights[i] = (float)values[i]/weights[i];
		}
		SortThree(weights, values, valueByWeights);
		for(int i = n-1; i > 0; i--)
		{
			for(int j = 0; j < weights[i]; j++, currentWeight++)
			{
				if(currentWeight == threshold)
				{
					return value;
				}
				sackWeights[i]++;
				value += valueByWeights[i];
			}
		}
		return value;
	}
	public static int Max(int a, int b)
	{
		return (a > b)? a : b;
	}
	public static int FindWeightIndex(int [] weights, int weight)
	{
		for(int i = 0; i < weights.length; i++)
		{
			if(weight >= weights[i])
			{
				return i;
			}
		}
		return 0;
	}
	public static int KnapsackDP(int [][] arr, int [] weights , int [] values , int i, int j)
	{
		if(arr[i][j] != 0)
		{
			return arr[i][j];
		}
		if(i == 0 || j == 0)
		{
			return 0;
		}
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
	public static void FindSackWeights(int [][] arr, int [] weights , int [] values , int i, int j, int sackWeights[])
	{
		if(i == 0 || j ==0)
		{
			return;
		}
		if(arr[i][j] == arr[i-1][j])
		{
			FindSackWeights(arr, weights ,values , i - 1, j, sackWeights);
		}
		else
		{
			sackWeights[i]++;
			FindSackWeights(arr, weights, values, i-1, j-weights[i], sackWeights);
		}
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
		int [] sackWeights = new int[n+1];
		for(int i = 1; i < n + 1; i++)
		{
			weights[i] = in.nextInt();
			values[i] = in.nextInt();
		}
		System.out.println("Enter knapsack threshold weight : ");
		int threshold = in.nextInt();
		int maxweightIndex = FindMaxIndex(weights, threshold);
		int [][] arr = new int[maxweightIndex + 1][threshold + 1];
		System.out.println("\t\t\t\t ---KNAPSACK TABLE DP---");
		System.out.print("\n\t");
		for(int i = 0; i <= threshold; i++)
		{
			KnapsackDP(arr,weights,values,maxweightIndex,i);
			System.out.print(i + "\t");
		}
		System.out.print("\n\t");
		for(int i = 0; i <= threshold; i++)
		{
			System.out.print("-" + "\t");
		}
		for(int i = 0; i <= maxweightIndex; i++)
		{
			System.out.print("\n" + weights[i] + "|\t");
			for(int j = 0; j <= threshold; j++)
			{
				System.out.print(arr[i][j] + "\t");
			}
		}
		System.out.println("\nMaximized Value(DP) \t: " + KnapsackDP(arr,weights,values,maxweightIndex,threshold));
		System.out.print("Sack contains Elements of Weights : " );
		FindSackWeights(arr,weights,values,maxweightIndex,threshold, sackWeights);
		for(int i = 0; i < sackWeights.length; i++)
		{
			if(sackWeights[i] != 0)
			{
				System.out.print(i + "(" + weights[i] +") ");
			}
		}
		sackWeights = new int[n+1];
		System.out.println("\nMaximized Value(Greedy)\t: " + KnapsackGreedy(weights,values,threshold, sackWeights));
		System.out.println("Sack contains : " );
		for(int i = 1; i < sackWeights.length; i++)
		{
			if(sackWeights[i] != 0)
			{
				System.out.println(sackWeights[i] + " pieces of " + (float)values[i]/weights[i] +
					" value. Taken from Weight : " + weights[i] + " Of Value : " + values[i] );
			}
		}
	}
}
