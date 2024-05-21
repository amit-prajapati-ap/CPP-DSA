#include <iostream>
using namespace std;
void inputarray(int arr[], int n)
{
    cout << "Enter the elements of rotated array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
int findpivot(int arr[], int n)
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
    return end;
}
int findpivot2(int arr[], int n)
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
    return end - 1;
}
int main()
{
    int arr[100], n;
    cout << "Enter the number of elements in an array : ";
    cin >> n;
    inputarray(arr, n);
    int pivot = findpivot(arr, n);
    int pivot2 = findpivot2(arr, n);
    cout << "Minimum Pivot element at index " << pivot << endl;
    cout << "Maximum Pivot element at index " << pivot2 << endl;
}