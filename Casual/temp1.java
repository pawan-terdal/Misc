import java.io.*;
interface hello
{
    void lol(int a);
}
class temp1 implements hello
{
    public static void main(String args[])
    {
        String a = "PESIT";
        System.out.println(a);
        int b = 10, c= 20, d=30;
    	System.out.println(a+b+c+d);
    	System.out.println(b+c+d+a);
    	System.out.println(b+a+c+d);
    	System.out.println(b+c+a+d);
    }

    public void lol(int a)
    {
        
    }
}
