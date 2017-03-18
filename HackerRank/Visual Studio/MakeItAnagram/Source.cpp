//https://www.hackerrank.com/challenges/make-it-anagram

#include<iostream>
#include<string>
#include<cctype>
#include<cmath>

using namespace std;

int main()
{
	int l1, l2, f1[26] = { 0 }, f2[26] = { 0 }, count = 0;
	string s1, s2;
	cin >> s1 >> s2;
	l1 = s1.length();
	l2 = s2.length();
	for (int i = 0; i < l1; i++)
	{
		f1[toupper(s1.at(i)) - 65]++;
	}
	for (int i = 0; i < l2; i++)
	{
		f2[toupper(s2.at(i)) - 65]++;
	}
	for (int i = 0; i < 26; i++)
	{
		count += (int)fabs(f1[i] - f2[i]);
	}
	cout << count << endl;
	system("pause");
}