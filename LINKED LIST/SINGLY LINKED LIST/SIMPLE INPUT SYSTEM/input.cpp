#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void inserttail(Node *&tail, Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}
Node *input()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the elements :" << endl;
    int data;
    cin >> data;
    Node *list = new Node(data);
    Node *head = list;
    Node *tail = list;
    for (int i = 1; i < n; i++)
    {
        int data;
        cin >> data;
        inserttail(tail, head, data);
    }
    print(head);
    return head;
}
int main()
{
    Node *head = input();
}