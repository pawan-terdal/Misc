//https://www.hackerrank.com/challenges/30-operators

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double a, b, c, total;
	cin >> a >>b >> c;
	total = a + b / 100 * a + c / 100 * a;
	cout << "The total meal cost is " << round(total) << " dollars";
}