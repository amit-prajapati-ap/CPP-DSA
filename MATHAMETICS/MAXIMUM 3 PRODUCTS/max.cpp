#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maximumProduct(vector<int> &nums)
{
    int n = nums.size();
    int ans;
    int max1 = n - 1, max2 = n - 2, max3 = n - 3;
    int min1 = 0, min2 = 1, min3 = n - 1;
    sort(nums.begin(), nums.end());
    ans = max(max1 * max2 * max3, min1 * min2 * min3);
    return ans;
}
int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int a[n];
    vector<int> arr;
    cout << "Enter elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        arr.push_back(a[i]);
    }
    int ans = maximumProduct(arr);
    cout << "Answer is : " << ans;
}