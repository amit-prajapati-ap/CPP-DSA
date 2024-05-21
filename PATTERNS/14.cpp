#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of row : ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int space = n - i;
        for (int s = 0; s < space; s++)
        {
            cout << ' ';
        }
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int k = 2; k <= i; k++)
        {
            cout << i - k + 1;
        }
        cout << endl;
    }
}