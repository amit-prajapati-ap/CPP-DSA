#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int solveRec(int n)
{
    if (n <= 1)
        return n;
    int ans = solveRec(n - 1) + solveRec(n - 2);
    return ans;
}
int solveMem(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = solveMem(n - 1, dp) + solveMem(n - 2, dp);
    return dp[n];
}
int solveTab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}
int solve_Space_Optimal(int n)
{
    if (n == 0 || n == 1)
        return n;
    int prev1 = 1;
    int prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main()
{
    int data;
    cout << "Enter the Number of Fibonacci Numbers : ";
    cin >> data;
    // // Using Recursion
    // int ans = solveRec(data);
    // // Using Top-Down Approach or (Recursion + Memorization)
    // vector<int> dp(data + 1, -1);
    // int ans = solveMem(data, dp);
    // // Using Bottom - Up Approach or Tabulation Method
    // int ans = solveTab(data);
    // Using Space - Optimal Approach or Space-Optimization Method
    int ans = solve_Space_Optimal(data);
    cout << ans;
}