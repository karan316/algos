#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
using namespace std;
class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node()
    {
        left = NULL;
        right = NULL;
    }
    void iterativePreOrder(Node *root);
    void iterativeInOrder(Node *root);
    void iterativePostOrder(Node *root);
    void recursivePreOrder(Node *root);
    void recursiveInOrder(Node *root);
    void recursivePostOrder(Node *root);
    int countLeaves(Node *root);
    int height(Node *root);
    bool isIdentical(Node *root1, Node *root2);
    int countNonLeafNodes(Node *root);
    int sumOfLeafNodes(Node *root);
    Node *cloneTree(Node *root);
    Node *mirror(Node *root);
    Node *createBinaryTree();
    void insertNode(Node *root);
    void displayTree(Node *tree, int level);
    bool parentNode(Node *root, int ele);
    bool ancestor(Node *root, int ele);
    bool isBST(Node *root, Node *l, Node *r);
};

void Node::iterativePreOrder(Node *root)
{
    stack<Node *> nodeStack;

    if (root == NULL)
        nodeStack.push(root);

    while (nodeStack.empty() != true)
    {
        //assign a node reference to the popped element
        Node *node = nodeStack.top();
        cout << node->data << endl;
        nodeStack.pop();

        //push the right one first as the left one has to be displayed first
        if (node->right)
        {
            nodeStack.push(node->right);
        }

        if (node->left)
        {
            nodeStack.push(node->left);
        }
    }
}

void Node::iterativeInOrder(Node *root)
{
    stack<Node *> nodeStack;
    Node *node = root;
    while (true)
    {
        while (node->left != NULL)
        {
            nodeStack.push(node);
            node = node->left; // got to the extreme left
        }

        if (node == NULL && nodeStack.empty() != true)
        {
            node = nodeStack.top();
            nodeStack.pop();
            cout << node->data;
            node = node->right;
        }
        if (node == NULL && nodeStack.empty() == true)
            break;
    }
}
void Node::iterativePostOrder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> nodeStack1, nodeStack2;
    nodeStack1.push(root);
    Node *node;

    while (!nodeStack1.empty())
    {
        node = nodeStack1.top();
        nodeStack1.pop();

        nodeStack2.push(node);

        if (node->left)
            nodeStack1.push(node->left);

        if (node->right)
            nodeStack1.push(node->right);
    }

    while (!nodeStack2.empty())
    {
        node = nodeStack2.top();
        nodeStack2.pop();
        cout << node->data;
    }
}

void Node::recursivePreOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << "\t";
    recursivePreOrder(root->left);
    recursivePreOrder(root->right);
}
void Node::recursiveInOrder(Node *root)
{
    if (root == NULL)
        return;

    recursiveInOrder(root->left);
    cout << root->data << "\t";
    recursiveInOrder(root->right);
}
void Node::recursivePostOrder(Node *root)
{
    if (root == NULL)
        return;

    recursivePostOrder(root->left);
    recursivePostOrder(root->right);
    cout << root->data << "\t";
}

Node *Node::createBinaryTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node *new_node = new Node;
    new_node->data = x;

    cout << "Left child of " << x << endl;
    new_node->left = createBinaryTree();
    cout << "Right child of " << x << endl;
    new_node->right = createBinaryTree();

    return new_node;
}

Node *Node::cloneTree(Node *root)
{
    if (root == NULL)
        return 0;

    Node *new_node = new Node();

    new_node->left = cloneTree(root->left);
    new_node->right = cloneTree(root->right);
    return new_node;
}

int Node::countLeaves(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int Node::countNonLeafNodes(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;
    return countNonLeafNodes(root->left) + countNonLeafNodes(root->right) + 1;
}

int Node::sumOfLeafNodes(Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL and root->right == NULL)
        return root->data;

    return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
}

Node *Node::mirror(Node *root)
{
    if (root == NULL)
        return root;

    Node *temp;
    Node *node = root;

    mirror(node->left);
    mirror(node->right);

    temp = node->left;
    node->left = node->right;
    node->right = temp;
}

int Node::height(Node *root)
{
    if (root == NULL)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}
