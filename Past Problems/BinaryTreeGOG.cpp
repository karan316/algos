#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

/* Iterative function for inorder tree 
traversal */
void inOrder(struct Node *root)
{
    stack<Node *> nodeStack;
    Node *curr = root;

    while (curr != NULL || !nodeStack.empty())
    {
        /* Reach the left most Node of the 
		curr Node */
        while (curr != NULL)
        {
            /* place pointer to a tree node on 
			the stack before traversing 
			the node's left subtree */
            nodeStack.push(curr);
            curr = curr->left;
        }

        /* Current must be NULL at this point */
        curr = nodeStack.top();
        nodeStack.pop();

        cout << curr->data << " ";

        /* we have visited the node and its 
		left subtree. Now, it's right 
		subtree's turn */
        curr = curr->right;

    } /* end of while */
}

void mirror(Node *node)
{
    if (node == NULL)
        return;
    else
    {
        struct Node *temp;

        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);

        /* swap the pointers in this node */
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

bool isBST(Node *root, Node *left = NULL, Node *right = NULL)
{
    if (root == NULL)
        return true;

    // if left node exist then check if it has correct data or not i.e. left node's data should be less than root's data
    if (left != NULL and root->data <= left->data)
        return false;

    // if right node exist then check if it has correct data or not i.e. right node's data should be greater than root's data
    if (right != NULL and root->data >= right->data)
        return false;

    // check recursively for every node.
    return isBST(root->left, left, root) and
           isBST(root->right, root, right);
}

bool isIdentical(Node *root1, Node *root2)
{
    queue<Node *> q1, q2;
    //using level order traversal
    q1.push(root1);
    q2.push(root2);

    while (!q1.empty() && !q2.empty())
    {
        Node *node1 = q1.front();
        Node *node2 = q2.front();

        if (node1->data != node2->data)
            return false; // elements not equal

        //Remove front nodes from the queue
        q1.pop();
        q2.pop();

        if (node1->left && node2->left) //if node 1 and node 2 have  left child push it into the queue
        {
            q1.push(node1->left);
            q2.push(node2->left);
        }

        else if (node1->left || node2->left)
            return false;

        if (node1->right && node2->right)
        {
            q1.push(node1->right);
            q2.push(node2->right);
        }

        else if (node1->right || node2->right)
            return false;
    }

    return true;
}