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
void BuildFromLevelOrder(node* &root) {
    queue<node*> q;
    int data;
    cout<<"Enter the Data For Root Node : ";
    cin>>data;
    root = new node(data);
    q.push(root);
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout<<"Enter Left Node Data For : "<<temp->data<<" : ";
        cin>>data;
        if(data != -1) {
            temp->left = new node(data);
            q.push(temp->left);
        }
        cout<<"Enter Right Node Data For : "<<temp->data<<" : ";
        cin>>data;
        if(data != -1) {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    node *root2 = NULL;
    buildtree(root);
}