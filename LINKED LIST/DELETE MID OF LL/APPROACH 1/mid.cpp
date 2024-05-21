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
// Deletes middle of linked list and returns head of the modified list
void deleteMid(Node *&head)
{
    // Your Code Here
    if (head->next == NULL || head == NULL)
    {
        head = NULL;
    }
    // Calculating Size of Linked list
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    int res = count / 2;
    temp = head;
    while (temp != NULL)
    {
        res--;
        if (res == 0)
        {
            Node *mid = temp->next;
            temp->next = temp->next->next;
            free(mid);
        }
        temp = temp->next;
    }
}
void insert(Node *&head, int data)
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
int getlen(Node *head)
{
    int ans = 0;
    while (head != NULL)
    {
        head = head->next;
        ans++;
    }
    return ans;
}
int Findmid(Node *head)
{
    int len = getlen(head);
    int mid = len / 2;
    int cnt = 0;
    while (cnt < mid)
    {
        head = head->next;
        cnt++;
    }
    return head->data;
}
int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the elements :" << endl;
    int data;
    cin >> data;
    Node *list = new Node(data);
    Node *head = list;
    for (int i = 1; i < n; i++)
    {
        int data;
        cin >> data;
        insert(head, data);
    }
    print(head);
    cout << "Mid Element : " << Findmid(head) << endl;
}