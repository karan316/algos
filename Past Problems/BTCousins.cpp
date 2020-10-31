#include <bits/stdc++.h>
#include "./headers/data_structures/BinaryTree.h"
using namespace std;

int depth_x = -1;
int depth_y = -2;
BinaryTree *parent_x = NULL;
BinaryTree *parent_y = NULL;

void checkDepthAndParent(BinaryTree *root, BinaryTree *parent, int x, int y, int depth)
{
    if (root == NULL)
    {
        return;
    }

    if (x == root->data)
    {
        parent_x = parent;
        depth_x = depth;
    }
    else if (y == root->data)
    {
        parent_y = parent;
        depth_y = depth;
    }
    else
    {
        checkDepthAndParent(root->left, root, x, y, depth + 1);
        checkDepthAndParent(root->right, root, x, y, depth + 1);
    }
}

bool isCousins(BinaryTree *root, int x, int y)
{
    checkDepthAndParent(root, NULL, x, y, 0);
    if (depth_x == depth_y && parent_x != parent_y)
        return true;
    return false;
}

int main()
{
    stack<BinaryTree *> nodeStack;
    BinaryTree tree;
    BinaryTree *root = new BinaryTree();
    root = tree.createBinaryTree();
    tree.display(root);
    int x = 5, y = 4;
    cout << isCousins(root, x, y) << endl;
}