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
int input(vector<int> &inorder, vector<int> &preorder)
{
    int n;
    cout << "Enter Number Of Elements : ";
    cin >> n;
    cout << "Enter The Elements Of Inorder : " << endl;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        inorder.push_back(data);
    }
    cout << "Enter The Elements Of Preorder : " << endl;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        preorder.push_back(data);
    }
    return n;
}
int FindPos(vector<int> &inorder, int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (inorder[i] == element)
        {
            return i;
        }
    }
    return -1;
}
node *BuildTree(vector<int> &inorder, vector<int> &preorder, int n, int &preindex, int start, int end)
{
    if (preindex >= n || start > end)
    {
        return nullptr;
    }
    int element = preorder[preindex++];
    node *root = new node(element);
    int pos = FindPos(inorder, element, n);
    root->left = BuildTree(inorder, preorder, n, preindex, start, pos - 1);
    root->right = BuildTree(inorder, preorder, n, preindex, pos + 1, end);
    return root;
}
node *BuildFromPreorder(vector<int> &inorder, vector<int> &preorder, int n)
{
    int preindex = 0;
    node *root = BuildTree(inorder, preorder, n, preindex, 0, n - 1);
    return root;
}
int main()
{
    node *root = NULL;
    vector<int> inorder;
    vector<int> preorder;
    int n = input(inorder, preorder);
    root = BuildFromPreorder(inorder, preorder, n);
    LevelOrder(root);
}