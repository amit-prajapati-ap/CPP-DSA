#include <iostream>
using namespace std;
void swapalt(int arr[], int size)
{

    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            swap(arr[i], arr[i + 1]);
        }
        else
        {
            continue;
        }
    }
}
int main()
{
    int odd[5] = {1, 2, 3, 4, 5};
    int even[8] = {2, 1, 4, 3, 6, 5, 8, 7};
    swapalt(odd, 5);
    swapalt(even, 8);
    cout << "ODD SIZE OF ARRAY : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << odd[i] << ' ';
    }
    cout << endl;
    cout << "EVEN SIZE OF ARRAY : " << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << even[i] << ' ';
    }
}