//https://www.hackerrank.com/challenges/cavity-map

#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n,l;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    l=s[0].length();
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<l-1;j++)
        {
            int flag=0;
            if(s[i].at(j)>s[i].at(j-1) && s[i].at(j)>s[i].at(j+1) && s[i].at(j)>s[i-1].at(j) && s[i].at(j)>s[i+1].at(j))
            {
                flag=1;
            }
            if(flag)
            {
                s[i].replace(j,1,"X");
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
}
