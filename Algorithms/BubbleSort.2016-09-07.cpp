//Sorting using Bubble Sort

#include<iostream>

using namespace std;

void Sort(int arr[],int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - 1 - i; j++)
		{
			if(arr[j+1] < arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main()
{
	int n;
	cout << "Enter N Elements : ";
	cin >> n;
	int arr[n];
	cout  << "Enter " << n << " Elements : ";
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	Sort(arr,n);

	cout << "Sorted Array : ";
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
