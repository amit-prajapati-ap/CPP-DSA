#include <iostream>
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
int findLCA(node *root, int a, int b)
{
    while (root != NULL)
    {
        if (root->data < a && root->data < b)
        {
            root = root->right;
        }
        else if (root->data > a && root->data > b)
        {
            root = root->left;
        }
        else
        {
            return root->data;
        }
    }
}
int main()
{
    // CREATION OF BST
    node *root = nullptr;
    cout << "Enter The Data Of BST : ";
    int data = 0;
    while (data != -1)
    {
        cin >> data;
        if (data != -1)
        {
            root = insertbst(root, data);
        }
    }
    int a, b;
    cout << "Enter The Value of Two Childs : ";
    cin >> a >> b;
    cout << "Lowest Common Ancestor of " << a << " And " << b << " is : " << findLCA(root, a, b) << endl;
}