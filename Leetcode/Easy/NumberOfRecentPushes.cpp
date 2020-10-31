#include <bits/stdc++.h>
using namespace std;
class RecentCounter
{
private:
    vector<int> req;
    int low;

public:
    RecentCounter()
    {
        low = 0;
    }
    int ping(int t)
    {
        req.push_back(t);
        while (req[low] < t - 3000)
        {
            low++;
        }
        return req.size() - low;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */