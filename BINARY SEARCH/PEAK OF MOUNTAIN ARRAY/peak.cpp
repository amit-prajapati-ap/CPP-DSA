#include <iostream>
using namespace std;
int peak(int arr[], int n)
{
    // 1st approach ->
    /*
    int beg = 0, end = n - 1;
     int mid = beg + (end - beg) / 2;
     while (beg < end)
     {
         if (arr[mid] < arr[mid + 1])
         {
             beg = mid + 1;
         }
         else
         {
             end = mid;
         }
         mid = beg + (end - beg) / 2;
     }
     return beg;
    */
    // 2nd approach ->
    int beg = 0;
    int end = n - 1;
    int mid = beg + (end - beg) / 2;

    while (beg <= end)
    {
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            beg = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = beg + (end - beg) / 2;
    }
    return -1;
}
int main()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 4, 3, 2, 1};
    int ans = peak(arr, 10);
    cout << "PEAK ELEMENT OF MOUNTAIN ARRAY IS " << ans << endl;
}