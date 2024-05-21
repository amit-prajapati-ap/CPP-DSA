#include <iostream>
using namespace std;
int add(int arr[], int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = temp + arr[i];
    }
    return temp;
}
int main()
{
    int n, arr[100], sum;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sum = add(arr, n);
    cout << "Sum is : " << sum << endl;
}