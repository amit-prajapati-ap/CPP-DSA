#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void inserthead(Node *&head, int data)
{ // LINKED LIST INSERTION AT HEAD
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void print(Node *head)
{ // LINKED LIST DISPLAY
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}
// Approach 1
Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
// Approach 2
Node *reverse2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *Subhead = reverse2(head->next);
    head->next->next = head;
    head->next = NULL;
    return Subhead;
}
// Approach 3
void reverse3(Node *&head, Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    Node *forward = curr->next;
    reverse3(head, forward, curr);
    curr->next = prev;
}
int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Enter the elements : " << endl;
    int data;
    cin >> data;
    Node *list1 = new Node(data);
    Node *head = list1;
    for (int i = 1; i < n; i++)
    {
        int data;
        cin >> data;
        inserthead(head, data);
    }
    print(head);
    // Node *ans = reverse2(head);
    Node *curr = head;
    Node *prev = NULL;
    reverse3(head, curr, prev);
    print(head);
}