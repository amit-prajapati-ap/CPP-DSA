#include <iostream>
#include <vector>
#include <deque>
using namespace std;
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void solve(int *arr, vector<int> &ans, int n, int k)
{
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    if (dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    for (int i = k; i < n; i++)
    {
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        if (dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
}
int main()
{
    int n, *arr, k;
    cout << "Enter Number Of Elements : ";
    cin >> n;
    arr = new int[n];
    cout << "Enter The Elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter The Value of k : ";
    cin >> k;
    vector<int> ans;
    solve(arr, ans, n, k);
    print(ans);
}