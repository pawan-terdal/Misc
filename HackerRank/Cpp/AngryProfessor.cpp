//https://www.hackerrank.com/challenges/angry-professor

#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,count=0;
        cin>>n>>k;
        int arr[10000];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]<=0)
            {
                count++;
            }
        }
        if(count>=k)
        {
            cout<<"NO";
        }
        else
        {
            cout<<"YES";
        }
        cout<<endl;
    }
}
