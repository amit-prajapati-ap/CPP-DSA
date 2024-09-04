#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <utility>
using namespace std;
int solveRev(int n, vector<int> &days, vector<int> &cost, int i)
{
    if (i >= n)
    {
        return 0;
    }
    int index;
    // 1-Day Pass
    int option1 = cost[0] + solveRev(n, days, cost, i + 1);
    // 7-Days Pass
    for (index = i; (index < n) && (days[index] < (days[i] + 7)); index++)
        ;
    int option2 = cost[1] + solveRev(n, days, cost, index);
    // 30-Days Pass
    for (index = i; (index < n) && (days[index] < (days[i] + 30)); index++)
        ;
    int option3 = cost[2] + solveRev(n, days, cost, index);
    return min(option1, min(option2, option3));
}
int solveMem(int n, vector<int> &days, vector<int> &cost, int i, vector<int> &dp)
{
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int index;
    // 1-Day Pass
    int option1 = cost[0] + solveMem(n, days, cost, i + 1, dp);
    // 7-Days Pass
    for (index = i; (index < n) && (days[index] < (days[i] + 7)); index++)
        ;
    int option2 = cost[1] + solveMem(n, days, cost, index, dp);
    // 30-Days Pass
    for (index = i; (index < n) && (days[index] < (days[i] + 30)); index++)
        ;
    int option3 = cost[2] + solveMem(n, days, cost, index, dp);
    dp[i] = min(option1, min(option2, option3));
    return dp[i];
}
int solveTab(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        // 1-Day Pass
        int option1 = cost[0] + dp[i + 1];
        int index;
        // 7-Days Pass
        for (index = i; (index < n) && (days[index] < (days[i] + 7)); index++)
            ;
        int option2 = cost[1] + dp[index];
        // 30-Days Pass
        for (index = i; (index < n) && (days[index] < (days[i] + 30)); index++)
            ;
        int option3 = cost[2] + dp[index];
        dp[i] = min(option1, min(option2, option3));
    }
    return dp[0];
}
int solve_Space_Optimal(int n, vector<int> &days, vector<int> &cost)
{
    int ans = 0;
    queue<pair<int, int>> month;
    queue<pair<int, int>> week;
    for (int day : days)
    {
        while (!month.empty() && month.front().first + 30 <= day)
        {
            month.pop();
        }
        while (!week.empty() && week.front().first + 7 <= day)
        {
            week.pop();
        }
        month.push({day, ans + cost[2]});
        week.push({day, ans + cost[1]});
        ans = min(ans + cost[0], min(month.front().second, week.front().second));
    }
    return ans;
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // // Recursive
    // return solveRev(n,days,cost,0);
    // // Recursion + Memorization
    // vector<int> dp(n+1,-1);
    // return solveMem(n,days,cost,0,dp);
    // // Tabulation
    // return solveTab(n,days,cost);
    // Space Optimal Method
    return solve_Space_Optimal(n, days, cost);
}
int main()
{
    int n, data;
    vector<int> day, cost;
    cout << "Enter The Number of Days To Be Travel : ";
    cin >> n;
    cout << "Enter The Days : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        day.push_back(data);
    }
    cout << "Enter The Cost Of 1Day , 7Day & 30Day Pass Cost : " << endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> data;
        cost.push_back(data);
    }
    cout << "Minimum Cost Required To Complete The Tour is : " << minimumCoins(n, day, cost) << endl;
}