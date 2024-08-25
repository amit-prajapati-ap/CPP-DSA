#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
class cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
void traverse(Node *root, vector<string> &ans, string temp)
{
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(temp);
        return;
    }
    traverse(root->left, ans, temp + '0');
    traverse(root->right, ans, temp + '1');
}
vector<string> huffmanCodes(string S, vector<int> f, int N)
{
    priority_queue<Node *, vector<Node *>, cmp> pq;
    for (int i = 0; i < N; i++)
    {
        Node *temp = new Node(f[i]);
        pq.push(temp);
    }
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *temp = new Node(left->data + right->data);
        temp->left = left;
        temp->right = right;
        pq.push(temp);
    }
    vector<string> ans;
    string temp = "";
    Node *root = pq.top();
    pq.pop();
    traverse(root, ans, temp);
    return ans;
}
void print(vector<string> &ans)
{
    cout<<"Printing Huffman Encoding : "<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int main()
{
    string str;
    cout << "Enter The Huffman String : ";
    cin >> str;
    vector<int> freq;
    cout << "Enter The Frequencies Of Huffman String (-1 For Exit) : " << endl;
    int data = 0;
    while (data != -1)
    {
        cin >> data;
        freq.push_back(data);
    }
    vector<string> ans = huffmanCodes(str, freq, str.length());
    print(ans);
}