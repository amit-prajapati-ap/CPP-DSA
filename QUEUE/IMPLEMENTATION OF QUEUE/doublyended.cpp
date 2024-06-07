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
    bool push_back(int data)
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
    int pop_front()
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
    bool push_front(int data)
    {
        if ((qfront == 0 && rear == size - 1) && rear == (qfront - 1) % (size - 1))
        {
            cout << "Queue is Full" << endl;
            return false;
        }
        else if (qfront == -1)
        {
            qfront = rear = 0;
            arr[rear] = data;
        }
        else if (qfront == 0 && rear != size - 1)
        {
            qfront = size - 1;
            arr[qfront] = data;
        }
        else
        {
            qfront--;
            arr[qfront] = data;
        }

        return true;
    }
    int pop_back()
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
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return ans;
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
        q.pop_front();
    }
    cout << endl;
}
int main()
{
    queue q(5);
    cout << q.empty() << endl;
    q.front();
    q.push_back(1);
    q.push_back(2);
    q.push_front(3);
    q.push_front(4);
    q.push_back(5);
    print(q);
    q.pop_back();
    print(q);
    q.pop_front();
    print(q);
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.pop_back();
}