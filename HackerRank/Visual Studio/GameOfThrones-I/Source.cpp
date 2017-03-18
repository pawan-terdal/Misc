//https://www.hackerrank.com/challenges/game-of-thrones

#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main()
{
	int l, f[26] = { 0 }, excuse = 0;
	string s;
	cin >> s;
	l = s.length();
	if (l % 2 == 0)
	{
		excuse = 0;
	}
	else
	{
		excuse = 1;
	}
	for (int i = 0; i < l; i++)
	{
		f[toupper(s.at(i)) - 65]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (f[i] % 2 != 0)
		{
			excuse--;
		}
	}
	if (!excuse)
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