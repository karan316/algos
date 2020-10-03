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
    ListNode *reverseList(ListNode *head)
    {

        ListNode *prev = NULL, *cur = head, *nex;
        while (cur)
        {
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        return prev;
    }
};

// h
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
// p    q    r ...          q

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         //if not an empty list and does not contain a single element
//         if( head != NULL && head->next != NULL ) {
//             ListNode *temp = head;
//             while(temp->next != NULL) {
//                 //take this pointer till the end
//                 temp = temp->next;
//             }
//             //reverse the first and last pointer values
//             rev(head, temp);
//             return head;
//         }

//         return head;
//     }

//     void rev(ListNode *start, ListNode *end) {
// //         base case is when start and end are at the same position or adjacent to each other
//         if(start == end || end->next == start) {
//             return;
//         }

//         //swap values
//         start->val = start->val + end->val;
//         end->val = start->val - end->val;
//         start->val = start->val - end->val;

//         ListNode *new_end = start;

//         //take this pointer(new_end) to one value before the end for every recursive call
//         while(new_end->next != end) {
//             new_end = new_end->next;
//         }

// //         move the start pointer to its next
//         start = start->next;
// //         reverse with the new locations for start and end
//         rev(start, new_end);
//     }
// };
