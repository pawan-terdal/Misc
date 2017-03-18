//https://www.hackerrank.com/challenges/bear-and-workbook

#include<iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int t[n];
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
    }

    int no=0,page=1,i,j;

    for(i=0;i<n;i++)
    {
        for(j=1;j<=t[i];j++)
        {
            if(j==page)
            {
                no++;
            }
            if(j%k==0)
            {
                page++;
            }
        }
        if((j-1)%k!=0)
        {
            page++;
        }
    }
    cout<<no;
}
