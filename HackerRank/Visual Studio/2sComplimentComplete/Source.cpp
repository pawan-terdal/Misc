// C++

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

long long cc(long long A)
{
	int ret = 0;
	for (int i = 0; i < 32; i++) {
		ret += (A & (1 << i)) > 0;
	}
	return (long long)ret;
}

int high(long long A)
{
	int i;
	for (i = 32; i >= 0; i--) {
		if ((A & (1LL << i)) != 0)
			return i;
	}
	return 0;
}

long long res(long long A)
{
	assert(A >= 0LL);
	if (A == 0LL) return 0LL;

	// if(A > 1000000LL)
	//   printf("%lld: %d\n", A, high(A));
	fflush(stdout);
	long long h = high(A);
	long long ret;
	if (A == (long long)(1LL << (h + 1LL)) - 1LL)
	{
		ret = 2LL * res(A >> 1LL) + ((A + 1LL) >> 1LL);
	}
	else {
		long long mask = (1LL << h);
		ret = res((1LL << h) - 1LL) + res(A ^ mask) + (A - (1LL << h) + 1LL);
	}
	return ret;
}

long long comp23(int a)
{
	long long ret = 0;
	//cout << "------" << endl << a << endl;
	for (int i = 0; i < 32; i++)
	{
		if ((a & (1 << i)) != 0)
		{
			//  cout << "1";
			ret += (1LL << i);
		}
		else {
			// cout << "0";
		}
	}
	// cout << endl << "--------" << endl;
	return ret;
}

int main()
{
	int sA, sB;
	long long A, B;
	int N;
	cin >> N;
	while (N--)
	{
		cin >> sA >> sB;
		A = comp23(sA);
		B = comp23(sB);
		long long retans;
		if (A == 0) {
			retans = res(B);
		}
		else if (sB < 0) {
			retans = res(B) - res(A) + cc(A);
		}
		else if (sA < 0) {
			retans = res(comp23(-1)) - res(A) + cc(A) + res(B);
		}
		else {
			retans = res(B) - res(A) + cc(A);
		}

		printf("%lld\n", retans);
		//cout << endl;
		//cout << ret << endl;
	}
	system("pause");
	return 0;
}
