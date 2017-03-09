import java.io.*;
import java.util.*;

class Prog3a
{
	public static void main(String[] args)
	{
		int a, b;
		System.out.print("Enter two numbers: ");
		Scanner in = new Scanner(System.in);
		a = in.nextInt();
		b = in.nextInt();

		if(b == 0)
		{
			throw new IllegalArgumentException("Argument 'b' is 0");
		}
		System.out.println("Quotient : " + ((float)a/b));
	}
}
