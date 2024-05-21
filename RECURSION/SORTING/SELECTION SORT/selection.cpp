#include <iostream>
using namespace std;
void selection(int *arr, int n,int j)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    int min = j
    for (int i = j+1; i < n; i++)
    {
        if (arr[i-1] < arr[j])
        {
            swap(arr[i-1], arr[i]);
        }
    }
    selection(arr+1, --n,min);
}
int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selection(arr, n);
    cout << "After sorting : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
}