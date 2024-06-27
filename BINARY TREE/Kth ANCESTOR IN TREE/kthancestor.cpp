#include <iostream>
#include <queue>
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
node *FindAncestor(node *root, int &k, int n)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == n)
    {
        return root;
    }
    node *left = FindAncestor(root->left, k, n);
    node *right = FindAncestor(root->right, k, n);
    if (left != nullptr && right == nullptr)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return left;
    }
    if (right != nullptr && left == nullptr)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return right;
    }
    return nullptr;
}
int KthAncestor(node *root, int k, int n)
{
    node *ans = FindAncestor(root, k, n);
    if (ans == nullptr || ans->data == n)
    {
        return -1;
    }
    return ans->data;
}
int main()
{
    node *root = NULL;
    BuildFromLevelOrder(root);
    cout << "Enter The Value Of k : ";
    int k;
    cin >> k;
    cout << "Enter The Value Of N : ";
    int n;
    cin >> n;
    LevelOrder(root);
    cout << "Kth Ancestor In Tree is : " << KthAncestor(root, k, n) << endl;
}