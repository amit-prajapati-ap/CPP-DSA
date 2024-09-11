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
void inorder(node *root, vector<int> &inval)
{
    if (root == NULL)
        return;
    inorder(root->left, inval);
    inval.push_back(root->data);
    inorder(root->right, inval);
}
bool Approach2(node *root, int target)
{
    vector<int> inorderval;
    inorder(root, inorderval);
    int i = 0, j = inorderval.size() - 1;
    while (i < j)
    {
        int sum = inorderval[i] + inorderval[j];
        if (sum == target)
        {
            return true;
        }
        else if (sum < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}
bool checkSum(node *root, int target)
{
    return Approach2(root, target);
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
    cout << "Enter The Value Of Target : ";
    int target;
    cin >> target;
    if (checkSum(root, target))
    {
        cout << "Yes!! Possible To Make Equal To Target." << endl;
    }
    else
    {
        cout << "No!! Impossible To Make Equal To Target." << endl;
    }
}