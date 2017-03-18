using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace FillingJars
{
    class Program
    {
        static void Main(string[] args)
        {
            BigInteger sum = 0;
            int n, m;
            string[] input = Console.ReadLine().Split(' ');
            n = Convert.ToInt32(input[0]);
            m = Convert.ToInt32(input[1]);
            while (m!=0)
            {
                long a, b, k;
                string[] values = Console.ReadLine().Split(' ');
                a = Convert.ToInt64(values[0]);
                b = Convert.ToInt64(values[1]);
                k = Convert.ToInt64(values[2]);
                sum += (b - a + 1) * k;
                m--;
            }
            Console.Write(sum / n);
            Console.ReadLine();
        }
    }
}
