#include <iostream>
#include <limits.h>
#include <deque>
using namespace std;
int solve(int *arr, int n, int k)
{
    // //Approach 1 (Iterative)
    // int sum = 0;
    // int mini = INT_MAX, maxi = INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     if ((i + k) > n)
    //     {
    //         continue;
    //     }
    //     for (int j = i; j < k + i; j++)
    //     {
    //         if (arr[j] < mini)
    //         {
    //             mini = arr[j];
    //         }
    //         if (arr[j] > maxi)
    //         {
    //             maxi = arr[j];
    //         }
    //     }
    //     cout << "Mini = " << mini << " , Maxi = " << maxi << endl;
    //     sum += mini + maxi;
    // }
    // return sum;
    // Approach 2
    deque<int> maxi(k);
    deque<int> mini(k);
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];
    for (int i = k; i < n; i++)
    {
        //Removal
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }
        //Addition
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}
int main()
{
    int n = 7, k = 4;
    int arr[] = {2,5,-1,7,-3,-1,-2};
    int ans = solve(arr, n, k);
    cout << "Sum Of All Min & Max Element In Every K Size Window : " << ans << endl;
}