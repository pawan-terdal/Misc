using System;

namespace MyNamspace
{
  public class Email
  {
    public void Send()
    {
      Console.WriteLine("Sending Email");
    }
  }

  public class PayTM
  {
    Email email;
    public PayTM(Email email)
    {
      this.email = email;
    }
    public void Transact()
    {
      Console.WriteLine("Transactions being done.");
      email.Send();
    }
  }

  class Example
  {
    public static void Main(string[] args)
    {
      PayTM payTM = new PayTM(new Email());
      payTM.Transact();
    }
  }    
}