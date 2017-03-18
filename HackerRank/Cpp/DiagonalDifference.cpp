//https://www.hackerrank.com/challenges/diagonal-difference

#include<iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n][n],sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(i==j)
            {
                sum+=arr[i][j];
            }
            if(i==n-j-1)
            {
                sum-=arr[i][j];
            }
        }
    }
    cout<<fabs(sum);
}
