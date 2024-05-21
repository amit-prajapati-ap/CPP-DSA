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
{ // LINKED LIST INSERTION AT TAIL
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void insertathead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
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
Node *removez(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            Node *rem = temp;
            temp = temp->next;
            head = temp;
            rem->next = NULL;
            delete rem;
        }
        else
        {
            return temp;
        }
    }
    return temp;
}
Node *reverse(Node *head)
{

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertAtTail(Node *&head, Node *&tail, int val)
{

    Node *temp = new Node(val);
    // empty list
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *add(Node *first, Node *second)
{
    int carry = 0;

    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {

        int val1 = 0;
        if (first != NULL)
            val1 = first->data;

        int val2 = 0;
        if (second != NULL)
            val2 = second->data;

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        // create node and add in answer Linked List
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;
        if (first != NULL)
            first = first->next;

        if (second != NULL)
            second = second->next;
    }
    return ansHead;
}
Node *addTwoLists(Node *first, Node *second)
{
    // step 1 -  reverse input LL
    first = reverse(first);
    second = reverse(second);

    // step2 - add 2 LL
    Node *ans = add(first, second);

    // step 3
    ans = reverse(ans);
    ans = removez(ans);
    if (ans == NULL)
    {
        Node *temp = new Node(0);
        return temp;
    }
    else
    {
        return ans;
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements of 1st LL : ";
    cin >> n;
    cout << "Enter the elements :" << endl;
    int data;
    cin >> data;
    Node *list1 = new Node(data);
    Node *head1 = list1;
    Node *tail1 = list1;
    for (int i = 1; i < n; i++)
    {
        cin >> data;
        inserttail(tail1, head1, data);
    }
    print(head1);
    n;
    cout << "Enter the number of elements of 2nd LL : ";
    cin >> n;
    cout << "Enter the elements :" << endl;
    cin >> data;
    Node *list2 = new Node(data);
    Node *head2 = list2;
    Node *tail2 = list2;
    for (int i = 1; i < n; i++)
    {
        cin >> data;
        inserttail(tail2, head2, data);
    }
    print(head2);
    cout << "Sum of Two Lists is :" << endl;
    Node *ans = addTwoLists(head1, head2);
    print(ans);
}