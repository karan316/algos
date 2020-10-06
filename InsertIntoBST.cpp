#include<bits/stdc++.h>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
	TreeNode *insert(TreeNode *root, int value) {
				}
    TreeNode* insertIntoBST(TreeNode* root, int value) {
	    // insert if root is NULL
			if(root == NULL) {
			TreeNode *new_node = new TreeNode(value);
			return new_node;
			}
		// go to right if value is greater
			if(value > root->value) {
			root->right = insertIntoBST(root->right, value);
			} else {
		// go to left if value is smaller
			root->left = insertIntoBST(root->left, value);
			}
			return root;

    }
};
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int value) {
	   TreeNode* current = root, *new_node = new TreeNode(value);
        if(!root) return new_node;
        
        while(true) {
//            go to right subtree if greater
            if(value > current->val) {
//                 if there is a node
                if(current->right) {
                    current = current->right;
                    continue;
                }
//                 if it is null(insertion point)
                current->right = new_node;
                break;
            } else {
                if(current->left) {
                    current = current->left;
                    continue;
                }
//                 if it is null(insertion point
                current->left = new_node;
                    break;
            }
        }
        return root;
    }
};
