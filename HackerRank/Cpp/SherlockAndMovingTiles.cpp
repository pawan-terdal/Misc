//https://www.hackerrank.com/challenges/sherlock-and-moving-tiles

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    long l,s1,s2,q;
    long double qi;
    long double t;
    cin>>l>>s1>>s2;
    cin>>q;
    while(q--)
    {
        cin>>qi;
        t=(l*sqrt(2.0)-sqrt(2.0*qi))/fabs(s2-s1);
        cout<<t<<endl;
    }
}

