#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int merge(vector<int> &nums, int low, int mid, int high)
    {
        int count = 0;
        int j = mid + 1;
        //         for every element in left array
        for (int i = low; i <= mid; i++)
        {
            //             increment j until j is out of bounds or left ele is less than x2 of right element
            while (j <= high && nums[i] > 2LL * nums[j])
            {
                j++;
            }
            //             calculate count based on j and mid
            count += (j - (mid + 1));
        }

        vector<int> temp;
        int left = low, right = mid + 1;
        //         sort and merge the two arrays
        while (left <= mid && right <= high)
        {
            if (nums[left] < nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else
            {
                temp.push_back(nums[right++]);
            }
        }
        //         add any remaining elements from left array
        while (left <= mid)
        {
            temp.push_back(nums[left++]);
        }
        //         add any remaining elements from right array
        while (right <= high)
        {
            temp.push_back(nums[right++]);
        }
        //         copy all elements to original array
        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }
        //         return the calculated count
        return count;
    }
    int mergeSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return 0;
        int mid = (low + high) / 2;
        int rev_pairs = mergeSort(nums, low, mid);
        rev_pairs += mergeSort(nums, mid + 1, high);
        rev_pairs += merge(nums, low, mid, high);
        return rev_pairs;
    }
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};