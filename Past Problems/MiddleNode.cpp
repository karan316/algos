#include <iostream>
#include "./headers/data_structures/LinkedList.h"
using namespace std;

int main()
{
    LinkedList list;
    list.appendLast(1);
    list.appendLast(2);
    list.appendLast(3);
    list.appendLast(4);
    list.appendLast(5);

    list.display();
    Node *temp = list.head;
    int node_count = 0;
    while (temp)
    {
        temp = temp->next;
        node_count++;
    }
    temp = list.head;
    node_count = node_count / 2;
    while (node_count != 0)
    {
        temp = temp->next;
        node_count--;
    }

    cout << temp->info;
}
