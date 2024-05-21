#include <iostream>
using namespace std;
int getmin(int arr[], int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            break;
        }
        else
        {
            continue;
        }
    }
    return min;
}
int getmax(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            break;
        }
        else
        {
            continue;
        }
    }
    return max;
}
int main()
{
    int size, arr[100];
    cout << "Enter the size of array : ";
    cin >> size;
    cout << "Enter the elements of array : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Minimum value is " << getmin(arr, size) << endl;
    cout << "Maximum value is " << getmax(arr, size) << endl;
}