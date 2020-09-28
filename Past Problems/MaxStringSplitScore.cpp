#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "011101";
    int num_of_zeroes, num_of_ones, max_score = INT_MIN;
    for (int i = 0; i < s.length() - 1; i++)
    {
        num_of_ones = 0;
        num_of_zeroes = 0;
        int j;
        for (j = 0; j <= i; j++)
        {
            if (s[j] == '0')
            {
                num_of_zeroes++;
            }
        }
        for (int k = j; k < s.length(); k++)
        {
            if (s[k] == '1')
            {
                num_of_ones++;
            }
        }
        max_score = max(max_score, num_of_ones + num_of_zeroes);
    }
    cout << max_score;
}