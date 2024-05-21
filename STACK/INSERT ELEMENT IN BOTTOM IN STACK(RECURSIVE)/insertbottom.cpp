#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int> &s, int data)
{
    if (s.empty())
    {
        s.push(data);
        return;
    }
    int num = s.top();
    s.pop();
    solve(s, data);
    s.push(num);
}
void print(stack<int> s) {
while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Before Inserting : ";
    print(s);
    int data;
    cout << "Enter the element You Want to insert at bottom : ";
    cin >> data;
    solve(s, data);
    cout << "After Inserting : ";
    print(s);
}