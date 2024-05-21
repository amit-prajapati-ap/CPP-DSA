#include <iostream>
using namespace std;

int linear(int *arr, int n, int key)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[0] == key)
    {
        return arr[0];
    }
    else
    {
        linear(arr + 1, n - 1, key);
    }
}

int main()
{

    int arr[6] = {3, 2, 5, 8, 6, 10};
    int key = 5;
    int ans = linear(arr, 6, key);
    cout << "Element are found : " << ans << "\n";
}