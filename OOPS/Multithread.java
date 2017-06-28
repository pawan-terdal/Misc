import java.io.*;

class Thread1 implements Runnable
{
    Thread t;

    Thread1()
    {
        t = new Thread(this, "Thread by implementing Runnable");
        t.start();
    }

    public void run()
    {
        try
        {
            for(int i = 0; i < 5; i++)
            {
                System.out.println(i);
                Thread.sleep(1000);
            }
        }
        catch(InterruptedException e)
        {
            System.out.println("Thread1 interrupted.");
        }
    }
}

class Thread2 extends Thread
{
    Thread2()
    {
        super("Thread by extending");
        start();
    }

    public void run()
    {
        try
        {
            for(int i = 5; i < 10; i++)
            {
                System.out.println(i);
                Thread.sleep(1000);
            }
        }
        catch(InterruptedException e)
        {
            System.out.println("Thread2 interrupted.");
        }
    }
}

class Multithread
{
    public static void main(String[] args) {
        Thread1 t1 = new Thread1();
        Thread2 t2 = new Thread2();

        if(t1.t.isAlive())
        {
            System.out.println("Thread1 is alive.");
        }

        try
        {
            t1.t.join();
        }
        catch(InterruptedException e)
        {

        }

        if(!t1.t.isAlive())
        {
            System.out.println("Thread1 is dead.");
        }

        System.out.println(t1.t);
        System.out.println(t2);
    }
}
