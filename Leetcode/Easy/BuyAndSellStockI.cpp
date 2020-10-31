#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy_price = INT_MAX;
        int max_profit = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            if (prices[i] < buy_price)
                buy_price = prices[i];
            else if (prices[i] - buy_price > max_profit)
                max_profit = prices[i] - buy_price;
        }
        return max_profit;
    }
};