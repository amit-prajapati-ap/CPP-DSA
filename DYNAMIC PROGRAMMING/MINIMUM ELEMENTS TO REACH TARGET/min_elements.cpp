#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int solveRec(vector<int> &arr, int n, int target)
{
    if (target == 0)
    {
        return 0;
    }
    else if (target < 0)
    {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int ans = solveRec(arr, n, target - arr[i]);
        if (ans != INT_MAX)
        {
            mini = min(ans + 1, mini);
        }
    }
    return mini;
}
int solveMem(vector<int> &arr, int n, int target, vector<int> &dp)
{
    if (target == 0)
    {
        return 0;
    }
    else if (target < 0)
    {
        return INT_MAX;
    }
    if (dp[target] != -1)
    {
        return dp[target];
    }

    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int ans = solveMem(arr, n, target - arr[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(ans + 1, mini);
        }
    }
    return dp[target] = mini;
}
int solveTab(vector<int> &arr, int n, int tar)
{
    vector<int> dp(tar + 1, INT_MAX);
    dp[0] = 0;
    for (int target = 1; target <= tar; target++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int ans = dp[target - arr[i]];
            if (ans != INT_MAX)
            {
                mini = min(ans + 1, mini);
            }
        }
        dp[target] = mini;
    }
    if (dp[tar] == INT_MAX)
    {
        return -1;
    }
    return dp[tar];
}
int minElements(vector<int> &arr, int n, int target)
{
    // // Recursive Method
    // int ans = solveRec(arr, n, target);
    // if (ans == INT_MAX)
    // {
    //     return -1;
    // }
    // return ans;
    // // Memorization Method
    // vector<int> dp(target + 1,-1);
    // int ans = solveMem(arr, n, target,dp);
    // if (ans == INT_MAX)
    // {
    //     return -1;
    // }
    // return ans;
    // Tabulation Method
    return solveTab(arr, n, target);
}
int main()
{
    int n, data, target;
    cout << "Enter The Number Of Elements : ";
    cin >> n;
    cout << "Enter The Elements : " << endl;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        arr.push_back(data);
    }
    cout << "Enter The Targeted Value : ";
    cin >> target;
    cout << "Minimum Elements To Reach Target : " << minElements(arr, n, target) << endl;
}