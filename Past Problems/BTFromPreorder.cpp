#include<bits/stdc++.h>
#include "./headers/data_structures/BinaryTree.h"
using namespace std;

BinaryTree *BinaryTree::createBinaryTree()
{
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    BinaryTree *new_node = new BinaryTree;
    new_node->data = x;

    cout << "Left child of " << x << endl;
    new_node->left = createBinaryTree();
    cout << "Right child of " << x << endl;
    new_node->right = createBinaryTree();

    return new_node;
}

int main() {


}