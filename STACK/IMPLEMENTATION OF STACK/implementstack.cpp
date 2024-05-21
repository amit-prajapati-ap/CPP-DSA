#include <iostream>
using namespace std;

class stack
{
    int size, peak;
    int *arr;

public:
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        peak = -1;
    }
    void push(int data)
    {
        if (size - peak > 1)
        {
            arr[++peak] = data;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }
    void pop()
    {
        if (peak >= 0)
        {
            peak--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }
    int top()
    {
        if (!empty())
        {
            return arr[peak];
        }
        else
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
    }
    bool empty()
    {
        if (peak == -1)
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    stack s(5);
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);
    cout << s.top() << endl;
    s.pop();
    s.push(30);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout<<s.empty()<<endl;
}