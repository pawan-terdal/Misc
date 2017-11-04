import java.io.*;
import java.util.*;

class Number
{
	public static int number;
	public static int iterations;
}

class FindRandomThread implements Runnable
{
	public void run()
	{
		for(int i = 0; i < Number.iterations; i++)
		{
			Number.number = (int)(Math.random() * 10);
			System.out.print("Number[Thread1] : " + Number.number);
			try
			{
			    Thread.sleep(1000);
			}
			catch(InterruptedException e)
			{
			     // this part is executed when an exception (in this example InterruptedException) occurs
			}
		}
 	}
}

class SquareThread implements Runnable
{
	public void run()
 	{
 		for(int i = 0; i < Number.iterations; i++)
		{
  			System.out.print("\tSquare[Thread2] : " + Number.number * Number.number);
  			try
			{
			    Thread.sleep(1050);
			}
			catch(InterruptedException e)
			{
			     // this part is executed when an exception (in this example InterruptedException) occurs
			}
  		}
 	}
}

class CubeThread implements Runnable
{
	public void run()
 	{
 		for(int i = 0; i < Number.iterations; i++)
		{
  			System.out.println("\tCube[Thread3] : " + Number.number * Number.number * Number.number);
  			try
			{
			    Thread.sleep(1050);
			}
			catch(InterruptedException e)
			{
			     // this part is executed when an exception (in this example InterruptedException) occurs
			}
  		}
 	}
}

class Prog3b
{
	public static void main(String[] args)
	{
		System.out.print("Enter number of iterations : ");
		Scanner in = new Scanner(System.in);
		Number.iterations = in.nextInt();
		Thread [] threads = new Thread[3];
		threads[0] = new Thread(new FindRandomThread());
		threads[1] = new Thread(new SquareThread());
		threads[2] = new Thread(new CubeThread());
		for(int i = 0; i < 3; i++)
		{
			threads[i].start();
		}
	}
}
