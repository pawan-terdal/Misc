using System;
namespace MyNamespace
{
  public class Student : IComparable
  {
    public int marks;
    public string name;

    public Student (string name, int marks) 
    {
      this.name = name;
      this.marks = marks;
    }
    
    public int CompareTo(Object student)
    {
      return this.marks - ((Student)student).marks;
    }
  }

  public class Generics
  {
    public static int Max(int a, int b)
    {
      return a > b ? a : b;
    }

    public static double Max(double a, double b)
    {
      return a > b ? a : b;
    }

    public static Student Max(Student a, Student b)
    {
      return a.marks > b.marks ? a : b;
    }

    // public static T Max<T>(T a, T b) where T: IComparable
    // {
    //   return a.CompareTo(b) > 0 ? a : b;
    // }

    public static void Main(String[] args)
    {
      Console.WriteLine(Max(4,5));
      
      Console.WriteLine(Max(4,5.5));

      Console.WriteLine(Max(40,5.5));

      var student1 = new Student("Student 1", 50);
      var student2 = new Student("Student 2", 60);

      Console.WriteLine(Max(student1,student2).name);
    }
  }   
}