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
    ListNode *merge(ListNode *h1, ListNode *h2)
    {
        //         DUMMY NODE
        ListNode *newHead = new ListNode(INT_MIN);
        //         linker node
        ListNode *newNode = newHead;

        while (h1 && h2)
        {
            //             join the link to the lesser node and move ahead
            if (h1->val < h2->val)
            {
                newNode->next = h1;
                newNode = newNode->next;
                h1 = h1->next;
            }
            else
            {
                newNode->next = h2;
                newNode = newNode->next;
                h2 = h2->next;
            }
        }
        //         join any remaining links
        if (h1)
            newNode->next = h1;
        else
            newNode->next = h2;

        //         return the actual head which is next of the dummy node
        return newHead->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *h1 = head;
        ListNode *h2 = head;

        //         h2 will either be last node or second last node
        while (h2->next && h2->next->next)
        {
            h2 = h2->next->next;
            h1 = h1->next;
        }

        //        bring h2 to the start of second list
        h2 = h1->next;
        //         break the two lists
        h1->next = NULL;

        //         merge the two lists after dividing them
        return merge(sortList(head), sortList(h2));
    }
};

int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("/home/karan/Karan/DSA/input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("/home/karan/Karan/DSA/output.txt", "w", stdout);

#endif
}