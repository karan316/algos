#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums = {0, 0, 1};
    int zero_count = 0;
    for (int i = 0; i != nums.size(); i++)
    {
        if (nums.at(i) == 0)
        {
            zero_count++;
        }
    }
    // remove all elements matching with zeroes
    nums.erase(std::remove(nums.begin(), nums.end(), 0), nums.end());

    while (zero_count != 0)
    {
        nums.push_back(0);
        zero_count--;
    }

    for (auto i : nums)
    {
        cout << i << "\t";
    }
}