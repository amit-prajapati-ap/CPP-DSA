#include <iostream>
using namespace std;
void merge(int arr1[], int a1, int arr2[], int a2, int arr3[], int a3)
{
    int i = 0, j = 0, k = 0;
    while (i < a1 && j < a2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < a1)
    {
        arr3[k++] = arr1[i++];
    }

    while (j < a2)
    {
        arr3[k++] = arr2[j++];
    }
}
void display(int arr3[], int a3)
{
    cout << "After merging :" << endl;
    for (int i = 0; i < a3; i++)
    {
        cout << arr3[i] << ' ';
    }
}
int main()
{
    int arr1[5] = {1, 3, 5, 7, 9}, arr2[3] = {2, 4, 6}, arr3[8] = {0};
    merge(arr1, 5, arr2, 3, arr3, 8);
    display(arr3, 8);
}