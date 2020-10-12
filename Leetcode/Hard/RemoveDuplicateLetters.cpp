#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<char, int> count;
    bool isLexicallySmaller(char a, char b)
    {
        if (a < b)
            return true;
        return false;
    }
    bool isLastOccurence(char c)
    {
        if (!count[c])
            return true;
        return false;
    }
    string removeDuplicateLetters(string s)
    {
        unordered_map<char, bool> visited;
        string result = "";
        for (char c : s)
            count[c]++;
        for (char c : s)
        {
            // decrement the count to keep track of last occurrence
            count[c]--;
            // if the current char is already in the result don't add it to the result
            if (visited[c])
                continue;
            // as long as result is not empty and last char in the result is lexically greater and we expect to see it in further iterations - keep deleting the last char
            while (!result.empty() && isLexicallySmaller(c, result.back()) && !isLastOccurence(result.back()))
            {
                visited[result.back()] = false;
                result.pop_back();
            }
            // add the new char to result
            visited[c] = true;
            result += c;
        }
        return result;
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

    string s;
    cin >> s;
    Solution sol;
    cout << sol.removeDuplicateLetters(s) << endl;
}