#include <iostream>
using namespace std;
class stacks
{
    int size, freespot;
    int *arr, *next, *tops;

public:
    stacks(int n, int k)
    {
        size = n;
        arr = new int[n];
        next = new int[n];
        tops = new int[k];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        for (int i = 0; i < k; i++)
        {
            tops[i] = -1;
        }

        freespot = 0;
    }
    bool push(int data, int m)
    {
        if (freespot == -1)
        {
            cout<<"Stack Overflow"<<endl;
            return false;
        }
        int index = freespot;
        freespot = next[index];
        arr[index] = data;
        next[index] = tops[m - 1]; // m-1 Becouse 0 Based Indexing
        tops[m - 1] = index;
        return true;
    }
    int pop(int m)
    {
        if (empty(m))
        {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        int index = tops[m - 1];
        tops[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        int temp = arr[index];
        return temp;
    }
    int top(int m)
    {
        if (empty(m))
        {
            return -1;
        }
        return arr[tops[m - 1]];
    }
    bool empty(int m)
    {
        if (tops[m - 1] == -1)
        {
            return true;
        }
        return false;
    }
};
void print(stacks s, int m)
{
    if (s.empty(m))
    {
        cout << "Stack Number " << m << " is Empty." << endl;
        return;
    }
    while (!s.empty(m))
    {
        cout << s.top(m) << "  ";
        s.pop(m);
    }
    cout << endl;
}
int main()
{
    // int n, k;
    // cout << "Enter Number of Elements & Number Of Stacks : ";
    // cin >> n >> k;
    stacks s(10, 3);
    // s.push(10, 2);
    // s.push(20, 3);
    // s.push(5, 1);
    // s.push(15, 2);
    // s.push(25, 3);
    // s.push(40, 1);
    // s.push(50, 2);
    // s.pop(2);
    // s.push(60, 3);
    // s.push(70, 1);
    // s.push(90,2);
    // s.push(100,1);
    // s.pop(3);
    // s.push(100,3);
    s.pop(2);
    print(s, 1);
    s.push(10,3);
    print(s, 2);
    print(s, 3);
}