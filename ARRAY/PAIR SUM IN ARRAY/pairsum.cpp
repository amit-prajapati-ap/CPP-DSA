#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum;
    cin >> sum;
    // TRIPLET SUM CODE
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            for (int k = j + 1; k < 10; k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    cout << arr[i] << '+' << arr[j] << '+' << arr[k] << '=' << sum << endl;
                    break;
                }
            }
        }
    }
    // PAIR SUM CODE
    /* for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                cout << arr[i] << '+' << arr[j] << '=' << sum << endl;
                break;
            }
        }
    } */
}