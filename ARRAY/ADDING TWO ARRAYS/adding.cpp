#include <iostream>
using namespace std;
void reverse(int arr[], int n)
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
    int carry = 0, arr1[100], arr2[100], arr3[100], a1, a2, k = 0;
    cout << "Enter number of elements of array 1 : ";
    cin >> a1;
    cout << "Enter the elements :" << endl;
    for (int i = 0; i < a1; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter number of elements of array 2 : ";
    cin >> a2;
    cout << "Enter the elements :" << endl;
    for (int i = 0; i < a2; i++)
    {
        cin >> arr2[i];
    }
    int i = a1 - 1;
    int j = a2 - 1;
    while (i >= 0 && j >= 0)
    {
        int sum = arr1[i] + arr2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        arr3[k] = sum;
        i--;
        j--;
        k++;
    }
    while (i >= 0)
    {
        int sum = arr1[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        arr3[k] = sum;
        i--;
        k++;
    }
    while (j >= 0)
    {
        int sum = arr2[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        arr3[k] = sum;
        j--;
        k++;
    }
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        arr3[k] = sum;
        k++;
    }
    reverse(arr3, k);

    cout << " Array after addition : " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << arr3[i] << ' ';
    }
    cout << endl;
}
