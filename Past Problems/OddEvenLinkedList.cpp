// #include <bits/stdc++.h>
// #include "./headers/data_structures/LinkedList.h"

// using namespace std;

// void shiftNodeToEnd(LinkedList list, Node *node)
// {
//     int node_val = node->info;
//     list.appendLast(node_val);
// }

// void deleteEvenNodesUptoSize(LinkedList list, int size)
// {
//     Node *prev = list.head;
//     Node *temp = prev->next;
//     int count = 2;
//     while (size != 1)
//     {
//         if (count % 2 == 0)
//         {
//             prev->next = temp->next;
//             delete temp;
//             temp = prev->next;
//         }
//         else
//         {
//             prev = temp;
//             temp = temp->next;
//         }
//         size--;
//         count++;
//     }
// }

// int main()
// {
//     LinkedList list;
//     // 1->2->3->4->5->NULL
//     list.appendLast(2);
//     list.appendLast(1);
//     list.appendLast(3);
//     list.appendLast(5);
//     list.appendLast(6);
//     list.appendLast(4);
//     list.appendLast(7);
//     int count = 1;
//     Node *temp = list.head;
//     int size = 0;
//     while (temp != NULL)
//     {
//         size++;
//         temp = temp->next;
//     }
//     int list_size = size;
//     temp = list.head;
//     while (size != 0)
//     {
//         if (count % 2 == 0)
//             shiftNodeToEnd(list, temp);
//         temp = temp->next;
//         count++;
//         size--;
//     }
//     size = list_size;
//     // while (size != 0)
//     // {
//     //     if (count % 2 == 0)
//     //     {
//     //         list.deleteInfo(temp->info);
//     //     }
//     //     count++;
//     //     temp = temp->next;
//     //     size--;
//     // }
//     deleteEvenNodesUptoSize(list, size);
//     list.display();
// }

class Solution
{
public:
    void appendLast(ListNode *head, int val)
    {
        ListNode *temp;
        temp->val = val;
        if (head != NULL)
        {
            ListNode *t = head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
            return;
        }
        // if no element is present
        head = temp;
    }

    void shiftNodeToEnd(ListNode *head, ListNode *node)
    {
        int node_val = node->val;
        appendLast(head, node_val);
    }
    void deleteEvenNodesUptoSize(ListNode *head, int size)
    {
        ListNode *prev = head;
        ListNode *temp = prev->next;
        int count = 2;
        while (size != 1)
        {
            if (count % 2 == 0)
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
            size--;
            count++;
        }
    }
    ListNode *oddEvenList(ListNode *head)
    {

        int count = 1;
        ListNode *temp = head;
        int size = 0;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        int list_size = size;
        temp = head;
        while (size != 0)
        {
            if (count % 2 == 0)
                shiftNodeToEnd(head, temp);
            temp = temp->next;
            count++;
            size--;
        }
        deleteEvenNodesUptoSize(head, list_size);

        return head;
    }
};