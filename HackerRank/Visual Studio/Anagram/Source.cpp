//https://www.hackerrank.com/challenges/anagram

#include<iostream>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s, s1, s2;
		cin >> s;
		int l = s.length(), l1, l2, count = 0;
		int f1[26] = { 0 }, f2[26] = { 0 };
		s1 = s.substr(0, l / 2);
		l1 = l / 2;
		if (l % 2 != 0)
		{
			cout << "-1" << endl;
		}
		else
		{
			l2 = l1;
			s2 = s.substr(l / 2, l / 2);

			for (int i = 0; i < l1; i++)
			{
				char ch = tolower(s1.at(i));
				f1[ch - 97]++;
			}
			for (int i = 0; i < l2; i++)
			{
				char ch = tolower(s2.at(i));
				f2[ch - 97]++;
			}
			for (int i = 0; i < 26; i++)
			{
				if (f2[i] != 0 && (f2[i] > f1[i]))
				{
					count += f2[i] - f1[i];
				}
			}
			cout << count << endl;
		}
	}
	system("pause");
}