//https://www.hackerrank.com/challenges/library-fine
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int d1;
    int m1;
    int y1;
    cin >> d1 >> m1 >> y1;
    int d2;
    int m2;
    int y2;
    cin >> d2 >> m2 >> y2;
    if(y2<y1)
    {
        cout<<10000;
    }
    else if(y2==y1)
    {
        if(m2<m1)
        {
            cout<<(m1-m2)*500;
        }
        else if(m2==m1)
        {
            if(d2<d1)
            {
                cout<<(d1-d2)*15;
            }
            else
            {
                cout<<0;
            }
        }
        else
        {
            cout<<0;
        }
    }
    else
    {
        cout<<0;
    }
    return 0;
}
