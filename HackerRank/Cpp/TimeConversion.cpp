//https://www.hackerrank.com/challenges/time-conversion

#include<iostream>

using namespace std;

int main()
{
    char s[12];
    cin>>s;
    int hh=(s[0]-48)*10+(s[1]-48);
    int mm=(s[3]-48)*10+(s[4]-48);
    int ss=(s[6]-48)*10+(s[7]-48);
    char td=s[8];
    if(td=='A')
    {
        if(hh==12)
        {
            hh=0;
        }
    }
    else
    {
        if(hh!=12)
        {
            hh=hh+12;
        }
    }
    if(hh<10)
    {
        cout<<0<<hh;
    }
    else
    {
        cout<<hh;
    }
    cout<<":";
    if(mm<10)
    {
        cout<<0<<mm;
    }
    else
    {
        cout<<mm;
    }
    cout<<":";
    if(ss<10)
    {
        cout<<0<<ss;
    }
    else
    {
        cout<<ss;
    }
    return 0;
}
