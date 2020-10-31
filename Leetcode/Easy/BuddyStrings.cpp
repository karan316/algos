#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        if (A.empty() || B.empty() || A.length() != B.length())
            return false;

        int n = A.length();

        //         if strings are equal && set of char in A is lesser than A's length => there are duplicates which can be swapped
        if (A == B && set<char>(A.begin(), A.end()).size() < A.size())
            return true;

        //         array to keep track of different character indices
        vector<int> index;
        //         for every different character push the index
        for (int i = 0; i < n; i++)
        {
            if (A[i] != B[i])
                index.push_back(i);
        }
        //         if there are only two different characters and those two characters give same string if swapped return true
        if (index.size() == 2 && A[index[0]] == B[index[1]] && A[index[1]] == B[index[0]])
            return true;
        return false;
    }
};

int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("/home/karan/Karan/DSA/input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("/home/karan/Karan/DSA/output.txt", "w", stdout);

#endif
}