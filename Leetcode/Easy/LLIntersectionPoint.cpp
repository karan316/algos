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

// SOLUTION 1:
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> node_set;
        //         add every element in the first list to the set
        while (headA != NULL)
        {
            node_set.insert(headA);
            headA = headA->next;
        }
        // traverse the second list and find if the same node exists in the set
        while (headB != NULL)
        {
            if (node_set.find(headB) != node_set.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};

// SOLUTION 2: (OPTIMAL)
class Solution
{
public:
    int getListSize(ListNode *head)
    {
        int size = 0;
        while (head)
        {
            head = head->next;
            size++;
        }

        return size;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int size_A = getListSize(headA);
        int size_B = getListSize(headB);

        //      start both the pointers equally from both the lists
        if (size_A > size_B)
        {

            for (int i = 0; i < size_A - size_B; i++)
            {
                headA = headA->next;
            }
        }

        if (size_A < size_B)
        {
            for (int i = 0; i < size_B - size_A; i++)
            {
                headB = headB->next;
            }
        }

        //         move both the pointers head and check which pointers are same
        while (headA && headB)
        {
            if (headA == headB)
                return headA;
            else
            {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }
};