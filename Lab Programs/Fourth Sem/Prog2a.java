import java.io.*;
import java.util.*;

class Staff
{
	public String Id, Name;
	public long Phone, Salary;

	Staff(String id, String name, long phone, long salary)
	{
		Id = id;
		Name = name;
		Phone = phone;
		Salary = salary;
	}

	public void DisplayS()
	{
		System.out.println("Id           : " + Id);
		System.out.println("Name         : " + Name);
		System.out.println("Phone        : " + Phone);
		System.out.println("Salary       : " + Salary);
	}
}

class Teaching extends Staff
{
	String Domain, Publications;

	Teaching(String id, String name, long phone, long salary, String domain, String publications)
	{
		super(id, name, phone, salary);
		Domain = domain;
		Publications = publications;
	}

	public void Display()
	{
		DisplayS();
		System.out.println("Domain       : " + Domain);
		System.out.println("Publications : " + Publications);
	}
}

class Technical extends Staff
{
	String Skills;

	Technical(String id, String name, long phone, long salary, String skills)
	{
		super(id, name, phone, salary);
		Skills = skills;
	}

	public void Display()
	{
		DisplayS();
		System.out.println("Skills       : " + Skills);
	}
}

class Contract extends Staff
{
	int Period;

	Contract(String id, String name, long phone, long salary, int period)
	{
		super(id, name, phone, salary);
		Period = period;
	}

	public void Display()
	{
		DisplayS();
		System.out.println("Period       : " + Period);
	}
}
class Prog2a
{
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		String id, name, domain, publications, skills;
		int period;
		long phone, salary;
		PrintWriter p = new PrintWriter(System.out, true);
		p.println("Enter details of Teaching Staff : ");
		System.out.print("Id           : " );
		id = in.nextLine();
		System.out.print("Name         : " );
		name = in.nextLine();
		System.out.print("Phone        : " );
		phone = in.nextLong();
		in.nextLine();
		System.out.print("Salary       : " );
		salary = in.nextLong();
		in.nextLine();
		System.out.print("Domain       : " );
		domain = in.nextLine();
		System.out.print("Publications : " );
		publications = in.nextLine();

		Teaching teaching = new Teaching(id, name, phone, salary, domain, publications);

		System.out.println("Enter details of Technical Staff : ");
		System.out.print("Id           : " );
		id = in.nextLine();
		System.out.print("Name         : " );
		name = in.nextLine();
		System.out.print("Phone        : " );
		phone = in.nextLong();
		in.nextLine();
		System.out.print("Salary       : " );
		salary = in.nextLong();
		in.nextLine();
		System.out.print("Skills       : " );
		skills = in.nextLine();
		Technical technical = new Technical(id, name, phone, salary,skills);

		System.out.println("Enter details of Contract Staff : ");
		System.out.print("Id           : " );
		id = in.nextLine();
		System.out.print("Name         : " );
		name = in.nextLine();
		System.out.print("Phone        : " );
		phone = in.nextLong();
		in.nextLine();
		System.out.print("Salary       : " );
		salary = in.nextLong();
		in.nextLine();
		System.out.print("Period       : " );
		period = in.nextInt();
		Contract contract = new Contract(id, name, phone, salary, period);

		System.out.println("Details of Teaching Staff : ");
		teaching.Display();
		System.out.println("Details of Technical Staff : ");
		technical.Display();
		System.out.println("Details of Contract Staff : ");
		contract.Display();
	}
}
