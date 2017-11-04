using System;

namespace MyNamespace
{
  class PayTM
  {
    public delegate void NotificationServices(int amount);

    public void SMS(int amount)
    {
      Console.WriteLine("Sending SMS.");
    }

    public void Transact(int amount, NotificationServices notificationServices = null)
    {
      Console.WriteLine("Transaction being done.");

      if(notificationServices == null)
        notificationServices = SMS;
      else
        notificationServices += SMS;

      notificationServices(amount);
    }
  }

  class MyClass
  {
    public static void Main(string[] args)
    {
      PayTM payTM = new PayTM();
      payTM.Transact(50);

      // PayTM payTM = new PayTM();
      // PayTM.NotificationServices notificationServices = Email;
      // notificationServices += Post;
      // payTM.Transact(50, notificationServices);
    }

    // public static void Email(int amount)
    // {
    //   Console.WriteLine("Sending Email.");
    // }
    // public static void Post(int amount)
    // {
    //   Console.WriteLine("Sending Post.");
    // }
  }
}