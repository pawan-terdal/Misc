import java.util.*;

public class QuickSort
{
    int arr[] = new int[10000];
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        QuickSort ob = new QuickSort();
        System.out.println("Enter number of terms");
        int n = sc.nextInt();
        Random r = new Random();
        for(int i = 0; i < n; i++)
        {
            ob.arr[i] = r.nextInt(5000);
        }
        ob.Quicksort(0, n - 1);
        for(int i = 0; i < n; i++)
        {
            System.out.println(ob.arr[i]);
        }
    }

    void Quicksort(int l, int r)
    {
        if(l < r)
        {
            int pivot = this.arr[r];
            int part = this.Partition(l, r, pivot);
            this.Quicksort(l, part - 1);
            this.Quicksort(part + 1, r);
        }
    }

    int Partition(int l, int r, int pi)
    {
        int leftPointer = l;
        int rightPointer = r - 1;
        while(leftPointer < rightPointer)
        {
            while(this.arr[leftPointer] < pi)
            {
                leftPointer++;
            }
            while(this.arr[rightPointer] > pi && rightPointer >= 0)
            {
                rightPointer--;
            }

            if(leftPointer >= rightPointer)
            {
                break;
            }
            else
            {
                int temp = this.arr[leftPointer];
                this.arr[leftPointer] = this.arr[rightPointer];
                this.arr[rightPointer] = temp;
            }
        }

        int temp = this.arr[r];
        this.arr[r] = this.arr[leftPointer];
        this.arr[leftPointer] = temp;

        return leftPointer;
    }
}
