#include <iostream>
#include <vector>
using namespace std;
// CREATING THE CLASS NODE
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
// INSERTION IN BST
node *insertbst(node *root, int data)
{
    if (root == nullptr)
    {
        root = new node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertbst(root->right, data);
    }
    else
    {
        root->left = insertbst(root->left, data);
    }
    return root;
}
void inorder(node* root,vector<int> &ans) {
     if (root == nullptr)
     {
        return;
     }
     inorder(root->left,ans);
     ans.push_back(root->data);
     inorder(root->right,ans);
}
int Find_Kth_Largest(node *root, int k)
{
    vector<int> ans;
    inorder(root,ans);
    int i = (ans.size() - k);
    return ans[i];
}
int main()
{
    // CREATION OF BST
    node *root = nullptr;
    cout << "Enter The Data Of BST (-1 For Competion Of Entry) : ";
    int data;
    while (data != -1)
    {
        cin >> data;
        if (data != -1)
        {
            root = insertbst(root, data);
        }
    }
    cout << "Enter The Value Of K : ";
    cin >> data;
    cout << "Kth Maximum Element is : " << Find_Kth_Largest(root,data) << endl;
}