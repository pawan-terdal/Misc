//https://www.hackerrank.com/challenges/simple-array-sum

#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n],sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<sum;
}
