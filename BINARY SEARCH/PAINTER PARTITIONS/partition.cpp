#include <iostream>
using namespace std;
bool possiblesol(int arr[], int n, int k, int mid)
{
    int painters = 0;
    int boardsum = 0;
    for (int i = 0; i < n; i++)
    {
        if ((boardsum + arr[i]) <= mid)
        {
            boardsum += arr[i];
        }
        else
        {
            painters++;
            if (painters > k || arr[i] > mid)
            {
                return false;
            }
        }
        boardsum = arr[i];
    }
    return true;
}
int sumofarray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
int minimumtime(int arr[], int n, int k)
{
    int start = 0, ans, end = sumofarray(arr, n);
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (possiblesol(arr, n, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
    int boards[100], size, painters;
    cout << "Enter the number of Sections of boards : ";
    cin >> size;
    cout << "Enter the number of boards in each section : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> boards[i];
    }
    cout << "How many painters to be paint all the boards : ";
    cin >> painters;
    int ans = minimumtime(boards, size, painters);
    cout << "MINIMUM TIME TO PAINT ALL BOARDS " << ans;
}