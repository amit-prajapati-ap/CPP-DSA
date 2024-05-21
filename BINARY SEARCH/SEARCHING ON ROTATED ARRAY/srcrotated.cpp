#include <iostream>
using namespace std;
int binarysrc(int arr[], int start, int end, int key)
{
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
int getpivot(int arr[], int n)
{
    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}
int src(int arr[], int n, int key)
{
    int ans;
    int pivot = getpivot(arr, n);
    if (arr[pivot] <= key && key <= arr[n - 1])
    {
        ans = binarysrc(arr, pivot, n - 1, key);
    }
    else
    {
        ans = binarysrc(arr, 0, pivot - 1, key);
    }
    return ans;
}
int main()
{
    int arr[10] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    int key;
    cout << "Enter the key you want to search : ";
    cin >> key;
    int ans = src(arr, 10, key);
    if (ans == -1)
    {
        cout << "Element Does not exist" << endl;
    }
    else
    {
        cout << "Element were found at index " << ans << endl;
    }
}