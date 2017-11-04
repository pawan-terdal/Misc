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

	public static void IsSorted(int [] arr)
	{
		for(int i = 0; i < arr.length - 1; i++)
		{
			if(arr[i] > arr[i+1])
			{
				throw new RuntimeException("Not Sorted.");
			}
		}
	}
	public static void Populate(int[] arr)
	{
		Random r = new Random();
		r.setSeed(3);
		for(int i = 0; i < arr.length; i++)
		{
			arr[i] = r.nextInt(arr.length * 5);
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
		int t;
		Scanner in = new Scanner(System.in);
        System.out.print("Enter number of testcases : ");
        t = in.nextInt();
        int num = 5000;
		System.out.println("Length\t\t\tTime(milliseconds)");
        for(int i = 0; i < t; i++, num+= 20000)
        {
            int [] arr = new int[num];
		    Populate(arr);
			//System.out.println(arr[0]);
		    double startTime = System.currentTimeMillis();
		    QuickSort(arr, 0 , arr.length - 1);
		    double stopTime = System.currentTimeMillis();
            double elapsedTime = stopTime - startTime;
			IsSorted(arr);
      	    System.out.println( num + "\t\t\t" + elapsedTime);
        }
	}
}
