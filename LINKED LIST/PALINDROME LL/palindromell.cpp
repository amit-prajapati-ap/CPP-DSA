#include <iostream>
#include <vector>
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
void inserttail(Node *&tail, Node *&head, int data)
{ // LINKED LIST INSERTION AT TAIL
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void insertathead(Node *&head, int data)
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
// Approach 1
bool compare(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        if (arr[s] != arr[e])
        {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}
bool isPalindrome1(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return compare(arr);
}

// Approach 2
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}
bool isPalindrome2(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *last = reverse(slow);
    while (last)
    {
        if (head->data != last->data)
        {
            return false;
        }
        head = head->next;
        last = last->next;
    }
    return true;
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
    Node *tail = list;
    for (int i = 1; i < n; i++)
    {
        int data;
        cin >> data;
        inserttail(tail, head, data);
    }
    print(head);
    if (isPalindrome1(head))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
    if (isPalindrome2(head))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
}