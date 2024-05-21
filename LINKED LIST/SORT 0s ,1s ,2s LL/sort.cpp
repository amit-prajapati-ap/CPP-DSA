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
void input(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}
Node *sortList(Node *head)
{
    // Approach 2 (Without data replacement)
    Node *zlist = new Node(-1);
    Node *ztail = zlist;
    Node *olist = new Node(-1);
    Node *otail = olist;
    Node *tlist = new Node(-1);
    Node *ttail = tlist;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            input(ztail, curr);
        }
        else if (curr->data == 1)
        {
            input(otail, curr);
        }
        else
        {
            input(ttail, curr);
        }
        curr = curr->next;
    }
    if (olist->next != NULL)
    {
        ztail->next = olist->next;
    }
    else
    {
        ztail->next = tlist->next;
    }
    otail->next = tlist->next;
    ttail->next = NULL;
    head = zlist->next;
    delete tlist;
    delete olist;
    delete zlist;
    return head;

    /*
    //Approach 1 (Data replacement)
    int countz = 0;
    int counto = 0;
    int countt = 0;
    Node* curr = head;
    while(curr != NULL) {
        if(curr->data == 0) {
            countz++;
        }
        else if (curr->data == 1) {
            counto++;
        }
        else
        {
            countt++;
        }
        curr = curr->next;
    }
    curr = head;
    while(curr != NULL) {
        if(countz != 0)
        {
            curr->data = 0;
            countz--;
        }
        else if(counto != 0) {
            curr->data = 1;
            counto--;
        }
        else
        {
            curr->data = 2;
            countt--;
        }
        curr = curr->next;
    }
    return head;
    */
}
int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the elements(From 0, 1 and 2 only) :" << endl;
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
    cout << "List is Sorted : " << endl;
    Node *ans = sortList(head);
    print(ans);
}