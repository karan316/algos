#include <bits/stdc++.h>
#include "headers/data_structures/BinaryTree.h"
using namespace std;

bool isMirror(BinaryTree *root1, BinaryTree *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 && root2 && root1->data == root2->data)
    {
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }

    return false;
}
int main()
{
    BinaryTree tree;
    BinaryTree *root = tree.createBinaryTree();

    if (isMirror(root, root))
        cout << "Tree is Symmetric\n";
    else
        cout << "Tree is not a Symmetric\n";
}
// 1,2,2,null,3,null,3