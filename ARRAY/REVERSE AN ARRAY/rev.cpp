#include <iostream>
using namespace std;
void rev(int arr[], int n)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    cout << "Before reverse  :  ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << ' ';
    }
    rev(arr, 6);
    cout << endl << "After reverse  :  ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << ' ';
    }
}