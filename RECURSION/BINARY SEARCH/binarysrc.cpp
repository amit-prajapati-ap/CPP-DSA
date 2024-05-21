#include <iostream>
using namespace std;
int binary(int *arr, int s, int e, int key)
{
    if (s > e)
    {
        return -1;
    }
    int mid = s + (e - s / 2);
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] > key)
    {
        binary(arr, s, mid - 1, key);
    }
    else
    {
        binary(arr, mid + 1, e, key);
    }
}
int main()
{
    int arr[6] = {2, 5, 7, 8, 10, 15};
    int key = 10;
    cout << "Element are found at location: " << binary(arr, 0, 5, key) << endl;
}