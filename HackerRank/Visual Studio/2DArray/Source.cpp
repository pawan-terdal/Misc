//https://www.hackerrank.com/challenges/2d-array

#include<iostream>

using namespace std;

int main()
{
	int mat[6][6] = { 0 };
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> mat[i][j];
		}
	}
	int max = -99999999,sum=0;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			sum = 0;
			sum += mat[i][j];
			for (int k = j - 1; k <= j + 1; k++)
			{
				sum += mat[i - 1][k] + mat[i + 1][k];
			}
			max = (sum > max) ? sum : max;
		}
	}
	cout << max << endl;
	system("pause");
}