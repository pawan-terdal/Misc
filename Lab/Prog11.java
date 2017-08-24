import java.io.*;
import java.util.*;

class Prog11
{
    public static void Combinations(int position, int offset, int array[], int elements[])
    {
        if(position == array.length)
            return;
        for(int i = offset; i < elements.length; i++)
        {
            array[position] = elements[i];
            /*for(int j = 0; j <= position; j++)
                System.out.print(array[j] + " ");
            System.out.println();
            */
            Combinations(position+1, i+1, array,elements);
        }
    }
    public static void main(String[] args)
    {
        int elements[] = new int[] {1, 2, 3};
        int array[] = new int[3];
        Combinations(0,0,array,elements);
    }
}
