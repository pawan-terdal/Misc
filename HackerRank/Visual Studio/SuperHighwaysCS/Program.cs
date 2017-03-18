//https://www.hackerrank.com/contests/round-2-holiday-cup/challenges/super-highways

using System;
using System.Numerics;

namespace SuperHighwaysCS
{
    class Program
    {
        static void Main(string[] args)
        {
            const long div = 1000000009;
            long t;
            t = Convert.ToInt64(Console.ReadLine());
            while (t--!=0)
            {
                BigInteger n, k, c;
                BigInteger totalCost;
                totalCost = 0;
                string[] input = Console.ReadLine().Split(' ');
                n = Convert.ToInt64(input[0]);
                k = Convert.ToInt64(input[1]);
                c = Convert.ToInt64(input[2]);

                if (n == 1)
                {
                    Console.WriteLine("0");
                }
                else 
                {
                    totalCost = n * (n - 1) * (n + 1) / 6 * k + n * (n - 1) / 2 * c;
                    Console.WriteLine(totalCost%div);
                }
            }
            Console.ReadLine();
            Console.ReadKey();
        }
    }
}
