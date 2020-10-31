#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num = 1111;
    int i = 0;
    int j = 0;
    while (true)
    {
        if (num >= pow(2, j) - 1 && num <= pow(2, j + 1) - 1)
        {
            i = j + 1;
            break;
        }
        j++;
    }
    int xor_num = pow(2, i) - 1;
    int result = num xor xor_num;
    cout << "XOR: " << xor_num << endl;
    cout << "Result: " << result << endl;
}
