#include <iostream>
using namespace std;
double findprecision(int integer, int n, int precision)
{
    double ans = integer;
    double factor = 1;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}
int binarysrc(int arr[], int n, int key)
{
    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        long int temp = arr[mid] * arr[mid];
        if (temp == key)
        {
            return mid;
        }
        else if (temp < key)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int findroot(int root)
{
    int arr[root];
    for (int i = 0; i < root; i++)
    {
        arr[i] = i;
    }
    return binarysrc(arr, root, root);
}
int main()
{
    int root;
    cout << "Enter the number you want to root : ";
    cin >> root;
    int integer = findroot(root);
    double decimal = findprecision(integer, root, 3);
    if (integer == -1)
    {
        cout << "NOT FOUND";
    }
    else
    {
        cout << "The root of " << root << " is " << decimal;
    }
}