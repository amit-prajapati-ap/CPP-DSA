#include <iostream>
#include <vector>
using namespace std;
int solveRec(vector<int> &cost, int n)
{ // Using Top-Down Approach
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }
    return min(solveRec(cost, n - 1), solveRec(cost, n - 2)) + cost[n];
}
int solveMem(vector<int> &cost, int n, vector<int> &dp)
{ // Using Top-Down Approach
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = min(solveMem(cost, n - 1, dp), solveMem(cost, n - 2, dp)) + cost[n];
    return dp[n];
}
int solveTab(vector<int> &cost, int n)
{
    vector<int> dp(n + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return min(dp[n - 1], dp[n - 2]);
}
int solve_Space_Optimal(vector<int> &cost, int n)
{
    int prev1 = cost[1];
    int prev2 = cost[0];
    for (int i = 2; i < n; i++)
    {
        int curr = min(prev1, prev2) + cost[i];
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}
int main()
{
    cout << "Enter the Number Of Stairs : ";
    int n;
    cin >> n;
    cout << "Enter The Cost Of Each Staires : " << endl;
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    // // Recursion
    // cout << "Minimum Cost To Reach The Top : " << solveRec(cost,n) << endl;
    // // Memorization
    // vector<int> dp(n + 1, -1);
    // cout << "Minimum Cost To Reach The Top : " << solveMem(cost,n,dp) << endl;
    // // Tabulation
    // cout << "Minimum Cost To Reach The Top : " << solveTab(cost,n) << endl;
    // Space Optimization
    cout << "Minimum Cost To Reach The Top : " << solve_Space_Optimal(cost, n) << endl;
}