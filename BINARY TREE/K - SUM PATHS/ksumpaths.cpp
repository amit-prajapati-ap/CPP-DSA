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
        if (data != 0)
        {
            temp->left = new node(data);
            q.push(temp->left);
        }
        cout << "Enter Right Node Data For : " << temp->data << " : ";
        cin >> data;
        if (data != 0)
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
void FindSumK(node *root, int k, int &c, vector<int> path)
{
    if (root == nullptr)
    {
        return;
    }
    path.push_back(root->data);
    FindSumK(root->left, k, c, path);
    FindSumK(root->right, k, c, path);
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            c++;
        }
    }
    path.pop_back();
}
int SumK(node *root, int k)
{
    int count = 0;
    vector<int> path;
    FindSumK(root, k, count, path);
    return count;
}
int main()
{
    node *root = NULL;
    BuildFromLevelOrder(root);
    cout << "Enter The Value Of K : ";
    int k;
    cin >> k;
    LevelOrder(root);
    cout << "Number Of K Sum Path is : " << SumK(root, k) << endl;
}