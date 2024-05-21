#include <iostream>
using namespace std;
int main()
{
    int arr[100], n;
    cout << "Enter the number of elements of the array : ";
    cin >> n;
    cout << "Enter the elements of array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}