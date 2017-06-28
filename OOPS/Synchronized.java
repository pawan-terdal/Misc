import java.io.*;

class Callme
{
    public void call(String msg)
    {
        System.out.print('[');
        System.out.print(msg);
        try
        {
            Thread.sleep(1000);
        }
        catch(InterruptedException e)
        {

        }
        System.out.println(']');
    }
}

class Caller implements Runnable
{
    Thread t;
    Callme target;
    String msg;

    Caller(Callme targ, String msg)
    {
        target = targ;
        this.msg = msg;
        Thread t = new Thread(this);
        t.start();
    }

    public void run()
    {
        synchronized(target)
        {
            target.call(msg);
        }
    }
}

class Synchronized
{
    public static void main(String[] args)
    {
        Callme target = new Callme();
        Caller c1 = new Caller(target, "LOL");
        Caller c2 = new Caller(target, "Nithin");
        Caller c3 = new Caller(target, "Reddy");

        try
        {
            c1.t.join();
            c2.t.join();
            c3.t.join();
        }
        catch(InterruptedException e)
        {

        }
    }
}
