//https://www.hackerrank.com/challenges/the-love-letter-mystery

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
		int l, ops = 0;
		string s = "";
		cin >> s;
		l = s.length();
		for (int i = 0; i < l / 2; i++)
		{
			ops += fabs(s.at(i) - s.at(l - i - 1));
		}
		cout << ops << endl;
	} 
	system("pause");
}