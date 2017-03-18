//https://www.hackerrank.com/challenges/plus-minus

#include<iostream>

using namespace std;

int main()
{
    int n,np=0,nn=0,nz=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>0)
        {
            np++;
        }
        else if(arr[i]<0)
        {
            nn++;
        }
        else
        {
            nz++;
        }
    }
    cout<<(float)np/n<<endl;
    cout<<(float)nn/n<<endl;
    cout<<(float)nz/n<<endl;
}
