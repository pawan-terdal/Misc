import java.io.*;
import java.util.*;

class Prog4
{
	public static void Swap(int [] arr, int i, int j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	public static void QuickSort(int [] arr, int p, int r)
	{
		if(p < r)
		{
			int pivot = QuickPivot(arr,p,r);
			QuickSort(arr, p, pivot-1);
			QuickSort(arr, pivot+1, r);
		}

	}

	public static int QuickPivot(int [] arr, int p, int r)
	{
		int pivot = p;
		int pivotElement = arr[r];
		for(int i = p; i <= r - 1; i++)
		{
			if(arr[i] < pivotElement)
			{
				Swap(arr, i, pivot++);
			}
		}
		Swap(arr, pivot, r);
		return pivot;
	}

	public static void Populate(int[] arr)
	{
		Random r = new Random();
		r.setSeed(3);
		for(int i = 0; i < arr.length; i++)
		{
			arr[i] = r.nextInt(arr.length);
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
		QuickSort(arr, 0 , arr.length - 1);
		double stopTime = System.currentTimeMillis();
        double elapsedTime = stopTime - startTime;
      	System.out.println("Elapsed Time : " + elapsedTime);
		//Display(arr);
	}
}
