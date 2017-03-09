import java.io.*;
import java.util.*;

class Stack
{
	public int[] Elements = new int[100];
	public int MaxItems;
	public int Top;
	private Scanner in = new Scanner(System.in);

	Stack()
	{
		MaxItems = 100;
		Top = -1;
	}

	public void Push(int number)
	{
		if(Top == MaxItems - 1)
		{
			System.out.println("Overflow Detected.");
			return;
		}
		Elements[++Top] = number;
	}

	public int Pop()
	{
		if(Top == -1)
		{
			System.out.println("Underflow Detected.");
			return -99999;
		}
		Top--;
		return Elements[Top + 1];
	}

	public void Display()
	{
		if(Top == -1)
		{
			System.out.println("Stack is Empty.");
			return;
		}
		System.out.println("The Stack is as Follows : ");
		for(int i = Top; i >= 0; i--)
		{
			System.out.println(Elements[i]);
		}
	}
}

public class Prog1b
{
	public static void main(String args[])
	{
		Stack stack = new Stack();
		Scanner in = new Scanner(System.in);
		int choice = 0, number;
		System.out.println("---------------MENU------------------");
		System.out.println("1. Push.");
		System.out.println("2. Pop");
		System.out.println("3. Display.");
		System.out.println("4. Exit.");

		while(true)
		{
			System.out.print("Enter Choice : ");
			choice = in.nextInt();

			switch(choice)
			{
				case 1 :
				{
					System.out.println("Enter a number to push : ");
					number = in.nextInt();
					stack.Push(number);
					break;
				}
				case 2 :
				{
					number = stack.Pop();
					if(number != -99999)
					{
						System.out.println("Element popped : " + number);
					}
					break;
				}
				case 3 :
				{
					stack.Display();
					break;
				}
				case 4 :
				{
					System.exit(0);
                    break;
				}
				default :
				{
					System.out.println("Wrong Choice.");
				}
			}
		}

	}
}
