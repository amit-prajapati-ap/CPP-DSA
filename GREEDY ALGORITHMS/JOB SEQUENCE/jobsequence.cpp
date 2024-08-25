#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
struct Job
{
    int id;
    int deadline;
    int profit;
};
class Solution
{
public:
    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    vector<int> FindMax(int n, Job arr[])
    {
        sort(arr, arr + n, cmp);
        int maxdead = 0;
        for (int i = 0; i < n; i++)
        {
            maxdead = max(maxdead, arr[i].deadline);
        }
        vector<int> schedule(maxdead + 1, -1);
        int profit = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int currid = arr[i].id;
            int currprofit = arr[i].profit;
            int currdead = arr[i].deadline;
            for (int k = currdead; k > 0; k--)
            {
                if (schedule[k] == -1)
                {
                    profit += currprofit;
                    schedule[k] = currid;
                    count++;
                    break;
                }
            }
        }
        vector<int> ans(2);
        ans[0] = count;
        ans[1] = profit;
        return ans;
    }
};
int main()
{
    int n;
    cout << "Enter Number of Jobs : ";
    cin >> n;
    int data = 0;
    Job j[n];
    for (int i = 0; i < n; i++)
    {
        j[i].id = i + 1;
    }
    cout << "Enter Job Deadline of Each Job :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        j[i].deadline = data;
    }
    cout << "Enter Job Profit of Each Job :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        j[i].profit = data;
    }
    Solution s;
    vector<int> ans = s.FindMax(n, j);
    cout << "Number Of Job You Done : " << ans[0] << endl;
    cout << "Maximum Profit You Earn : " << ans[1] << endl;
}