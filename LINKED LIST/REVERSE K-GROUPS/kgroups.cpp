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
int length(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}
Node *Kreverse(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if (length(head) < k)
    {
        return head;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    int cnt = 0;
    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    if (next != NULL)
    {
        head->next = Kreverse(next, k);
    }
    return prev;
}
void insert(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
}
int main()
{

    int n;
    cout << "Enter Number Of Elements : ";
    cin >> n;
    cout << "Enter Elements : " << endl;
    int data;
    cin >> data;
    Node *List = new Node(data);
    Node *head = List;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> data;
        insert(head, data);
    }
    print(head);
    int k;
    cout << "Enter The value Of K : ";
    cin >> k;
    Node *Ans = Kreverse(head, k);
    print(Ans);
}