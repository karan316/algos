#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
void removeLoop(Node *head)
{
    if (!head || !head->next)
        return;
    Node *fast = head;
    Node *slow = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    // if loop starts from head
    if (slow == head)
    {
        while (slow->next != head)
        {
            slow = slow->next;
        }
        slow->next = NULL;
    }

    if (slow == fast)
    {
        slow = head;
        while (slow->next != fast->next)
        {
            if (slow == fast->next)
            {
                fast->next == NULL;
            }
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = NULL;
    }
}

int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("/home/karan/Karan/DSA/input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("/home/karan/Karan/DSA/output.txt", "w", stdout);

#endif
}