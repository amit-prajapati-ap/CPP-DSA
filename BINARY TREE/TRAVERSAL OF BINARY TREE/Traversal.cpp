#include <iostream>
#include <queue>
#include <vector>
#include <stack>
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
void Inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << "  ";
    Inorder(root->right);
}
void Preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "  ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << "  ";
}
void ReverseLevelOrder(node *root)
{
    stack<node *> s;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            s.push(NULL);
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            s.push(temp);
            if (temp->right)
            {
                q.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
        }
    }
    s.pop(); // Removing 1st NULL
    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        if (temp == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << temp->data << "  ";
        }
    }
    cout << endl;
}
void count(node *root, int &size)
{
    if (root == nullptr)
    {
        return;
    }
    size++;
    count(root->left, size);
    count(root->right, size);
}
void InorderIterational(node *root)
{
    stack<node *> s;
    while (root != NULL || !s.empty())
    {
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        cout << root->data << "  ";
        root = root->right;
    }
    cout << endl;
}
void PreorderIterational(node *root)
{
    stack<node *> s;
    while (root != NULL || !s.empty())
    {
        while (root != NULL)
        {
            s.push(root);
            cout << root->data << "  ";
            root = root->left;
        }
        root = s.top();
        s.pop();
        root = root->right;
    }
    cout << endl;
}
vector<int> SolvedPostorderIterational(node *root)
{
    vector<int> ans;
    stack<node *> s;
    while (true)
    {
        while (root)
        {
            s.push(root);
            s.push(root);
            root = root->left;
        }
        if (s.empty())
        {
            return ans;
        }
        root = s.top();
        s.pop();
        if (!s.empty() && s.top() == root)
        {
            root = root->right;
        }
        else
        {
            ans.push_back(root->data);
            root = NULL;
        }
    }
    return ans;
}
void PostorderIterational(node *root)
{
    vector<int> ans = SolvedPostorderIterational(root);
    for (auto i : ans)
    {
        cout << i << "  ";
    }
    cout << endl;
}
int main()
{
    node *root = NULL;
    BuildFromLevelOrder(root);
    cout << "Level Order Traversal : " << endl;
    LevelOrder(root);
    cout << "Reverse Level Order Traversal : " << endl;
    ReverseLevelOrder(root);
    cout << "Inorder Traversal : " << endl;
    Inorder(root);
    cout << endl;
    cout << "PreOrder Traversal : " << endl;
    Preorder(root);
    cout << endl;
    cout << "PostOrder Traversal : " << endl;
    Postorder(root);
    cout << endl;
    int size = 0;
    count(root, size);
    cout << "Size = " << size << endl;
    cout << "Inorder Iterational Traversal : " << endl;
    InorderIterational(root);
    cout << "Preorder Iterational Traversal : " << endl;
    PreorderIterational(root);
    cout << "Postorder Iterational Traversal : " << endl;
    PostorderIterational(root);
}