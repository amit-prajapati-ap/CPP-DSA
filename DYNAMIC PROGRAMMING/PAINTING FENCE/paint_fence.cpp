#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
int add(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}
int mul(int a, int b)
{
    return ((a % MOD) * 1ll * (b % MOD)) % MOD;
}
int solveRec(int n, int k)
{
    if (n == 1)
        return k;
    else if (n == 2)
        return add(k, mul(k, k - 1));
    return add(mul(solveRec(n - 2, k), k - 1), mul(solveRec(n - 1, k), k - 1));
}
int solveMem(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;
    else if (n == 2)
        return add(k, mul(k, k - 1));
    else if (dp[n] != -1)
        return dp[n];
    dp[n] = add(mul(solveMem(n - 2, k, dp), k - 1), mul(solveMem(n - 1, k, dp), k - 1));
    return dp[n];
}
int solveTab(int n, int k)
{
    vector<int> dp(n + 1, k);
    dp[2] = add(k, mul(k, k - 1));
    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
    }
    return dp[n];
}
int solveSpaceOpt(int n, int k)
{
    int prev2 = k, prev1 = add(k, mul(k, k - 1));
    for (int i = 3; i <= n; i++)
    {
        int ans = add(mul(prev2, k - 1), mul(prev1, k - 1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int numberOfWays(int n, int k)
{
    // // Recursion Method
    // return solveRec(n, k);
    // // Recursion + Memorization Method
    // vector<int> dp(n+1,-1);
    // return solveMem(n,k,dp);
    // // Tabulation Method
    // return solveTab(n,k);
    // Space Optimal Method
    return solveSpaceOpt(n, k);
}
int main()
{
    int n, k;
    cout << "Enter The Number Of Posts : ";
    cin >> n;
    cout << "Enter The Number Of Colors : ";
    cin >> k;
    cout << "Number of Ways To Paint The Fence : " << numberOfWays(n, k) << endl;
}