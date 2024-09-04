#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int solveRev(int n, int x, int y, int z)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    int ans1 = solveRev(n - x, x, y, z) + 1;
    int ans2 = solveRev(n - y, x, y, z) + 1;
    int ans3 = solveRev(n - z, x, y, z) + 1;
    return max(ans1, max(ans2, ans3));
}
int solveMem(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    if (dp[n] != -1)
        return dp[n];
    int ans1 = solveMem(n - x, x, y, z, dp) + 1;
    int ans2 = solveMem(n - y, x, y, z, dp) + 1;
    int ans3 = solveMem(n - z, x, y, z, dp) + 1;
    dp[n] = max(ans1, max(ans2, ans3));
    return dp[n];
}
int solveTab(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0 && dp[i - x] != -1)
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0 && dp[i - y] != -1)
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0 && dp[i - z] != -1)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }
    return dp[n];
}
int cutSegments(int n, int x, int y, int z)
{
    // // Approach 1 : Recursion
    // int ans = solveRev(n,x,y,z);
    // if(ans < 0) {
    // 	return 0;
    // }
    // return ans;
    // // Approach 2 : Recursion + Memorization
    // vector<int> dp(n+1,-1);
    // int ans = solveMem(n,x,y,z,dp);
    // if(ans < 0) {
    // 	return 0;
    // }
    // return ans;
    // Apprioach 3 : Tabulation
    int ans = solveTab(n, x, y, z);
    if (ans < 0)
    {
        return 0;
    }
    return ans;
}
int main()
{

    int x, y, z, n;
    cout << "Enter The Length Of Rod : ";
    cin >> n;
    cout << "Enter The Length Of x , y & z Rod : ";
    cin >> x >> y >> z;
    cout << "Maximum Number Of Segments to Make With Given Values : " << cutSegments(n, x, y, z) << endl;
}