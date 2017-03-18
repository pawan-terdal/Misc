//https://www.hackerrank.com/challenges/possible-path

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace PossiblePath
{
    class Program
    {
        static long gcd(long a,long b)
        {
            if(a==0||b==0)
            {
                return 0;
            }
            long c;
            while(b!=0)
            {
                c = a % b;
                a = b;
                b = c;
            }
            return a;
        }
        static void Main(string[] args)
        {
            long t;
            t = Convert.ToInt64(Console.ReadLine());
            while (t != 0)
            {
                long a, b, c, d;
                string[] values = Console.ReadLine().Split(' ');
                a = Convert.ToInt64(values[0]);
                b = Convert.ToInt64(values[1]);
                c = Convert.ToInt64(values[2]);
                d = Convert.ToInt64(values[3]);
                if(gcd(a,b)==gcd(c,d))
                {
                    Console.WriteLine("YES");
                }
                else
                {
                    Console.WriteLine("NO");
                }
                t--;
            }
            Console.ReadLine();
        }
    }
}
