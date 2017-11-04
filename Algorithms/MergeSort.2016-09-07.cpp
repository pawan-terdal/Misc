//This a program to sort elements using merge sort.

#include<iostream>

using namespace std;

void Merge(int arr[],int p,int q,int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int arr1[n1+1];
	int arr2[n2+1];
	for(int i = 0; i < n1; i++)
	{
		arr1[i] = arr[p+i];
	}
	for(int i = 0; i < n1; i++)
	{
		arr2[i] = arr[q+i+1];
	}
	arr1[n1] = 99999;
	arr2[n2] = 99999;
	int i = 0, j = 0;
	for(int k = p; k <=r;k++)
	{
		if(arr1[i] <= arr2[j])
		{
			arr[k] = arr1[i];
			i++;
		}
		else
		{
			arr[k] = arr2[j];
			j++;
		}
	}
}

void MergeSort(int arr[],int p,int r)
{
	if(p < r)
	{
		int q = (p + r)/2;
		MergeSort(arr,p,q);
		MergeSort(arr,q+1,r);
		Merge(arr,p,q,r);
	}
}

int main()
{
	int n;
	cout << "Enter number of elements : ";
	cin >> n;
	int arr[n];
	cout << "Enter " << n << " Elements : ";
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	MergeSort(arr,0,n-1);

	cout << "Sorted Array : ";
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
