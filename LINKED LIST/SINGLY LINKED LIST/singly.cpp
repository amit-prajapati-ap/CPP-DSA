// Creating A Linked list
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
int main()
{

    Node *data1 = new Node(5);
    cout << data1->data << endl;
    cout << data1->next << endl;
}