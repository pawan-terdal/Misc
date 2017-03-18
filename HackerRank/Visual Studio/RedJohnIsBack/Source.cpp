//https://www.hackerrank.com/challenges/red-john-is-back

#include<iostream>
#include<cmath>

using namespace std;

long long fact(int n)
{
	int fact = 1;
	for (int i = 2; i <= n; i++)
	{
		fact *= i;
	}

	return fact;
}
long long comb(int num, int den)
{

	long long val = 0;
	for (int i = 1; i <= den; i++)
	{
		val += fact(num) / fact(i) / fact(num - i);
	}
	cout << " "<< val << endl;
	return val;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long total = 1;
		int n;
		cin >> n;
		int nH = n / 4, nV = n % 4;
		int tnH = nH, tnV = nV;
		while (tnV < n)
		{
			cout << tnH << " " << tnV;
			if (tnH>=tnV)
			{
				total += comb(tnH + 1, tnV);
			}
			else
			{
				total += comb(tnV + 1, tnH);
			}
			tnH--;
			tnV += 4;
		}
		cout << total << endl;
	}
}