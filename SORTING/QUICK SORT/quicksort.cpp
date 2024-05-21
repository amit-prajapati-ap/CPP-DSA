#include <iostream>
using namespace std;
int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotindex = s + count;
    int i = s, j = e;
    swap(arr[pivotindex], arr[s]);
    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] <= pivotindex)
        {
            i++;
        }
        while (arr[j] > pivotindex)
        {
            j--;
        }
        if (i < pivotindex && j > pivotindex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotindex;
}
void quicksort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);
    // Left part sort
    quicksort(arr, s, p - 1);
    // Right part sort
    quicksort(arr, p + 1, e);
}
void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
int main()
{

    int arr[5] = {4, 3, 7, 5, 2};
    int n = 5;
    quicksort(arr, 0, n - 1);
    display(arr, n);
}