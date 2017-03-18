//https://www.hackerrank.com/challenges/kaprekar-numbers
#include<iostream>
#include<math.h>

using namespace std;

int CalcDigits(long num)
{
    int digits=0;
    while(num!=0)
    {
        num=num/10;
        digits++;
    }
    return digits;
}

long long LeftPart(long long num,long d)
{
    return num/d;
}

long long RightPart(long long num,long d)
{
    return num%d;
}

int main()
{
    long long p,q,square,sum,l,r,d,flag=0;
    cin>>p>>q;
    if((p>0)&&(q>p)&&(q<100000))
    {
        for(long long i=p;i<=q;i++)
        {
            int digits=CalcDigits(i);
            square=i*i;
            d=(long long)ceil(pow(10.00,digits));
            l=LeftPart(square,d);
            r=RightPart(square,d);
            sum=l+r;
            if(sum==i)
            {
                flag=1;
                cout<<i<<" ";
            }
        }
        if(!flag)
        {
            cout<<"INVALID RANGE";
        }
    }
    else
    {
        cout<<"INVALID RANGE";
    }
}
