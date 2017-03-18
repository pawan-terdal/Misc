//https://www.hackerrank.com/challenges/cut-the-sticks
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int k=0;
    cout<<n<<endl;
    while(a[n-1]!=0)
    {
        int no=0;
        for(int i=n-1;i>=0;i--)
        {
            a[i]=a[i]-a[k];
            if(a[i]!=0)
            {
                no++;
            }
            else
            {
                k=i+1;
                break;
            }
        }
        if(no==0)
        {
            break;
        }
        cout<<no<<endl;
    }

}
