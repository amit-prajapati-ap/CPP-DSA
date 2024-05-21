#include <iostream>
using namespace std;
void rotateArray(int *arr, int n)
{
    int temp = arr[0];
    for (int i = 0; i < n; i++)
    {
        int rotate = arr[i + 1];
        if ((i + 1) < n)
        {
            arr[i] = rotate;
        }
        else
        {
            arr[i] = temp;
        }
    }
}
int main()
{
    int n;
    cout << "Enter the enumber of elements of array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    rotateArray(arr, n);
    cout << "After rotation : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}