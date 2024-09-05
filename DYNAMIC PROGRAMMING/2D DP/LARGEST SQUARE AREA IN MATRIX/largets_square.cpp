#include <iostream>
#include <vector>
using namespace std;
int solveRev(vector<vector<int>> &mat, int n, int m, int i, int j, int &maxi)
{
    if (i >= n || j >= m)
    {
        return 0;
    }
    int right = solveRev(mat, n, m, i, j + 1, maxi);
    int down = solveRev(mat, n, m, i + 1, j, maxi);
    int diagonal = solveRev(mat, n, m, i + 1, j + 1, maxi);
    if (mat[i][j] == 1)
    {
        int ans = 1 + min(diagonal, min(down, right));
        maxi = max(ans, maxi);
        return ans;
    }
    else
    {
        return 0;
    }
}
int solveMem(vector<vector<int>> &mat, vector<vector<int>> &dp, int n, int m, int i, int j, int &maxi)
{
    if (i >= n || j >= m)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int right = solveMem(mat, dp, n, m, i, j + 1, maxi);
    int down = solveMem(mat, dp, n, m, i + 1, j, maxi);
    int diagonal = solveMem(mat, dp, n, m, i + 1, j + 1, maxi);
    if (mat[i][j] == 1)
    {
        int ans = 1 + min(diagonal, min(down, right));
        maxi = max(ans, maxi);
        dp[i][j] = ans;
        return ans;
    }
    else
    {
        return dp[i][j] = 0;
    }
}
int solveTab(vector<vector<int>> &mat, int maxi)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int right = dp[i][j + 1];
            int down = dp[i + 1][j];
            int diagonal = dp[i + 1][j + 1];
            if (mat[i][j] == 1)
            {
                int ans = 1 + min(diagonal, min(down, right));
                maxi = max(ans, maxi);
                dp[i][j] = ans;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return maxi;
}
int solve_Space_Optimal(vector<vector<int>> &mat, int maxi)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<int> curr(m + 1, 0);
    vector<int> next(m + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int right = curr[j + 1];
            int down = next[j];
            int diagonal = next[j + 1];
            if (mat[i][j] == 1)
            {
                int ans = 1 + min(diagonal, min(down, right));
                maxi = max(ans, maxi);
                curr[j] = ans;
            }
            else
            {
                curr[j] = 0;
            }
        }
        next = curr;
    }
    return maxi;
}
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    // // Recursive
    // int maxi = 0;
    // solveRev(mat,n,m,0,0,maxi);
    // return maxi;
    // Memorization
    // int maxi = 0;
    // vector<vector<int> > dp(n,vector<int> (m,-1));
    // solveMem(mat,dp,n,m,0,0,maxi);
    // return maxi;
    // // Tabulation
    // return solveTab(mat,0);
    // Space Optimal
    return solve_Space_Optimal(mat, 0);
}
int main()
{

    int n, m, data;
    cout << "Enter The Row & Column of Matrix : ";
    cin >> n >> m;
    cout << "Enter The Data in Matrix : ";
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n * m; i++)
    {
        cin >> data;
        arr[i / m][i % m] = data;
    }
    cout << "Maximum Side Of Length Of Square is : " << maxSquare(n, m, arr) << endl;
}