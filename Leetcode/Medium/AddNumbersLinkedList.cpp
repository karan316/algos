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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
            return l1;
        if (!l1 && l2)
            return l2;
        if (l1 && !l2)
            return l1;
        int carry = 0;
        ListNode *l3 = NULL;
        ListNode *temp;
        while (l1 && l2)
        {
            int sum = carry + l1->val + l2->val;
            if (sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }
            ListNode *new_node = new ListNode(sum);
            if (!l3)
            {
                l3 = new_node;
                temp = l3;
            }
            else
            {
                temp->next = new_node;
                temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (!l2)
        {
            while (l1)
            {
                int sum = carry + l1->val;
                if (sum > 9)
                {
                    carry = sum / 10;
                    sum = sum % 10;
                }
                else
                {
                    carry = 0;
                }
                ListNode *new_node = new ListNode(sum);
                if (!l3)
                {
                    l3 = new_node;
                    temp = l3;
                }
                else
                {
                    temp->next = new_node;
                    temp = temp->next;
                }
                l1 = l1->next;
            }
        }
        if (!l1)
        {
            while (l2)
            {
                int sum = carry + l2->val;
                if (sum > 9)
                {
                    carry = sum / 10;
                    sum = sum % 10;
                }
                else
                {
                    carry = 0;
                }
                ListNode *new_node = new ListNode(sum);
                if (!l3)
                {
                    l3 = new_node;
                    temp = l3;
                }
                else
                {
                    temp->next = new_node;
                    temp = temp->next;
                }
                l2 = l2->next;
            }
        }
        if (carry)
        {
            cout << "carry: " << carry << endl;
            ListNode *new_node = new ListNode(carry);
            temp->next = new_node;
        }
        return l3;
    }
};