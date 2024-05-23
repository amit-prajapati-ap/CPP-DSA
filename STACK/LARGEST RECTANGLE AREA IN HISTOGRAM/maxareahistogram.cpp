#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>
using namespace std;
vector<int> prevSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> nextSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int MaxArea(vector<int> arr, int n)
{
    vector<int> next(n);
    next = nextSmallerElement(arr, n);
    vector<int> prev(n);
    prev = prevSmallerElement(arr, n);
    int Area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int length = arr[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int breadth = next[i] - prev[i] - 1;
        int NewArea = length * breadth;
        Area = max(Area, NewArea);
    }
    return Area;
}

int main()
{
    int n;
    vector<int> arr;
    cout << "Enter Number Of Elements : ";
    cin >> n;
    cout << "Enter the Elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        arr.push_back(data);
    }
    cout << "Largest Rectangular Area of Histogram is : " << MaxArea(arr, n);
}