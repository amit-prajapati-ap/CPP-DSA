#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class info
{
public:
    int maxi;
    int mini;
    int size;
    bool isbst;
};
void BuildFromLevelOrder(node *&root)
{
    queue<node *> q;
    int data;
    cout << "Enter the Data For Root Node : ";
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter Left Node Data For : " << temp->data << " : ";
        cin >> data;
        if (data != -1)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }
        cout << "Enter Right Node Data For : " << temp->data << " : ";
        cin >> data;
        if (data != -1)
        {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
}
void LevelOrder(node *root)
{
    cout << "Printing The Tree : " << endl;
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
info solve(node *root, int &ans)
{
    if (root == nullptr)
    {
        return {INT_MIN, INT_MAX, 0, true};
    }
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
    info currnode;
    currnode.size = left.size + right.size + 1;
    currnode.maxi = max(root->data, right.maxi);
    currnode.mini = min(root->data, left.mini);
    if (left.isbst && right.isbst && (root->data > left.maxi && root->data < right.mini))
    {
        currnode.isbst = true;
    }
    else
    {
        currnode.isbst = 0;
    }
    if (currnode.isbst)
    {
        ans = max(ans, currnode.size);
    }
    return currnode;
}
int LargestBST(node *root)
{
    int ans = 0;
    info temp = solve(root, ans); return ans;
}
int main()
{
    node *root = NULL;
    BuildFromLevelOrder(root);
    LevelOrder(root);
    // // Approach 2
    // cout << "Largest BST in a Binary Tree : " << LargestBST(root) << endl;
}