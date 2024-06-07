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
queue<int> solve(queue<int> q, int n)
{
    // //Approach 1 (using Queue)
    // queue<int> newq;
    // for (int i = 0; i < n / 2; i++)
    // {
    //     newq.push(q.front());
    //     q.pop();
    // }
    // while (!newq.empty())
    // {
    //     q.push(newq.front());
    //     q.push(q.front());
    //     q.pop();
    //     newq.pop();
    // }
    // return q;
    // Approach 2 (using Stack)
    stack<int> s;
    int half;
    if (n&1 == 1)
    {
        half = (n / 2) + 1;
    }
    else
    {
        half = n/2;
    }
    
    for (int i = 0; i < half; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < half; i++)
    {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < half; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        q.push(q.front());
        q.pop();
        s.pop();
    }
    q.push(q.front());
    q.pop();
    return q;
}
int main()
{
    int n;
    cout << "Enter The Number of Elements : ";
    cin >> n;
    queue<int> q;
    cout << "Enter The Elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        q.push(data);
    }
    cout << "Before Interleave : " << endl;
    print(q);
    cout << "After Interleave : " << endl;
    queue<int> newq = solve(q, n);
    print(newq);
}