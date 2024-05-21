#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool ispossible(int arr[], int n, int k, int mid)
{
    int cowcount = 1;
    int lastposition = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - lastposition >= mid)
        {
            cowcount++;
            if (cowcount == k)
            {
                return true;
            }
            lastposition = arr[i];
        }
    }
    return false;
}
int aggressivecows(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int start = 0, maxi = -1, ans = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int end = maxi;
    int mid = start + (end - start / 2);
    while (start <= end)
    {
        if (ispossible(arr, n, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start / 2);
    }

    return ans;
}
int main()
{
    int k = 2;
    int arr[100], n;
    cout << "Enter the number of element : ";
    cin >> n;
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = aggressivecows(arr, 5, k);
    cout << ans;
}