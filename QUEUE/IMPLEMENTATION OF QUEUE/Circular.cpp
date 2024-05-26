#include <iostream>
using namespace std;
class queue
{
    int *arr, size, qfront, rear;

public:
    queue(int n)
    {
        size = n;
        arr = new int[n];
        qfront = rear = -1;
    }
    bool push(int data)
    {
        if ((qfront == 0 && rear == size - 1) && rear == (qfront - 1) % (size - 1))
        {
            cout << "Queue is Full" << endl;
            return false;
        }
        if (qfront == -1)
        {
            qfront = rear = 0;
            arr[rear] = data;
        }
        else if (rear == size - 1 && qfront != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
        return true;
    }
    int pop()
    {
        if (empty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int ans = arr[qfront];
        if (qfront == rear)
        {
            qfront = rear = -1;
        }
        else if (qfront == size - 1)
        {
            qfront = 0;
        }
        else
        {
            qfront++;
        }
        return ans;
    }
    bool empty()
    {
        if (qfront == -1)
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
        }
        return arr[qfront];
    }
};
void print(queue q)
{
    if (q.empty())
    {
        cout << "Queue is Empty" << endl;
        return;
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
    queue q(5);
    cout << q.empty() << endl;
    q.front();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    print(q);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(6);
    print(q);
}