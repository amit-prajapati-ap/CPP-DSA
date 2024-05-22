#include <iostream>
#include <stack>
using namespace std;
void insertatbottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();
    insertatbottom(s, x);
    s.push(num);
}
void ReverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    ReverseStack(s);
    insertatbottom(s, num);
}
void sorted(stack<int> &s, int num)
{
    if (s.empty() || (!s.empty() && s.top() < num))
    {
        s.push(num);
        return;
    }
    int val = s.top();
    s.pop();
    sorted(s, num);
    s.push(val);
}
void SortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    SortStack(s);
    sorted(s, num);
}
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    int n;
    stack<int> s;
    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        s.push(data);
    }
    cout << "Before Sorting the Stack : " << endl;
    print(s);
    SortStack(s);
    cout << "After Sorting the Stack : " << endl;
    cout << "Decreasing Order : " << endl;
    print(s);
    cout << "Increasing Order : " << endl;
    ReverseStack(s);
    print(s);
}