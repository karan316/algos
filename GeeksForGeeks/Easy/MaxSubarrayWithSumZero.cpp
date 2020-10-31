#include <bits/stdc++.h>
using namespace std;

int maxLen(int nums[], int n)
{
    unordered_map<int, int> index;
    int sum = 0, max_count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum == 0)
        {
            // whenever sum is zero update the count
            max_count = i + 1;
        }
        else
        {
            // if sum not zero and sum does not exist in the map insert it.
            if (index.count(sum) == 0)
            {
                index.insert(pair<int, int>(sum, i));
                // if it exists then update the max_count if the number of subarray elements is greater than the previous count.
            }
            else
            {
                max_count = max(max_count, i - index[sum]);
            }
        }
    }
    return max_count;
}
