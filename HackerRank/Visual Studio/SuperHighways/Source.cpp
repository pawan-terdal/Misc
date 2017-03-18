//https://www.hackerrank.com/contests/round-2-holiday-cup/challenges/super-highways

#include<iostream>
#include<cmath>
using namespace std;

#define div 1000000009

int main()
{
	long t;
	cin >> t;
	while (t--)
	{
		long long n, k, c, totalCost = 0;
		cin >> n >> k >> c;
		k %= div;
		c %= div;

		if (n == 1)
		{
			cout << 0 << endl;
		}
		else if (n == 2)
		{
			cout << (k + c) % div << endl;
		}
		else
		{
			totalCost = n*(n - 1)*(n + 1) / 6 * k + n*(n - 1) / 2 * c;
			cout << totalCost << endl;
		}
	}
	system("pause");
}