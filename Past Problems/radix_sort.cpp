#include <iostream>
using namespace std;

// A utility function to get maximum value in arr[]
int getMax(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

// A function to do counting sort of arr[] according to the digit represented by exp.
void countSort(int a[], int n, int exp)
{
	int temp[n]; // output array
	int i, count[10] = {0};

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		temp[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		a[i] = temp[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixSort(int a[], int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(a, n);

	/* Do counting sort for every digit. Note that instead 
	of passing digit number, exp is passed. exp is 10^i 
	where i is current digit number */
	for (int exp = 1; m / exp > 0; exp = exp * 10)
		countSort(a, n, exp);
}

int main()
{
	int a[10];
	cout << "Enter the array size\n";
	int n;
	cin >> n;
	cout << "Enter the array elements\n";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	radixSort(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
