//hackerrank.com/challenges/handshake

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
namespace HandShakes
{
    class Program
    {
        static void Main(string[] args)
        {
            int t;
            t = Convert.ToInt32(Console.ReadLine());
            while(t!=0)
            {
                long n;
                n = Convert.ToInt64(Console.ReadLine());
                if(n>=2)
                {
                    Console.WriteLine(n * (n - 1) / 2);
                }
                else
                {
                    Console.WriteLine(0);
                }
                t--;
            }
        }
    }
}
