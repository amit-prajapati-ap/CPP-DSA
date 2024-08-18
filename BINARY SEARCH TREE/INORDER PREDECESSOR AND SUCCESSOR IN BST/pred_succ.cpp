#include <iostream>
#include <vector>
#include <utility>
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
void inorder(node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
int Find_key_index(vector<int> arr, int k)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        int mid = s + (e - s) / 2;
    }
}
pair<int, int> Pred_Succ(node *root, int k)
{
    vector<int> arr;
    inorder(root, arr);
    int index = Find_key_index(arr, k);
    if ((index - 1) < 0)
    {
        return {-1, arr[index + 1]};
    }
    else if ((index + 1) > arr.size())
    {
        return {arr[index - 1], -1};
    }
    else
    {
        return {arr[index - 1], arr[index + 1]};
    }
}
int main()
{
    // CREATION OF BST
    node *root = nullptr;
    cout << "Enter The Data Of BST (-1 For Competion Of Entry) : ";
    int data;
    while (data != -1)
    {
        cin >> data;
        if (data != -1)
        {
            root = insertbst(root, data);
        }
    }
    pair<int, int> pred_succ;
    cout << "Enter The Value Of k : ";
    int k;
    cin >> k;
    pred_succ = Pred_Succ(root, k);
    cout << "Predecessor = " << pred_succ.first << endl
         << "Successor = " << pred_succ.second << endl;
}