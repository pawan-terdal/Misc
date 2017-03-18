//https://www.hackerrank.com/challenges/larrys-array

#include<iostream>
#include<cmath>

using namespace std;

void Rotate(int *a,int *b,int *c)
{
    if(max(max(*a,*b),*c) == *c)
    {
        return;
    }
    else if(max(*a,max(*b,*c))==*a)
    {
        int temp = *a;
        *a=*b;
        *b=*c;
        *c=temp;
    }
    else
    {
        int temp= *c;
        *c=*b;
        *b=*a;
        *a=temp;
    }
}

int IsSorted(int a[],int n)
{
    int isSorted=1;
    for(int i=0;i<3;i++)
    {
        if(a[i]>a[i+1])
        {
            isSorted=0;
            break;
        }
    }
    return isSorted;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(int i=n-1,k=0;i>=2;i--,k++)
        {
            int j;
            for(j=1;j<n-k-1;j+=2)
            {
                Rotate(a+j-1,a+j,a+j+1);
            }
            Rotate(a+i-2,a+i-1,a+i);
        }

        if(IsSorted(a,n))
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }

        if(t!=0)
        {
            cout<<endl;
        }
    }
}
