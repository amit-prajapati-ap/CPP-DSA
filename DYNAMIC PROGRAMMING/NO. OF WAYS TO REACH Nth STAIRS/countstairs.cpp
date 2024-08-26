#include <iostream>
#include <vector>
using namespace std;
int solveRec(int n, int i)
{
    if (i == n)
    {
        return 1;
    }
    else if (i > n)
    {
        return 0;
    }
    return solveRec(n, i + 1) + solveRec(n, i + 2);
}
int solveMem(int n, int i, vector<int> &dp)
{
    if (i == n)
    {
        return 1;
    }
    else if (i > n)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    return dp[i] = solveMem(n, i + 1, dp) + solveMem(n, i + 2, dp);
}
int solveTab(int n)
{
    vector<int> dp(n + 2, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = dp[i + 1] + dp[i + 2];
    }
    return dp[0];
}
int solve_Space_Optimal(int n)
{
    int next1 = 1;
    int next2 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = next1 + next2;
        next2 = next1;
        next1 = curr;
    }
    return next1;
}
int main()
{
    cout << "Enter the Number Of Stairs : ";
    int n;
    cin >> n;
    // // Recursion
    // cout << solveRec(n, 0) << " Ways To Reach " << n << " Stairs." << endl;
    // // Memorization
    // vector<int> dp(n + 1, -1);
    // cout << solveMem(n, 0, dp) << " Ways To Reach " << n << " Stairs." << endl;
    // // Tabulation
    // cout << solveTab(n) << " Ways To Reach " << n << " Stairs." << endl;
    // Space Optimization
    cout << solve_Space_Optimal(n) << " Ways To Reach " << n << " Stairs." << endl;
}