
#include <bits/stdc++.h>

using namespace std;

// not working optimal (don't do this)
class Solution
{
public:
    bool isKthBitSet(int num, int k)
    {
        if (num & 1 << (k - 1))
            return true;
        return false;
    }
    int getFirstSetBitFromRight(int num)
    {
        return log2(num & -num) + 1; //can use ffs() function as well
    }
    int *findTwoElement(int *arr, int n)
    {
        // code here
        int result[2];
        int xor1 = arr[0];
        for (int i = 1; i < n; i++)
        {
            xor1 ^= arr[i];
        }
        int xor2 = 1;
        for (int i = 2; i <= n; i++)
        {
            xor2 ^= i;
        }
        int ans = xor1 ^ xor2;
        int set_bit = getFirstSetBitFromRight(ans);
        vector<int> set_bucket;
        vector<int> unset_bucket;

        //  sort the arrays and the range 1..n based on if the kth bit is set
        for (int i = 0; i < n; i++)
        {
            if (isKthBitSet(arr[i], set_bit))
                set_bucket.push_back(arr[i]);
            else
                unset_bucket.push_back(arr[i]);
            if (isKthBitSet(i + 1, set_bit))
                set_bucket.push_back(i + 1);
            else
                unset_bucket.push_back(i + 1);
        }
        int num_1 = set_bucket[0], num_2 = unset_bucket[0];
        for (int i = 1; i < set_bucket.size(); i++)
            num_1 ^= set_bucket[i];

        for (int i = 1; i < unset_bucket.size(); i++)
            num_2 ^= unset_bucket[i];

        // if num_1 exists in the array it has to be the repeating number
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == num_1)
            {
                result[0] = num_1;
                result[1] = num_2;
                return result;
            }
        }
        result[0] = num_2;
        result[1] = num_1;
        return result;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}