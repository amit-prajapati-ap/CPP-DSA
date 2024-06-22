#include <iostream>
#include <queue>
#include <map>
#include <vector>
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
void VerticalTraversal(node *root)
{
    vector<int> ans;
    map<int, map<int, vector<int>>> Nodes;
    queue<pair<node *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        node *front = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        Nodes[hd][lvl].push_back(front->data);
        if (front->left)
        {
            q.push(make_pair(front->left, make_pair(hd - 1, lvl + 1)));
        }
        if (front->right)
        {
            q.push(make_pair(front->right, make_pair(hd + 1, lvl + 1)));
        }
    }
    for (auto i : Nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    cout << "Vertical Printing Of The Tree : " << endl;
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
    VerticalTraversal(root);
}