// Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

// Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

// Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

// Example 1:

// Input: [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3
// Example 2:

// Input: [5,-3,5]
// Output: 10
// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10

#include <bits/stdc++.h>
using namespace std;

// Standard Kadane's algorithm to find maximum subarray sum
int kadane(int a[], int n);

// The function returns maximum circular contiguous sum in a[]
int maxCircularSum(int a[], int n)
{
    //  get the maximum sum using standard kadane's algorithm
    int max_kadane = kadane(a, n);

    // Now find the maximum sum that includes corner elements.
    int max_wrap = 0, i;
    for (i = 0; i < n; i++)
    {
        max_wrap += a[i]; // Calculate array-sum
        a[i] = -a[i];     // invert the array (change sign)
    }

    // max sum with corner elements will be array-sum - (-max subarray sum of inverted array)
    max_wrap = max_wrap + kadane(a, n);

    // The maximum circular sum will be maximum of two sums
    return ((max_wrap < max_kadane) || max_wrap == 0) ? max_kadane : max_wrap;
}
int kadane(int a[], int n)
{
    int max_so_far = 0, max_ending_here = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}