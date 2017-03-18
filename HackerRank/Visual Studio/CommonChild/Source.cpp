//https://www.hackerrank.com/challenges/common-child

#include<iostream>
#include<cstring>
#include<cmath>
#include<string>

using namespace std;

int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int main()
{
	int f1[26] = { 0 }, f2[26] = { 0 };
	char a[5002], b[5002];
	string ma = "", mb = "";
	int l1, l2;
	cin >> a;
	cin >> b;
	l1 = strlen(a);
	l2 = strlen(b);
	for (int i = 0; i < l1; i++)
	{
		f1[a[i] - 65]++;
	}
	for (int i = 0; i < l2; i++)
	{
		f2[b[i] - 65]++;
	}
	for (int i = 0; i < 26; i++)
	{
		f1[i] = min(f1[i], f2[i]);
		f2[i] = f1[i];
	}

	for (int i = 0; i < l1; i++)
	{
		if (f1[a[i] - 65]>0)
		{
			ma += a[i];
		}
	}

	for (int i = 0; i < l2; i++)
	{
		if (f2[b[i] - 65]>0)
		{
			mb += b[i];
		}
	}
	cout << ma << endl;
	cout << mb << endl;
	system("pause");
}