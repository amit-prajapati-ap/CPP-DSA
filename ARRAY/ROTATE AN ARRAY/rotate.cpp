#include <iostream>
using namespace std;
void rotate(int arr[], int n, int k)
{
    int temp[100] = {0};
    for (int i = 0; i < n; i++)
    {
        temp[(k + i) % n] = arr[i];
    }
    arr = temp;
    cout << "After rotate : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}
int main()
{
    int arr[100], n, k;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the number to rotate : ";
    cin >> k;

    rotate(arr, n, k);
}