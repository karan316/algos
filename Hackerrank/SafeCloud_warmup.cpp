#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
bool isSafeCloud(int i)
{
    bool isSafe = (i == 0) ? true : false;
    return isSafe;
}
int jumpingOnClouds(vector<int> c)
{
    // 0 0 1 0 0 1 0
    int jump;
    int numOfJumps = 0;
    for (jump = 0; jump < c.size();)
    {
        int x = jump + 2;
        if (x == c.size() - 1)
        {
            // jump += 2;
            numOfJumps++;
            break;
        }
        if (isSafeCloud(c[x]))
        {
            jump += 2;
            numOfJumps++;
            continue;
        }
        x = jump + 1;
        if (x == c.size() - 1)
        {
            numOfJumps++;
            break;
        }
        if (isSafeCloud(c[x]))
        {
            numOfJumps++;
            jump++;
        }
    }

    return numOfJumps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
