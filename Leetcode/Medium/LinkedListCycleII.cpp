#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = head;
        //       if slow == NULL => no cycle fast == NULL to check for NULL->next condition
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            //             if at any point they meet there is a cycle
            if (slow == fast)
                break;
        }

        fast = head;
        //         increment both pointers one by one until they meet or slow becomes NULL
        while (slow && slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
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