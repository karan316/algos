#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> nums = {1, 2, 1, 1, 1};
    int k = 3;
    int n = nums.size();
    int count = 0;
    int pref = 0;
    unordered_map<int, int> countPref;
    countPref[pref]++;
    for (int i = 0; i < n; i++)
    {
        pref += nums[i];
        int need = pref - k;
        count += countPref[need];
        countPref[pref]++;
    }
    return count;
}