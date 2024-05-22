#include <iostream>
#include <stack>
using namespace std;
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
int *NextSmaller(int *arr, int n)
{
    // //Approach 1 (Using Loop)
    // int *ans = new int[n];
    // for (int i = 0; i < n-1; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[j] < arr[i])
    //         {
    //             ans[i] = arr[j];
    //             break;
    //         }
    //         else
    //         {
    //             ans[i] = -1;
    //         }
    //     }
    // }
    // ans[n-1] = -1;
    // return ans;

    // Approach 2 (Using Stack)
    int *ans = new int[n];
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter Number Of Elements : ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the Elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int *ans = NextSmaller(arr, n);
    cout << "Next Smaller Elements : " << endl;
    print(ans, n);
}