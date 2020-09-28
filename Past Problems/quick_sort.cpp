#include <iostream>
using namespace std;

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

    quickSort(a, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
}
