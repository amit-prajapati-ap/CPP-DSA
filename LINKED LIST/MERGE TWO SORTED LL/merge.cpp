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
Node *solve(Node *first, Node *second)
{
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }
    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next;
    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) &&
            (curr2->data <= next1->data))
        {
            // Merge list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            // Updata Ptr's
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}
Node *sortTwoLists(Node *first, Node *second)
{
    // Write your code here.
    if (first == NULL)
    {
        return second;
    }
    else if (second == NULL)
    {
        return first;
    }
    else if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements of 1st List : ";
    cin >> n;
    cout << "Enter the elements :" << endl;
    int data;
    cin >> data;
    Node *list1 = new Node(data);
    Node *head1 = list1;
    Node *tail1 = list1;
    for (int i = 1; i < n; i++)
    {
        int data;
        cin >> data;
        inserttail(tail1, head1, data);
    }
    print(head1);
    cout << "Enter the number of elements of 2st List : ";
    cin >> n;
    cout << "Enter the elements :" << endl;
    cin >> data;
    Node *list2 = new Node(data);
    Node *head2 = list2;
    Node *tail2 = list2;
    for (int i = 1; i < n; i++)
    {
        int data;
        cin >> data;
        inserttail(tail2, head2, data);
    }
    print(head2);
    cout << "After Merging These Two Lists : " << endl;
    Node *ans = sortTwoLists(head1, head2);
    print(ans);
}