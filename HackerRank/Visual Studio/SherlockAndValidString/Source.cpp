//https://www.hackerrank.com/challenges/sherlock-and-valid-string

#include<iostream>
#include<string>	
#include<cstring>

using namespace std;

int main()
{
	char s[100001];
	cin >> s;
	int fa[26] = { 0 }, l = strlen(s);
	for (int i = 0; i < l; i++)
	{
		fa[s[i] - 97]++;
	}
	int diff, f1, f2, i, no1 = 0, no2 = 0, no3 = 0;
	for (i = 0; i < 26; i++)
	{
		if (fa[i] != 0)
		{
			f1 = fa[i];
			break;
		}
	}
	for (; i < 26; i++)
	{
		if (fa[i] != 0 && fa[i] != f1)
		{
			f2 = fa[i];
			break;
		}
	}
	for (i = 0; i < 26; i++)
	{
		if (fa[i] == f1)
		{
			no1++;
		}
		else if (fa[i] == f2)
		{
			no2++;
		}
		else if (fa[i]!=0)
		{
			no3++;
		}

	}
	if (no1 != 0 && no2 != 0 && no3 != 0)
	{
		cout << "NO";
	}
	else if (no1 <= 1 || no2 <= 1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	cout << endl;
	system("pause");
}