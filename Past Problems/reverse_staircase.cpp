#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, hash, space;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
      space = (n - 1) - i;
      hash = i + 1;
      while (space != 0) {
        cout<<" ";
        space--;
      }
      while (hash != 0) {
        cout<<"#";
        hash--;
      }
      cout<<"\n";
    }
    return 0;
}

