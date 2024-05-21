#include <iostream>
using namespace std;
void printarr(int arr[], int n)
{
    cout << "After sorting : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}
void bubblesorting(int arr[], int n)
{
    bool bl = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                bl = true;
            }
        }
        if (bl == false)
        {
            break;
        }
    }
}
void inputarr(int arr[], int n)
{
    cout << "Enter the elements of array for the sorting : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
int main()
{
    int arr[100], n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    inputarr(arr, n);
    bubblesorting(arr, n);
    printarr(arr, n);
}