// INSERTION IN DOUBLY LINKED LIST
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};
void inserthead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
}
void inserttail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}
void insertpos(Node *&head, Node *&tail, int pos, int data)
{
    if (pos == 1)
    {
        inserthead(head, data);
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        inserttail(tail, data);
        return;
    }
    Node *insert = new Node(data);
    insert->prev = temp;
    insert->next = temp->next;
    temp->next = insert;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    int n, data, position;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the elements : " << endl;
    cin >> data;
    Node *list1 = new Node(data);
    Node *head = list1;
    Node *tail = list1;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> data;
        inserttail(tail, data);
    }
    print(head);
    cout << "Enter the position which you insert : ";
    cin >> position;
    cout << "Enter the element : ";
    cin >> data;
    insertpos(head, tail, position, data);
    print(head);
    cout << "Head = " << head->data << endl;
    cout << "Tail = " << tail->data << endl;
}