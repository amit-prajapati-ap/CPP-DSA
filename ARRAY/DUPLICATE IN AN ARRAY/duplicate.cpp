#include <iostream>
using namespace std;
// 2nd approach
int findDuplicate(int *nums, int n)
{
    int s = 1;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= mid)
            {
                count++;
            }
        }
        if (count <= mid)
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return e;
}
int main()
{
    int arr[] = {2, 1, 4, 2, 3};
    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        ans = ans ^ arr[i];
    }
    for (int i = 1; i < 5; i++)
    {
        ans = ans ^ i;
    }
    int ans2 = findDuplicate(arr, 5);
    cout << ans << endl;
    cout << ans2 << endl;
}