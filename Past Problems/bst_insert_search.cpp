#include<iostream>

using namespace std;

class BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
public:
    BstNode() 
    {
        left = NULL;
        right = NULL;
    }

    BstNode *insertNode(BstNode *root, int data);
    BstNode *getNewNode(int data);
    bool Search(BstNode *root, int data);
};

BstNode *BstNode::insertNode(BstNode *root, int data)
{
    if(root == NULL)
    {
        root = getNewNode(data);
    }

    else if(data<=root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;

}

bool BstNode::Search(BstNode *root, int data)
{
    if(root == NULL)
    return false;

    else if(root->data == data)
        return true;
    
    
    else if(data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

BstNode *BstNode::getNewNode(int data)
{
    BstNode *node = new BstNode();
    node->data = data;
    return node;
}
int main()
{
    BstNode *root = NULL;
    BstNode tree;

    root = tree.insertNode(root, 13);
    root = tree.insertNode(root, 45);
    root = tree.insertNode(root, 78);
    root = tree.insertNode(root, 7);

    int num;
    cout<<"Enter the number to be searched\n";
    cin>>num;
    if(tree.Search(root, num) == true) cout<<"found :-)\n";
    else
    {
        cout<<"not found :-(\n";
    }
}


