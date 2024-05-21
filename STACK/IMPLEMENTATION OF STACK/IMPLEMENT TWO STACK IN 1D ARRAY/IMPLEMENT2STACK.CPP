#include <iostream>
using namespace std;

class TwoStack
{

    int size, peak1, peak2, *arr;

public:
    TwoStack(int size)
    {
        this->size = size;
        peak1 = -1;
        peak2 = size;
        arr = new int[size];
    }

    void push1(int data)
    {
        if (peak2 - peak1 > 1)
        {
            arr[++peak1] = data;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }
    void push2(int data)
    {
        if (peak2 - peak1 > 1)
        {
            arr[--peak2] = data;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }
    void pop1()
    {
        if (!empty1())
        {
            peak1--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }
    void pop2()
    {
        if (!empty2())
        {
            peak2++;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }
    int top1()
    {
        if (!empty1())
        {
            return arr[peak1];
        }
        cout << "Stack Underflow" << endl;
        return -1;
    }
    int top2()
    {
        if (!empty2())
        {
            return arr[peak2];
        }
        cout << "Stack Underflow" << endl;
        return -1;
    }
    bool empty1()
    {
        if (peak1 == -1)
        {
            return true;
        }
        return false;
    }
    bool empty2()
    {
        if (peak2 == size)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    TwoStack s(5);
    s.push1(5);
    s.push1(10);
    s.push2(15);
    s.push2(20);
    s.push2(25);
    cout << s.top1() << endl;
    s.pop1();
    s.push1(30);
    cout << s.top2() << endl;
    s.pop2();
    cout << s.top1() << endl;
    s.push2(35);
    cout << s.top2() << endl;
    s.pop1();
    cout << s.top1() << endl;
    s.pop2();
    cout << s.top2() << endl;
    s.pop1();
    cout << s.top1() << endl;
    s.pop1();
    cout << s.top1() << endl;
    s.pop2();
    cout << s.top2() << endl;
    cout<<s.empty1()<<endl;
    cout<<s.empty2()<<endl;
}