//https://www.hackerrank.com/challenges/bear-and-steady-gene

#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	int count = 0, lSub = 0, f[4] = { 0 }, opt = 0, l;
	vector<int> s(500000);
	string str;
	char ch;
	cin >> l;
	opt = l / 4;
	cin >> str;
	for (int i = 0; i < l; i++)
	{
		ch = str.at(i);
		if (ch == 'A')
		{
			s[i] = 0;
			f[0]++;
		}
		else if (ch == 'T')
		{
			s[i] = 1;
			f[1]++;
		}
		else if (ch == 'G')
		{
			s[i] = 2;
			f[2]++;
		}
		else
		{
			s[i] = 3;
			f[3]++;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (f[i] > opt)
		{
			f[i] = (int)fabs(f[i] - opt);
			lSub += f[i];
		}
		else
		{
			f[i] = 0;
		}
	}

	while (true)
	{
		int g[4] = { 0 }, complete = 0;
		for (int j = 0; j < lSub; j++)
		{
			g[s[j]]++;
		}
		if (g[0] >= f[0] && g[1] >= f[1] && g[2] >= f[2] && g[3] >= f[3])
		{
			break;
		}
		int j = 0;
		while (j + lSub < l)
		{
			g[s[j]]--;
			g[s[j + lSub]]++;
			if (g[0] >= f[0] && g[1] >= f[1] && g[2] >= f[2] && g[3] >= f[3])
			{
				complete = 1;
				break;
			}
			j++;
		}
		if (complete)
		{
			break;
		}
		else
		{
			lSub++;
		}
	}
	cout << lSub << endl;
	system("pause");
}

