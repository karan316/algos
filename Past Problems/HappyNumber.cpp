
// Input: 19
// Output: true
// Explanation:
// 1^2 + 9^2 = 82
// 8^2 + 2^2 = 68
// 6^2 + 8^2 = 100
// 1^2 + 0^2 + 0^2 = 1
// if a number repeats when sum of squares are counted it forms a cycle. That is the false condition.
#include <bits/stdc++.h>

using namespace std;

int squareDigits(int num)
{
    int ans = 0;
    while (num != 0)
    {
        ans += pow(num % 10, 2);
        num = num / 10;
    }
    return ans;
}
int splitAndSum(int n, unordered_set<int> seen)
{
    int result = squareDigits(n);
    if (seen.find(result) != seen.end())
    {
        return 0;
    }
    else
    {
        seen.insert(result);
    }
    if (result == 1)
        return 1;
    return splitAndSum(result, seen);
}
bool isHappy(int n)
{
    unordered_set<int> seen;
    while (true)
    {
        if (splitAndSum(n, seen) == 1)
            return true;
        if (splitAndSum(n, seen) == 0)
            return false;
    }
}

int main()
{
    int n;
    cin >> n;
    if (isHappy(n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}

// faster and efficient solution
// class Solution
// {
// public:
//     bool isHappy(int n)
//     {
//         vector<int> check;
//         while (1)
//         {
//             int sum = 0;
//             while (n > 0)
//             {
//                 int temp = n % 10;
//                 sum += (temp * temp);
//                 n = n / 10;
//             }
//             if (sum == 1)
//                 return 1;
//             auto it = find(check.begin(), check.end(), sum);
//             if (it != check.end())
//                 return 0;
//             check.push_back(sum);
//             n = sum;
//         }
//     }
// };