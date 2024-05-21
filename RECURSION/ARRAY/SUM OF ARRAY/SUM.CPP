#include <iostream>
using namespace std;

int sum(int *arr, int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        int ans = arr[0] + sum(arr + 1, n - 1);
        return ans;
    }
}

int main()
{

    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = sum(arr, n);
    cout << "Sum is : " << ans << endl;
}