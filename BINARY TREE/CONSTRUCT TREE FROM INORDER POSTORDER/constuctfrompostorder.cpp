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
int input(vector<int> &inorder, vector<int> &postorder)
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
    cout << "Enter The Elements Of Postorder : " << endl;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        postorder.push_back(data);
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
node *BuildTree(vector<int> &inorder, vector<int> &Postorder, int n, int &Postindex, int start, int end)
{
    if (Postindex < 0 || start > end)
    {
        return nullptr;
    }
    int element = Postorder[Postindex--];
    node *root = new node(element);
    int pos = FindPos(inorder, element, n);
    root->right = BuildTree(inorder, Postorder, n, Postindex, pos + 1, end);
    root->left = BuildTree(inorder, Postorder, n, Postindex, start, pos - 1);
    return root;
}
node *BuildFromPostorder(vector<int> &inorder, vector<int> &Postorder, int n)
{
    int Postindex = n - 1;
    node *root = BuildTree(inorder, Postorder, n, Postindex, 0, n - 1);
    return root;
}
int main()
{
    node *root = NULL;
    vector<int> inorder;
    vector<int> postorder;
    int n = input(inorder, postorder);
    root = BuildFromPostorder(inorder, postorder, n);
    LevelOrder(root);
}