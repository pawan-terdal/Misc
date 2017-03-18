//https://www.hackerrank.com/challenges/red-john-is-back

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace RedJohnIsBackCS
{
    class Program
    {
        static BigInteger fact(int n)
        {
            BigInteger fact = 1;
            for (BigInteger i = 2; i <= n; i++)
            {
                fact *= i;
            }

            return fact;
        }
        public static BigInteger s(int d,int i)
        {
            BigInteger val = 1;
            int[] arr = new int[10] { 0,0,0,0,0,0,0,0,0,0 };
            for(int j=0;j< d;j++)
            {
                arr[j % i]++;
            }
            int a = arr[0];
            int n = 1;
            for (int j = 0; j < i; j++)
            {
                Console.Write(arr[j] + " ");
            }
            for (int j=1;j< i;j++)
            {
                if(a==arr[j])
                {
                    n++;
                }
                else
                {
                    val *= fact(n);
                    n = 1;
                    a = arr[j];
                }
            }
            val *= fact(n);
            Console.WriteLine("\n"+fact(d)+" "+val);
            return val;
        }

        public static long comb(int num, int den)
        {
            long val = 0;
            for (int i = 1; i <= den; i++)
            {
                Console.WriteLine("\n\n"+i + " " + den);
                BigInteger k = fact(i);
                k = k / s(den, i);
                //Console.Write(k + " ");
                val += (long)(k*fact(num) / fact(i) / fact(num - i));
            }
            Console.WriteLine();
            //Console.WriteLine(" " + val);
            return val;
        }
        static void Main(string[] args)
        {
            List<long> primes = new List<long>();
            primes.Add(2);
            for (long i = 3; i < 1000000; i++)
            {
                int flag = 1;
                int size = primes.Count;
                for (int j = 0; j < size; j++)
                {
                    if (primes[j] > (long)Math.Sqrt(i))
                    {
                        break;
                    }
                    if (i % primes[j] == 0)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag==1)
                {
                    primes.Add(i);
                }
            }

            int t;
            t = Convert.ToInt32(Console.ReadLine());
            while (t!=0)
            {
                long total = 1;
                int n;
                n = Convert.ToInt32(Console.ReadLine());
                int[] arr = new int[n + 1];
                arr[0] = 1;
                for(int i=1;i<=n;i++)
                {
                    arr[i] += arr[i - 1];
                    if(i-4>=0)
                    {
                        arr[i] += arr[i - 4];
                    }
                }
                //int nH = n / 4, nV = n % 4;
                //int tnH = nH, tnV = nV;
                //while (tnH !=0)
                //{
                //    //Console.Write(tnH + " " + tnV);
                //    if (tnH >= tnV)
                //    {
                //        total += comb(tnH + 1, tnV);
                //    }
                //    else
                //    {
                //        total += comb(tnV + 1, tnH);
                //        //total += perm(tnV+1, tnH);
                //    }
                //    tnH--;
                //    tnV += 4;
                //}
                t--;
                total = arr[n];
                int count=0;

                foreach(int a in primes)
                {
                    if(a<=total)
                    {
                        count++;
                    }
                }

                //Console.WriteLine(total);
                Console.WriteLine(count);
            }
            Console.ReadLine();
        }
    }
}
