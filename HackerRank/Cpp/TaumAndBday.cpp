//https://www.hackerrank.com/challenges/taum-and-bday
#include<iostream>
using namespace std;
int main()
{
    int t;
    long x,y,z,b,w;
    cin>>t;
    while(t--)
    {
        cin>>b>>w>>x>>y>>z;
        if(x>y+z)
            x=y+z;
        else if(y>x+z)
            y=x+z;
        cout<<b*x+w*y<<endl;
    }
}
