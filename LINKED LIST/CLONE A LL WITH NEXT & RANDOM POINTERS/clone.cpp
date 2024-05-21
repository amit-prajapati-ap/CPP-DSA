#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        random = NULL;
    }
};
void inserttail(Node *&tail, Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }

    tail->next = temp;
    tail->random = temp->random;
    tail = temp;
}
void insertrandom(Node *&head)
{
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->random->next;
    head->next->next->next->random = head->next;
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
    temp = head;
    while (temp != NULL)
    {
        cout << temp->random->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}
Node *clone1(Node *head)
{

    Node *clonehead = NULL;
    Node *clonetail = NULL;
    Node *temp = head;

    while (temp != NULL)
    {
        inserttail(clonetail, clonehead, temp->data);
        temp = temp->next;
    }
    map<Node *, Node *> m;
    Node *original = head;
    Node *clone = clonehead;
    while (original != NULL)
    {
        m[original] = clone;
        original = original->next;
        clone = clone->next;
    }
    original = head;
    clone = clonehead;
    while (original != NULL)
    {
        clone->random = m[original->random];
        clone = clone->next;
        original = original->next;
    }
    return clonehead;
}
Node *clone2(Node *head)
{
    // step 1: Create a Clone List
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        inserttail(cloneTail, cloneHead, temp->data);
        temp = temp->next;
    }

    // step 2: insert nodes of Clone List in between originalList

    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        Node *next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // step 3: Random pointer copy
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {

        if (originalNode->random != NULL)
        {
            cloneNode->random = originalNode->random->next;
        }
        else
        {
            cloneNode->random = NULL;
        }

        cloneNode = cloneNode->next;
        originalNode = originalNode->next;
    }

    // step 4: revert step 2 changes
    Node *original = head;
    Node *copy = cloneHead;

    while (original && copy)
    {
        original->next =
            original->next ? original->next->next : original->next;

        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    // step 5 answer return
    return cloneHead;
}
int main()
{
    int n;
    cout << "Enter the number of elements (Only 4 size): ";
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
    insertrandom(head);
    cout << "Before Clonning : " << endl;
    print(head);
    Node *clonehead1 = clone1(head); // Using Map
    cout << "After Clonning : " << endl;
    print(clonehead1);
    Node *clonehead2 = clone2(head); // Changing pointers
    print(clonehead2);
}