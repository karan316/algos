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
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        //         Find the middle node
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //         rejoin the middle node link to the reversed list
        slow->next = reverseList(slow->next);
        // move the pointer to the reverse side
        slow = slow->next;
        //         traverse till the end and simultaneuosly move the start pointer, if values not equal return false
        while (slow != NULL)
        {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *next = NULL;
        while (head != NULL)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};