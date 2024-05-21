#include <iostream>
#include <map>
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
void insert(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        Node *curr = tail;
        while (curr != NULL)
        {
            if (curr->data == element)
            {
                Node *temp = new Node(data);
                temp->next = curr->next;
                curr->next = temp;
                break;
            }
            curr = curr->next;
        }
    }
}
void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << ' ';
        tail = tail->next;
    } while (temp != tail);
    cout << endl;
}
// Approch 1 (using map)
bool Detect(Node *head)
{
    if (head == NULL)
    {
        return false;
    }

    Node *curr = head;
    map<Node *, bool> visited;
    while (curr != NULL)
    {
        if (visited[curr] == true)
        {
            return true;
        }
        visited[curr] = true;
        curr = curr->next;
    }
    return 0;
}
// Approach 2 (Floyed's Cycle Detection Algorithm)
bool Floyed(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
// Approach 3 (Finding Beginning)
Node *Beginning(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            break;
        }
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow /*or fast*/;
}
// Approach 4 (Removing Loop)
void Remove(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *startofloop = Beginning(head);
    Node *curr = startofloop;
    while (curr->next != startofloop)
    {
        curr = curr->next;
    }
    curr->next = NULL;
}
int main()
{
    Node *tail = NULL;
    int n, element = 0;
    cout << "Enter Number Of Elements : ";
    cin >> n;
    cout << "Enter Elements : " << endl;
    int data;
    cin >> data;
    insert(tail, element, data);
    element = data;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> data;
        insert(tail, element, data);
        element = data;
    }
    print(tail);
    if (Detect(tail))
    {
        cout << "Circular" << endl;
    }
    else
    {
        cout << "Not Circular" << endl;
    }
    Node *Found = Beginning(tail);
    cout << "Beginning of Loop Data : " << Found->data << endl;
    Remove(tail);
    cout << "Loop Is Removed!!" << endl;
    if (Detect(tail))
    {
        cout << "Circular" << endl;
    }
    else
    {
        cout << "Not Circular" << endl;
    }
}