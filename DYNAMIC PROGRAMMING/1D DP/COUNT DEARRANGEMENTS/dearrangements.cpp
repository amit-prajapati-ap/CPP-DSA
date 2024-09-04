#include <vector>
#include <iostream>
using namespace std;
#define MOD 1000000007
long long int SolveRec(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return ((n - 1 % MOD) * ((SolveRec(n - 1) % MOD) + (SolveRec(n - 2) % MOD))) % MOD;
}
long long int SolveMem(int n, vector<int> &dp)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = ((n - 1 % MOD) * ((SolveMem(n - 1, dp) % MOD) + (SolveMem(n - 2, dp) % MOD))) % MOD;
}
long long int SolveTab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        long long int sum = (dp[i - 1] % MOD) + (dp[i - 2] % MOD) % MOD;
        dp[i] = ((i - 1) * sum) % MOD;
    }
    return dp[n];
}
long long int SolveSpaceOpt(int n)
{
    long long int prev1 = 1;
    long long int prev2 = 0;
    for (int i = 3; i <= n; i++)
    {
        long long int sum = (prev1 % MOD) + (prev2 % MOD) % MOD;
        prev2 = prev1;
        prev1 = ((i - 1) * sum) % MOD;
    }
    return prev1;
}
long long int countDerangements(int n)
{
    // // Recursion
    // return SolveRec(n);
    // // Recursion + Memorization
    // vector<int> dp(n+1,-1);
    // return SolveMem(n, dp);
    // // Tabulation
    // return SolveTab(n);
    // Space Optimization
    return SolveSpaceOpt(n);
}
int main()
{
    cout << "Enter The Value Of n : ";
    int n;
    cin >> n;
    cout << "Number Of Dearrangements is : " << countDerangements(n) << endl;
}