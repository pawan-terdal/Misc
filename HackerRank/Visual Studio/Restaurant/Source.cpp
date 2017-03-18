//https://www.hackerrank.com/challenges/restaurant

#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int l, b;
		cin >> l >> b;
		int n = l, m = b,c;
		while (m != 0)
		{
			c = n%m;
			n = m;
			m = c;
		}
		cout << l*b / (n*n) << endl;
	}
	system("pause");
}