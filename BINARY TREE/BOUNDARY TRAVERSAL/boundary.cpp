#include <iostream>
#include <queue>
#include <vector>
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
void TraverseLeft(node *root, vector<int> &ans)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        TraverseLeft(root->left,ans);
    }
    else
    {
        TraverseLeft(root->right,ans);
    }
}
void TraverseLeaf(node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(root->data);
        return;
    }
    TraverseLeaf(root->left, ans);
    TraverseLeaf(root->right, ans);
}
void TraverseRight(node *root, vector<int> &ans)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }
    if (root->right)
    {
        TraverseRight(root->right,ans);
    }
    else
    {
        TraverseRight(root->left,ans);
    }
    ans.push_back(root->data);
}
void BoundaryTraversal(node *root)
{
    vector<int> ans;
    ans.push_back(root->data);
    TraverseLeft(root->left, ans);
    TraverseLeaf(root->left, ans);
    TraverseLeaf(root->right, ans);
    TraverseRight(root->right, ans);
    cout<<"Boundary Printing Of The Tree : "<<endl;
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
    LevelOrder(root);
    BoundaryTraversal(root);
}