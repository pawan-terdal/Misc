import java.io.*;
import java.util.*;

class Prog5
{
	public static void MergeSort(int [] arr, int p, int r)
	{
		if(p < r)
		{
			int q = (p + r)/2;			
			MergeSort(arr,p,q);
			MergeSort(arr,q + 1,r);
			Merge(arr,p,q,r);			
		}
		
	}

	public static void Merge(int [] arr, int p, int q, int r)
	{
		int n = r - p + 1;
		int n1 = q - p + 1;
		int n2 = r - q;
		int [] arr1 = new int[n1 + 1];
		int [] arr2 = new int[n2 + 1];

		for(int i = 0; i < n1; i++)
		{
			arr1[i] = arr[p + i];
		}
		arr1[n1] = Integer.MAX_VALUE;

		for(int i = 0; i < n2; i++)
		{
			arr2[i] = arr[q + i + 1];
		}
		arr2[n2] = Integer.MAX_VALUE;

		int j = 0, k = 0;
		for(int i = 0; i < n; i++)
		{
			if(arr1[j] < arr2[k])
			{                    
				arr[p + i] = arr1[j++];
			}
			else
			{
				arr[p + i] = arr2[k++];
			}
		}
	}

	public static void Populate(int[] arr)
	{
		for(int i = 0; i < arr.length; i++)
		{
			Random r = new Random();
			r.setSeed(3);
			arr[i] = (int)(r.nextInt(arr.length * 5));
		}
	}
	public static void Display(int[] arr)
	{
		for(int i = 0; i < arr.length; i++)
		{
			System.out.println(arr[i]);
		}
	}
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		System.out.println("Enter number of elements : ");
		int num = in.nextInt();
		int [] arr = new int[num];
		Populate(arr);
		double startTime = System.currentTimeMillis();
		MergeSort(arr, 0 , arr.length - 1);
		double stopTime = System.currentTimeMillis();
        double elapsedTime = stopTime - startTime;
      	System.out.println("Elapsed Time : " + elapsedTime);
      	//Display(arr);
	}	
}