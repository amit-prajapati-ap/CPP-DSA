#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <limits.h>
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
// BST Traversal
void LevelOrder(node *root)
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
node *preordertobst(vector<int> &arr, int mini, int maxi, int &i)
{
    if (i >= arr.size())
    {
        return nullptr;
    }
    if (arr[i] < mini || arr[i] > maxi)
    {
        return nullptr;
    }
    node *root = new node(arr[i++]);
    root->left = preordertobst(arr, mini, root->data, i);
    root->right = preordertobst(arr, root->data, maxi, i);
    return root;
}
int main()
{
    int n;
    cout << "Enter The Number Of Elements : ";
    cin >> n;
    vector<int> preorder(n, 0);
    cout << "Enter The Elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }
    // // Approach 1 (Simple Insertion)
    // node *root = nullptr;
    // for (auto i : preorder)
    // {
    //     root = insertbst(root, i);
    // }
    // // Approach 2 (Sorting)
    // sort(preorder.begin(), preorder.end());
    // node *root = inordertobst(preorder, 0, preorder.size() - 1);
    // LevelOrder(root);
    // Approach 3 (Preorder)
    int i = 0;
    node *root = preordertobst(preorder, INT_MIN, INT_MAX, i);
    LevelOrder(root);
}