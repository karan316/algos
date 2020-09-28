#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int a[], int n, int i)
{
    int largest = i;       // Initialize largest as root
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

void merge(int *a, int start, int end)
{
    int mid = (start + end) / 2;

    int i = start;
    int j = mid + 1;
    int k = start;

    int temp[100];

    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= end)
    {
        temp[k++] = a[j++];
    }
    //We need to copy all element to original arrays
    for (int i = start; i <= end; i++)
    {
        a[i] = temp[i];
    }
}

void mergeSort(int a[], int start, int end)
{
    //Base case 1 or 0 elements
    if (start >= end)
    {
        return;
    }

    //Follow 3 steps
    //1. Divide
    int mid = (start + end) / 2;

    //Recursively the arrays - s,mid and mid+1,e
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);

    //Merge the two parts
    merge(a, start, end);
}

int partition(int *A, int start, int end)
{
    int pivot = A[end - 1];
    int partition_index = start; //set partition index as start initially
    for (int i = start; i < end; i++)
    {
        if (A[i] <= pivot)
        {
            swap(A[i], A[partition_index]); //swap if element is lesser than pivot
            partition_index++;
        }
    }
    swap(A[partition_index], A[end]); //swap pivot with element at partition index in the end
    return partition_index;
}

void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void quickSort(int *A, int start, int end)
{
    if (start < end)
    {
        int partiton_index = partition(A, start, end);
        quickSort(A, start, partiton_index - 1);
        quickSort(A, partiton_index + 1, end);
    }
}

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
    int ch;
    cout << "1. Quick Sort\n2. Merge Sort \n3. Radix Sort \n4. Heap Sort\n ";
    cout << "Enter the sorting technique\n";
    cin >> ch;
    switch (ch)
    {
    case 1:
        quickSort(a, 0, n);
        break;
    case 2:
        mergeSort(a, 0, n - 1);
        break;
    case 3:
        radixSort(a, n);
        break;
    case 4:
        heapSort(a, n);
        break;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
