//https://www.hackerrank.com/challenges/alternating-characters

#include<iostream>
#include<string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n = 0;
		string s;
		cin >> s;
		char ch = s.at(0);
		for (int i = 1; i < s.length(); i++)
		{
			if (s.at(i) == ch)
			{
				n++;
			}
			else
			{
				ch = s.at(i);
			}
		}
		cout << n << endl;
	}
}