#include <iostream>
using namespace std;

class node
{
public:
    int info;
    node *next;
    node()
    {
        info = 0;
        next = NULL;
    }
};

class LinkedList
{
    node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void display();
    void appendLast();
    void appendFront();
    void deleteLast();
    void deleteFront();
    void deleteInfo();
    void deleteAlternateNode();
    void sortList();
    void insertInBetween();
    void rev(node *f, node *b);
    void revHandler();
    void insertAfter();
    void insertBefore();
};

void LinkedList::insertAfter()
{
    if (head != NULL)
    {
        node *tmp = new node();
        cout << "\n\t Enter the element to be inserted: ";
        cin >> tmp->info;
        cout << "\n\t Enter the element after which the new node should be appended: ";
        int ele;
        cin >> ele;
        node *cur = head->next;
        node *prev = head;
        while (prev != NULL)
        {
            if (prev->info == ele)
            {
                tmp->next = cur;
                prev->next = tmp;
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        if (prev == NULL)
            cout << "\n\t Element not found!";
        return;
    }
    cout << "\n\t List empty!";
}

void LinkedList::insertBefore()
{
    if (head != NULL)
    {
        node *tmp = new node();
        cout << "\n\t Enter the element to be inserted: ";
        cin >> tmp->info;
        cout << "\n\t Enter the element before which the new node should be appended: ";
        int ele;
        cin >> ele;
        node *cur = head->next;
        node *prev = head;
        while (cur != NULL)
        {
            if (cur->info == ele)
            {
                tmp->next = cur;
                if (prev != NULL)
                {
                    prev->next = tmp;
                    head = tmp;
                }
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        if (cur == NULL)
            cout << "\n\t Element not found!";
        return;
    }
    cout << "\n\t List empty!";
}

void LinkedList::revHandler()
{

    if (head != NULL && head->next != NULL)
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        rev(head, temp);
        return;
    }
    cout << "\n\t Nothing to be reversed!";
}

// 1 -> 2 -> 3 -> 4 -> 5 -> NULL
// 5 -> 4 -> 3 -> 2 -> 1 -> NULL

void LinkedList::rev(node *start, node *end)
{
    if (end->next == start || start == end)
        return;
    start->info = start->info + end->info;
    end->info = start->info - end->info;
    start->info = start->info - end->info;

    node *temp = start;
    while (temp->next != end)
    {
        temp = temp->next;
    }
    start = start->next;
    rev(start, temp);
}

void LinkedList::insertInBetween()
{
    if (head != NULL)
    {
        node *tmp = new node();
        cout << "\n\t Enter an element to insert in list(ascending): ";
        cin >> tmp->info;
        node *cur = head;
        node *prev = NULL;
        // handle first element
        if (head->info >= tmp->info)
        {
            tmp->next = head;
            head = tmp;
            return;
        }
        while (cur != NULL)
        {
            if (cur->info >= tmp->info && prev->info <= tmp->info)
            {
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        if (cur == NULL)
        { //last element
            prev->next = tmp;
        }
        else
        {
            tmp->next = cur;
            prev->next = tmp;
        }
        return;
    }
    cout << "\n\t List empty!";
}

void LinkedList::sortList()
{
    if (head != NULL && head->next != NULL)
    {
        node *i = head;
        node *j;
        node *pos;
        while (i->next != NULL)
        {
            pos = i;
            j = i->next;
            while (j != NULL)
            {
                if (j->info < pos->info)
                {
                    pos = j;
                }
                j = j->next;
            }
            if (pos->info != i->info)
            {
                i->info = i->info + pos->info;
                pos->info = i->info - pos->info;
                i->info = i->info - pos->info;
            }
            i = i->next;
        }
        return;
    }
    cout << "\n\t Nothing to be sorted";
}

void LinkedList::deleteAlternateNode()
{
    if (head != NULL && head->next != NULL)
    {
        node *cur = head->next;
        node *prev = head;
        while (cur != NULL && prev != NULL)
        {
            prev->next = cur->next;
            prev = cur->next;
            delete cur;
            if (prev != NULL)
                cur = prev->next;
        }
    }
}

void LinkedList::appendLast()
{
    node *tmp = new node();
    cout << "\n\t Enter the element: ";
    cin >> tmp->info;
    if (head != NULL)
    {
        node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = tmp;
        return;
    }
    head = tmp;
}

void LinkedList::appendFront()
{
    node *tmp = new node();
    cout << "\n\t Enter the element: ";
    cin >> tmp->info;
    if (head != NULL)
    {
        tmp->next = head;
        head = tmp;
        return;
    }
    head = tmp;
}

void LinkedList::deleteFront()
{
    if (head != NULL)
    {
        node *tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    cout << "\n\t Nothing to be deleted";
}

void LinkedList::deleteInfo()
{
    if (head != NULL)
    {
        int ele;
        cout << "\n\t Enter the element: ";
        cin >> ele;
        node *tmp = head;
        node *prev = NULL;
        while (tmp != NULL && tmp->info != ele)
        {
            prev = tmp;
            tmp = tmp->next;
        }
        if (tmp != NULL && tmp->info == ele)
        {
            if (prev != NULL)
            {
                prev->next = tmp->next;
                delete tmp;
                return;
            }
            prev = head;
            head = head->next;
            delete prev;
            return;
        }
        cout << "\n\t Element not found!";
        return;
    }
    cout << "\n\t Nothing to be deleted";
}

void LinkedList::deleteLast()
{
    if (head == NULL)
    {
        cout << "\n\t Nothing to be deleted!";
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    node *t = head;
    while ((t->next)->next != NULL)
    {
        t = t->next;
    }
    delete t->next;
    t->next = NULL;
}

void LinkedList::display()
{
    if (head != NULL)
    {
        node *t = head;
        cout << "\n\t ";
        while (t != NULL)
        {
            cout << t->info << "->";
            t = t->next;
        }
        cout << "NULL";
        return;
    }
    cout << "\n\t List empty!";
}

int main()
{
    LinkedList LL;
    int op;
    do
    {
        cout << "\n\t Singly Linked List";
        cout << "\n\t 1. Display";
        cout << "\n\t 2. Append Last";
        cout << "\n\t 3. Delete Last";
        cout << "\n\t 4. Append Front";
        cout << "\n\t 5. Delete Front";
        cout << "\n\t 6. Delete based on data";
        cout << "\n\t 7. Delete alternate node";
        cout << "\n\t 8. Sort list";
        cout << "\n\t 9. Insert and maintain order";
        cout << "\n\t 10. Reverse list";
        cout << "\n\t 11. Insert After some element";
        cout << "\n\t 12. Insert Before some element";
        cout << "\n\t -1. Exit";
        cout << "\n\t Enter option: ";
        cin >> op;
        if (op != -1)
        {
            switch (op)
            {
            case 1:
                LL.display();
                break;
            case 2:
                LL.appendLast();
                break;
            case 3:
                LL.deleteLast();
                break;
            case 4:
                LL.appendFront();
                break;
            case 5:
                LL.deleteFront();
                break;
            case 6:
                LL.deleteInfo();
                break;
            case 7:
                LL.deleteAlternateNode();
                break;
            case 8:
                LL.sortList();
                break;
            case 9:
                LL.insertInBetween();
                break;
            case 10:
                LL.revHandler();
                break;
            case 11:
                LL.insertAfter();
                break;
            case 12:
                LL.insertBefore();
                break;
            }
        }
    } while (op != -1);
    return 0;
}
