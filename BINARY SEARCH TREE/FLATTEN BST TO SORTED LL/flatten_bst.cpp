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
void printLL(node *head)
{
    while (head)
    {
        if (head->right)
        {
            cout << head->data << " ---> ";
        }
        else
        {
            cout << head->data << endl;
        }
        head = head->right;
    }
}
void findInorder(node *root, vector<int> &inorder)
{
    if (root == nullptr)
    {
        return;
    }
    findInorder(root->left, inorder);
    inorder.push_back(root->data);
    findInorder(root->right, inorder);
}
node *convertLL(node *&root)
{
    vector<int> inorder;
    findInorder(root, inorder);
    node *ans = new node(inorder[0]);
    node *curr = ans;
    int n = inorder.size();
    for (int i = 1; i < n; i++)
    {
        node *temp = new node(inorder[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = curr->right;
    }
    curr->left = NULL;
    curr->right = NULL;
    return ans;
}
int main()
{
    // CREATION OF BST
    node *root = nullptr;
    cout << "Enter The Data Of BST : ";
    int data;
    while (data != -1)
    {
        cin >> data;
        if (data != -1)
        {
            root = insertbst(root, data);
        }
    }
    root = convertLL(root);
    printLL(root);
}