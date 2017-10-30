using System;

namespace MyNamespace
{
  public interface IRandom
  {
    string Hello();
  }

  class Interface : IRandom
  {
    public String Hello(String myString)
    {
      return "Hello World!.";
    }

    public int Hello()
    {
      return 1;
    }

    // public String Hello()
    // {
    //   return "Hello World!.";
    // }

    public static void Main(String[] args)
    {
      Interface myInterface = new Interface();
      Console.WriteLine(myInterface.Hello());
    }
  }
}