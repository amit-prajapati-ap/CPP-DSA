#include <iostream>
#include <queue>
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
void print(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << "  ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(node *root, vector<int> &in)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
node *inordertobst(vector<int> &inorder, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    node *ans = new node(inorder[mid]);
    ans->left = inordertobst(inorder, s, mid - 1);
    ans->right = inordertobst(inorder, mid + 1, e);
    return ans;
}
node *balanced(node *root)
{
    vector<int> in;
    inorder(root, in);
    return inordertobst(in, 0, in.size() - 1);
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
    cout << "Before Conversion : " << endl;
    print(root);
    node *balRoot = balanced(root);
    cout << "After Conversion : " << endl;
    print(balRoot);
}