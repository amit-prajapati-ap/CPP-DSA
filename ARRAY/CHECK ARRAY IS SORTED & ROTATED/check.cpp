#include <iostream>
using namespace std;
bool check(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            count++;
        }
    }
    if (arr[n - 1] > arr[0])
    {
        count++;
    }
    if (count <= 1)
    {
        return true;
    }
    return false;
}
int main()
{
    int arr[5] = {2, 5, 1, 8, 9}, k = 2;
    bool bl = check(arr, 5, k);
    cout << "Check : " << bl;
}