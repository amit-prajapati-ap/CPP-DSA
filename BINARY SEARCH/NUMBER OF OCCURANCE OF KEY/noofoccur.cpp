#include <iostream>
using namespace std;
int lastoccur(int arr[], int n, int key)
{
    int beg = 0, end = n - 1, ans;
    int mid = beg + (end - beg) / 2;
    while (beg <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            beg = mid + 1;
        }
        else if (arr[mid] < key)
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = beg + (end - beg) / 2;
    }
    return ans;
}
int firstoccur(int arr[], int n, int key)
{
    int beg = 0, end = n - 1, ans;
    int mid = beg + (end - beg) / 2;
    while (beg <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = beg + (end - beg) / 2;
    }
    return ans;
}

int number_of_occurance(int arr[], int n, int key)
{
    int ans;
    ans = lastoccur(arr, n, key) - firstoccur(arr, n, key) + 1;
    return ans;
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 4, 6, 7, 8, 9, 10};
    int ans;
    ans = number_of_occurance(arr, 10, 4);
    cout << "NUMBER OF OCCURANCE OF 4 IS " << ans;
}