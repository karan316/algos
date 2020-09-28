#include <bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    vector<int> cardPoints = {1, 79, 80, 1, 1, 1, 200, 1};
    int k = 3;
    int sum = 0, j = cardPoints.size() - 1, i = 0;
    while (i <= j && k != 0)
    {
        sum += max(cardPoints[i], cardPoints[j]);
        if (cardPoints[i] != cardPoints[j])
        {
            if (cardPoints[i] > cardPoints[j])
            {
                i++;
            }
            else
            {
                j--;
            }
            k--;
        }
        else
        {
            if (cardPoints[i + 1] > cardPoints[j - 1])
            {
                i++;
            }
            else
            {
                j--;
            }
            k--;
        }
    }

    cout << sum;
}

// solution

//    int maxScore(vector<int>& cardPoints, int k) {
//         int sum = 0;
//         int n = cardPoints.size();

//         vector<int> cummulativeSumFromFront(n+1, 0);
//         vector<int> cummulativeSumFromBehind(n+1, 0);

//         sum = 0;
//         for (int i=0; i<n; i++) {
//             sum += cardPoints[i];
//             cummulativeSumFromFront[i+1] = sum;
//         }
//         sum = 0;
//         for (int i=n-1; i>=0; i--) {
//             sum += cardPoints[i];
//             cummulativeSumFromBehind[i] = sum;
//         }

//         // Reversing is optional. I reversed it so that it would be easy
//         // to access sum of last (k-i) elements by just indexing at [k-i]
//         // Otherwise, I would have had to index it at [n-k+i] which would
//         // have made it difficult to read.
//         reverse(cummulativeSumFromBehind.begin(), cummulativeSumFromBehind.end());

//         int answer = 0;
//         for(int i=0; i<=k; i++) {
//             int fromStart = i; // Cumulative sum of first 'i' cards.
//             int fromEnd = k-i; // Cumulative sum of last 'k-i' cards.
//             answer = max(answer,
//                            cummulativeSumFromFront[fromStart]
//                          + cummulativeSumFromBehind[fromEnd]);
//         }
//         return answer;
//     }