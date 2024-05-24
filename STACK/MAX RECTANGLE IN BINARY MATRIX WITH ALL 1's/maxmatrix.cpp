#include <iostream>
#include <limits.h>
#include <stack>
#include <vector>
using namespace std;
void print(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}
vector<int> prevSmallerElement(int *arr, int n)
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
vector<int> nextSmallerElement(int *arr, int n)
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
int maxarea(int *arr, int n)
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
int MaxArea(int **arr, int n)
{
    int area = maxarea(arr[0], n);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                arr[i][j] = arr[i][j] + arr[i - 1][j];
            }
            else
            {
                arr[i][j] = 0;
            }
        }
        area = max(area, maxarea(arr[i], n));
    }
    return area;
}
int main()
{
    int n;
    int **arr;
    cout << "Enter Number Of Row : ";
    cin >> n;
    arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    cout << "Enter the Elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    print(arr, n);
    cout << "Largest Rectangular Area of Binary Matrix is : " << MaxArea(arr, n);
}