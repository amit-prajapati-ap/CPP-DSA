#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int solveRec(vector<int> &arr, int index)
{
    if (index < 0)
    {
        return 0;
    }
    else if (index == 0)
    {
        return arr[index];
    }
    int include = arr[index] + solveRec(arr, index - 2);
    int exclude = 0 + solveRec(arr, index - 1);
    return max(include, exclude);
}
int solveMem(vector<int> &arr, int index, vector<int> &dp)
{
    if (index < 0)
    {
        return 0;
    }
    else if (index == 0)
    {
        return arr[index];
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }

    int include = arr[index] + solveMem(arr, index - 2, dp);
    int exclude = 0 + solveMem(arr, index - 1, dp);
    return dp[index] = max(include, exclude);
}
int solveTab(vector<int> &arr, int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = arr[0];
    for (int index = 2; index < n; index++)
    {
        int include = arr[index] + dp[index - 2];
        int exclude = 0 + dp[index - 1];
        dp[index] = max(include, exclude);
    }
    return dp[n - 1];
}
int solve_Space_Optimal(vector<int> &arr, int n)
{
    int prev2 = 0;
    int prev1 = arr[0];
    for (int index = 2; index < n; index++)
    {
        int include = arr[index] + prev2;
        int exclude = 0 + prev1;
        int curr = max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums, int n)
{
    // // Recursive Method
    // return solveRec(nums, n - 1);
    // // Memorization Method
    // vector<int> dp(n, -1);
    // return solveMem(nums, n - 1, dp);
    // // Tabulation Method
    // return solveTab(nums, n);
    // Space-Optimization Method
    return solve_Space_Optimal(nums, n);
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
    cout << "Maximum Sum Of Non-Adjacent Elements : " << maximumNonAdjacentSum(arr, n) << endl;
}