//https://www.hackerrank.com/challenges/the-grid-search
#include <vector>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int m=0;m<t;m++)
    {

        int r1, r2, c1, c2, flag=0,pos=-1,prevpos=-1;
        string s1[1005], s2[1005];
        cin>>r1>>c1;
        for(int i=0;i<r1;i++)
        {
            cin>>s1[i];
        }
        cin>>r2>>c2;
        getchar();
        for(int i=0;i<r2;i++)
        {
            cin>>s2[i];
        }
        for(int i=0;i<=r1-r2;i++)
        {
            flag=0;
            for(int j=0;j<=c1-c2;j++)
            {
                int k=0;
                for(k=0;k<r2;k++)
                {
                    if((int)(s2[k].compare(s1[i+k].substr(j,c2)))!=0)
                    {
                        break;
                    }
                }
                if(k==r2)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                break;
            }

        }
        cout << (flag? "YES" : "NO")<<"\n";
    }
    exit(1);
}
