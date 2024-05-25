#include <iostream>
#include <limits.h>
#include <stack>
using namespace std;
// //Approach 1
// class stack
// {
//     int size, peak, mini;
//     int *arr, *ministack;

// public:
//     stack(int size)
//     {
//         this->size = size;
//         arr = new int[size];
//         peak = -1;
//         ministack = new int[size];
//         mini = -1;
//         ministack[mini] = -1;
//     }
//     void push(int data)
//     {
//         if (size - peak > 1)
//         {
//             arr[++peak] = data;
//             minpush(data);
//         }
//         else
//         {
//             cout << "Stack Overflow" << endl;
//         }
//     }
//     void minpush(int data)
//     {
//         if (ministack[mini] == -1)
//         {
//             ministack[++mini] = data;
//             return;
//         }

//         if (data <= ministack[mini])
//         {
//             ministack[++mini] = data;
//             return;
//         }
//         int temp = ministack[mini];
//         ministack[++mini] = temp;
//     }
//     int getmin()
//     {
//         return ministack[mini];
//     }
//     void pop()
//     {

//         if (peak >= 0)
//         {
//             peak--;
//             mini--;
//         }
//         else
//         {
//             cout << "Stack Underflow" << endl;
//         }
//     }
//     int top()
//     {
//         if (!empty())
//         {
//             return arr[peak];
//         }
//         else
//         {
//             cout << "Stack Underflow" << endl;
//             return -1;
//         }
//     }
//     bool empty()
//     {
//         if (peak == -1)
//         {
//             return 1;
//         }
//         return 0;
//     }
// };
// Approach 2
class SpecialStack
{
    stack<int> s;
    int mini = INT_MAX;

public:
    void push(int data)
    {
        // Implement the push() function.
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data < mini)
            {
                s.push(2 * data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    void pop()
    {
        // Implement the pop() function.
        if (s.empty())
        {
            return;
        }
        int curr = s.top();
        s.pop();
        if (curr < mini)
        {
            int val = 2 * mini - curr;
            mini = val;
        }
    }

    int top()
    {
        // Implement the top() function.
        if (s.empty())
        {
            return -1;
        }
        int curr = s.top();
        if (curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    int getMin()
    {
        // Implement the getMin() function.
        return mini;
    }
    bool specialempty()
    {
        return s.empty();
    }
};
// void minprint(stack<int> s)
// {
//     while (!s.empty())
//     {
//         cout << s.getMin() << " ";
//         s.pop();
//     }
//     cout << endl;
// }
void miniprint(SpecialStack s)
{
    while (!s.specialempty())
    {
        cout << s.getMin() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    SpecialStack s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    miniprint(s);
}