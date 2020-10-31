#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char> &str)
{
    for (int i = 0; i != str.size() / 2; i++)
    {
        swap(str[i], str[str.size() - (i + 1)]);
    }
}

int main()
{
    string word;
    cout << "String: ";
    cin >> word;
    vector<char> str(word.begin(), word.end());
    cout << "Reversed string is ";
    reverseString(str);
    vector<char>::iterator it;
    for (it = str.begin(); it != str.end(); ++it)
    {
        cout << *(it);
    }
}