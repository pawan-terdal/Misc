//https://www.hackerrank.com/challenges/gem-stones

#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n, count = 0;
	cin >> n;
	string s[100] = {""};
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 97; i <= 122; i++)
	{
		int flag = 1;
		for (int j = 0; j < n; j++)
		{
			if (s[j].find((char)i) == -1)
			{
				flag = 0;
				break;
			}
		}
		count += flag;		
	}
	cout << count <<endl;
	system("pause");
}