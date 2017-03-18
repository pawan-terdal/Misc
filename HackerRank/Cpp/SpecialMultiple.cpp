//https://www.hackerrank.com/challenges/special-multiple

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int num,complete=0,count=2;
        vector <long> arr(10000);
        arr[0]=0;
        arr[1]=9;
        cin>>num;
        if(9%num==0)
        {
            cout<<9<<endl;
            continue;
        }
        long long a=9;
        while(true)
        {
            a*=10;
            int l=count;
            for(int i=0;i<l;i++)
            {
                arr[l+i]=a+arr[i];
                count++;
                if(arr[l+i]%num==0)
                {
                    cout<<arr[l+i]<<endl;
                    complete=1;
                    break;
                }
            }
            if(complete)
            {
                break;
            }
        }
    }

}
