#include <bits/stdc++>

using namespace std;

int countSubarray(vector<int> nums, int k)
{
    // CRUX: X^Y = Z also implies Y = Z^X
    unordered_map<int, int> freq;
    int count = 0;
    int xr = 0;

    for (int i : nums)
    {
        xr = xr ^ i;

        // if prefix xor equals k then increment count
        if (xr == k)
        {
            count++;
        }

        // if y =  xr ^ k existed in the map which means we found freq[y] number of more subarrays because we had found y freq number of times already and given that current prefix xor is xr there could only be a subarray with value equal to k
        if (freq.find(xr ^ k) != freq.end())
        {
            count += freq[xr ^ k];
        }
        // increment the prefix xor count
        freq[xr]++;
    }
    return count;
}