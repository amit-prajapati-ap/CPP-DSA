#include <iostream>
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
// INSERTION IN BST
node *insertbst(node *root, int data)
{
    if (root == nullptr)
    {
        root = new node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertbst(root->right, data);
    }
    else
    {
        root->left = insertbst(root->left, data);
    }
    return root;
}
// TRAVERSING THE BST
void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}
// SEARCHING IN BST
// APPROACH 1 ITERATIVE
bool SearchI(node *root, int target)
{
    while (root != nullptr)
    {
        if (root->data == target)
        {
            return true;
        }
        else if (target < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
}
// Approach 2 Recursive
bool SearchR(node *root, int target)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    bool left = SearchR(root->left, target);
    bool right = SearchR(root->right, target);
    if (left || right)
    {
        return true;
    }
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
// Deletion
node *Deletion(node *root, int value)
{
    if (root == nullptr)
    {
        return root;
    }
    if (root->data == value)
    {
        // 0 Child Case
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // 1 Child Case
        // Left Child Case
        else if (root->left != nullptr && root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // Right Child Case
        else if (root->left == nullptr && root->right != nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 Child Case
        else if (root->left != nullptr && root->right != nullptr)
        {
            int mini = FindMinMax(root->right).second;
            root->data = mini;
            root->right = Deletion(root->right, mini);
            return root;
        }
    }
    else if (value < root->data)
    {
        root->left = Deletion(root->left, value);
        return root;
    }
    else
    {
        root->right = Deletion(root->right, value);
        return root;
    }
}
int main()
{
    // CREATION OF BST
    node *root = nullptr;
    cout << "Enter The Data Of BST : ";
    int data;
    while (data != -1)
    {
        cin >> data;
        if (data != -1)
        {
            root = insertbst(root, data);
        }
    }
    inorder(root);
    cout << endl;
    cout << "Enter The Element Want To Search : ";
    cin >> data;
    // Iterative
    if (SearchI(root, data))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    // Recursive
    if (SearchR(root, data))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    // Outputing Maximum & Minimum Element
    pair<int, int> ans = FindMinMax(root);
    cout << "Maximum Element : " << ans.first << endl;
    cout << "Minimum Element : " << ans.second << endl;
    cout << "Enter The Element Want To Delete : ";
    cin >> data;
    Deletion(root, data);
    inorder(root);
}