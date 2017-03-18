//https://www.hackerrank.com/challenges/sherlock-and-squares
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int t;
    long arr[31623];
    for(long i=1;i<=31623;i++)
    {
        arr[i]=i*i;
    }
    cin>>t;
    while(t--)
    {
        int no=0;
        long a,b;
        cin>>a>>b;
        for(long i=1;arr[i]<=b;i++)
        {
            if(arr[i]>=a)
            {
                no++;
            }

        }
        cout<<no<<endl;
    }

}
