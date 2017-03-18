//https://www.hackerrank.com/challenges/caesar-cipher-1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctype.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    char s[n+1];
    cin >> s;
    int k;
    cin >> k;
    k=k%26;
    int t;
    for(int i=0;i<n;i++)
    {
        char ch = s[i];
        if(isalpha(ch))
        {
            if(isupper(ch))
            {
                if(k+ch>90)
                {
                    ch=64+(k+ch)%90;
                }
                else
                {
                    ch=k+ch;
                }
            }
            else
            {
                if(k+ch>122)
                {
                    ch=96+(k+ch)%122;
                }
                else
                {
                    ch=k+ch;
                }
            }
        }
        s[i]=ch;
    }
    cout<<s;
    return 0;
}
