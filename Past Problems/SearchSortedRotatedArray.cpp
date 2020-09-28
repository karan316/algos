// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3, 1};
    int target = 1;
    int pivot = 0;
    if (nums.size() == 0)
        return -1;
    if (nums.size() == 1 && nums[0] != target)
    {
        return -1;
    }
    else if (nums.size() == 1 && nums[0] == target)
    {
        return 0;
    }
    int j;
    for (j = 1; j < nums.size(); j++)
    {
        if (nums[j] < nums[j - 1])
        {
            pivot = j;
        }
    }
    if (j == nums.size())
    {
        pivot = nums.size();
    }

    if (pivot == nums.size())
    {
        auto it = find(nums.begin(), nums.end(), target);
        if (it == nums.end())
        {
            cout << "-1\n";
            return 0;
        }
        cout << distance(nums.begin(), it) << "\n";
        return 0;
    }

    if (target >= nums[0])
    {
        auto it = find(nums.begin(), nums.begin() + pivot, target);
        if (it == nums.begin() + pivot)
        {
            cout << "-1\n";
            return 0;
        }
        cout << distance(nums.begin(), it) << "\n";
    }
    else
    {
        auto it = find(nums.begin() + pivot, nums.end(), target);
        if (it == nums.end())
        {
            cout << "-1\n";
            return 0;
        }
        cout << distance(nums.begin(), it) << "\n";
    }
}