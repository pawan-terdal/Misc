//https://www.hackerrank.com/challenges/utopian-tree
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,h=1;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            if(i&1==1)
            {
                h*=2;
            }
            else
            {
                h+=1;
            }
        }
        cout<<h<<endl;
    }
}
