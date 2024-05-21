#include <iostream>
#include <stack>
using namespace std;
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}
void deleting(stack<int> &s, int count, int size)
{
    if (count == size / 2)
    {
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();
    deleting(s, ++count, size);
    s.push(num);
}
void solve(stack<int> s)
{

    int size = s.size();
    int count = 0;
    cout << "Before deleting : " << endl;
    print(s);
    deleting(s, count, size);
    cout << "After deleting : " << endl;
    print(s);
}
int main()
{

    int n, count = 0;
    stack<int> s;
    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Enter the elements of stack : " << endl;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        s.push(data);
    }
    solve(s);
}