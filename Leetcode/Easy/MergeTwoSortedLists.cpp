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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *link, *head;
        if (l1 == NULL && l2 == NULL)
            return l1;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if (l1->val > l2->val)
            swap(l1, l2);
        head = l1;
        link = l1;
        l1 = l1->next;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                link->next = l1;
                l1 = l1->next;
                link = link->next;
            }
            else
            {
                link->next = l2;
                l2 = l2->next;
                link = link->next;
            }
        }

        if (l2 == NULL)
        {
            link->next = l1;
        }
        else
        {
            link->next = l2;
        }

        return head;
    }
};