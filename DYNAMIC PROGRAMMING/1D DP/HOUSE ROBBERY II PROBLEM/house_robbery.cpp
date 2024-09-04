#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int solve_Space_Optimal(vector<int> &arr, int s, int e)
{
    int n = arr.size() - 1;
    int prev1 = arr[s];
    int prev2 = 0;
    for (int i = s + 1; i < e; i++)
    {
        int exl = prev1 + 0;
        int inc = prev2 + arr[i];
        int ans = max(inc, exl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int maximumValueRobbed(vector<int> &arr, int n)
{
    return max(solve_Space_Optimal(arr, 0, n - 1), solve_Space_Optimal(arr, 1, n));
}
int main()
{
    int n, data, target;
    cout << "Enter The Number Of Houses : ";
    cin >> n;
    cout << "Enter The Money In Each House : " << endl;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        arr.push_back(data);
    }
    cout << "Maximum Number Of Money Robbed : " << maximumValueRobbed(arr, n) << endl;
}