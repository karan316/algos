#include <iostream>

using namespace std;

bool trueSum(int s[], int true_value, int len, int k)
{
    int sum = 0;
    for (int j = k; j < len + k; j++)
    {
        sum += s[j];
    }
    if (sum == true_value)
        return true;
    return false;
}

// Complete the birthday function below.
int birthday(int chocolates[], int date, int month, int n)
{

    int ways = 0;
    for (int i = 0; i < n; i++)
    {
        if (trueSum(chocolates, date, month, i))
        {
            ways++;
        }
    }

    return ways;
}

int main()
{
    int n;
    cin >> n;
    int chocolates[n];
    for (int i = 0; i < n; i++)
    {
        cin >> chocolates[i];
    }
    int date, month;
    cin >> date >> month;
    int ways = birthday(chocolates, date, month, n);
    cout << ways;
}