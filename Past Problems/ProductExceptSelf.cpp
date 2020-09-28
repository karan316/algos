// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]
#include <bits/stdc++.h>

using namespace std;

// int main()
// {
//     // vector<int> nums = {0, 0, 0, 0};
//     vector<int> nums = {1, 2, 3, 4}; //24, 12,, 8, 6
//     // set<int> product_set;
//     vector<int> product;
//     int result;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (i == 0)
//         {
//             result = nums[1];
//         }
//         else
//         {
//             result = nums[0];
//         }
//         for (int j = 1, k = 2; j < nums.size(); j++, k++)
//         {
//             if (i == 0)
//             {
//                 if (k == nums.size())
//                     break;
//                 result = result * nums[k];
//             }
//             else if (i != j)
//             {
//                 result = result * nums[j];
//             }
//         }
//         product.push_back(result);
//     }

//     for (int i : product)
//     {
//         cout << i << " ";
//     }
// }

// errichto code
int main()
{
    vector<int> nums = {1, 2, 3, 4}; //24, 12,, 8, 6
    const int n = nums.size();
    vector<int> pref_product;
    pref_product.push_back(1);
    for (int x : nums)
    {
        pref_product.push_back(pref_product.back() * x);
    }

    vector<int> suf_product(n + 1);
    suf_product[n] = 1;

    for (int i = n - 1; i >= 0; --i)
    {
        suf_product[i] = suf_product[i + 1] * nums[i];
    }

    vector<int> product(n);

    for (int i = 0; i < n; i++)
    {
        product[i] = pref_product[i] * suf_product[i + 1];
    }

    for (int i : product)
    {
        cout << i << " ";
    }
}