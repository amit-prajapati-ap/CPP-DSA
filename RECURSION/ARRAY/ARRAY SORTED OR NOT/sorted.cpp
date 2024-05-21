#include <iostream>
using namespace std;

bool check(int *arr, int n)
{
    if (n == 0)
    {
        return true;
    }
    if (n == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    check(arr + 1, n - 1);
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
    bool ans = check(arr, n);
    if (ans == 1)
    {
        cout << "Sorted" << endl;
    }
    else
    {
        cout << "Not sorted" << endl;
    }
    delete[] arr;
}