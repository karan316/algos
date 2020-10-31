#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums = {2, 3, 1, 5};
    int n = nums.size();

    if (n <= 1)
        return true;
    pair<int, int> interval{0, 0};
    int jumps = 0;
    while (true)
    {
        jumps++;
        int can_reach = -1;
        for (int i = interval.first; i <= interval.second; i++)
        {
            can_reach = max(can_reach, i + nums[i]);
        }
        if (can_reach >= n - 1)
            return true;
        interval = {interval.second + 1, can_reach};

        if (interval.first > interval.second)
            return false;
    }

    assert(false);
}