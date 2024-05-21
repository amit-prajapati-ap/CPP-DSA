#include <iostream>
using namespace std;
void getans(int *arr, int n)
{
    int ans[2];
    int smaxval1 = -1, smaxval2 = -1;
    int sminval1 = 32000, sminval2 = 32000;
    for (int i = 0; i < n; i++)
    {
        if (sminval1 > arr[i])
        {
            sminval2 = sminval1;
            sminval1 = arr[i];
        }
        else if (sminval1 < arr[i] && sminval2 > arr[i])
        {
            sminval2 = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (smaxval1 < arr[i])
        {
            smaxval2 = smaxval1;
            smaxval1 = arr[i];
        }
        else if (smaxval1 > arr[i] && smaxval2 < arr[i])
        {
            smaxval2 = arr[i];
        }
    }
    ans[0] = sminval2;
    ans[1] = smaxval2;

    cout << "2ND MINIMUM ELEMENT IS : " << ans[0] << endl;
    cout << "2ND MAXIMUM ELEMENT IS : " << ans[1] << endl;
}
int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    getans(arr, n);
}