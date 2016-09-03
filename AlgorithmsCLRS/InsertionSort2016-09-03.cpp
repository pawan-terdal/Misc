#include<iostream>
using namespace std;

void Sort(int arr[],int n)
{
	for(int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i-1;
		while(j >= 0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main()
{
	int n;
	cout << "Enter Number Of Elements : ";
	cin >> n;
	int arr[n];

	cout << "Enter " << n << " Elements : ";
	for(int i = 0; i < n ; i++)
	{
		cin >> arr[i];
	}

	Sort(arr,n);

	cout<<"Sorted Array : ";
	for(int i = 0; i < n ; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
