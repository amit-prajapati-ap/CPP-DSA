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
node *buildtree(node *root)
{

    int data;
    cout << "Enter the Data in BT : ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);
    cout << "Enter The data In The Left Of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter The data In The right Of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}
void LevelOrder(node *root)
{
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
void Inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << "  ";
    Inorder(root->right);
}
void Preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "  ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << "  ";
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    cout << "Level Order Traversal : " << endl;
    LevelOrder(root);
    cout << "Inorder Traversal : " << endl;
    Inorder(root);
    cout << endl;
    cout << "PreOrder Traversal : " << endl;
    Preorder(root);
    cout << endl;
    cout << "PostOrder Traversal : " << endl;
    Postorder(root);
}