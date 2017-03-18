#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int f[26] = { 0 };
	for (int i = 0; i < s.length(); i++)
	{
		f[s.at(i) - 97]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (f[i] != 0)
		{
			cout << char(97 + i) << " " << f[i] << endl;
		}
	}
	system("pause");
}