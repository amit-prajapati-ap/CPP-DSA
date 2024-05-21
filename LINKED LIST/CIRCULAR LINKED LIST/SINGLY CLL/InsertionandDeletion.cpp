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
void deletion(Node *&tail, int element)
{
    if (tail == NULL)
    {
        tail = NULL;
        return;
    }

    Node *prev = tail;
    Node *curr = prev->next;
    while (curr->data != element)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    if (curr == prev)
    {
        curr = NULL;
    }
    else if (tail == curr)
    {
        tail = prev;
    }

    curr->next = NULL;
    free(curr);
}
void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "Empty list" << endl;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << ' ';
        tail = tail->next;
    } while (temp != tail);
    cout << endl;
}

int main()
{
    Node *tail = NULL;
    insert(tail, 2, 5);
    print(tail);
    insert(tail, 5, 3);
    print(tail);
    insert(tail, 3, 7);
    print(tail);
    insert(tail, 5, 1);
    print(tail);
    insert(tail, 7, 6);
    print(tail);
    deletion(tail, 5);
    print(tail);
}