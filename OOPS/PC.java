import java.io.*;

class Q
{
    int n;
    boolean valueSet = false;

    synchronized void put(int n)
    {
        if(valueSet)
        {
            try
            {
                wait();
            }
            catch(InterruptedException e)
            {

            }
        }
        System.out.println("Put " + n);
        this.n = n;
        valueSet = true;
        notify();
    }

    synchronized int get()
    {
        if(!valueSet)
        {
            try
            {
                wait();
            }
            catch(InterruptedException e)
            {

            }
        }
        valueSet = false;
        System.out.println("Got " + n + "\n");
        notify();
        return n;
    }
}

class Producer implements Runnable
{
    Q q;

    Producer(Q q)
    {
        this.q = q;
        new Thread(this, "Producer").start();
    }

    public void run()
    {
        int i = 0;
        while(true)
        {
            q.put(i++);
        }
    }
}

class Consumer implements Runnable
{
    Q q;

    Consumer(Q q)
    {
        this.q = q;
        new Thread(this, "Consumer").start();
    }

    public void run()
    {
        while(true)
        {
            q.get();
        }
    }
}

class PC
{
    public static void main(String[] args) {
        Q q = new Q();
        new Producer(q);
        new Consumer(q);
    }
}
