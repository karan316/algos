// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

// Example 1:
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
// Example 2:
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray

#include <bits/stdc++.h>

using namespace std;

// 0 0 1 1 0 1 0 1 0 0 0 0 0 1 0 1 0 1 0 1
int main()
{
    // vector<int> nums = {0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1};
    vector<int> nums = {0, 1};
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == 0)
        {
            nums[i] = -1;
        }
    }

    int answer = 0;

    vector<int> pref;

    pref.push_back(0);
    for (int x : nums)
    {
        pref.push_back(pref.back() + x);
    }
    unordered_map<int, int> first_oc;
    for (int i = 0; i < (int)pref.size(); i++)
    {
        int x = pref[i];
        auto it = first_oc.find(x);
        if (it != first_oc.end())
        {
            answer = max(answer, i - first_oc[x]);
        }
        else
        {
            first_oc[x] = i;
        }
    }

    cout << answer;
} //O(n) space and time