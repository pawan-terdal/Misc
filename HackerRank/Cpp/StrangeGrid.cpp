//https://www.hackerrank.com/challenges/strange-grid

#include<iostream>

using namespace std;

int main()
{
    long long r,c,m,num;
    cin>>r>>c;
    m=(r-1)/2;
    num=m*10;
    if(r%2==0)
    {
        num+=(c-1)*2+1;
    }
    else
    {
        num+=(c-1)*2;
    }
    cout<<num;
}
