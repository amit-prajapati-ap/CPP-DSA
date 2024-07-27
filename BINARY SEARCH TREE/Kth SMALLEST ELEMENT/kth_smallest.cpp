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
int Find_Kth_Smallest(node *root, int &i, int k)
{
    if (root == nullptr)
    {
        return -1;
    }
    int left = Find_Kth_Smallest(root->left, i, k);
    if (left != -1)
    {
        return left;
    }
    i++;
    if (i == k)
    {
        return root->data;
    }
    return Find_Kth_Smallest(root->right, i,k);
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
    int i = 0;
    cout << "Kth Minimum Element is : " << Find_Kth_Smallest(root, i, data) << endl;
}