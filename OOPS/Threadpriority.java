import java.io.*;

class Clicker implements Runnable
{
    int click;
    Thread t;
    volatile boolean isRunning = true;
    Clicker(int p)
    {
            t = new Thread(this);
            t.setPriority(p);
    }

    public void run()
    {
        while(isRunning)
        {
            click++;
        }
    }

    public void stop()
    {
        isRunning = false;
    }
}

class ThreadPriority
{
    public static void main(String[] args)
    {
        Thread.currentThread().setPriority(Thread.MAX_PRIORITY);
        Clicker lo = new Clicker(Thread.NORM_PRIORITY - 4);
        Clicker hi = new Clicker(Thread.NORM_PRIORITY + 4);

        lo.t.start();
        hi.t.start();

        try
        {
            Thread.sleep(10000);
            lo.stop();
            hi.stop();
            lo.t.join();
            hi.t.join();
        }
        catch(InterruptedException e)
        {

        }
        System.out.println("LO " + lo.click);
        System.out.println("Hi " + hi.click);
    }
}
