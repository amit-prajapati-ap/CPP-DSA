#include <iostream>
#include <vector>
using namespace std;
int solveRev(vector<int> &weight, vector<int> &value, int index, int w)
{
    if (index == 0)
    {
        if (weight[0] <= w)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    int include = 0;
    if (weight[index] <= w)
    {
        include = value[index] + solveRev(weight, value, index - 1, w - weight[index]);
    }
    int exclude = 0 + solveRev(weight, value, index - 1, w);
    return max(include, exclude);
}
int solveMem(vector<int> &weight, vector<int> &value, int index, int w, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= w)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][w] != -1)
    {
        return dp[index][w];
    }
    int include = 0;
    if (weight[index] <= w)
    {
        include = value[index] + solveMem(weight, value, index - 1, w - weight[index], dp);
    }
    int exclude = solveMem(weight, value, index - 1, w, dp);
    dp[index][w] = max(include, exclude);
    return max(include, exclude);
}
int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= w)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weight[i] <= w)
            {
                include = value[i] + dp[i - 1][w - weight[i]];
            }
            int exclude = dp[i - 1][w];
            dp[i][w] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}
int solve_Space_Optimal(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= w)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weight[i] <= w)
            {
                include = value[i] + prev[w - weight[i]];
            }
            int exclude = prev[w];
            curr[w] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[capacity];
}
int solve_Space_Optimal2(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<int> curr(capacity + 1, 0);
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= w)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int w = capacity; w >= 0; w--)
        {
            int include = 0;
            if (weight[i] <= w)
            {
                include = value[i] + curr[w - weight[i]];
            }
            int exclude = curr[w];
            curr[w] = max(include, exclude);
        }
    }
    return curr[capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // // Recursive
    // solveRev(weight, value, n-1, maxWeight);
    // // Recursion + Memorization
    // vector<vector<int> > dp(n,vector<int>(maxWeight + 1,-1));
    // return solveMem(weight, value, n-1, maxWeight, dp);
    // // Tabulation
    // return solveTab(weight, value, n, maxWeight);
    // // Space Optimation
    // return solve_Space_Optimal(weight, value, n, maxWeight);
    // Space Optimation 2
    return solve_Space_Optimal2(weight, value, n, maxWeight);
}
int main()
{
    int n, maxWeight, data;
    vector<int> w, v;
    cout << "Enter The Number of Items : ";
    cin >> n;
    cout << "Enter The Weight Of Every Items : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        w.push_back(data);
    }
    cout << "Enter The Value Of Every Items : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        v.push_back(data);
    }
    cout << "Enter The Maximum Weight That Can Carry Into Knapsack : ";
    cin >> maxWeight;
    cout << "Maximum Value That Carry Into Knapsack is : " << knapsack(w, v, n, maxWeight) << endl;
}