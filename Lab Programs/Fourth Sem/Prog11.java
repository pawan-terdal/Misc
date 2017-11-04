import java.io.*;
import java.util.*;

class Prog11
{
	public static int GivenSum = 0;
	public static int NoOfSolutions = 0;
	public static int Sum(int arr[], int position)
	{
		int sum = 0;
		for(int i = 0; i <= position; i++)
		{	
			sum += arr[i];
		}
		return sum;
	}
	public static void Combinations(int offset, int position, int elements[], int array[])
	{
		if(position == array.length)
		{
			return;
		}
		for(int i = offset; i < elements.length; i++)
		{
			array[position] = elements[i];
			Combinations(i + 1, position + 1, elements, array);
			if(Sum(array, position) > GivenSum)
			{
				return;
			}
			if(Sum(array, position) == GivenSum)
			{
				NoOfSolutions++;
				System.out.print("[ ");
				for(int j = 0; j <= position; j++)
				{
					System.out.print(array[j] + " ");
				}
				System.out.println("]");
			}
		}
	}
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		System.out.println("Enter number of elements : ");
		int n = in.nextInt();
		System.out.println("Enter elements : ");
		int elements[] = new int[n];
		int array[] = new int[n];
		for(int i = 0; i < n; i++)
		{
			elements[i] = in.nextInt();
		}
		System.out.println("Enter Subset Sum : ");
		GivenSum = in.nextInt();
		Combinations(0, 0, elements, array);
		if(NoOfSolutions == 0)
		{
			System.out.println("No Subsets Satisfying Conditions.");
		}
	}
}
