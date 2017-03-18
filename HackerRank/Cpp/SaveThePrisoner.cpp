//https://www.hackerrank.com/contests/101hack35/challenges/save-the-prisoner

#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long n,m,s;
        cin>>n>>m>>s;
        cout<<((m+s-2)%n)+1<<endl;
    }
}
