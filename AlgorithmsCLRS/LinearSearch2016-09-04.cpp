//This is a program to search an element using Linear Search Algorithm.

#include<iostream>

using namespace std;

int Search(int arr[],int n,int v)
{
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == v)
		{
			return i+1;
		}	
	}
	return 0;
}

int main()
{
	int n , v, pos;
	cout << "Enter number of elements : ";
	cin >> n;
	
	cout << "Enter " << n << " Elements : ";
	int arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	cout << "Enter element to search for : ";
	cin >> v;
	
	pos =  Search(arr,n,v);
	
	if(pos)
	{
		cout << "Element found at " << pos << " position.\n";
	}
	else
	{
		cout << "Element not found.\n";
	}
}
