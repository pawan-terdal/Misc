//Sorting using selection sort algorithm.

#include<iostream>

using namespace std;

void Sort(int arr[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		int min = i;
		
		for(int j = i + 1; j < n; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

int main()
{
	int n;
	cout << "Enter Number Of Elements : ";
	cin >> n;
	int arr[n];
	cout << "Enter " << n << " Elements : ";
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
