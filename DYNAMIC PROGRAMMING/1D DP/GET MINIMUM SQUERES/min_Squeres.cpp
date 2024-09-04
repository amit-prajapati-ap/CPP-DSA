#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int solveRev(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solveRev(n - i * i));
    }
    return ans;
}
int solveMem(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + solveMem(n - i * i, dp));
    }
    dp[n] = ans;
    return dp[n];
}
int solveTab(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= n; j++)
        {
            if (i - j * j >= 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
    }
    return dp[n];
}
int MinSquares(int n)
{
    // // Recursive
    // return solveRev(n);
    // Recursive + Memorization
    // vector<int> dp(n+1,-1);
    // return solveMem(n,dp);
    // Tabulation
    return solveTab(n);
}
int main()
{

    cout << "Enter The Number : ";
    int n;
    cin >> n;
    cout << "Minimum Number Of Perfect Squeres To Make N is : " << MinSquares(n) << endl;
}