#include <iostream>
using namespace std;
void rotatearray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        swap(arr[i], arr[n - 1]);
    }
}
void print(int *arr, int n)
{
    cout << "After rotate Array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements : "
         << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    rotatearray(arr, n);
    print(arr, n);
}