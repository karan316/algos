#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        ListNode *temp = head;
        int size = 0;
        while (temp)
        {
            size++;
            temp = temp->next;
        }
        //      For large k values take the mod
        k = k % size;
        while (k--)
        {
            temp = head;
            ListNode *prev;
            while (temp->next)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            temp->next = head;
            head = temp;
        }
        return head;
    }
};