//https://www.hackerrank.com/challenges/two-strings

#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int flag = 0;
		int fa[26] = { 0 };
		string a, b;
		cin >> a;
		cin >> b;
		for (int i = 0; i < a.length(); i++)
		{
			fa[tolower(a.at(i))-97]++;
		}
		for (int i = 0; i < b.length(); i++)
		{
			if (fa[tolower(b.at(i))-97] != 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
		cout << endl;
	}
	system("pause");
}