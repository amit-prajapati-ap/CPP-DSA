#include <iostream>
using namespace std;
void printarray(int arr[], int n)
{
    cout << "After sorting : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}
void sortColors(int *nums, int n)
{
    int i = 0, k = 0, j = n - 1;
    while (k <= j)
    {
        if (nums[k] == 0)
        {
            swap(nums[i], nums[k]);
            i++;
            k++;
        }
        else if (nums[k] == 1)
        {
            k++;
        }
        else
        {
            swap(nums[k], nums[j]);
            j--;
        }
    }
}
int main()
{
    int arr[100], n;
    cout << "Enter the number of elements of array : ";
    cin >> n;
    cout << "Enter the elements of array (0,1,2) form only :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // sortarr(arr,n);
    sortColors(arr, n);
    printarray(arr, n);
}