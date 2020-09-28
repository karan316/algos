#include <bits/stdc++.h>

using namespace std;

// int main()
// {
//     string num = "12345";
//     int k = 2;
//     string min_string = num;
//     for (int i = 1; i <= k; i++)
//     {
//         string str_copy;
//         for (int j = 0; j < num.length(); j++)
//         {
//             str_copy = min_string;
//             // puts(str_copy.erase(j, 1).c_str());
//             if (stoi(str_copy.erase(j, 1)) < stoi(min_string))
//             {
//                 cout << stoi(str_copy) << endl;
//                 min_string = str_copy;
//             }
//         }
//     }

//     puts(min_string.c_str());
// }

// string removeKdigits(string num, int k) {

//             if (num.length() == k)
//             {
//                 return "0";
//             }
// //         until k
//             for (int j = 0; j < k; j++)
//             {
// //                 start from the beginning
//                 int i = 0;
// //                 go till the number which has its next number lesser than itself
//                 while (i < num.length() - 1 && num[i] <= num[i + 1])
//                 {
//                     i++;
//                 }
// //                 erase that character
//                 num.erase(i, 1);
//             }

//             // removing leading zeroes
//             while (num.length() > 1 && num[0] == '0')
//                 num.erase(0, 1);

//             if (num.length() == 0)
//             {
//                 return "0";
//             }

//             return num;
// }

int main()
{
    string num = "10354";
    int k = 2;

    if (num.length() == k)
    {
        cout << "0" << endl;
        return 0;
    }
    for (int j = 0; j < k; j++)
    {
        int i = 0;
        while (i < num.length() - 1 && num[i] <= num[i + 1])
        {
            i++;
        }
        num.erase(i, 1);
    }

    // removing leading zeroes
    while (num.length() > 1 && num[0] == '0')
        num.erase(0, 1);

    if (num.length() == 0)
    {
        cout << "o\n";
        return 0;
    }

    cout << num << endl;
}
