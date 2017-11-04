import java.io.*;
import java.util.*;

class DivideByZero extends Exception
{
	DivideByZero(String s)
	{
		super("LO<");
	}
}
class Prog3a
{
	public static void main(String[] args)
	{
		int a, b;
		System.out.print("Enter two numbers: ");
		Scanner in = new Scanner(System.in);
		a = in.nextInt();
		b = in.nextInt();
		try
		{
		if(b == 0)
		{
			throw new DivideByZero("Argument 'b' is 0");
		}
		System.out.println("Quotient : " + ((float)a/b));
		}
		catch(DivideByZero d)
		{
			System.out.println("LOLLL");
		}
	}
}
