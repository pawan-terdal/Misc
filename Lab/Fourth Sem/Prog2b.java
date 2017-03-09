import java.io.*;
import java.util.*;

class Customer
{
	String Name;
	int Date;
	int Month;
	int Year;

	Customer(String input)
	{
		String dob = "";
		StringTokenizer tokenizer = new StringTokenizer(input.trim(),",");
		Name = tokenizer.nextToken().trim();
		dob = tokenizer.nextToken().trim();
		tokenizer = new StringTokenizer(dob,"/");
		Date = Integer.parseInt(tokenizer.nextToken().trim());
		Month = Integer.parseInt(tokenizer.nextToken().trim());
		Year = Integer.parseInt(tokenizer.nextToken().trim());
	}

	public void Display()
	{
		System.out.println(Name + ',' + Date + ',' + Month + ',' + Year);
	}
}

class Prog2b
{
	public static void main(String[] args) 
	{
		String name, dob, input;
		int count = 0;
		Scanner in = new Scanner(System.in);
		Customer [] customers = new Customer[100];
		System.out.println("1. Enter Customers' Details.");
		System.out.println("2. Display After Modification.");
		System.out.println("3. Exit.");

		while(true)
		{
			int choice;
			System.out.print("Enter choice : ");
			choice = in.nextInt();
			in.nextLine();
			switch (choice) 
			{
				case 1 :
				{
					System.out.print("Enter number of customers : ");
					count = in.nextInt();
					in.nextLine();

					for(int i = 0; i < count; i++)
					{
						System.out.println("Enter Customer " + (i+1) +" Name And DOB in the format <name,dd/mm/yy> :");
						input = in.nextLine();
						customers[i] = new Customer(input);
					}
					break;
				}
				case 2 :
				{
					if(count == 0)
					{
						System.out.println("Enter customers first.");
						break;
					}
					System.out.println("Customer Details : ");
					for(int i = 0; i < count; i++)
					{
						customers[i].Display();
					}
					break;
				}
				case 3 :
				{
					System.exit(0);
				}
				default :
				{
					System.out.println("Wrong choice. Try again.");
				}
			}
		}		
	}
}