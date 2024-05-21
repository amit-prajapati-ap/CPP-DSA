#include <iostream>
using namespace std;
int unique(int arr[], int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = temp ^ arr[i];
    }
    return temp;
}
int main()
{
    int arr[7] = {1, 2, 1, 3, 2, 4, 3}, ans;
    ans = unique(arr, 7);
    cout << "Answer is : " << ans;
}