// Deletion
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
void print(Node *&head)
{ // LINKED LIST DISPLAY
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}
void deletion(Node *&head, int pos)
{
    if (pos == 1) // Deleting 1st Node
    {
        Node *temp = head;
        head = head->next;
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
        prev->next = curr->next;
        curr->next = NULL;
        free(curr);
    }
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
    int pos;
    cout << "Enter the Position Which you delete : ";
    cin >> pos;
    cout << "Before Deletion :" << endl;
    print(head);
    cout << "After Deletion :" << endl;
    deletion(head, pos);
    print(head);
}