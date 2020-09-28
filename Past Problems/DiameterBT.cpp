#include <bits/stdc++.h>
#include "./headers/data_structures/BinaryTree.h"
using namespace std;
int height(BinaryTree *root)
{
    if (root == NULL)
        return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);

    return max(left_height, right_height) + 1;
}
int diameter(BinaryTree *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);

    return max(left_height + right_height + 1, max(left_diameter, right_diameter));
}

int main()
{
    BinaryTree tree;
    BinaryTree *root = tree.createBinaryTree();
    tree.display(root);
    cout << diameter(root) - 1;
}

// class Solution
// {
//     int ans;
// public
//     int diameterOfBinaryTree(TreeNode root)
//     {
//         ans = 1;
//         depth(root);
//         return ans - 1;
//     }
// public
//     int depth(TreeNode node)
//     {
//         if (node == null)
//             return 0;
//         int L = depth(node.left);
//         int R = depth(node.right);
//         ans = Math.max(ans, L + R + 1);
//         return Math.max(L, R) + 1;
//     }
// }