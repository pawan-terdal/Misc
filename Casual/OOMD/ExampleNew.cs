using System;
using System.Collections;
using System.Collections.Generic;

namespace MyNamspace
{
  public interface ISend
  {
    void Send();
  }

  public class Email : ISend
  {
    public void Send()
    {
      Console.WriteLine("Sending Email");
    }
  }

  public class SMS : ISend
  {
    public void Send()
    {
      Console.WriteLine("Sending SMS");
    }
  }

  // public class Post : ISend
  // {
  //   public void Send()
  //   {
  //     Console.WriteLine("Sending Post");
  //   }
  // }

  public class PayTM
  {
    List<ISend> notificationChannels = new List<ISend>();
    public void AddNotificationChannel(ISend notificationChannel)
    {
      notificationChannels.Add(notificationChannel);
    }
    public void Transact()
    {
      Console.WriteLine("Transactions being done.");
      foreach (var notificationChannel in notificationChannels)
      {
          notificationChannel.Send();
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