#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> target = {1, 2, 3};
    int n = 3;

    vector<string> output;
    stack<int> nums;

    for (int i = target.size() - 1; i >= 0; i--)
    {
        nums.push(target[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (nums.empty())
            goto result;
        if (nums.top() == i)
        {
            output.push_back("Push");
            nums.pop();
        }
        else
        {
            output.push_back("Push");
            output.push_back("Pop");
        }
    }

result:
    for (auto i : output)
    {
        cout << i << " ";
    }
}