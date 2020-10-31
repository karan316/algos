#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1;
        long long power = n;
        if (n < 0)
            power = -power;
        while (power > 0)
        {
            if (power % 2 == 0)
            {
                x *= x;
                power /= 2;
            }
            else
            {
                ans = ans * x;
                power -= 1;
            }
        }
        if (n < 0)
            return 1 / ans;
        return ans;
    }
};