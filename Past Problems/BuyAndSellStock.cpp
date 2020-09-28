#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices)
{
    if (prices.size() == 0)
    {
        return 0;
    }

    int maxProfit = 0;
    // for every element if the next element as a greater value than you add the difference to the profit.
    for (int i = 0; i < prices.size() - 1; i++)
    {
        if (prices[i + 1] > prices[i])
        {
            maxProfit += prices[i + 1] - prices[i];
        }
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
}