bool Node::isIdentical(Node *root1, Node *root2)
{
    queue<Node *> q1, q2;
    //using level order traversal
    q1.push(root1);
    q2.push(root2);

    while (q1.empty() != true && q2.empty() != true)
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

bool Node::isBST(Node *root, Node *l = NULL, Node *r = NULL)
{
    if (root == NULL)
        return true;

    // if left node exist then check it has correct data or not i.e. left node's data should be less than root's data
    if (l != NULL and root->data <= l->data)
        return false;

    // if right node exist then check it has correct data or not i.e. right node's data should be greater than root's data
    if (r != NULL and root->data >= r->data)
        return false;

    // check recursively for every node.
    return isBST(root->left, l, root) and
           isBST(root->right, root, r);
}

void Node::insertNode(Node *root)
{
    Node *new_node = new Node;
    cout << "Enter element:";
    cin >> new_node->data;

    new_node->left = NULL;
    new_node->right = NULL;

    if (root == NULL)
    {
        root = new_node;
        return;
    }

    char dir[20];
    cout << "Enter traversal order:";
    cin >> dir;

    Node *cur = root;
    Node *prev = NULL;

    int i;
    for (i = 0; i < strlen(dir); i++)
    {
        if (cur == NULL)
            break;
        prev = cur;
        if (dir[i] == 'L')
        {
            cur = cur->left;
        }
        else
            cur = cur->right;
    }

    if (cur != NULL || i != strlen(dir)) //if there is already an element in the postion or number of characters entered is greater than the existing levels
    {
        cout << "Cannot insert the node\n";
        delete new_node;
        return;
    }

    if (dir[i - 1] == 'L')
        prev->left = new_node;
    else
        prev->right = new_node;
    return;
}

void Node::displayTree(Node *root, int level)
{
    if (root == NULL)
        return;
    displayTree(root->right, level + 1);
    for (int i = 0; i < level; i++)
        cout << "        ";
    cout << root->data << endl;
    displayTree(root->left, level + 1);
}

bool Node::parentNode(Node *root, int ele)
{
    if (root == NULL)
        return false;
    if (root->data == ele)
        return true;
    if (parentNode(root->left, ele) || parentNode(root->right, ele))
    {
        cout << "Parent Node of " << ele << " is " << root->data << endl;
        return false;
    }
}

bool Node::ancestor(Node *root, int ele)
{
    if (root == NULL)
        return false;
    if (root->data == ele)
        return true;
    if (ancestor(root->left, ele) || ancestor(root->right, ele))
    {
        cout << root->data << "\t";
        return true;
    }
    return false;
}

int main()
{
    int choice;
    Node n;
    Node *root = new Node();
    while (true)
    {
        cout << "1.Create binary tree\n2.Preorder\n3.Inorder\n4.Postorder\n5.Number of leaf nodes\n6.Height of the tree\n7.Number of non leaf nodes\n8.Sum of leaf nodes\n9.Clone tree\n10. Mirror tree\n11. Display tree\n12.Recursive Pre\n13.Recursive In\n14.Recursive Post\n15.Check Identical trees\n16.Insert a node into the tree\n17.Parent Node of an element\n18.Ancestor of a node\n19.Is it a binary tree?\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            root = n.createBinaryTree();
            break;
        case 2:
            n.iterativePreOrder(root);
            break;
        case 3:
            n.iterativeInOrder(root);
            break;
        case 4:
            n.iterativePostOrder(root);
            break;
        case 5:
            int leaf_count;
            leaf_count = n.countLeaves(root);
            cout << "Leaf Count: " << leaf_count << endl;
            break;
        case 6:
            int height;
            height = n.height(root);
            cout << "Height of the tree: " << height << endl;
            break;
        case 7:
            int non_leaf_count;
            non_leaf_count = n.countNonLeafNodes(root);
            cout << "Non leaf nodes: " << non_leaf_count << endl;
            break;
        case 8:
            int sum_of_leaf_nodes;
            sum_of_leaf_nodes = n.sumOfLeafNodes(root);
            cout << "Sum of leaf nodes: " << sum_of_leaf_nodes << endl;
            break;
        case 9:
            Node *clone_root;
            clone_root = n.cloneTree(root);
            n.displayTree(clone_root, n.height(clone_root));
            break;
        case 10:
            Node *mirror_root;
            mirror_root = n.mirror(root);
            n.displayTree(mirror_root, n.height(mirror_root));
            break;
        case 11:
            n.displayTree(root, n.height(root));
            break;
        case 12:
            n.recursivePreOrder(root);
            cout << "\n";
            break;
        case 13:
            n.recursiveInOrder(root);
            cout << "\n";
            break;
        case 14:
            n.recursivePostOrder(root);
            cout << "\n";
            break;
        case 15:
            cout << "Enter the second tree\n";
            Node *root2;
            root2 = n.createBinaryTree();
            if (n.isIdentical(root, root2))
                cout << "Trees are identical!\n";
            else
                cout << "Trees are not identical\n";
            break;
        case 16:
            n.insertNode(root);
            break;
        case 17:
        {
            int ele;
            cout << "Enter the element\n";
            cin >> ele;
            n.parentNode(root, ele);
        }
            cout << "\n";
            break;
        case 18:
        {
            int ele;
            cout << "Enter the element\n";
            cin >> ele;
            n.ancestor(root, ele);
        }
            cout << "\n";
            break;
        case 19:
            n.isBST(root, NULL, NULL);
            break;
        default:
            exit(0);
        }
    }
}