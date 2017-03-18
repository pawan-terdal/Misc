//https://www.hackerrank.com/challenges/manasa-and-stones

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        int mini=min(a,b);
        int maxi=max(a,b);
        long sum=0;
        if(a!=b)
        {
            for(int i=0;i<n;i++)
            {
                sum=(n-i-1)*mini+i*maxi;
                cout<<sum<<" ";
            }
        }
        else
        {
            cout<<(n-1)*a;
        }
        cout<<endl;
    }
}
