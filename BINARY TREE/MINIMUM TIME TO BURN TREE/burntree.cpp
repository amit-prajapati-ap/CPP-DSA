#include <iostream>
#include <queue>
#include <unordered_map>
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
node *CreateMapping(node *root, int data, unordered_map<node *, node *> &NTP)
{
    queue<node *> q;
    q.push(root);
    NTP[root] = NULL;
    node *res = NULL;
    while (!q.empty())
    {
        node *frontnode = q.front();
        q.pop();
        if (frontnode->data == data)
        {
            res = frontnode;
        }
        if (frontnode->left)
        {
            NTP[frontnode->left] = frontnode;
            q.push(frontnode->left);
        }
        if (frontnode->right)
        {
            NTP[frontnode->right] = frontnode;
            q.push(frontnode->right);
        }
    }
    return res;
}
int FindMinTime(node *root, unordered_map<node *, node *> &NodeToParent, unordered_map<node *, bool> &visited)
{
    queue<node *> q;
    q.push(root);
    visited[root] = true;
    int ans = 0;
    while (!q.empty())
    {
        int flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }
            if (NodeToParent[front] && !visited[NodeToParent[front]])
            {
                flag = 1;
                q.push(NodeToParent[front]);
                visited[NodeToParent[front]] = 1;
            }
        }
        if (flag == 1)
        {
            ans++;
        }
    }
    return ans;
}
int Burn(node *root, int target)
{
    unordered_map<node *, bool> visited;
    unordered_map<node *, node *> NodeToParent;
    node *targ = CreateMapping(root, target, NodeToParent);
    int ans = FindMinTime(targ, NodeToParent, visited);
    return ans;
}
int main()
{
    node *root = NULL;
    BuildFromLevelOrder(root);
    LevelOrder(root);
    cout << "Enter Number Where From You Want To Burn : ";
    int target;
    cin >> target;
    cout << "Minimum Time To Burn Entire Tree is : " << Burn(root, target) << endl;
}