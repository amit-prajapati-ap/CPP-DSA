#include <iostream>
using namespace std;
int firstoccur(int arr[], int n, int key)
{
    int beg = 0, end = n - 1, ans = -1;
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
int lastoccur(int arr[], int n, int key)
{
    int beg = 0, end = n - 1, ans = -1;
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
int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 4, 5, 6, 7};
    int first, last;
    first = firstoccur(arr, 10, 3);
    last = lastoccur(arr, 10, 3);
    cout << "FIRST OCCURANCE OF 3 IN INDEX " << first << endl;
    cout << "LAST OCCURANCE OF 3 IN INDEX " << last << endl;
}