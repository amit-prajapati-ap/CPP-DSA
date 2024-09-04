#include <iostream>
#include <vector>
using namespace std;
int solveRev(vector<int> &num, int tar)
{
    if (tar == 0)
    {
        return 1;
    }
    else if (tar < 0)
    {
        return 0;
    }
    int ans = 0;
    for (auto i : num)
    {
        ans += solveRev(num, tar - i);
    }
    return ans;
}
int solveMem(vector<int> &num, int tar, vector<int> &dp)
{
    if (tar == 0)
    {
        return 1;
    }
    else if (tar < 0)
    {
        return 0;
    }
    if (dp[tar] != -1)
    {
        return dp[tar];
    }
    int ans = 0;
    for (auto i : num)
    {
        ans += solveMem(num, tar - i, dp);
    }
    dp[tar] = ans;
    return dp[tar];
}
int solveTab(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= tar; i++)
    {
        for (auto j : num)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{
    // // Recursive
    // return solveRev(num,tar);
    // // Recursion + Memorization
    // vector<int> dp(tar+1,-1);
    // return solveMem(num, tar, dp);
    // Tabulation
    return solveTab(num, tar);
}
int main()
{
    cout << "Enter Number Of Elements : ";
    int n, data, target;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        num.push_back(data);
    }
    cout << "Enter The Value Of Target : ";
    cin >> target;
    cout << "Number Of Ways To Make Target From Selecting Number From Array : " << findWays(num, target) << endl;
}