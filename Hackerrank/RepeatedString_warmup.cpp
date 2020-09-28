#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n)
{
    int numberOfa = 0;
    for (char c : s)
    {
        if (c == 'a')
            numberOfa++;
    }
    long double result = (double)(n * numberOfa) / (double)s.length();
    cout.setf(ios::fixed);
    cout << setprecision(50) << result << endl;
    return round(result);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";
    cout << result << "\n";

    fout.close();

    return 0;
}

// 203302892858