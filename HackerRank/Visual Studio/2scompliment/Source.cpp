//https://www.hackerrank.com/contests/codebusting/challenges/2s-complement

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;



int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int max;
		vector<int> arr;
		arr.push_back(0);
		arr.push_back(1);
		int a, b;
		cin >> a >> b;
		max = (fabs(a) > fabs(b)) ? fabs(a) : fabs(b);
		int noOfOnes = 1, value = 1;
		while (value != max + 2)
		{
			int temp = arr.size();
			for (int i = 0; i < temp; i++)
			{
				arr.push_back(arr[i] + 1);
				noOfOnes += arr[temp + i];
				value++;
				if (value == max + 2)
				{
					break;
				}
			}
		}
		int n = 0;
		if (a >= 0 && b >= 0)
		{
			for (int i = a; i <= b; i++)
			{
				n += arr[i];
			}
		}
		else if (a < 0 && b >= 0)
		{
			for (int i = -1; i >= a; i--)
			{
				n += (32 - arr[fabs(i) - 1]);
			}
			for (int i = 0; i <= b; i++)
			{
				n += arr[i];
			}
		}
		else
		{
			for (int i = fabs(b); i <= fabs(a); i++)
			{
				n += (32 - arr[fabs(i) - 1]);
			}
		}
		cout << n << endl;
	}
	system("pause");
}