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
void solve(queue<int> &q, int k,int n)
{
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    for (int i = 0; i < k; i++)
    {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}
int main()
{

    int n;
    cout << "Enter The Number of Elements : ";
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        q.push(data);
    }
    int k;
    cout << "Enter The Value of k : ";
    cin >> k;
    cout << "Before Reverse : " << endl;
    print(q);
    solve(q,k,n);
    cout << "After Reverse : " << endl;
    print(q);
}