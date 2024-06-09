#include <iostream>
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
int main()
{
    node *root = NULL;
    buildtree(root);
}