import java.util.*;

class Staff
{
    String staffID;
    String name;
    String phno;
    String salary;

    public void TakeInput(Scanner sc)
    {
        System.out.println("Enter Staff ID");
        this.staffID = sc.next();
        System.out.println("Enter Name");
        this.name = sc.next();
        System.out.println("Enter Phone Number");
        this.phno = sc.next();
        System.out.println("Enter Salary");
        this.salary = sc.next();
    }

    public void ShowOutput()
    {
        System.out.println("Staff ID : " + this.staffID);
        System.out.println("Name : " + this.name);
        System.out.println("Phone Number : " + this.phno);
        System.out.println("Salary : " + this.salary);
    }
}

class Teaching extends Staff
{
    String domain;
    String pub;
    public void TakeInput1(Scanner sc)
    {
        this.TakeInput(sc);
        System.out.println("Enter Domain");
        this.domain = sc.next();
        System.out.println("Enter Publications");
        this.pub = sc.next();
    }
    public void ShowOutput1()
    {
        this.ShowOutput();
        System.out.println("Domain : " + this.domain);
        System.out.println("Publications : " + this.pub);
    }
}

class Technical extends Staff
{
    String skills;
    void TakeInput2(Scanner sc)
    {
        this.TakeInput(sc);
        System.out.println("Enter Skills");
        this.skills = sc.next();
    }
    void ShowOutput2()
    {
        this.ShowOutput();
        System.out.println("Skills : " + this.skills);
    }
}

class Contract extends Staff
{
    String period;
    void TakeInput3(Scanner sc)
    {
        this.TakeInput(sc);
        System.out.println("Enter Period");
        this.period = sc.next();
    }
    void ShowOutput3()
    {
        this.ShowOutput();
        System.out.println("Period : " + this.period);
    }
}

class TwoA
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        Staff a = new Teaching();
        ((Teaching)a).TakeInput1(sc);
        //a.ShowOutput1();
    }
}
