//https://www.hackerrank.com/challenges/palindrome-index

#include<iostream>	
#include<string>	

using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int index = -1;
		int l;
		string s;
		cin >> s;
		l = s.length();
		if (l > 2)
		{
			for (int i = 0; i < l / 2; i++)
			{
				if (s.at(i) != s.at(l - i - 1))
				{
					if (s.at(i) == s.at(l - i - 2) && s.at(i + 1) == s.at(l - i - 3))
					{
						cout << "hi";
						index = l - i - 1;
					}
					else
					{
						index = i;
					}
					break;
				}
			}
		}
		else
		{
			if (l == 1)
			{
				cout << -1;
			}
			else
			{
				cout << 0;
			}
		}
		cout << index << endl;
	}
	system("pause");
}