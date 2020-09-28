#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        a.push_back(ele);
    }

    int t = 0;

    for (int i = 0; i < a.size(); i++)
    {
        t ^= a[i];
    }
    cout << t << endl;
}