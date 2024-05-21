// Insertion
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};
void inserthead(Node *&head, int data) { //LINKED LIST INSERTION AT HEAD
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void inserttail(Node *&tail, int data) { //LINKED LIST INSERTION AT TAIL
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void insertpos(Node *&head, Node *&tail, int pos, int data) { //LINKED LIST INSERTION AT ANY POSITION
    if (pos == 1) {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL){
        inserttail(tail, data);
        return;
    }
    Node *insert = new Node(data);
    insert->next = temp->next;
    temp->next = insert;
}
void print(Node *&head) { //LINKED LIST DISPLAY
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{

    Node *list1 = new Node(1);
    Node *head = list1;
    Node *tail = list1;
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        inserttail(tail, data);
    }
    print(head);
    // insertpos(head, tail, 7, 15);
    // print(head);
    cout << "Tail = " << tail->data << endl;
    cout << "Head = " << head->data << endl;
}