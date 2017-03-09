import java.io.*;
import java.util.*;

class Student
{
	public String Name;
	public String Usn;
	public String Branch;
	public String Phone;

	Student(String name , String usn , String branch , String phone )
	{
		this.Name = name;
		this.Usn = usn;
		this.Branch = branch;
		this.Phone = phone;
	}

	public void Display(int index)
	{
		System.out.println("Name \t: " + Name);
		System.out.println("USN \t: " + Usn);
		System.out.println("Branch \t: " + Branch);
		System.out.println("Phone \t: " + Phone);
	}
}

public class Prog1a
{
	public static void DisplayList(ArrayList<Student> students)
	{
		System.out.println("Student Details : ");
		for (int i = 0; i < students.size(); i++ )
		{
			System.out.println("\nStudent " + (i+1) + " Details : ");
			students.get(i).Display(i);
		}
	}

	public static ArrayList<Student> InputList()
	{
		String name,usn,branch,phone;
		int number;
		Scanner in = new Scanner(System.in);
		System.out.print("Enter number of students : ");
		number = in.nextInt();
		in.nextLine();
		ArrayList<Student> students = new ArrayList<Student>();
		System.out.println("Enter Details of " + number + " Students : ");
		for(int i = 0; i < number; i++)
		{
			System.out.println("Student " + (i+1) + " Details: ");
			System.out.print("Name   : ");
			name = in.nextLine();
			System.out.print("USN  	 : ");
			usn = in.nextLine();
			System.out.print("Branch : ");
			branch = in.nextLine();
			System.out.print("Phone  : ");
			phone = in.nextLine();
			Student student = new Student(name, usn, branch, phone);
			students.add(student);
		}

		return students;
	}

	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);

		System.out.println("---------------MENU------------------");
		System.out.println("1. Enter new Student Records.");
		System.out.println("2. Display Student Records.");
		System.out.println("3. Exit.");
		ArrayList<Student> students = null;

		int choice = 0;
		while(true)
		{
			System.out.print("Enter Choice : ");
			choice = in.nextInt();

			switch(choice)
			{
				case 1 :
				{
					students = InputList();
					break;
				}
				case 2 :
				{
					if(students == null)
					{
						System.out.println("No Records.");
						break;
					}
					DisplayList(students);
					break;
				}
				case 3 :
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
