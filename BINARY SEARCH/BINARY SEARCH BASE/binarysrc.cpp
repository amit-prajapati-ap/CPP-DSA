#include <iostream>
using namespace std;
int search(int arr[], int n, int src)
{
    int beg = 0, end = n - 1;
    int mid = beg + (end - beg / 2);
    while (beg <= end)
    {
        if (arr[mid] == src)
        {
            return mid + 1;
        }
        else if (arr[mid] < src)
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = beg + (end - beg / 2);
    }
    return -1;
}
int main()
{
    int arr[] = {2, 3, 7, 9, 14, 22, 25, 30, 40, 55};
    int key;
    cout << "Enter the element that you want to search : ";
    cin >> key;
    int src = search(arr, 10, key);
    if (src == -1)
    {
        cout << "Element are not found";
    }
    else
    {
        cout << key << " are found at location " << src;
    }
}