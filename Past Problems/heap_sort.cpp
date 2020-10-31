#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int a[], int n, int i)
{
	int largest = i;	   // Initialize largest as root
	int left = 2 * i + 1;  // left = 2*i + 1
	int right = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (left < n && a[left] > a[largest])
		largest = left;

	// If right child is larger than largest so far
	if (right < n && a[right] > a[largest])
		largest = right;

	// If largest is not root
	if (largest != i)
	{
		swap(a[i], a[largest]);

		// Recursively heapify the affected sub-tree
		heapify(a, n, largest);
	}
}

// main function to do heap sort
void heapSort(int a[], int n)
{
	// Build heap (rearrange array)
	for (int i = (n / 2) - 1; i >= 0; i--)
		heapify(a, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(a[0], a[i]);
		// call max heapify on the reduced heap
		heapify(a, i, 0);
	}
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

	heapSort(a, n);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << "\n";
}
