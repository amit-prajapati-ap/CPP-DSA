#include <iostream>
#include <queue>
#include <limits.h>
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
void LongestBloodline(node *root, int len, int maxlen, int sum, int &maxsum)
{
    if (root == nullptr)
    {
        if (len > maxlen)
        {
            maxlen = len;
            maxsum = max(sum, maxsum);
        }
        else if (len == maxlen)
        {
            maxsum = max(sum, maxsum);
        }
        return;
    }
    sum = sum + root->data;
    LongestBloodline(root->left, ++len, maxlen, sum, maxsum);
    LongestBloodline(root->right, ++len, maxlen, sum, maxsum);
}
int Bloodline(node *root)
{
    int sum = 0, maxSum = INT_MIN;
    int len = 0, maxLen = 0;
    LongestBloodline(root, len, maxLen, sum, maxSum);
    return maxSum;
}
int main()
{
    node *root = NULL;
    BuildFromLevelOrder(root);
    LevelOrder(root);
    cout << "Sum Of Longest Bloodline is : " << Bloodline(root) << endl;
}