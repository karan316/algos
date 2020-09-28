#include <iostream>
using namespace std;

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

int main()
{
    int a[100];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
}