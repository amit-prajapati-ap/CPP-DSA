#include <iostream>
#include <map>
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
// Approach 1 (Sorted)
void duplicate(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
}
// Approach 2 (Unsorted)
void duplicate2(Node *&head)
{
    if (head == NULL)
        return;

    map<int, bool> visited;
    Node *current = head;
    Node *prev = NULL;

    while (current != NULL)
    {
        if (visited[current->data] == true)
        {
            Node *temp = current;
            prev->next = current->next;
            current = current->next;
            delete temp;
        }
        else
        {
            visited[current->data] = true;
            prev = current;
            current = current->next;
        }
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
    // duplicate(head);
    // print(head);
    cout << "After Removing Duplicates :" << endl;
    duplicate2(head);
    print(head);
}