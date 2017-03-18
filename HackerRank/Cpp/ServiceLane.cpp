//https://www.hackerrank.com/challenges/service-lane
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> width(n);
    for(int i = 0; i < n; i++)
    {
        cin>>width[i];
    }
    while(t--)
    {
        int k = 3;
        int a, b;
        cin >> a >> b;
        for(int i = a; i <= b; i++)
        {
            if(width[i] == 2)
            {
                k = 2;
            }
            if(width[i] == 1)
            {
                k = 1;
                break;
            }
        }
        cout << k <<endl;
    }
}
