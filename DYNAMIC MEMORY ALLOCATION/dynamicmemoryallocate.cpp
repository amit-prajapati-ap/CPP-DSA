// Dynamically memory allocation through "HEAP"
#include <iostream>
using namespace std;
int getsum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = getsum(arr, n);
    cout << "Answer is " << ans << endl;
}