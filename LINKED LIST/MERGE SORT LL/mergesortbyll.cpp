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
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
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
Node *merge(Node *first, Node *second)
{
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
Node *findmid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *mergesort(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = findmid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;
    left = mergesort(left);
    right = mergesort(right);
    Node *ans = merge(left, right);
    return ans;
}
int main()
{
    Node *head = input();
    Node *Merge = mergesort(head);
    cout << "After Sorting : " << endl;
    print(Merge);
}