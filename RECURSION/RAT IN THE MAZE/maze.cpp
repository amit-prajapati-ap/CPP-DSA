bool issafe(vector<vector<int>> m, vector<vector<int>> visited, int x, int y, int n)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
    {
        return true;
    }
    return false;
}
void solve(vector<vector<int>> &m, vector<string> &ans, vector<vector<int>> visited, string path, int x, int y, int n)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    // down
    visited[x][y] = 1;
    int newx = x + 1;
    int newy = y;
    if (issafe(m, visited, newx, newy, n))
    {
        path.push_back('D');
        solve(m, ans, visited, path, newx, newy, n);
        path.pop_back();
    }
    // left
    newx = x;
    newy = y - 1;
    if (issafe(m, visited, newx, newy, n))
    {
        path.push_back('L');
        solve(m, ans, visited, path, newx, newy, n);
        path.pop_back();
    }
    // right
    newx = x;
    newy = y + 1;
    if (issafe(m, visited, newx, newy, n))
    {
        path.push_back('R');
        solve(m, ans, visited, path, newx, newy, n);
        path.pop_back();
    }
    // up
    newx = x - 1;
    newy = y;
    if (issafe(m, visited, newx, newy, n))
    {
        path.push_back('U');
        solve(m, ans, visited, path, newx, newy, n);
        path.pop_back();
    }
    visited[x][y] = 0;
}
class Solution
{
public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        if (m[0][0] == 0)
        {
            return ans;
        }
        string path = "";
        int srcx = 0;
        int srcy = 0;
        vector<vector<int>> visited = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }
        solve(m, ans, visited, path, srcx, srcy, n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
