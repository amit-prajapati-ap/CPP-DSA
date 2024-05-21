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
int findmid(Node *head)
{
    Node *Slow = head;
    Node *Fast = head->next;
    while (Fast != NULL)
    {
        Fast = Fast->next;
        if (Fast != NULL)
        {
            Fast = Fast->next;
        }
        Slow = Slow->next;
    }
    return Slow->data;
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
    cout << "Mid Elements : " << findmid(head) << endl;
}