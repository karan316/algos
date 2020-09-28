#include <bits/stdc++.h>

using namespace std;

// MY SOLUTION
// class Solution
// {
// public:
//     void merge(int arr1[], int arr2[], int n, int m)
//     {
//         // code here
//         int initial_gap = ceil((float)(n + m) / 2);
//         int gap = initial_gap;
//         int first_pointer = 0, second_pointer = first_pointer + gap;
//         ;

//         do
//         {
//             while (second_pointer < n + m)
//             {
//                 second_pointer = first_pointer + gap;
//                 if (first_pointer < n && second_pointer < n && arr1[first_pointer] > arr1[second_pointer])
//                 {
//                     swap(arr1[first_pointer], arr1[second_pointer]);
//                 }
//                 else if (first_pointer < n && second_pointer >= n && arr1[first_pointer] > arr2[second_pointer % initial_gap])
//                 {
//                     swap(arr1[first_pointer], arr2[second_pointer % initial_gap]);
//                 }
//                 else if (first_pointer >= n && second_pointer >= n && arr2[first_pointer % initial_gap] > arr2[second_pointer % initial_gap])
//                 {
//                     swap(arr2[first_pointer % initial_gap], arr2[second_pointer % initial_gap]);
//                 }
//                 first_pointer++;
//                 second_pointer = first_pointer + gap;
//             }
//             gap = ceil((float)gap / 2);
//             first_pointer = 0;
//             second_pointer = first_pointer + gap;

//         } while (gap != 1);
//     }
// };

class Solution
{
public:
    int nextGap(int gap)
    {

        if (gap <= 1)
            return 0;
        return ceil((float)gap / 2);
    }
    void merge(int arr1[], int arr2[], int n, int m)
    {
        int i, j, gap = n + m;
        for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
        {
            // comparing elements in the first array.
            for (i = 0; i + gap < n; i++)
                if (arr1[i] > arr1[i + gap])
                    swap(arr1[i], arr1[i + gap]);

            //comparing elements in both arrays.
            for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
                if (arr1[i] > arr2[j])
                    swap(arr1[i], arr2[j]);

            if (j < m)
            {
                //comparing elements in the second array.
                for (j = 0; j + gap < m; j++)
                    if (arr2[j] > arr2[j + gap])
                        swap(arr2[j], arr2[j + gap]);
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
