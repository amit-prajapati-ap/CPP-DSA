#include <iostream>
#include <queue>
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
bool Identical(node *root1, node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    else if (root1 != nullptr && root2 == nullptr)
    {
        return false;
    }
    else if (root1 == nullptr && root2 != nullptr)
    {
        return false;
    }
    bool left = Identical(root1->left, root2->left);
    bool right = Identical(root1->right, root2->right);
    bool value = root1->data == root2->data;
    if (left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    node *root1 = NULL;
    BuildFromLevelOrder(root1);
    LevelOrder(root1);
    node *root2 = NULL;
    BuildFromLevelOrder(root2);
    LevelOrder(root2);
    if (Identical(root1, root2))
    {
        cout << "Tree is Balanced" << endl;
    }
    else
    {
        cout << "Tree is Not Balanced" << endl;
    }
}