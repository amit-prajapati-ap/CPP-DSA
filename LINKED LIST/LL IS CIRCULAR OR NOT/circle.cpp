#include <iostream>
#include <windows.h>
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
bool circle(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return false;
    }
    return true;
}
void inserthead(Node *&head, int data)
{ // LINKED LIST INSERTION AT HEAD
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}
void inserttail(Node *&tail, int data, int element = 0)
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
void printtail(Node *tail)
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
void printhead(Node *&head)
{ // LINKED LIST DISPLAY
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
    Node *head1 = NULL;
    bool option;
    int num;
start:
    system("cls");
    cout << "Choose Following option : " << endl
         << "1 For Non-Circular." << endl
         << "2 For Circular." << endl
         << "3 For Exit" << endl;
    cin >> num;
    if (num == 1)
    {
        system("cls");
        int n;
        cout << "Enter Number Of Elements : ";
        cin >> n;
        cout << "Enter Elements : " << endl;
        int data;
        cin >> data;
        Node *list = new Node(data);
        Node *head = list;
        for (int i = 0; i < n - 1; i++)
        {
            int data;
            cin >> data;

            inserthead(head, data);
        }
        printhead(head);
        Sleep(2000);
        head1 = head;
        goto start;
    }
    else if (num == 2)
    {
        system("cls");
        int n;
        cout << "Enter Number Of Elements : ";
        cin >> n;
        cout << "Enter Elements : " << endl;
        int data;
        cin >> data;
        Node *tail = NULL;
        inserttail(tail, data);
        int temp = data;
        for (int i = 0; i < n - 1; i++)
        {
            int data;
            cin >> data;

            inserttail(tail, data, temp);
            temp = data;
        }
        printtail(tail);
        Sleep(2000);
        head1 = tail;
        goto start;
    }
    else if (num == 3)
    {
        system("cls");
        cout << "ThankYou!!"<<endl;
        Sleep(2000);
    }

    else
    {
        system("cls");
        cout << "Invalid Option!" << endl
             << "Please Re-Enter!" << endl;
        Sleep(2500);
        goto start;
    }

    if (circle(head1))
    {
        cout << "Circular in Nature!!";
    }
    else
    {
        cout << "Not Circular in Nature!!";
    }
}