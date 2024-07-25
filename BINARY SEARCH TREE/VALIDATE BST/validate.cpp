#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// CREATING THE CLASS NODE
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
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

// Approach 1
void inorder(node *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
bool ValidBST(node *root)
{
    vector<int> arr;
    inorder(root, arr);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] > arr[i])
        {
            return false;
        }
    }
    return true;
}

// Approach 2
bool ValidateBST(node *root, int min, int max)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->data >= min && root->data <= max)
    {
        bool left = ValidateBST(root->left, min, root->data);
        bool right = ValidateBST(root->right, root->data, max);
        return left && right;
    }
    return false;
}
// Minimum Value And Maximum Value
pair<int, int> FindMinMax(node *root)
{
    pair<int, int> ans;
    node *maxi = root;
    node *mini = root;
    while (mini->left != nullptr)
    {
        mini = mini->left;
    }
    while (maxi->right != nullptr)
    {
        maxi = maxi->right;
    }
    ans = {maxi->data, mini->data};
    return ans;
}
int main()
{
    // CREATION OF BST
    node *root = NULL;
    BuildFromLevelOrder(root);
    cout << endl;
    LevelOrder(root);
    cout << endl;
    // Approach 1
    if (ValidBST(root))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }
    // Approach 2
    int min = FindMinMax(root).second;
    int max = FindMinMax(root).first;
    if (ValidateBST(root, min, max))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }
}