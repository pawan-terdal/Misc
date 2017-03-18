//https://www.hackerrank.com/challenges/string-similarity

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int	pos[100001],k=0;
		int sum = 0, l;
		char s[100001], beg;
		cin >> s;
		l = strlen(s);
		beg = s[0];
		for (int i = 0; i < l-1; i++)
		{
			if (s[i] == beg)
			{
				pos[k]=i;
				k++;
			}
		}
		for (int i = 0; i < k; i++)
		{
			int start = pos[i], count = 1;
			for (int j = start+1; j < l; j++)
			{
				if (s[j] == s[j - start])
				{
					count++;
				}
				else
				{
					break;
				}
			}
			sum += count;
		}
		cout << sum << endl;
	}
	system("pause");
}