#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        // if null return #
        if (!root)
            return "# ";

        //  else form the string | add space to get word from the string
        return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }

    TreeNode *helper(stringstream &ss)
    {
        string word;
        TreeNode *new_node = NULL;
        //         word is each node value in string
        if (ss >> word && word != "#")
        {
            new_node = new TreeNode(stoi(word));
            new_node->left = helper(ss);
            new_node->right = helper(ss);
        }

        return new_node;
    }

    TreeNode *deserialize(string data)
    {
        //         create a stream of strings
        stringstream ss(data);

        TreeNode *root = NULL;

        root = helper(ss);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("/home/karan/Karan/DSA/input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("/home/karan/Karan/DSA/output.txt", "w", stdout);

#endif
}