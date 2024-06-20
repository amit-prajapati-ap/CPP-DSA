#include <iostream>
#include <queue>
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
int TreeHeight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = TreeHeight(root->left);
    int right = TreeHeight(root->right);
    return (max(left, right) + 1);
}
// // Approach 1
// int TreeDiameter(node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     int left = TreeDiameter(root->left);
//     int right = TreeDiameter(root->right);
//     int height = TreeHeight(root->left) + 1 + TreeHeight(root->right);
//     return max(max(left, right), height);
// }
// Approach 2
pair<int,int> FindDiameter(node* root) {
    if (root == nullptr)
    {
        return {0,0};
    }
    pair<int,int> left = FindDiameter(root->left);
    pair<int,int> right = FindDiameter(root->right);
    int leftans = left.first;
    int rightans = right.first;
    int height = left.second + right.second + 1;
    pair<int,int> ans;
    ans.first = max(height,max(leftans,rightans));
    ans.second = max(left.second,right.second) + 1;
    return ans;
}
int TreeDiameter(node* root) {
    pair<int,int> ans;
    ans = FindDiameter(root);
    return ans.first;
}
int main()
{
    node *root = NULL;
    BuildFromLevelOrder(root);
    LevelOrder(root);
    // // //Aproach 1
    // cout << "Longest Diameter Of Tree is : " << TreeDiameter(root) << endl;
    // //Aproach 2
    cout << "Longest Diameter Of Tree is : " << TreeDiameter(root) << endl;
}