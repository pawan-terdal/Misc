//https://www.hackerrank.com/challenges/chocolate-feast
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c,m,total=0,nw,q,r;
        cin>>n>>c>>m;
        nw=n/c;
        total=nw;
        while(nw>=m)
        {
            q=nw/m;
            r=nw%m;
            nw=q+r;
            total+=q;
        }
        cout<<total<<endl;
    }
}
