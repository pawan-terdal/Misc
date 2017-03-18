//https://www.hackerrank.com/challenges/funny-string

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int isFunny = 1;
		string s;
		cin >> s;
		int l = s.length();
		for (int i = 0; i < l / 2; i++)
		{
			if (fabs(s.at(i + 1) - s.at(i)) != fabs(s.at(l - 1 - i) - s.at(l - 2 - i)))
			{
				isFunny = 0;
				break;
			}
		}
		if (isFunny)
		{
			cout << "Funny";
		}
		else
		{
			cout << "Not Funny";
		}
		cout << endl;
	}
	system("pause");
}