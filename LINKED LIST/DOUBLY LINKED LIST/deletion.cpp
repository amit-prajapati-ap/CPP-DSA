// Deletion In Doubly Linked List
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
void deletion(Node *&head, Node *&tail, int pos)
{
    if (pos == 1) // Deleting 1st Node
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            tail = prev;
        }

        prev->next = curr->next;
        curr->prev = NULL;
        curr->next = NULL;
        free(curr);
    }
}
void inserttail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
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
    cout << "Enter the position which you want to delete : " << endl;
    cin >> position;
    deletion(head, tail, position);
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
}