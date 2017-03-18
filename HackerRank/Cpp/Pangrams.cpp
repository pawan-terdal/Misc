//https://www.hackerrank.com/challenges/pangrams

#include<iostream>
#include<cctype>

using namespace std;

int main()
{
    int a[26]={0},isPan=1;
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
        char ch = toupper(s.at(i));
        a[ch-65]++;
    }

    for(int i=0;i<26;i++)
    {
        if(a[i]==0)
        {
            isPan=0;
            break;
        }
    }
    if(isPan)
    {
        cout<<"pangram";
    }
    else
    {
        cout<<"not pangram";
    }
}
