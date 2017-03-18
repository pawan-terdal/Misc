//https://www.hackerrank.com/challenges/sherlock-and-divisors

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
long f(long n)
{
    long fact=1;
    for(long i=2;i<=n;i++)
    {
        fact*=i;
    }
    return fact;
}

long combinations(long n)
{
    long total=0;
    for(long r=1;r<=n;r++)
    {
        total+=f(n)/(f(r)*f(n-r));
    }
    return total;

}

int main()
{
    int t;
    vector<int> primes;
    primes.push_back(2);
    for(int i=3;i<31623;i++)
    {
        int flag=1;
        int size = primes.size();
        for(int j=0;j<size;j++)
        {
            if(primes[j]>sqrt(i))
            {
                break;
            }
            if(i%primes[j]==0)
            {
                flag=0;
            }
        }
        if(flag)
        {
            primes.push_back(i);
        }
    }
    cin>>t;
    while(t--)
    {
        long noOf2=0,count=0,size,k=0;
        long long num,temp;
        cin>>num;
        temp=num;
        while(temp%2==0)
        {
            noOf2++;
            temp/=2;
        }

        if(noOf2!=0)
        {
            vector<long> factors;

            size = primes.size();
            for(int i=0;i<size;i++)
            {
                while(temp%primes[i]==0)
                {
                    count++;
                    factors.push_back(primes[i]);
                    temp/=primes[i];
                }
                if(temp==1)
                {
                    break;
                }
            }
            if(temp>31623)
            {
                factors.push_back(temp);
            }

            int k=1,a=0,b=0;
            long elem;
            a=noOf2+1;
            size=factors.size();
            if(size>0)
            {
                elem=factors[0];
            }
            for(int i=0;i<size;i++)
            {
                if(factors[i]==elem)
                {
                    b++;
                }
                else
                {
                    elem=factors[i];
                    k*=(b+1);
                    b=1;
                }
            }
            k*=(b+1);
            cout<<(a-1)*k;
        }
        else
        {
            cout<<0;
        }
        cout<<endl;
    }
}
