#include <iostream>
#include <vector>
using namespace std;
vector<int> getans(int *arr, int n, int k)
{
    vector<int> ans;
    for (int i = k; i < n; i++)
    {
        ans.push_back(arr[i]);
    }
    for (int i = 0; i < k; i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}
int main()
{
    int n, k;
    cout << "Enter number of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the value for rotate : ";
    cin >> k;
    vector<int> ans = getans(arr, n, k);
    cout << "Element after rotate : " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "  ";
    }
}