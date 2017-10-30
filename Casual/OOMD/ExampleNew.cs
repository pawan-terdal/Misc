using System;
using System.Collections;
using System.Collections.Generic;

namespace MyNamspace
{
  public interface INotifService
  {
    void Send();
  }

  public class Email : INotifService
  {
    public void Send()
    {
      Console.WriteLine("Sending Email");
    }
  }

  public class SMS : INotifService
  {
    public void Send()
    {
      Console.WriteLine("Sending SMS");
    }
  }

  // public class Post : INotifService
  // {
  //   public void Send()
  //   {
  //     Console.WriteLine("Sending Post");
  //   }
  // }

  public class PayTM
  {
    List<INotifService> _notificationServices = new List<INotifService>();

    public void AddNotificationChannel(INotifService notificationService)
    {
      _notificationServices.Add(notificationService);
    }
    
    public void Transact()
    {
      Console.WriteLine("Transactions being done.");
      foreach (var notificationService in _notificationServices)
      {
          notificationService.Send();
      }
    }
  }

  class Example
  {
    public static void Main(string[] args)
    {
      PayTM payTM = new PayTM();
      payTM.AddNotificationChannel(new Email());
      payTM.AddNotificationChannel(new SMS());
      // payTM.AddNotificationChannel(new Post());
      payTM.Transact();
    }
  }    
}