#include <iostream>
#include <queue>
#include <utility>
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
pair<bool, int> FindSumTree(node *root)
{
    if (root == NULL)
    {
        return {true, 0};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {true, root->data};
    }
    pair<bool, int> left = FindSumTree(root->left);
    pair<bool, int> right = FindSumTree(root->right);
    bool condition;
    if (root->data == (left.second + right.second))
    {
        condition = true;
    }
    else
    {
        condition = false;
    }
    pair<bool, int> ans;
    if (left.first && right.first && condition)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
bool SumTree(node *root)
{
    bool ans = FindSumTree(root).first;
    return ans;
}
int main()
{
    node *root = NULL;
    BuildFromLevelOrder(root);
    LevelOrder(root);
    if (SumTree(root))
    {
        cout << "This Tree Is Sum Tree." << endl;
    }
    else
    {
        cout << "Not a Sum Tree." << endl;
    }
}