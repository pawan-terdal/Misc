//https://www.hackerrank.com/challenges/summing-the-n-series

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace SummingTheNSeries
{
    class Program
    {
        static void Main(string[] args)
        {
            int t;
            t = Convert.ToInt32(Console.ReadLine());
            while (t != 0)
            {
                BigInteger n;
                n = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine((n*n)%((long)Math.Pow(10,9)+7));
                t--;
            }
        }
    }
}
