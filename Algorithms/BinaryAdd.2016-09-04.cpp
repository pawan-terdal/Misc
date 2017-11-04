//To add two binary n - bit numbers

#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int n, carry = 0;
	cout << "Enter number of bits : ";
	cin >> n;
	int num1[n+1],num2[n+1],num3[n+1];
	
	num1[n] = num2[n] = 0;
	
	cout << "Enter the first binary number : ";
	getchar();
	for(int i = n - 1; i>=0;i--)
	{
		num1[i] = getchar();
	}

	
	cout << "Enter the second binary number : ";
	getchar();
	for(int i = n - 1; i>=0;i--)
	{
		num2[i] = getchar();
	}

	for(int i = 0; i <= n ; i++)
	{
		num3[i] = (num1[i] + num2[i] + carry)%2;
		carry = num1[i]*num2[i] + num2[i]*carry + num1[i]*carry;
	}

	cout << "The Added Binary Number is : ";
	for(int i = n; i>=0; i--)
	{
		cout << num3[i];
	}
	
	cout << endl;
}
