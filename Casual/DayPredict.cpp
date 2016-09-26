#include <iostream>

using namespace std;

int main()
{
    int leapD = 366, normalD = 365, isLeap = 0;
    int leapDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int normalDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, count = 0;

    cout << "Enter year : ";
    cin >> year;

    long long day = 0;

    for (int i = 1776; i < year; i++)
    {
	if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
	{
	    day = (day + leapD) % 7;
	}
	else
	{
	    day = (day + normalD) % 7;
	}
    }

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
	isLeap = 1;
    }

    cout << "First Day of Year is : " << day << endl;
    for (int i = 0; i < 12; i++)
    {
	if (day == 0)
	{
	    count++;
	}
	if (isLeap)
	{
	    day = (day + leapDays[i]) % 7;
	}
	else
	{
	    day = (day + normalDays[i]) % 7;
	}
    }

    cout << "Number of 1st Day of the Month(which are Monday are) : " << count << endl;
}
