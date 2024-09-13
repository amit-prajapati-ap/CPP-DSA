#include <iostream>
#include <queue>
#include <vector>
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
// Level Order Traversing
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
// Storing Values in Array Inorder Format
void inorder(node *root, vector<int> &arr)
{
    if (!root)
    {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
// Merge two Arrays
void merge(vector<int> &arr1, int a1, vector<int> &arr2, int a2, vector<int> &arr3, int a3)
{
    int i = 0, j = 0, k = 0;
    while (i < a1 && j < a2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < a1)
    {
        arr3[k++] = arr1[i++];
    }

    while (j < a2)
    {
        arr3[k++] = arr2[j++];
    }
}
// Inserting Values in BST Inorder Format
node *inordertobst(vector<int> &inorder, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    node *ans = new node(inorder[mid]);
    ans->left = inordertobst(inorder, s, mid - 1);
    ans->right = inordertobst(inorder, mid + 1, e);
    return ans;
}
// Coversion of BST Into Doubly LL
void BSTtoDLL(node *root, node *&head)
{
    if (root == NULL)
    {
        return;
    }
    BSTtoDLL(root->right, head);
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;
    BSTtoDLL(root->left, head);
}
// Merge Doubly LL
node *mergeDLL(node *head1, node *head2)
{
    node *head = NULL;
    node *tail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}
int findn(node *head)
{
    int ans = 0;
    while (head != NULL)
    {
        ans++;
        head = head->right;
    }
    return ans;
}
// Doubly LL to BST Conversion
void DLLtoBST(node *head, vector<int> &ans)
{
    while (head != NULL)
    {
        ans.push_back(head->data);
        head = head->right;
    }
}
int main()
{
    // CREATION OF BST
    node *root1 = nullptr;
    node *root2 = nullptr;
    int data = 0;
    cout << "Enter The Data Of BST 1 : ";
    while (data != -1)
    {
        cin >> data;
        if (data != -1)
        {
            root1 = insertbst(root1, data);
        }
    }
    data = 0;
    cout << "Enter The Data Of BST 2 : ";
    while (data != -1)
    {
        cin >> data;
        if (data != -1)
        {
            root2 = insertbst(root2, data);
        }
    }
    cout << "BST 1 : " << endl;
    LevelOrder(root1);
    cout << "BST 2 : " << endl;
    LevelOrder(root2);
    // // Approach 1
    // vector<int> arr1, arr2;
    // inorder(root1, arr1);
    // inorder(root2, arr2);
    // vector<int> merged(arr1.size() + arr2.size(), 0);
    // merge(arr1, arr1.size(), arr2, arr2.size(), merged, merged.size());
    // node *root = inordertobst(merged, 0, merged.size());
    // LevelOrder(root);
    // Approach 2
    node *head1;
    node *head2;
    BSTtoDLL(root1, head1);
    BSTtoDLL(root2, head2);
    node *head = mergeDLL(head1, head2);
    vector<int> ans;
    DLLtoBST(head, ans);
    int n = findn(head);
    ans.push_back(-1);
    data = 0;
    int i = 0;
    node *root;
    while (data != -1)
    {
        data = ans[i++];
        if (data != -1)
        {
            root = insertbst(root, data);
        }
    }
    LevelOrder(root);
}