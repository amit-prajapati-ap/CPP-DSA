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
pair<bool, int> FindBalanced(node *root)
{
    if (root == nullptr)
    {
        return {true, 0};
    }
    pair<bool, int> left = FindBalanced(root->left);
    pair<bool, int> right = FindBalanced(root->right);
    bool leftans = left.first;
    bool rightans = right.first;
    bool diff = abs(left.second - right.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    if (leftans && rightans && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
bool balanced(node *root)
{
    return FindBalanced(root).first;
}
int main()
{
    node *root = NULL;
    BuildFromLevelOrder(root);
    LevelOrder(root);
    if (balanced(root))
    {
        cout << "Tree is Balanced" << endl;
    }
    else
    {
        cout << "Tree is Not Balanced" << endl;
    }
}