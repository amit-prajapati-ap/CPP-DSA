#include <iostream>
#include <vector>
using namespace std;
void getans(int *arr, int n)
{
    cout << "...........Processing start to finding your answer..........." << endl;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i + 1)
        {
            ans.push_back(arr[i]);
        }
    }
    cout << "Elements are : " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "  ";
    }
}
int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    getans(arr, n);
}