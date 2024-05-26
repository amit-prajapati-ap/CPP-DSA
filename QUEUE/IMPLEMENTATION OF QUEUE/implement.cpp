#include <iostream>
using namespace std;
// Using Array
class queue
{
    int size, qfront, rear, *arr;

public:
    queue(int n)
    {
        size = n;
        arr = new int[n];
        qfront = rear = 0;
    }

    bool push(int data)
    {
        if (rear == size)
        {
            cout << "Queue Overflow" << endl;
            return false;
        }
        arr[rear++] = data;
        return true;
    }
    int pop()
    {
        if (empty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int ans = arr[qfront++];
        if (empty())
        {
            qfront = rear = 0;
        }

        return ans;
    }
    bool empty()
    {
        if (qfront == rear)
        {
            return true;
        }
        return false;
    }
    int front()
    {
        if (empty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[qfront];
    }
};
void print(queue q)
{
    if (q.empty())
    {
        cout << "Queue is Empty" << endl;
    }
    while (!q.empty())
    {
        cout << q.front() << "  ";
        q.pop();
    }
    cout << endl;
}
int main()
{
    queue q(10);
    cout << q.front() << endl;
    cout << q.empty() << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    print(q);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(11);
    print(q);
}