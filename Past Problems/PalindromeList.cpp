#include <bits/stdc++.h>
#include "./headers/data_structures/LinkedList.h"
using namespace std;

int main()
{
    LinkedList list;
    list.appendLast(1);
    list.appendLast(0);
    list.appendLast(1);

    vector<int> list_copy;
    Node *temp = list.head;
    list.display();
    int i = 0;
    while (temp)
    {
        list_copy.push_back(temp->info);
        temp = temp->next;
        i++;
    }

    vector<int> og_list;
    og_list = list_copy;
    reverse(list_copy.begin(), list_copy.end());
    if (og_list == list_copy)
        cout << "palindrome";
    else
        cout << "not a palindrome";
}