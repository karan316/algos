#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// TRIED ONE PASS SOLUTION, DIDN'T WORK FOR ALL CASES
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if(head->next == NULL) return head->next;
//         ListNode *first = head, *second = head;
//         bool flag = true;
//         do {
//             if(n != 0) {
//                 second = second->next;
//                 n--;
//             }
// //             have to delete the first element
//             if(first == head && second == NULL) {
//                 break;
//             }
//             if(first->next->next == NULL) break;
//             if(n==0 && first->next->next != NULL) {
//                 flag = false;
//                 second = second->next;
//                 first = first->next;
//             }
//         }while(second != NULL && first->next->next != NULL);

//         // cout<<"first: "<<first->val<<endl;
//         if(first == head && flag) {
//             cout<<"deleting first"<<endl;
//             head = first->next;
//             delete(first);
//             return head;
//         }
//         ListNode *delete_node = first->next;
//         if(first->next)
//         first->next = first->next->next;
//         delete(delete_node);

//         return head;
//     }
// };

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == NULL)
            return head->next;
        ListNode *delete_node = head, *second = head;
        ListNode *first = new ListNode();
        first->next = delete_node;
        // KEEP A DISTANCE OF N BETWEEN FIRST AND SECOND NODE
        while (n != 0)
        {
            second = second->next;
            n--;
        }
        // IF FIRST ELEMENT HAS TO BE DELETED
        if (second == NULL)
        {
            first = delete_node->next;
            delete (delete_node);
            return first;
        }
        // OTHER CONDITIONS
        while (second != NULL)
        {
            first = delete_node;
            delete_node = delete_node->next;
            second = second->next;
        }
        first->next = delete_node->next;
        delete (delete_node);
        return head;
    }
};