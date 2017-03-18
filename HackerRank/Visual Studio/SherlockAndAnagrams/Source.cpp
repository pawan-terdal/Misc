//https://www.hackerrank.com/challenges/sherlock-and-anagrams

#include<iostream>
#include<string>
#include<cctype>
#include<cstring>

using namespace std;

char s[101];
int l;

int ok(int f1[],int f2[])
{
	for (int i = 0; i < 26; i++)
	{
		if (f1[i] != f2[i])
		{
			return 0;
		}
	}
	return 1;
}

void display(int f[])
{
	for (int i = 0; i < 26; i++)
	{
		if (f[i] != 0)
		{
			cout << f[i] << " " << char(i + 97) << endl;
		}
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int count = 0;
		cin >> s;		
		l = strlen(s);
		for (int i = 1; i < l; i++)
		{
			int f1[26] = { 0 }, l1 = 0;
			int a = 0, b = 0;
			while (a < l-i)
			{
				while (b < l-1  && l1 < i)
				{
					f1[s[b] - 97]++;
					b++;
					l1++;
				}

				int l2 = 0, f2[26] = {0};
				int c = a+1, d = a+1;
				while (c < l - i + 1)
				{
					while (d < l && l2 < i)
					{
						f2[s[d] - 97]++;
						d++;
						l2++;
					}
					//display(f2);
					if (ok(f1,f2))
					{
						//cout << a << b << " " << c << d << endl;
						count++;
					}

					f2[s[c] - 97]--;
					c++;
					l2--;
				}
				f1[s[a] - 97]--;
				a++;
				l1--;
			}
		}
		cout<<count<<endl;
	}
	system("pause");
}