#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
void findrev(queue<int> &q)
{
    // // Approach 1 (Using Stack)
    // stack<int> s;
    // while (!q.empty())
    // {
    //     s.push(q.front());
    //     q.pop();
    // }
    // while (!s.empty())
    // {
    //     q.push(s.top());
    //     s.pop();
    // }

    // Approach 2 (Using Recursion)
    if (q.empty())
    {
        return;
    }
    int temp = q.front();
    q.pop();
    findrev(q);
    q.push(temp);
}
int main()
{
    queue<int> q;
    cout << "Enter Number of Elements : ";
    int n;
    cin >> n;
    cout << "Enter The Elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        q.push(data);
    }
    cout << "Before Reverse : " << endl;
    print(q);
    findrev(q);
    cout << "After Reverse : " << endl;
    print(q);
}