//https://www.hackerrank.com/challenges/dance-class

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dancing_in_Pairs
{
    class Program
    {
        static void Main(string[] args)
        {
            var t=0;
            t = Convert.ToInt32(Console.ReadLine());
            while(t!=0)
            {
                var i = Convert.ToInt64(Console.ReadLine());
                var d = (long)Math.Floor(Math.Sqrt(i));
                if (d % 2 == 0)
                {
                    Console.WriteLine("even");
                }
                else
                {
                    Console.WriteLine("odd");
                }
                //var d = 4 * (i + 1);
                //var n = (long)Math.Ceiling((Math.Sqrt(d) - 2) / 2);
                //if (n % 2 == 0)
                //{
                //    Console.WriteLine("even");
                //}
                //else
                //{
                //    Console.WriteLine("odd");
                //}
                t--;
            }

            Console.ReadKey();
        }
    }
}
